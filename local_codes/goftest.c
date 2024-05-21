 #include <cassert>
 #include "TCanvas.h"
 #include "TPaveText.h"
 #include "TH1.h"
 #include "TF1.h"
 #include "Math/GoFTest.h"
 #include "Math/Functor.h"
 #include "TRandom3.h"
 #include "Math/DistFunc.h"

 void goftest(){
     TChain c("ntuple_data");

    c.Add("/home/zambra/root_files/clusterdata/out/GetSimpleTuple_data/C/prunedC*.root");

    float pzc,pc,mxfc,lc,qc,wc,xbc,ybc,ttc,nuc,pt2c,zhc;
    float mp,mn,mppion;
    float sr1c,sr2c,sr3c;
    float E;
    float dE;

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

    UInt_t nEvents1 = c.GetEntries();
    Double_t* sample1 = new Double_t[nEvents1];
    UInt_t nEvents2 = c.GetEntries();
    Double_t* sample2 = new Double_t[nEvents2];

    Int_t bin =100;
    TH1F *hd = new TH1F("hd","Energy for +Pions, w>2  Q^{2}>1 mod X_{f}>0.1  X_{b}<1",bin,0,2.7);
    hd->SetStats(kFALSE);
    TH1F *hmc = new TH1F("hmc"," ",bin,0,2.7);
    hmc->SetStats(kFALSE);
 //C
    for (UInt_t irow = 0; irow < nEvents1; ++irow){
        c.GetEntry(irow);

         E=zhc*nuc;
      if(ttc==2){
 
         if (lc==211)
         {
            sr1c=sqrt(pc*pc-pt2c);
            sr2c=sqrt((wc*wc-mn*mn+mppion*mppion)*(wc*wc-mn*mn+mppion*mppion)-4*wc*wc*mppion*mppion);
            sr3c=sqrt(qc*qc+nuc*nuc);
            mxfc=2*((nuc+mp)*(sr1c-((sr3c*zhc*nuc)/(nuc+mn))))/(sr2c);
      if (mxfc>0.1)
      {
            if (qc>1)
         {
             if(qc<4)
            {
                if(nuc>2.2){
                    if(nuc<4.2){
            if (wc>2)
            {
                if (xbc<1)
                {
                    if (ybc<0.85)
                    {
                        sample1[irow] = E;
                        hd->Fill(E);
                    }
                }
            }
            }
            }
         }
         }
      }
   }
   }
   }


    hd->Scale(1. /hd->Integral());
dE=-0.01;
Double_t ks2;
    for (UInt_t irow = 0; irow < nEvents2; ++irow){
        c.GetEntry(irow);

         E=zhc*nuc+dE;
      if(ttc==1){
         if (lc==211)
         {
            
            sr1c=sqrt((pc+dE)*(pc+dE)-(1+(dE/pc))*(1+(dE/pc))*pt2c);
            sr2c=sqrt((wc*wc-mn*mn+mppion*mppion)*(wc*wc-mn*mn+mppion*mppion)-4*wc*wc*mppion*mppion);
            sr3c=sqrt(qc*qc+nuc*nuc);
            mxfc=2*((nuc+mp)*(sr1c-((sr3c*(zhc*nuc+dE))/(nuc+mn))))/(sr2c);
      if (mxfc>0.1)
      {
            if (qc>1)
         {
             if(qc<4)
            {
                if(nuc>2.2){
                    if(nuc<4.2){
            if (wc>2)
            {
                if (xbc<1)
                {
                    if (ybc<0.85)
                    {
                     sample2[irow]=E;
                        hmc->Fill(E);

                    }
                }
            }
                    }
                    }
                }
         }
      }
   }
   }
   }
    hmc->Scale(1. /hmc->Integral());
    // -----------------------------------------
    // Create GoFTest object
    
    ROOT::Math::GoFTest* goftest_2 = new ROOT::Math::GoFTest(nEvents1, sample1, nEvents2, sample2);

    // b) Returning the p-value for the Kolmogorov-Smirnov test statistic 
    Double_t pvalueKS_1 = goftest_2-> KolmogorovSmirnov2SamplesTest();
    Double_t pvalueKS_2 = (*goftest_2)(ROOT::Math::GoFTest::kKS2s);
    assert(pvalueKS_1 == pvalueKS_2);
    ks2 = hd->KolmogorovTest(hmc);

    cout <<"energia =" << dE << "  ks=" << ks2 <<"\n";
    cout<< "2s ks="<< pvalueKS_1<<"\n";

    TCanvas *c1 = new TCanvas("c1","c1",800,600);
    hd->SetLineColor(kBlue);
    hmc->SetLineColor(kGreen); 
    hd->GetYaxis()->SetTitle("Entries");
    hd->GetXaxis()->SetTitle("Z_{h}*nu (GeV) ");
    hd->Draw();
    hmc->Draw("SAME");
    TLegend* leg = new TLegend(0.6,0.7,0.9,0.9);
    leg->AddEntry(hd,"C","l");
    leg->AddEntry(hmc,"mod D","l");
    leg->AddEntry(((TObject*)0), TString::Format("dE=  %g",dE), "");
    leg->AddEntry(((TObject*)0), TString::Format("2S P value %g",pvalueKS_1), "");
    leg->AddEntry(((TObject*)0), TString::Format("P value %g",ks2), "");
    leg->Draw("SAME");
    gStyle->SetOptStat(0);
    c1->SaveAs("2samplekstest.pdf");
 }