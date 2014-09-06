//HighpassFilter.cpp

#include "stdafx.h"
#define _USE_MATH_DEFINES
#define DIGITAL_FILTER_EXPORTS

#include "DigitalFilter.h"
#include <cmath>

using std::vector;

namespace DigitalFilter{
	HighpassFilter::HighpassFilter(unsigned int order, double cutoff){
		//�����o�ϐ����Z�b�g
		this->order = order;
		this->cutoff = cutoff;
		this->impulse = new vector<double>();

		vector<double> &imp = *impulse;

		//�������m��
		imp.resize(order);
		//�C���p���X���������߂�
		for (unsigned int i = 0; i < order; i++){
			imp[i] = impulse_response(i);
		}
		//�C���p���X�����ɑ��֐���������
		mult_hann_window();
	}

	double HighpassFilter::impulse_response(int n){
		return sinc(M_PI * (n - order / 2)) - 2.0 * cutoff * sinc(2.0 * M_PI * cutoff * (n - order / 2));
	}
}