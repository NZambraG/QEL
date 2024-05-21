#include <TROOT.h>
void P_Pion_C_norm_modxf()
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

    float pz,p,mxf,l,q,w,xb,yb,tt,nu,pt2,zh;
    float pzd,pd,mxfd,ld,qd,wd,xbd,ybd,ttd,nud,pt2d,zhd;
    float mp,mn,mppion;
    float sr1,sr2,sr3,sr1d,sr2d,sr3d;
    mp=0.938;
    mn=0.938;
    mppion=0.139;

    cd.SetBranchAddress("Pz", &pzd);
    cd.SetBranchAddress("P", &pd);
    cd.SetBranchAddress("pid", &ld);
    cd.SetBranchAddress("Q2", &qd);
    cd.SetBranchAddress("W", &wd);
    cd.SetBranchAddress("Xb", &xbd);
    cd.SetBranchAddress("Yb", &ybd);
    cd.SetBranchAddress("Nu", &nud);
    cd.SetBranchAddress("Pt2", &pt2d);
    cd.SetBranchAddress("Zh", &zhd);
    cd.SetBranchAddress("TargType", &ttd);

    cs.SetBranchAddress("mc_Pz", &pz);
    cs.SetBranchAddress("mc_P", &p);
    cs.SetBranchAddress("pid", &l);
    cs.SetBranchAddress("mc_Q2", &q);
    cs.SetBranchAddress("mc_W", &w);
    cs.SetBranchAddress("mc_Xb", &xb);
    cs.SetBranchAddress("mc_Yb", &yb);
    cs.SetBranchAddress("mc_Nu", &nu);
    cs.SetBranchAddress("mc_Pt2", &pt2);
    cs.SetBranchAddress("mc_Zh", &zh);
    cs.SetBranchAddress("mc_TargType", &tt);

    TH1F *hd = new TH1F("hd","P for +Pions, W>2, Q^{2}>1, mod X_{f}>0.1, X_{b}<1, Y_{b}<0.85",500,0,2.7);
    TH1F *hs = new TH1F("hs","P for +Pions, W>2, Q^{2}>1, mod X_{f}>0.1, X_{b}<1, Y_{b}<0.85",500,0,2.7);

    for (size_t irow=0; irow<cd.GetEntries(); ++irow){
        cd.GetEntry(irow);
        
        if(ttd==2){
        
        if (ld==211){
            sr1d=sqrt(pd*pd-pt2d*pt2d);
            sr3d=sqrt(qd*qd+nud*nud);
            sr2d=sqrt((wd*wd-mn*mn+mppion*mppion)*(wd*wd-mn*mn+mppion*mppion)-4*wd*wd*mppion*mppion);
            mxfd=2*((nud+mp)*(sr1d-((sr3d*zhd*nud)/(nud+mn))))/(sr2d);


        if (mxfd>0){
        if (qd>1){
        if (wd>2){
        if (xbd<1){
        if (ybd<0.85){
                        hd->Fill(pd);
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

     
      if(tt==2){
 
         if (l==211)
         {
            sr1=sqrt(p*p-pt2*pt2);
            sr2=sqrt((w*w-mn*mn+mppion*mppion)*(w*w-mn*mn+mppion*mppion)-4*w*w*mppion*mppion);
            sr3=sqrt(q*q+nu*nu);
            mxf=2*((nu+mp)*(sr1-((sr3*zh*nu)/(nu+mn))))/(sr2);
      if (mxf>0)
      {
            if (q>1)
         {
            if (w>2)
            {
                if (xb<1)
                {
                    if (yb<0.85)
                    {
                        hs->Fill(p);
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
   c1->SaveAs("P_Pion_C_norm_q_w_mxf_xb_yb_500bin.pdf");
 
}
