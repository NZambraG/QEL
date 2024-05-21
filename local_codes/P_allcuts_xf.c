#include <TROOT.h>
void P_allcuts_xf()
{
   TChain cd("ntuple_data");
   TChain cs("ntuple_sim");
cd.Add("/home/zambra/root_files/clusterdata/out/GetSimpleTuple_data/C/prunedC_420*.root");
cs.Add("/home/zambra/root_files/clusterdata/out/GetSimpleTuple_HSim/C1/prunedC_4*.root");


   float x,y,k,l,q,w,xb,tt;
   float xd,yd,kd,ld,qd,wd,xbd,ttd;

   cd.SetBranchAddress("Pz", &xd);
   cd.SetBranchAddress("P", &yd);
   cd.SetBranchAddress("pid", &ld);
   cd.SetBranchAddress("Q2", &qd);
   cd.SetBranchAddress("W", &wd);
   cd.SetBranchAddress("Xb", &xbd);
    cd.SetBranchAddress("TargType",&ttd);
   cs.SetBranchAddress("mc_Pz", &x);
   cs.SetBranchAddress("mc_P", &y);
   cs.SetBranchAddress("pid", &l);
   cs.SetBranchAddress("mc_Q2", &q);
   cs.SetBranchAddress("mc_W", &w);
   cs.SetBranchAddress("mc_Xb", &xb);
   cs.SetBranchAddress("mc_TargType",&tt);
    TH1F *hd = new TH1F("hd","P for +Pions, w>2  Q^{2}>1 X_{f}>0.1 X_{b}<1",100,0,1.5);
    TH1F *hs = new TH1F("hs","P for +Pions, w>2  Q^{2}>1 X_{f}>0.1",100,0,1.5);

   for (size_t irow=0; irow<cd.GetEntries(); ++irow){
      cd.GetEntry(irow);

         if (ld==211)
         {
            if(ttd==2){
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

         if (l==211)
         {
            if(tt==2){
            if (q>1)
         {
            if (w>2)
            {
                if (xb<1)
                {
                    hs->Fill(y);
                }

            }
            
         }}
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
   c1->SaveAs("P_Pion_C_norm_cuts_q_w_xb_tt.pdf");
 
}
