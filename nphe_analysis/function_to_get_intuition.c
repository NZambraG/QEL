#include <TROOT.h>
#include "RooRealVar.h"
#include "RooDataSet.h"
#include "RooGaussian.h"
#include "TCanvas.h"
#include "RooPlot.h"
#include "TAxis.h"
using namespace RooFit;
void function_to_get_intuition()
{
     //define pi
    float pi;
    pi=TMath::Pi();

    //phipq lower and higher value
    float ppqlr; 
    ppqlr=180;

    // Declare observable x for fit
   RooRealVar x("x", "x", -ppqlr, ppqlr);
    x.setRange("signal", -30, 30);

    //GAUSSIAN
    // Parámetros y defincion de la gaussiana
    RooRealVar mean("mean", "Mean of Gaussian", 0); 
    RooRealVar sigma("sigma", "Width of Gaussian", 30, 0.1, 200);
    RooGaussian gauss("gauss", "Gaussian PDF",x, mean, sigma);

    RooRealVar frac("frac", "fraction of Gaussian", 0.5,0.0,1.0);

    RooRealVar A("A", "A", 100,0,1000);
    RooRealVar B("B", "B",20,0,100);
    RooRealVar C("C", "C", 2,0,100 );
    
    RooGenericPdf genpdf("genpdf", "A + B*cos((pi/180) * x) + C*cos(2*(pi/180)*x)", RooArgSet(x, A, B, C));
    RooAddPdf model("model", "gauss + genpdf", RooArgList(gauss, genpdf), RooArgList(frac));
    //create data according to function
    std::unique_ptr<RooDataSet> data{genpdf.generate(x, 100000)};
       RooPlot* frame = x.frame();
    data->plotOn(frame);
    //fit the model to acc 
    genpdf.fitTo(*data,Range("full_range"));
    //print fit variables

   sigma.Print();
   A.Print();
   B.Print();
   C.Print();
   //plot acc and fit and individual functions
 

   genpdf.plotOn(frame, LineColor(kGreen));



    TCanvas* c2 = new TCanvas("canvas", "Fit phiPQ", 800, 600);
    frame->Draw();
    c2->SaveAs("function.pdf");

}