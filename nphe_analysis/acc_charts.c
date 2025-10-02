#include <TROOT.h>
#include "RooRealVar.h"
#include "RooDataSet.h"
#include "RooGaussian.h"
#include "TCanvas.h"
#include "RooPlot.h"
#include "TAxis.h"

void acc_charts()
{
    TChain cd("ntuple_data");
    TChain cs("ntuple_sim");   
    cd.Add("/home/zambra/root_files/clusterdata/out/GetSimpleTuple_data/C/prunedC*.root");
    cs.Add("/home/zambra/root_files/clusterdata/out/GetSimpleTuple_HSim/C1/prunedC*.root");
    //cs.Add("/home/zambra/root_files/clusterdata/out/GetSimpleTuple_HSim/C2/prunedC*.root");
    //cs.Add("/home/zambra/root_files/clusterdata/out/GetSimpleTuple_HSim/C3/prunedC*.root"); 


    float pzcd,pcd,lcd,qcd,wcd,xbcd,ybcd,ttcd,nucd,pt2cd,zhcd,phipqcd,nphed;
    float pzcs,pcs,lcs,qcs,wcs,xbcs,ybcs,ttcs,nucs,pt2cs,zhcs,phipqcs;
    float mcpzcs,mcpcs,mclcs,mcqcs,mcwcs,mcxbcs,mcybcs,mcttcs,mcnucs,mcpt2cs,mczhcs,mcphipqcs;

    float PhiPQ,Zh,Q2,Xb,Pt2,Pz,P,pid,W,Yb,Nu,TargType,Nphe;



    TFile f("fast_acc_bin_0.root", "RECREATE");
    TTree t0("Xb_0","Xb_0");
    t0.Branch("PhiPQ",&PhiPQ,"PhiPQ/F");
    t0.Branch("Zh",&Zh,"Zh/F");
    t0.Branch("Q2",&Q2,"Q2/F");
    t0.Branch("Xb",&Xb,"Xb/F");
    t0.Branch("Pt2",&Pt2,"Pt2/F");
    t0.Branch("Pz",&Pz,"Pz/F");
    t0.Branch("P",&P,"P/F");
    t0.Branch("pid",&pid,"pid/F");
    t0.Branch("W",&W,"W/F");
    t0.Branch("Yb",&Yb,"Yb/F");
    t0.Branch("Nu",&Nu,"Nu/F");
    t0.Branch("TargType",&TargType,"TargType/F");
    t0.Branch("Nphe",&Nphe,"Nphe/F");


    cd.SetBranchAddress("Pz", &pzcd);
    cd.SetBranchAddress("P", &pcd);
    cd.SetBranchAddress("pid", &lcd);
    cd.SetBranchAddress("Q2", &qcd);
    cd.SetBranchAddress("W", &wcd);
    cd.SetBranchAddress("Xb", &xbcd);
    cd.SetBranchAddress("Yb", &ybcd);
    cd.SetBranchAddress("Nu", &nucd);
    cd.SetBranchAddress("Pt2", &pt2cd);
    cd.SetBranchAddress("Zh", &zhcd);
    cd.SetBranchAddress("TargType", &ttcd);
    cd.SetBranchAddress("PhiPQ",&phipqcd);
    cd.SetBranchAddress("Nphe",&nphed);

    cs.SetBranchAddress("Pz", &pzcs);
    cs.SetBranchAddress("P", &pcs);
    cs.SetBranchAddress("pid", &lcs);
    cs.SetBranchAddress("Q2", &qcs);
    cs.SetBranchAddress("W", &wcs);
    cs.SetBranchAddress("Xb", &xbcs);
    cs.SetBranchAddress("Yb", &ybcs);
    cs.SetBranchAddress("Nu", &nucs);
    cs.SetBranchAddress("Pt2", &pt2cs);
    cs.SetBranchAddress("Zh", &zhcs);
    cs.SetBranchAddress("TargType", &ttcs);
    cs.SetBranchAddress("PhiPQ",&phipqcs);

    cs.SetBranchAddress("mc_Pz", &mcpzcs);
    cs.SetBranchAddress("mc_P", &mcpcs);
    cs.SetBranchAddress("mc_pid", &mclcs);
    cs.SetBranchAddress("mc_Q2", &mcqcs);
    cs.SetBranchAddress("mc_W", &mcwcs);
    cs.SetBranchAddress("mc_Xb", &mcxbcs);
    cs.SetBranchAddress("mc_Yb", &mcybcs);
    cs.SetBranchAddress("mc_Nu", &mcnucs);
    cs.SetBranchAddress("mc_Pt2", &mcpt2cs);
    cs.SetBranchAddress("mc_Zh", &mczhcs);
    cs.SetBranchAddress("mc_TargType", &mcttcs);
    cs.SetBranchAddress("mc_PhiPQ",&mcphipqcs);
float pesophi0,pesophi1,pesophi2,pesophi3,pesophi4;
   for (size_t irow=0; irow<cs.GetEntries(); ++irow){
      cs.GetEntry(irow);
      if(phipqcs>-180 & phipqcs<-150){
                pesophi0=phipqcs/mcphipqcs;

   }}

   for (size_t irow=0; irow<cd.GetEntries(); ++irow){
        cd.GetEntry(irow);
            if(nphed>0 & nphed<25){
                if(phipqcd>-180 & phipqcd<-150){
                        PhiPQ=phipqcd/pesophi0;
            Q2=qcd;
            Xb=xbcd;
            Pt2=pt2cd;
            Zh=zhcd;
            Nu=nucd;
            Pz=pzcd;
            P=pcd;
            W=wcd;
            Yb=ybcd;
            TargType=ttcd;
            Nphe=nphed;
            pid=lcd;
            t0.Fill();
                }}
    }


    t0.Write();
}