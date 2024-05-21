#include <TROOT.h>
void plotQ2Xb()
{
   TChain c("ntuple_data");

    c.Add("/home/zambra/root_files/clusterdata/out/GetSimpleTuple_data/C/prunedC_420*.root");
   //c.Add("/home/zambra/root_files/clusterdata/out/GetSimpleTuple_HSim/C1/prunedC_*.root");
   //c.Add("/home/zambra/root_files/clusterdata/out/GetSimpleTuple_HSim/C2/prunedC_*.root");
   //c.Add("/home/zambra/root_files/clusterdata/out/GetSimpleTuple_HSim/C3/prunedC_*.root");
   //c.Add("/home/zambra/root_files/clusterdata/out/GetSimpleTuple_HSim/C4_yshiftm03/prunedC_*.root");
   //c.Add("/home/zambra/root_files/clusterdata/out/GetSimpleTuple_HSim/C5_yshiftm03/prunedC_*.root");
   //c.Add("/home/zambra/root_files/clusterdata/out/GetSimpleTuple_HSim/C6_yshiftm03/prunedC_*.root");
   //c.Add("/home/zambra/root_files/clusterdata/out/GetSimpleTuple_HSim/C7_yshiftm03/prunedC_*.root");
   //c.Add("/home/zambra/root_files/clusterdata/out/GetSimpleTuple_HSim/C8_yshiftm03/prunedC_*.root");
   //c.Add("/home/zambra/root_files/clusterdata/out/GetSimpleTuple_HSim/C9_yshiftm03/prunedC_*.root");
    
   TCanvas *c1 = new TCanvas("c1","c1",1000,600); 
   
   float x,y;

   c.SetBranchAddress("Q2", &x);
   c.SetBranchAddress("Xb", &y);

   TH2F *h = new TH2F("h","Q^{2} vs X_{b} for data",100,1,4,100,0,1);

   for (size_t irow=0; irow<c.GetEntries(); ++irow){
      
      c.GetEntry(irow);  

         if (x>1.0){
         if(x<4.0)
         {
            h->Fill(x,y);  
         }
         }
   }

   h->GetXaxis()->SetRangeUser(0,5);
   h->GetYaxis()->SetTitle("X_{b}");
   h->GetXaxis()->SetTitle("Q^{2} ((GeV)^{2})");
   double norm;
   norm=1/h->Integral();
   h->Scale(norm);

   h->Draw("Colz");

   gStyle->SetOptStat(0);
   c1->SaveAs("plot_Q2_Xb_data.pdf");
}