#include <TROOT.h>
void plotP_allcuts()
{
   TChain cd("ntuple_data");
   TChain cs("ntuple_sim");
cd.Add("/home/zambra/root_files/clusterdata/out/GetSimpleTuple_data/C/prunedC_42*.root");
cs.Add("/home/zambra/root_files/clusterdata/out/GetSimpleTuple_HSim/C1/prunedC_*.root");
cs.Add("/home/zambra/root_files/clusterdata/out/GetSimpleTuple_HSim/C2/prunedC_*.root");
cs.Add("/home/zambra/root_files/clusterdata/out/GetSimpleTuple_HSim/C3/prunedC_*.root");
cs.Add("/home/zambra/root_files/clusterdata/out/GetSimpleTuple_HSim/C4_yshiftm03/prunedC_*.root");
cs.Add("/home/zambra/root_files/clusterdata/out/GetSimpleTuple_HSim/C5_yshiftm03/prunedC_*.root");
cs.Add("/home/zambra/root_files/clusterdata/out/GetSimpleTuple_HSim/C6_yshiftm03/prunedC_*.root");
cs.Add("/home/zambra/root_files/clusterdata/out/GetSimpleTuple_HSim/C7_yshiftm03/prunedC_*.root");
cs.Add("/home/zambra/root_files/clusterdata/out/GetSimpleTuple_HSim/C8_yshiftm03/prunedC_*.root");
cs.Add("/home/zambra/root_files/clusterdata/out/GetSimpleTuple_HSim/C9_yshiftm03/prunedC_*.root");


   float x,y,k,l,q,w,xb;
   float xd,yd,kd,ld,qd,wd,xbd;

   cd.SetBranchAddress("Pz", &xd);
   cd.SetBranchAddress("P", &yd);
   cd.SetBranchAddress("pid", &ld);
   cd.SetBranchAddress("Q2", &qd);
   cd.SetBranchAddress("W", &wd);
   cd.SetBranchAddress("Xb", &xbd);

   cs.SetBranchAddress("mc_Pz", &x);
   cs.SetBranchAddress("mc_P", &y);
   cs.SetBranchAddress("pid", &l);
   cs.SetBranchAddress("mc_Q2", &q);
   cs.SetBranchAddress("mc_W", &w);
   cs.SetBranchAddress("mc_Xb", &xb);
   
    TH1F *hd = new TH1F("hd","P for +Pions, w>2  Q^{2}>1 X_{f}>0.1 X_{b}<1",1000,0,1.5);
    TH1F *hs = new TH1F("hs","P for +Pions, w>2  Q^{2}>1 X_{f}>0.1",1000,0,1.5);

   for (size_t irow=0; irow<cd.GetEntries(); ++irow){
      cd.GetEntry(irow);

      kd=x/y;
      if (kd>0.1)
      {
         if (ld==211)
         {
            if (qd>1)
         {
            if (wd>2)
            {
                if (xbd<1)
                {
                    hd->Fill(yd);
                }

            }
            
         }
      }
   }
   }
   for (size_t irow=0; irow<cs.GetEntries(); ++irow){
      cs.GetEntry(irow);

      k=x/y;
      if (k>0.1)
      {
         if (l==211)
         {
            if (q>1)
         {
            if (w>2)
            {
                if (xb<1)
                {
                    hs->Fill(y);
                }

            }
            
         }
      }
   }
   }
   TCanvas *c1 = new TCanvas("c1","c1",800,600);

   hs->SetLineColor(kBlue);
   hd->SetLineColor(kRed);
   hs->Scale(1./hs->Integral());
   hd->Scale(1./hd->Integral());
   hd->GetYaxis()->SetTitle("Entries");
   hd->GetXaxis()->SetTitle("P (GeV) ");

   hd->Draw();
   hs->Draw("SAME");
   TLegend* leg = new TLegend(0.6,0.7,0.9,0.9);
   leg->AddEntry(hs,"Sim","l");
   leg->AddEntry(hd,"Data","l");
   leg->Draw("SAME");
   gStyle->SetOptStat(0);
   c1->SaveAs("P_Pion_C_norm_cuts_q_w_xf_xb.pdf");
 
}
