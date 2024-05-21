#include <TROOT.h>
void zh()
{
    TChain cd("ntuple_data");
    TChain cs("ntuple_sim");   
    cd.Add("/home/zambra/root_files/clusterdata/out/GetSimpleTuple_data/C/prunedC*.root");
    cs.Add("/home/zambra/root_files/clusterdata/out/GetSimpleTuple_HSim/C1/prunedC*.root");


    float zhd,zhs,mczhs,ld,l,ttd,tt;


    cd.SetBranchAddress("PhiPQ", &zhd);
    cs.SetBranchAddress("PhiPQ", &zhs);
    cs.SetBranchAddress("mc_PhiPQ", &mczhs);

    cd.SetBranchAddress("pid", &ld);
    cd.SetBranchAddress("TargType",&ttd);
    cs.SetBranchAddress("pid", &l);
    cs.SetBranchAddress("mc_TargType",&tt);
    TH1F *hd = new TH1F("zh","PhiPQ for +Pions",100,-200,200);
    TH1F *hs = new TH1F(" "," ",100,-200,200);
    TH1F *hs2 = new TH1F(" "," ",100,-200,200 );

   for (size_t irow=0; irow<cd.GetEntries(); ++irow){
      cd.GetEntry(irow);


            if(ttd==2){
            
                    hd->Fill(zhd);
                }
      
   }
   for (size_t irow=0; irow<cs.GetEntries(); ++irow){
      cs.GetEntry(irow);


            if(tt==2){
                
                    hs->Fill(zhs);
                    hs2->Fill(mczhs);
                
      }
   }
   TCanvas *c1 = new TCanvas("c1","c1",800,600);

    hs->SetLineColor(kGreen);
    hs2->SetLineColor(kRed);
    hd->SetLineColor(kBlue);
    hs->Scale(1./hs->Integral());
    hs2->Scale(1./hs2->Integral());
    hd->Scale(1./hd->Integral());


    hd->GetYaxis()->SetTitle("Entries");
    hd->GetXaxis()->SetTitle("P (GeV) ");

   hd->Draw();
   hs->Draw("SAME");
   hs2->Draw("SAME");
   TLegend* leg = new TLegend(0.6,0.7,0.9,0.9);
   leg->AddEntry(hs,"Sim","l");
      leg->AddEntry(hs2,"Sim mc","l");
   leg->AddEntry(hd,"Data","l");
   leg->Draw("SAME");
   gStyle->SetOptStat(0);
       gPad->SetLogy();
   c1->SaveAs("Phi_for_PPions_no_cuts.pdf");
 
}
