#include <TROOT.h>
void normZh_allp()
{

   TChain cs("ntuple_sim");
   TChain cd("ntuple_data");

    cd.Add("/eos/user/n/nzambra/out/GetSimpleTuple_data/C/prunedC_42*.root");
    cs.Add("/eos/user/n/nzambra/out/GetSimpleTuple_HSim/C1/prunedC_*.root");
    cs.Add("/eos/user/n/nzambra/out/GetSimpleTuple_HSim/C2/prunedC_*.root");
    cs.Add("/eos/user/n/nzambra/out/GetSimpleTuple_HSim/C3/prunedC_*.root");
    cs.Add("/eos/user/n/nzambra/out/GetSimpleTuple_HSim/C4_yshiftm03/prunedC_*.root");
    cs.Add("/eos/user/n/nzambra/out/GetSimpleTuple_HSim/C5_yshiftm03/prunedC_*.root");
    cs.Add("/eos/user/n/nzambra/out/GetSimpleTuple_HSim/C6_yshiftm03/prunedC_*.root");
    cs.Add("/eos/user/n/nzambra/out/GetSimpleTuple_HSim/C7_yshiftm03/prunedC_*.root");
    cs.Add("/eos/user/n/nzambra/out/GetSimpleTuple_HSim/C8_yshiftm03/prunedC_*.root");
    cs.Add("/eos/user/n/nzambra/out/GetSimpleTuple_HSim/C9_yshiftm03/prunedC_*.root");

   float x,y;

   cs.SetBranchAddress("mc_Zh", &x);
   cd.SetBranchAddress("Zh", &y);

    TH1F *hs = new TH1F("hs","Zh",100,-2,10);
    TH1F *hd = new TH1F("hd","",100,-2,10);

   for (size_t irow=0; irow<cs.GetEntries(); ++irow){
      cs.GetEntry(irow);
      hs->Fill(x);
   }
   for (size_t irow=0; irow<cd.GetEntries(); ++irow){
      cd.GetEntry(irow);
      hd->Fill(y);
   }

   TCanvas *c1 = new TCanvas("c1","c1",800,600);

   hs->SetLineColor(kBlue);
   hd->SetLineColor(kRed);


   hs->GetYaxis()->SetTitle("Entries");
   hs->GetXaxis()->SetTitle("Z_{h} (GeV)");

   TH1*h1 = (TH1*)(hs->Clone("h1"));
   TH1*h2 = (TH1*)(hd->Clone("h2"));
   h1->Scale(1./h1->Integral());
   h2->Scale(1./h2->Integral());

   h1->Draw();
   h2->Draw("SAME");
   h1->GetYaxis()->SetRangeUser(0,1);

   TLegend* leg = new TLegend(0.6,0.7,0.9,0.9);
   leg->AddEntry(hs,"Sim","l");
   leg->AddEntry(hd,"Data","l");
   leg->Draw("SAME");
   gStyle->SetOptStat(0);
   c1->SaveAs("norm_Zh_allparticles.pdf");
 
}