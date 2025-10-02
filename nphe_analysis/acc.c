#include <TROOT.h>
#include "RooRealVar.h"
#include "RooDataSet.h"
#include "RooGaussian.h"
#include "TCanvas.h"
#include "RooPlot.h"
#include "TAxis.h"

void acc()
{
    TChain cd("ntuple_data");
    TChain cs("ntuple_sim");   
    cd.Add("/home/zambra/root_files/clusterdata/out/GetSimpleTuple_data/C/prunedC_*.root");
    cs.Add("/home/zambra/root_files/clusterdata/out/GetSimpleTuple_HSim/C1/prunedC_*.root");
    //cs.Add("/home/zambra/root_files/clusterdata/out/GetSimpleTuple_HSim/C3/prunedC_*.root");
    //cs.Add("/home/zambra/root_files/clusterdata/out/GetSimpleTuple_HSim/C4_yshiftm03/prunedC_*.root");
    //cs.Add("/home/zambra/root_files/clusterdata/out/GetSimpleTuple_HSim/C5_yshiftm03/prunedC_*.root");
    //cs.Add("/home/zambra/root_files/clusterdata/out/GetSimpleTuple_HSim/C6_yshiftm03/prunedC_*.root");
    //cs.Add("/home/zambra/root_files/clusterdata/out/GetSimpleTuple_HSim/C7_yshiftm03/prunedC_*.root");
    //cs.Add("/home/zambra/root_files/clusterdata/out/GetSimpleTuple_HSim/C8_yshiftm03/prunedC_*.root");
    //cs.Add("/home/zambra/root_files/clusterdata/out/GetSimpleTuple_HSim/C9_yshiftm03/prunedC_*.root");

    float phipqd,nphed;

    float phipqs,mcphipqs,accphipq,nphes;

    cd.SetBranchAddress("PhiPQ",&phipqd);
    cd.SetBranchAddress("Nphe", &nphed);

    cs.SetBranchAddress("PhiPQ",&phipqs);
    cs.SetBranchAddress("Nphe", &nphes);
    cs.SetBranchAddress("mc_PhiPQ",&mcphipqs);

    float ppqlr; //phipq lower and higher value
    ppqlr=180;
//---------------------------------------------------------
//CUT

    //float x1,y1;
        //if(y1>0 & y1<25){
        //if(  y1<0.0375*x1*x1+20){
            //x1=phipqd;
       // y1=nphed;

//-----------------------------------------------------------


    //TH2F *hd = new TH2F("hd"," phiPQ vs nphe electron",100,-ppqlr,ppqlr,100,0,300);    
    TH1F *hd = new TH1F("hd"," phiPQ",100, -ppqlr, ppqlr);  
    TH1F *hs = new TH1F("hs"," ",100, -ppqlr, ppqlr); 
    TH1F *hmc = new TH1F("hmc"," ",100, -ppqlr, ppqlr); 
    TH1F *hdcorrected = new TH1F("hdcorrected"," ",100, -ppqlr, ppqlr); 
    TH1F *weight = new TH1F("weight"," ",100, -ppqlr, ppqlr); 

   for (size_t irow=0; irow<cs.GetEntries(); ++irow){
      cs.GetEntry(irow);

                hs->Fill(phipqs);
                hmc->Fill(mcphipqs);
      }
weight->Divide(hs,hmc);
   for (size_t irow=0; irow<cd.GetEntries(); ++irow){
        cd.GetEntry(irow);
            //if(nphed>0){ 
            //accphipq=phipqd/pesophi;
            hd->Fill(phipqd);
    }
hdcorrected->Divide(hd,weight);
    TCanvas* canvas = new TCanvas("canvas", "Fit phiPQ", 800, 600);
    hd->SetLineColor(kBlue);
    hs->SetLineColor(kRed);
    hmc->SetLineColor(kGreen);
    hdcorrected->SetLineColor(kBlack);

    hd->Draw();
    //hs->Draw("SAME");
    //hmc->Draw("SAME");
    hdcorrected->Draw("SAME");

    TLegend* leg = new TLegend(0.6,0.7,0.9,0.9);
    leg->AddEntry(hd,"data","l");
    leg->AddEntry(hdcorrected,"corrected data","l");
    leg->AddEntry(hs,"reconstructed","l");
    leg->AddEntry(hmc,"generated","l");
    leg->Draw("SAME");
    gStyle->SetOptStat(0);
}