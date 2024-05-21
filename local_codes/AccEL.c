 #include <cassert>
 #include "TCanvas.h"
 #include "TPaveText.h"
 #include "TH1.h"
 #include "TF1.h"
 #include "Math/GoFTest.h"
 #include "Math/Functor.h"
 #include "TRandom3.h"
 #include "Math/DistFunc.h"

 void AccEL(){
    TChain c("ntuple_data");
    TChain cs("ntuple_sim");  

    cc.Add("/home/zambra/root_files/local_codes/Acc_C_PPions.root");
    cd.Add("/home/zambra/root_files/clusterdata/out/GetSimpleTuple_data/C/prunedC*.root");

    float pzc,pc,mxfc,lc,qc,wc,xbc,ybc,ttc,nuc,pt2c,zhc;
    float sr1c,sr2c,sr3c;
    float mp,mn,mppion;
    float E,dE;
    float peso1,peso2,peso3;
    
    float mcpzc,mcpc,mcmxfc,mclc,mcqc,mcwc,mcxbc,mcybc,mcttc,mcnuc,mcpt2c,mczhc;
    float mcsr1c,mcsr2c,mcsr3c;
    float pzcs,pcs,mxfcs,lcs,qcs,wcs,xbcs,ybcs,ttcs,nucs,pt2cs,zhcs;
    float sr1cs,sr2cs,sr3cs;


    mp=0.938;
    mn=0.938;
    mppion=0.139;
    
    cd.SetBranchAddress("Pz", &pzc);
    cd.SetBranchAddress("P", &pc);
    cd.SetBranchAddress("pid", &lc);
    cd.SetBranchAddress("W", &wc);
    cd.SetBranchAddress("Yb", &ybc);
    cd.SetBranchAddress("Nu", &nuc);
    cd.SetBranchAddress("Zh", &zhc);
    cd.SetBranchAddress("TargType", &ttc);

    cc.SetBranchAddress("Q2", &qc);
    cc.SetBranchAddress("Xb", &xbc);
    cc.SetBranchAddress("Pt2", &pt2c);
    
    UInt_t nEvents1 = c.GetEntries();
    Double_t* sample1 = new Double_t[nEvents1];

    Int_t bin =100;
    TH1F *hd = new TH1F("hd","Acceptance corrected Energy for +Pions, Q^{2} =(1,4), nu=(2.2,4.2), X_{b}=(0.12,0.57), P_{T}^{2}=(0,1)",bin,0,2.7);
    hd->SetStats(kFALSE);
    TH1F *hmc = new TH1F("hmc"," ",bin,0,2.7);
    hmc->SetStats(kFALSE);

    for (UInt_t irow = 0; irow < nEvents2; ++irow){
        cs.GetEntry(irow);

         E=zhc*nuc;
      if(ttc==2){
 
         if (lc==211)
         {
            sr1c=sqrt(pc*pc-pt2c);
            sr2c=sqrt((wc*wc-mn*mn+mppion*mppion)*(wc*wc-mn*mn+mppion*mppion)-4*wc*wc*mppion*mppion);
            sr3c=sqrt(qc*qc+nuc*nuc);
            mxfc=2*((nuc+mp)*(sr1c-((sr3c*zhc*nuc)/(nuc+mn))))/(sr2c);
      if (ybc<0.85)
      {
            if (qc>1)
         {
             if(qc<4)
            {
                if(nuc>2.2){
                    if(nuc<4.2){
            if (wc>2)
            {
                if (xbc<0.57)
                { 
                    if (xbc<0.12)
                    {
                    if(pt2c<1.0)
                    { 
                        if(pt2c<0.0)
                        {
                        if (mxfc>0.1)
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
   }
   }
   }

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
      if (ybc<0.85)
      {
            if (qc>1)
         {
             if(qc<4)
            {
                if(nuc>2.2){
                    if(nuc<4.2){
            if (wc>2)
            {
                if (xbc<0.57)
                { 
                    if (xbc<0.12)
                    {
                    if(pt2c<1.0)
                    { 
                        if(pt2c<0.0)
                        {
                        if (mxfc>0.1)
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
   }
   }
   }


    hd->Scale(1. /hd->Integral());
dE=-0.01;
Double_t ks2;
      hmc->Scale(1. /hmc->Integral());
    // -----------------------------------------

    
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
    c1->SaveAs("AccEL.pdf");
 }