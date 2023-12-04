#define Analyzer_cxx
#include "Analyzer.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>


void Analyzer::Loop()
{
//   In a ROOT session, you can do:
//      root> .L Analyzer.C
//      root> Analyzer t
//      root> t.GetEntry(12); // Fill t data members with entry number 12
//      root> t.Show();       // Show values of entry 12
//      root> t.Show(16);     // Read and show values of entry 16
//      root> t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;
   }
}

void Analyzer:: PlotHistogram(){
   TCanvas* canvas = new TCanvas();
	canvas -> SetCanvasSize (1200, 1200);
	canvas -> SetTitle ("Angular separation over J/Psi mass");
   TH2F* hist = new TH2F ("Angular separation over J/Psi mass", "Angular separation over J/Psi mass", 100, 2., 4., 100, 0., 1.5); 
   //100 bins raspon [2,4]  and 100 bins [0, 1.5] raspon
	entries = fChain -> GetEntriesFast ();
	for (Long64_t i = 0; i < entries; i++){
		fChain -> GetEntry (i);
		ee.SetPtEtaPhiM (ele_pt -> at (0), ele_eta -> at (0), ele_phi -> at (0), 0); //postavljanje cetverovektora za elektron, masa je 0
		ep.SetPtEtaPhiM (ele_pt -> at (1), ele_eta -> at (1), ele_phi -> at (1), 0); // masa 0, postavljanje 4tvero vektora za pozitron
		JPsi = ee + ep;//suma cetverovektora
		hist -> Fill (JPsi.M(), dR);	
	}
	gStyle -> SetPalette (kRainBow);
	hist -> Draw ("COLZ");//to draw with a palette
	hist -> SetStats (0); //micanje prozora sa statistikom
	hist -> GetXaxis () -> SetTitle ("J/Psi mass");
	hist -> GetXaxis () -> SetLabelSize (0.02);
	hist -> GetXaxis () -> SetTitleSize (0.03);
	hist -> GetYaxis () -> SetTitle ("angular separation dR");
    hist -> GetYaxis () -> SetLabelSize (0.02);
	hist -> GetYaxis () -> SetTitleSize (0.03);	

	canvas->SaveAs("Zadatak_2.pdf");
    canvas->SaveAs("Zadatak_2.png");


}
