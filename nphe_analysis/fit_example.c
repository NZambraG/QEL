#include <TROOT.h>
#include "RooRealVar.h"
#include "RooDataSet.h"
#include "RooGaussian.h"
#include "TCanvas.h"
#include "RooPlot.h"
#include "TAxis.h"
using namespace RooFit;
void fit_example()
{
    TChain cd("ntuple_data");
    TChain cs("ntuple_sim");   
    cd.Add("/home/zambra/root_files/clusterdata/out/GetSimpleTuple_data/C/prunedC_4210*.root");
    cs.Add("/home/zambra/root_files/clusterdata/out/GetSimpleTuple_HSim/C1/prunedC_13*.root");
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
    TH1F *hd = new TH1F("hd"," phiPQ",100, 0, ppqlr);  
    TH1F *hs = new TH1F("hs"," ",100, 0, ppqlr); 
    TH1F *hmc = new TH1F("hmc"," ",100, 0, ppqlr); 
    TH1F *hdcorrected = new TH1F("hdcorrected"," ",100, 0, ppqlr); 
    TH1F *weight = new TH1F("weight"," ",100, 0, ppqlr); 
// do acceptance correction
   for (size_t irow=0; irow<cs.GetEntries(); ++irow){
      cs.GetEntry(irow);
    if(nphes>0){
                hs->Fill(phipqs);
                hmc->Fill(mcphipqs);
      }}
weight->Divide(hs,hmc);
   for (size_t irow=0; irow<cd.GetEntries(); ++irow){
        cd.GetEntry(irow);
            if(nphed>0){ 
            //accphipq=phipqd/pesophi;
            hd->Fill(phipqd);
    }}
hdcorrected->Divide(hd,weight);
hdcorrected->Scale(1./hdcorrected->Integral());

           
   // Declare observable x for fit
   RooRealVar x("x", "x", -ppqlr, ppqlr);
x.setRange("signal", -30, 30);
   float pi;
   pi=TMath::Pi();
// Create a binned dataset that imports contents of TH1 and associates its contents to observable 'x'
   RooDataHist dh("dh", "dh", x, Import(*hdcorrected));
//GAUSSIAN
    // Parámetros y defincion de la gaussiana
RooRealVar mean("mean", "Mean of Gaussian", 0); 
RooRealVar sigma("sigma", "Width of Gaussian", 30, 0.1, 200);
    RooGaussian gauss("gauss", "Gaussian PDF",x, mean, sigma);

    RooRealVar frac("frac", "fraction of Gaussian", 0.5,0.0,1.0);

//polinomial function
RooRealVar j("j", "j",1,0,100); 
RooRealVar k("k", "k", 1,0,100);
RooRealVar l("l", "l", 1,0,100);

    //RooRealVar polfrac("polfrac", "fraction of polynomial function", 0.5,0.0,1.0);
    //RooGenericPdf polynomial("genpdf", "1/(j*x) + 1/(k*x*x)+1/(l*x*x*x))", RooArgSet(x,j,k,l));
    
//phi pq function 
    RooRealVar A("A", "A", 41,30,50);
    RooRealVar B("B", "B",21,10,30);
    RooRealVar C("C", "C", 16,10,20 );
    RooRealVar D("D", "D", 2,0,10 );

    RooGenericPdf genpdf("genpdf", "A + B*cos((pi/180) *D* x) + C*cos(2*(pi/180)*D*x   +1/(j*x) + 1/(k*x*x)+1/(l*x*x*x))", RooArgSet(x, A, B, C,D,j,k,l));
    RooAddPdf model("model", "gauss + genpdf", RooArgList(gauss, genpdf), RooArgList(frac));
//fit the model to acc
    
   genpdf.fitTo(dh,Range("full_range"));
//print fit variables

   sigma.Print();
   A.Print();
   B.Print();
   C.Print();
   D.Print();
   j.Print();
   k.Print();
   l.Print();
   //plot acc and fit and individual functions
    RooPlot* frame = x.frame();
    dh.plotOn(frame);

    genpdf.plotOn(frame, LineColor(kGreen));
    model.plotOn(frame, Components(gauss), LineColor(kRed));
    model.plotOn(frame, Components(genpdf),LineStyle(kDashed), LineColor(kBlue));


    TCanvas* canvas = new TCanvas("canvas", "Fit phiPQ", 800, 600);
    frame->Draw();
    canvas->SaveAs("fit_genpdf_short_range_polynomial.pdf");

}