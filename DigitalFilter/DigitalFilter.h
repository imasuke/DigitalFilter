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
	};

	//ローパスフィルタ
	//窓関数法によるFIRフィルタ
	class DIGITAL_FILTER_API LowpassFilter : public Filter{
	public:
		LowpassFilter(unsigned int order, double cutoff);
	private:
		double impulse_response(int n);
	private:
		//サンプリング周波数が1になるように正規化
		double cutoff;
	};

	//ハイパスフィルタ
	class DIGITAL_FILTER_API HighpassFilter : public Filter{
	public:
		HighpassFilter(unsigned int order, double cutoff);
	private:
		double impulse_response(int n);
	private:
		//サンプリング周波数が1になるように正規化
		double cutoff;
	};

	//バンドパスフィルタ
	class DIGITAL_FILTER_API BandpassFilter : public Filter{
	public:
		BandpassFilter(unsigned int order, double low_edge, double high_edge);
	private:
		double impulse_response(int n);
	private:
		//サンプリング周波数が1になるように正規化
		double low_edge;
		double high_edge;
	};
}