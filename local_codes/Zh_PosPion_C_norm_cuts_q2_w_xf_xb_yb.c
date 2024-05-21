#include <TROOT.h>
void Zh_PosPion_C_norm_cuts_q2_w_xf_xb_yb()
{
   TChain cd("ntuple_data");
   TChain cs("ntuple_sim");
cd.Add("/home/zambra/root_files/clusterdata/out/GetSimpleTuple_data/C/prunedC_*.root");
cs.Add("/home/zambra/root_files/clusterdata/out/GetSimpleTuple_HSim/C1/prunedC_*.root");
cs.Add("/home/zambra/root_files/clusterdata/out/GetSimpleTuple_HSim/C2/prunedC_*.root");
cs.Add("/home/zambra/root_files/clusterdata/out/GetSimpleTuple_HSim/C3/prunedC_*.root");
cs.Add("/home/zambra/root_files/clusterdata/out/GetSimpleTuple_HSim/C4_yshiftm03/prunedC_*.root");
cs.Add("/home/zambra/root_files/clusterdata/out/GetSimpleTuple_HSim/C5_yshiftm03/prunedC_*.root");
cs.Add("/home/zambra/root_files/clusterdata/out/GetSimpleTuple_HSim/C6_yshiftm03/prunedC_*.root");
cs.Add("/home/zambra/root_files/clusterdata/out/GetSimpleTuple_HSim/C7_yshiftm03/prunedC_*.root");
cs.Add("/home/zambra/root_files/clusterdata/out/GetSimpleTuple_HSim/C8_yshiftm03/prunedC_*.root");
cs.Add("/home/zambra/root_files/clusterdata/out/GetSimpleTuple_HSim/C9_yshiftm03/prunedC_*.root");

   float x,y,k,l,q,w,xb,yb,zh;
   float xd,yd,kd,ld,qd,wd,xbd,ybd,zhd;

   cd.SetBranchAddress("Pz", &xd);
   cd.SetBranchAddress("P", &yd);
   cd.SetBranchAddress("pid", &ld);
   cd.SetBranchAddress("Q2", &qd);
   cd.SetBranchAddress("W", &wd);
   cd.SetBranchAddress("Xb", &xbd);
   cd.SetBranchAddress("Yb", &ybd);
   cd.SetBranchAddress("Zh", &zhd);

   cs.SetBranchAddress("mc_Pz", &x);
   cs.SetBranchAddress("mc_P", &y);
   cs.SetBranchAddress("pid", &l);
   cs.SetBranchAddress("mc_Q2", &q);
   cs.SetBranchAddress("mc_W", &w);
   cs.SetBranchAddress("mc_Xb", &xb);
   cs.SetBranchAddress("mc_Yb", &yb);
   cs.SetBranchAddress("mc_Zh", &zh);

    TH1F *hd = new TH1F("hd","Zh for +Pions, W>2  Q^{2}>1 X_{f}>0.1 X_{b}<1, Y_{b}<0.85",1000,0,2);
    TH1F *hs = new TH1F("hs","Zh for +Pions, W>2  Q^{2}>1 X_{f}>0.1, Y_{b}<0.85",1000,0,2);

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
                    if (ybd<0.85)
                    {
                        hd->Fill(zhd);
                    }
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
                    if (yb<0.85)
                    {
                        hs->Fill(zh);
                    }
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
   c1->SaveAs("Zh_PosPion_C_norm_cuts_q2_w_xf_xb_yb.pdf");
 
}
