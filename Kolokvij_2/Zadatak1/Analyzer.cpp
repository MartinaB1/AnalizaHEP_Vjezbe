#include"Analyzer.h"


Analyzer::Analyzer(){

}

Analyzer::~Analyzer(){

}


double Analyzer::Poisonova(int r, double lambda){

	return TMath::Poisson(r, lambda);
	
}


double Analyzer::lambda_max(int N, double e){

	lambda = 0. ;
    prob = 0. ;
	while (prob < e){
		for(int r=N; r<pow(10,3); r++)
			prob += Poisonova(r, lambda) ;
		lambda+=0.05 ;
	}
return lambda - 0.05 ;

}