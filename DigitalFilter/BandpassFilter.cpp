//BandpassFilter.cpp

#include "stdafx.h"
#define _USE_MATH_DEFINES
#define DIGITAL_FILTER_EXPORTS

#include "DigitalFilter.h"
#include <cmath>

using std::vector;

namespace DigitalFilter{
	BandpassFilter::BandpassFilter(unsigned int order, double low_edge, double high_edge){
		//メンバ変数をセット
		this->order = order;
		this->low_edge = low_edge;
		this->high_edge = high_edge;
		this->impulse = new vector<double>();

		vector<double> &imp = *impulse;

		//メモリ確保
		imp.resize(order);
		//インパルス応答を求める
		for (unsigned int i = 0; i < order; i++){
			imp[i] = impulse_response(i);
		}
		//インパルス応答に窓関数をかける
		mult_hann_window();
	}

	double BandpassFilter::impulse_response(int n){
		int i = n - order/2;
		return 2 * high_edge * sinc(2*M_PI*high_edge*i) - 2 * low_edge * sinc(2.0*M_PI*low_edge*i);
	}
}