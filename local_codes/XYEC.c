#include <TROOT.h>
void XYEC()
{

   TChain c("ntuple_data");

   c.Add("/home/zambra/root_files/clusterdata/out/GetSimpleTuple_data/C/prunedC*.root");

   
   TCanvas *c1 = new TCanvas("c1","c1",800,600);

   float x,y,tt,y1;

   c.SetBranchAddress("Pe", &x);
   c.SetBranchAddress("Etote", &y1);
   c.SetBranchAddress("TargType", &tt);   

   TH2F *h = new TH2F("h","E_{tot} vs P in carbon/data",250,0,4,250,0,4);

   for (size_t irow=0; irow<c.GetEntries(); ++irow){
      
    c.GetEntry(irow);  
    y=y1/0.27;
    if(tt==2)
    {
        h->Fill(x,y);  
    }
   }


   h->GetYaxis()->SetTitle("E_{tot}");
   h->GetXaxis()->SetTitle("P");
   double norm;
   norm=1/h->Integral();
   h->Scale(norm);

   h->Draw("Colz");

   gStyle->SetOptStat(0);
   c1->SaveAs("Etot_P.pdf");
 
}
