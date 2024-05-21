#include <TROOT.h>
void Energy_Pion_D_C_KStest()
{
    TChain c("ntuple_data");

    c.Add("/eos/user/n/nzambra/out/GetSimpleTuple_data/C/prunedC_*.root");

    float pzc,pc,mxfc,lc,qc,wc,xbc,ybc,ttc,nuc,pt2c,zhc;
    float mp,mn,mppion;
    float sr1c,sr2c,sr3c;
    float E;
    mp=0.938;
    mn=0.938;
    mppion=0.139;
    
    c.SetBranchAddress("Pz", &pzc);
    c.SetBranchAddress("P", &pc);
    c.SetBranchAddress("pid", &lc);
    c.SetBranchAddress("Q2", &qc);
    c.SetBranchAddress("W", &wc);
    c.SetBranchAddress("Xb", &xbc);
    c.SetBranchAddress("Yb", &ybc);
    c.SetBranchAddress("Nu", &nuc);
    c.SetBranchAddress("Pt2", &pt2c);
    c.SetBranchAddress("Zh", &zhc);
    c.SetBranchAddress("TargType", &ttc);

    TH1F *hd = new TH1F("hd","Energy for +Pions, w>2  Q^{2}>1 mod X_{f}>0.1  X_{b}<1",100,0,2);
    TH1F *hc = new TH1F("hc"," ",100,0,2);
//D
    for (size_t irow=0; irow<c.GetEntries(); ++irow){
        c.GetEntry(irow);

         E=zhc*nuc;
      if(ttc==1){
 
         if (lc==211)
         {
            sr1c=sqrt(pc*pc-pt2c*pt2c);
            sr2c=sqrt((wc*wc-mn*mn+mppion*mppion)*(wc*wc-mn*mn+mppion*mppion)-4*wc*wc*mppion*mppion);
            sr3c=sqrt(qc*qc+nuc*nuc);
            mxfc=2*((nuc+mp)*(sr1c-((sr3c*zhc*nuc)/(nuc+mn))))/(sr2c);
      if (mxfc>0.1)
      {
            if (qc>1)
         {
            if (wc>2)
            {
                if (xbc<1)
                {
                    if (ybc<0.85)
                    {
                        
                        hd->Fill(E);
                    }
                }
            }
            
         }
      }
   }
   }
   }
//C
    for (size_t irow=0; irow<c.GetEntries(); ++irow){
        c.GetEntry(irow);

         E=zhc*nuc;
      if(ttc==2){
 
         if (lc==211)
         {
            sr1c=sqrt(pc*pc-pt2c*pt2c);
            sr2c=sqrt((wc*wc-mn*mn+mppion*mppion)*(wc*wc-mn*mn+mppion*mppion)-4*wc*wc*mppion*mppion);
            sr3c=sqrt(qc*qc+nuc*nuc);
            mxfc=2*((nuc+mp)*(sr1c-((sr3c*zhc*nuc)/(nuc+mn))))/(sr2c);
      if (mxfc>0.1)
      {
            if (qc>1)
         {
            if (wc>2)
            {
                if (xbc<1)
                {
                    if (ybc<0.85)
                    {
                        hc->Fill(E);
                    }
                }
            }
            
         }
      }
   }
   }
   }

    TCanvas *c1 = new TCanvas("c1","c1",800,600);
    hd->SetLineColor(kBlue);
    hc->SetLineColor(kRed); 

    hd->Scale(1./hd->Integral());
    hc->Scale(1./hc->Integral());

 Double_t ks = hd->KolmogorovTest(hc);

    hd->GetYaxis()->SetTitle("Entries");
    hd->GetXaxis()->SetTitle("Z_{h}\nu (GeV) ");
    hd->Draw();
    hc->Draw("SAME");

    TLegend* leg = new TLegend(0.6,0.7,0.9,0.9);
    leg->AddEntry(hd,"D","l");
    leg->AddEntry(hc,"C","l");
    leg->AddEntry(((TObject*)0), TString::Format("KS test value %g",ks), "");

    leg->Draw("SAME");
    gStyle->SetOptStat(0);
    c1->SaveAs("Energy_Pion_D_C_norm_CFR01_100bin_ks.pdf");
 
}




