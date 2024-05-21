#include <TROOT.h>
void P_Pion_C_norm_xf()
{
   TChain cd("ntuple_data");
   TChain cs("ntuple_sim");
cd.Add("/eos/user/n/nzambra/out/GetSimpleTuple_data/C/prunedC_*.root");
cs.Add("/eos/user/n/nzambra/out/GetSimpleTuple_HSim/C1/prunedC_*.root");
cs.Add("/eos/user/n/nzambra/out/GetSimpleTuple_HSim/C2/prunedC_*.root");
cs.Add("/eos/user/n/nzambra/out/GetSimpleTuple_HSim/C3/prunedC_*.root");
cs.Add("/eos/user/n/nzambra/out/GetSimpleTuple_HSim/C4_yshiftm03/prunedC_*.root");
cs.Add("/eos/user/n/nzambra/out/GetSimpleTuple_HSim/C5_yshiftm03/prunedC_*.root");
cs.Add("/eos/user/n/nzambra/out/GetSimpleTuple_HSim/C6_yshiftm03/prunedC_*.root");
cs.Add("/eos/user/n/nzambra/out/GetSimpleTuple_HSim/C7_yshiftm03/prunedC_*.root");
cs.Add("/eos/user/n/nzambra/out/GetSimpleTuple_HSim/C8_yshiftm03/prunedC_*.root");
cs.Add("/eos/user/n/nzambra/out/GetSimpleTuple_HSim/C9_yshiftm03/prunedC_*.root");

    float x,y,k,l,q,w,xb,yb,tt;
    float xd,yd,kd,ld,qd,wd,xbd,ybd,ttd;

    cd.SetBranchAddress("Pz", &xd);
    cd.SetBranchAddress("P", &yd);
    cd.SetBranchAddress("pid", &ld);
    cd.SetBranchAddress("Q2", &qd);
    cd.SetBranchAddress("W", &wd);
    cd.SetBranchAddress("Xb", &xbd);
    cd.SetBranchAddress("Yb", &ybd);
    cd.SetBranchAddress("TargType", &ttd);


    cs.SetBranchAddress("mc_Pz", &x);
    cs.SetBranchAddress("mc_P", &y);
    cs.SetBranchAddress("pid", &l);
    cs.SetBranchAddress("mc_Q2", &q);
    cs.SetBranchAddress("mc_W", &w);
    cs.SetBranchAddress("mc_Xb", &xb);
    cs.SetBranchAddress("mc_Yb", &yb);
    cs.SetBranchAddress("mc_TargType", &tt);

    TH1F *hd = new TH1F("hd","P for +Pions, W>2  Q^{2}>1 X_{f}>0.1 X_{b}<1, Y_{b}<0.85",500,0,2.7);
    TH1F *hs = new TH1F("hs","P for +Pions, W>2  Q^{2}>1 X_{f}>0.1, Y_{b}<0.85",500,0,2.7);

    for (size_t irow=0; irow<cd.GetEntries(); ++irow){
        cd.GetEntry(irow);
        kd=xd/yd;
        if(ttd==2){
        if (kd>0.1){
        if (ld==211){
        if (qd>1){
        if (wd>2){
        if (xbd<1){
        if (ybd<0.85){
                        hd->Fill(yd);
        }
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
      if(tt==2){
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
                        hs->Fill(y);
                    }
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
   c1->SaveAs("P_Pion_C_norm_q_w_xf_xb_yb_tt.pdf");
 
}
