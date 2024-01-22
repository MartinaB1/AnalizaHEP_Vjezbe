#include<TROOT.h>
#include<TMath.h>
#include<TStyle.h>
#include<iostream>

using namespace std;


class Analyzer{

 public:
	Analyzer();
	~Analyzer();
	double Poisonova(int, double);
	double lambda_max(int, double);

 private:
	double prob, lambda, e;
	int r,N; 

};