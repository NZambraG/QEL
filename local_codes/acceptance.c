#include <TROOT.h>
void acceptance()
{
    TChain cd("ntuple_data");
    TChain cs("ntuple_sim");   
    cd.Add("/home/zambra/root_files/clusterdata/out/GetSimpleTuple_data/C/prunedC*.root");
    cs.Add("/home/zambra/root_files/clusterdata/out/GetSimpleTuple_HSim/C1/prunedC*.root");

    float zhd,zhs,mczhs,ld,l,ttd,tt,w;

   float w2,w1,w3;
   TFile f("nombre.root", "RECREATE");
   TTree t1("PhiPQ","PhiPQ");
   t1.Branch("w1",&w1,"w1/F");
   t1.Branch("w2",&w2,"w2/F");
   t1.Branch("w3",&w3,"w3/F");

    cd.SetBranchAddress("PhiPQ", &zhd);
    cs.SetBranchAddress("PhiPQ", &zhs);
    cs.SetBranchAddress("mc_PhiPQ", &mczhs);

    cd.SetBranchAddress("pid", &ld);
    cd.SetBranchAddress("TargType",&ttd);
    cs.SetBranchAddress("pid", &l);
    cs.SetBranchAddress("mc_TargType",&tt);
    TH1F *hd = new TH1F("zh","Acc PhiPQ for +Pions",100,-200,200);
    TH1F *hs = new TH1F(" "," ",100,-200,200);
    TH1F *hs2 = new TH1F(" "," ",100,-200,200 );
    TH1F *AccCorrected = new TH1F(" "," ",100,0,200 );
    TH1F *AccCorrectedComparison = new TH1F(" "," ",100,-200,0 );
   for (size_t irow=0; irow<cs.GetEntries(); ++irow){
      cs.GetEntry(irow);

         if (l==211)
         {
            if(tt==2){
                w=zhs/mczhs;
                    hs->Fill(zhs);
                    hs2->Fill(mczhs);
            }
      }
   }
   for (size_t irow=0; irow<cd.GetEntries(); ++irow){
      cd.GetEntry(irow);

         if (ld==211)
         {
            if(ttd==2){

                    hd->Fill(zhd);
                    AccCorrected->Fill(zhd,w);

                    w1=zhd/w;
                    w2 = AccCorrected->GetBinContent(irow);                
                    AccCorrectedComparison->Fill(w1);
                    t1.Fill();
                }
         }
   }

    for (int i = 0; i < AccCorrected->GetNbinsX(); ++i) {

        w3 = AccCorrected->GetBinContent(i);
        t1.Fill();
    }

t1.Write();

   TCanvas *c1 = new TCanvas("c1","c1",800,600);

    AccCorrectedComparison->SetLineColor(kGreen);
    AccCorrected->SetLineColor(kRed);
   hd->SetLineColor(kBlack);
   hd->Scale(1./hd->Integral());
    AccCorrected->Scale(1./AccCorrected->Integral());
    AccCorrectedComparison->Scale(1./AccCorrectedComparison->Integral());

    hd->GetYaxis()->SetTitle("Entries");
    hd->GetXaxis()->SetTitle("P (GeV) ");
   hd->Draw();
    AccCorrected->Draw("SAME");
    AccCorrectedComparison->Draw("SAME");
    TLegend* leg = new TLegend(0.6,0.7,0.9,0.9);
    leg->AddEntry(hd,"hd","l");
    leg->AddEntry(AccCorrected,"Acc","l");
    leg->AddEntry(AccCorrectedComparison,"AccC","l");
    leg->Draw("SAME");
    gStyle->SetOptStat(0);
    gPad->SetLogy();
    c1->SaveAs("Acc_Comp.pdf");

 
}
