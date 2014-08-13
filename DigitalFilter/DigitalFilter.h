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
	//ディジタルフィルタ抽象クラス
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
		//カットオフ周波数(サンプリング周波数が1となるよう正規化)
		double cutoff;
	};

	//ローパスフィルタ
	//窓関数法によるFIRフィルタ
	class DIGITAL_FILTER_API LowpassFilter : public Filter
	{
	public:
		LowpassFilter(unsigned int order, double cutoff);
	private:
		double impulse_response(int n);
	};
}