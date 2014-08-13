// DigitalFilter.cpp : DLL �A�v���P�[�V�����p�ɃG�N�X�|�[�g�����֐����`���܂��B
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
		//���͂̎��̂ւ̎Q��
		vector<double> &input = *x;
		//�t�B���^�̏o�͐M��
		vector<double> y(input.size());

		vector<double> &imp = *impulse;

		//�t�B���^�����O
		for (unsigned int n = 0; n < input.size(); n++){
			for (unsigned int i = 0; i < order; i++){
				if (n >= i){
					y[n] += imp[i] * input[n - i];
				}
			}
		}
		//�t�B���^�����O���ʂ��i�[
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