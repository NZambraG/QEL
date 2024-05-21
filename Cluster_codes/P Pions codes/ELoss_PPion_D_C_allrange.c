#include <TROOT.h>

void ELoss_PPion_D_C_allrange()
{
    TChain c("ntuple_data");

    c.Add("/eos/user/n/nzambra/out/GetSimpleTuple_data/C/prunedC_*.root");

    float pzc,pc,mxfc,lc,qc,wc,xbc,ybc,ttc,nuc,pt2c,zhc;
    float mp,mn,mppion;
    float sr1c,sr2c,sr3c;
    float E;
    float dE;
    dE=0.072;
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

    TH1F *hd = new TH1F("hd","Energy loss for +Pions, w>2  Q^{2}>1 mod X_{f}>0.1 X_{b}<1 bin 100 ",100,1,2.7);
    TH1F *hc = new TH1F("hc"," ",100,1,2.7);
    TH1F *hmc = new TH1F("hmc"," ",100,1,2.7);
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
//modified D
    for (size_t irow=0; irow<c.GetEntries(); ++irow){
        c.GetEntry(irow);

         E=zhc*nuc+dE;
      if(ttc==1){
 
         if (lc==211)
         {
            
            sr1c=sqrt((pc+dE)*(pc+dE)-(1+(dE/pc))*(1+(dE/pc))*pt2c*pt2c);
            sr2c=sqrt((wc*wc-mn*mn+mppion*mppion)*(wc*wc-mn*mn+mppion*mppion)-4*wc*wc*mppion*mppion);
            sr3c=sqrt(qc*qc+nuc*nuc);
            mxfc=2*((nuc+mp)*(sr1c-((sr3c*(zhc*nuc+dE))/(nuc+mn))))/(sr2c);
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
                        hmc->Fill(E);
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
    hmc->SetLineColor(kGreen); 
    hd->Scale(1./hd->Integral());
    hc->Scale(1./hc->Integral());
    hmc->Scale(1./hmc->Integral());
 Double_t ks = hc->KolmogorovTest(hd);
  Double_t ks2 = hc->KolmogorovTest(hmc);


    hd->GetYaxis()->SetTitle("Entries");
    hd->GetXaxis()->SetTitle("Z_{h}*nu (GeV) ");

    hd->Draw();
    hc->Draw("SAME");
    hmc->Draw("SAME");
    TLegend* leg = new TLegend(0.6,0.7,0.9,0.9);
    leg->AddEntry(hd,"D","l");
    leg->AddEntry(hc,"C","l");
    leg->AddEntry(hmc,"D + dE","l");
    leg->AddEntry(((TObject*)0), TString::Format("KS original %g",ks), "");
    leg->AddEntry(((TObject*)0), TString::Format("dE=  %g",dE), "");
    leg->AddEntry(((TObject*)0), TString::Format("KS mod %g",ks2), "");

    leg->Draw("SAME");
    gStyle->SetOptStat(0);
    c1->SaveAs("ELoss_Pion_D_C_modD_+72MeV_bin100_range1_027.pdf");
}
