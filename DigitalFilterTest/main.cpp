//main.cpp
#define _USE_MATH_DEFINES
#define SAMPLEING_RATE 1000

#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>

#include "../DigitalFilter/DigitalFilter.h"

using namespace DigitalFilter;
using std::vector;

void output_vector(vector<double> &wave, char *name);

int main(void){
	LowpassFilter lpf(100, 0.2);
	HighpassFilter hpf(100, 0.4);
	BandpassFilter bpf(100, 0.2, 0.4);
	vector<double> wave(1000); //sampling rate = 1000[Hz] �� 1[s]
	double value1, value2, value3;

	for(unsigned int i=0;i<wave.size();i++){
		value1 = sin(2*M_PI*50*((double)i/SAMPLEING_RATE)); //50[Hz]
		value2 = sin(2*M_PI*450*((double)i/SAMPLEING_RATE)); //450[Hz]
		value3 = sin(2*M_PI*300*((double)i/SAMPLEING_RATE)); // 300[Hz]
		wave[i] = value1 + value2 + value3;
	}
	output_vector(wave, "original.txt");
	bpf.filtering(&wave);
	output_vector(wave, "filtered.txt");

	return 0;
}

void output_vector(vector<double> &wave, char *name){
	std::ofstream ofs(name);
	for(unsigned int i=0;i<wave.size();i++){
		ofs << wave[i] << std::endl;
	}
}