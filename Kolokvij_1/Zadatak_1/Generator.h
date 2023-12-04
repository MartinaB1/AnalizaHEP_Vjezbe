#include<iostream>
#include<cstdlib>
#include<sstream>
#include<fstream>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<TROOT.h>
#include<TChain.h>
#include<TFile.h>
#include<TApplication.h>
#include<TString.h>
#include<TH1F.h>
#include<TCanvas.h>

using namespace std;

class Generator{
    public:
        Generator();
        ~Generator();
        void GeneratePDF();

    private:
        float a ,b ,f, x;
        TH1F *hist;
        TCanvas *canvas;

};
