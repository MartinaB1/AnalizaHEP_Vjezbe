#define Analyzer_cxx
#include "Analyzer.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

void Analyzer::Loop()
{

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


void Analyzer::CompareHypothesis()
{
   TCanvas *c3 = new TCanvas("compare","compare",1000,1000);
   testStatistic_H0 = new TH1F("testStatistic_H0","H_0 Test Statistic PDF",100,10,70);
   testStatistic_H1 = new TH1F("testStatistic_H1","H_1 Test Statistic PDF",100,10,70);
   testStatistic_H0->SetStats(0);
   testStatistic_H1->SetStats(0);


   TF1 *Poisson0 = new TF1("Poisson", "TMath::Poisson(x,[0])", 0, 1000);
   Poisson0->SetParameter(0,40);
   TF1 *Poisson1 = new TF1("Poisson", "TMath::Poisson(x,[0])", 0, 1000);
   Poisson1->SetParameter(0,32);


   for (int i=0; i < 1000000 ; i++)
   {
     double r0 = Poisson0 -> GetRandom();
     double r1 = Poisson1 -> GetRandom();

     testStatistic_H0->Fill(r0);
     testStatistic_H1->Fill(r1);

   }

   
   testStatistic_H0->SetLineColor(kRed-2);

   testStatistic_H0->SetTitle("Hypoyhesis testing");
   testStatistic_H0->GetXaxis()->SetTitle("broj sudara");

   testStatistic_H0->Scale(1./testStatistic_H0->Integral());
   testStatistic_H0->Draw("HIST");

   testStatistic_H1->SetLineColor(kBlue-4);

   testStatistic_H1->SetTitle("Hypoyhesis testing");
   testStatistic_H1->GetXaxis()->SetTitle("broj sudara");

   testStatistic_H1->Scale(1./testStatistic_H1->Integral());
   testStatistic_H1->Draw("HIST SAME");


    TLegend *leg = new TLegend(0.7,0.6,0.9,0.9);
   leg->AddEntry(testStatistic_H0, "H0", "f");
   leg->AddEntry(testStatistic_H1, "H1", "f");
   leg->Draw();

   c3->SaveAs("Compare.pdf");

}



void Analyzer::PValueCalculation()
{

   TCanvas *c2 = new TCanvas("c2","c2",1000,1000);

   testStatistic_PDF = new TH1F("testStatistic_PDF","Test Statistic PDF",100,10,70);
   testStatistic_PDF->SetStats(0);

   TF1 *Poissontest = new TF1("Poisson", "TMath::Poisson(x,[0])", 0, 1000);
   Poissontest->SetParameter(0,36);


   t_obs = 0.;
   double p_value = 0.;

   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;

      testStatistic_PDF->Fill(BrojSudara);

      t_obs+=BrojSudara;
   }

   t_obs/=fChain->GetEntries();

   testStatistic_PDF->Fit(Poissontest,"");

   testStatistic_PDF->SetFillColor(kRed-2);
   testStatistic_PDF->SetLineColor(kRed-2);

   testStatistic_PDF->SetTitle("Test Statistic PDF distribution");
   testStatistic_PDF->GetXaxis()->SetTitle("broj sudara");

   testStatistic_PDF->Scale(1./testStatistic_PDF->Integral());
   testStatistic_PDF->Draw("HIST");
   

   c2->SaveAs("TestStatistic_PDF.pdf");

   p_value = testStatistic_PDF->Integral(testStatistic_PDF->FindBin(t_obs),0);
   cout << "p-value for the null hypothesis is: " << p_value << endl;
   cout << "Lambda je " << Poissontest->GetParameter(0) << endl;

}


