#include "Analyzer.h"

int main (){
	Analyzer *analyze;
	analyze = new Analyzer ();
	analyze -> PlotHistogram ();
	analyze -> ~Analyzer ();
}