#include <TROOT.h>
void mxf()
{
   TChain cd("ntuple_data");
   TChain cs("ntuple_sim");
cd.Add("/home/zambra/root_files/clusterdata/out/GetSimpleTuple_data/C/prunedC_4201*.root");
cs.Add("/home/zambra/root_files/clusterdata/out/GetSimpleTuple_HSim/C1/prunedC_1*.root");


    float pz,p,mxf,mxf1,l,q,w,xb,yb,tt,nu,pt2,zh;
    float pzd,pd,mxfd,mxfd1,ld,qd,wd,xbd,ybd,ttd,nud,pt2d,zhd;
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
    cs.SetBranchAddress("mc_pid", &l);
    cs.SetBranchAddress("mc_Q2", &q);
    cs.SetBranchAddress("mc_W", &w);
    cs.SetBranchAddress("mc_Xb", &xb);
    cs.SetBranchAddress("mc_Yb", &yb);
    cs.SetBranchAddress("mc_Nu", &nu);
    cs.SetBranchAddress("mc_Pt2", &pt2);
    cs.SetBranchAddress("mc_Zh", &zh);
    cs.SetBranchAddress("mc_TargType", &tt);

    TH1F *hd = new TH1F("hd","  W>2, Q^{2}>1, mod X_{f}>0.1, X_{b}<1, Y_{b}<0.85",100,-1,1);
    TH1F *hs = new TH1F("hs"," ",100,-1,1);
    TH1F *hd1 = new TH1F("hd","P for +Pions, W>2, Q^{2}>1, mod X_{f}>0.1, X_{b}<1, Y_{b}<0.85",100,-1,1);
    TH1F *hs1 = new TH1F("hs","P for +Pions, W>2, Q^{2}>1, mod X_{f}>0.1, X_{b}<1, Y_{b}<0.85",100,-1,1);
    for (size_t irow=0; irow<cd.GetEntries(); ++irow){
        cd.GetEntry(irow);
        
        if(ttd==2){
        
        if (ld==211){
            sr1d=sqrt(pd*pd-pt2d);
            sr3d=sqrt(qd*qd+nud*nud);
            sr2d=sqrt((wd*wd-mn*mn+mppion*mppion)*(wd*wd-mn*mn+mppion*mppion)-4*wd*wd*mppion*mppion);
            mxfd=2*((nud+mp)*(sr1d-((sr3d*zhd*nud)/(nud+mn))))/(sr2d);
            mxfd1=2*((nud+mp)*(sr1d-(((qd*qd+nud*nud)*zhd*nud)/(nud+mn))))/(sr2d);
                        hd->Fill(mxfd);
                        hd1->Fill(mxfd1);
        }
        }
        }
        
            for (size_t irow=0; irow<cs.GetEntries(); ++irow){
        cs.GetEntry(irow);

     
      if(tt==2){
 
         if (l==211)
         {
            sr1=sqrt(p*p-pt2);
            sr2=sqrt((w*w-mn*mn+mppion*mppion)*(w*w-mn*mn+mppion*mppion)-4*w*w*mppion*mppion);
            sr3=sqrt(q*q+nu*nu);
                               mxf=2*((nu+mp)*(sr1-((sr3*zh*nu)/(nu+mn))))/(sr2);
                                mxf1=2*((nu+mp)*(sr1-(((q*q+nu*nu)*zh*nu)/(nu+mn))))/(sr2);
                        hs->Fill(mxf);
                        hs1->Fill(mxf1);
                    }
                }
            }
            

    TCanvas *c1 = new TCanvas("c1","c1",800,600);

    hs->SetLineColor(kBlue);
    hd->SetLineColor(kRed);
    hs1->SetLineColor(kGreen);
    hd1->SetLineColor(kBlack);
    hs->Scale(1./hs->Integral());
    hd->Scale(1./hd->Integral());
    hs1->Scale(1./hs1->Integral());
    hd1->Scale(1./hd1->Integral());
    hd->GetYaxis()->SetTitle("Entries");
    hd->GetXaxis()->SetTitle("X_F ");

    hd->Draw();
    hs->Draw("SAME");
    //hs1->Draw("SAME");
    //hd1->Draw("SAME");
    TLegend* leg = new TLegend(0.6,0.7,0.9,0.9);
    leg->AddEntry(hs,"Sim mxf ","l");
    leg->AddEntry(hd,"Data mxf ","l");
    //leg->AddEntry(hs1,"Sim mxf H","l");
    //leg->AddEntry(hd1,"Data mxf H","l");
    leg->Draw("SAME");
    gStyle->SetOptStat(0);
    c1->SaveAs("mxf_H_vs_M.pdf");
 
}
