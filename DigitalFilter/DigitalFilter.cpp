// DigitalFilter.cpp : DLL アプリケーション用にエクスポートされる関数を定義します。
//

#include "stdafx.h"
#define _USE_MATH_DEFINES
#define DIGITAL_FILTER_EXPORTS

#include "DigitalFilter.h"
#include <cmath>

//using
using std::vector;

namespace DigitalFilter{
	Filter::~Filter(){
		delete impulse;
	}

	void Filter::filtering(vector<double> *x){
		//入力の実体への参照
		vector<double> &input = *x;
		//フィルタの出力信号
		vector<double> y(input.size());

		vector<double> &imp = *impulse;

		//フィルタリング
		for (unsigned int n = 0; n < input.size(); n++){
			for (unsigned int i = 0; i < order; i++){
				if (n >= i){
					y[n] += imp[i] * input[n - i];
				}
			}
		}
		//フィルタリング結果を格納
		for (unsigned int i = 0; i < input.size(); i++){
			input[i] = y[i];
		}
	}

	void Filter::mult_hann_window(){
		vector<double> &imp = *impulse;
		for (unsigned int i = 0; i < order; i++){
			imp[i] *= 0.5 - 0.5 * cos(2 * M_PI*((double)i / order));
		}
	}

	double Filter::sinc(double x){
		return (x == 0.0) ? 1.0 : sin(x)/x;
	}
}