//DigitaiFilter.h
#pragma once

#ifdef DIGITAL_FILTER_EXPORTS
#define DIGITAL_FILTER_API __declspec(dllexport) 
#else
#define DIGITAL_FILTER_API __declspec(dllimport) 
#endif

#include <vector>

namespace DigitalFilter
{
	//�f�B�W�^���t�B���^���ۃN���X
	class DIGITAL_FILTER_API Filter{
	public:
		virtual ~Filter();
		void filtering(std::vector<double> *x);
	protected:
		virtual double impulse_response(int n) = 0;
		void mult_hann_window();
		double sinc(double x);

	protected:
		std::vector<double> *impulse;
		unsigned int order;
		//�J�b�g�I�t���g��(�T���v�����O���g����1�ƂȂ�悤���K��)
		double cutoff;
	};

	//���[�p�X�t�B���^
	//���֐��@�ɂ��FIR�t�B���^
	class DIGITAL_FILTER_API LowpassFilter : public Filter
	{
	public:
		LowpassFilter(unsigned int order, double cutoff);
	private:
		double impulse_response(int n);
	};
}