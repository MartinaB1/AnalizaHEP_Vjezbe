#include <Generator.h>

Generator::Generator(){

}
Generator::~Generator(){
    
}

void Generator::GeneratePDF(){
    srand( (unsigned)time( NULL ) );
    int i = 0;
    float a,b,x;
	TCanvas* canvas = new TCanvas();
    canvas->SetCanvasSize(900, 900);
	TH1F* hist = new TH1F ("GeneratePDF", "GeneratePDF", 48, -3., 9.); //48 binova, od -3 do 9
    while(i < pow(10,5)){
        a=(float)rand()/RAND_MAX;
        x = -3 + 12 * a;
        f = (-a*a +6*a + 27) /36.; //f(-3)=36 max fje
        b=(float)rand()/RAND_MAX;
        if(b<f){
            i++; //generirana dobra vrijednost
            hist -> Fill (x);
        }
    }
	
    hist->SetTitle("GeneratePDF");
	hist -> Draw ("HIST");
	hist->GetXaxis()->SetTitle("generirani broj");
    hist->GetYaxis()->SetTitle("generirana vrijednost");
	hist -> GetXaxis () -> SetLabelSize (0.04);
	hist -> GetYaxis () -> SetLabelSize (0.04);
	hist -> SetFillColor (kBlue);
	hist -> SetLineColor (kBlack);
	
	canvas->SaveAs("Histo_pT.pdf");
    canvas->SaveAs("Histo_pT.png");

}



