#include <TROOT.h>
#include <cassert>
#include "TCanvas.h"
#include "TPaveText.h"
#include "TH1.h"
#include "TF1.h"
#include "Math/GoFTest.h"
#include "Math/Functor.h"
#include "TRandom3.h"
#include "Math/DistFunc.h"
void ks2s()
{
    TChain c("ntuple_data");

    c.Add("/home/zambra/root_files/clusterdata/out/GetSimpleTuple_data/C/prunedC_421*.root");

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

Double_t *sample1[c.GetEntries()];
Double_t *sample2[c.GetEntries()];

    TH1F *hd = new TH1F("hd","Energy for +Pions, w>2  Q^{2}>1 mod X_{f}>0.1  X_{b}<1",100,1,2.7);
    TH1F *hmc = new TH1F("hmc"," ",100,1,2.7);

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
                        sample1[irow]=E;
                        hd->Fill(E);
                    }
                }
            }
            
         }
      }
   }
   }
   }
    hd->Scale(1./hd->Integral());

dE=-0.012;
Double_t ks2;
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

        hmc->Scale(1./hmc->Integral());
        ks2 = hd->KolmogorovTest(hmc);
        cout <<"energia =" << dE << "  ks=" << ks2 <<"\n";
   ROOT::Math::GoFTest* goftest_2 = new ROOT::Math::GoFTest(c.GetEntries(),sample1,c.GetEntries(),sample2);
        Double_t pvalueKS_1 = goftest_2-> KolmogorovSmirnov2SamplesTest();
        cout << "pvalue:"<< pvalueKS_1 <<"\n";

}