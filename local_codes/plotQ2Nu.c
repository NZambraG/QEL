#include <TROOT.h>
void plotQ2Nu()
{

   TChain c("ntuple_e");

   //c.Add("/home/zambra/root_files/clusterdata/out/GetSimpleTuple_data/C/prunedC_42*.root");
   c.Add("/home/zambra/root_files/clusterdata/out/GetSimpleTuple_HSim/C1/prunedC_*.root");
   c.Add("/home/zambra/root_files/clusterdata/out/GetSimpleTuple_HSim/C2/prunedC_*.root");
   c.Add("/home/zambra/root_files/clusterdata/out/GetSimpleTuple_HSim/C3/prunedC_*.root");
   c.Add("/home/zambra/root_files/clusterdata/out/GetSimpleTuple_HSim/C4_yshiftm03/prunedC_*.root");
   c.Add("/home/zambra/root_files/clusterdata/out/GetSimpleTuple_HSim/C5_yshiftm03/prunedC_*.root");
   c.Add("/home/zambra/root_files/clusterdata/out/GetSimpleTuple_HSim/C6_yshiftm03/prunedC_*.root");
   c.Add("/home/zambra/root_files/clusterdata/out/GetSimpleTuple_HSim/C7_yshiftm03/prunedC_*.root");
   c.Add("/home/zambra/root_files/clusterdata/out/GetSimpleTuple_HSim/C8_yshiftm03/prunedC_*.root");
   c.Add("/home/zambra/root_files/clusterdata/out/GetSimpleTuple_HSim/C9_yshiftm03/prunedC_*.root");
   
   TCanvas *c1 = new TCanvas("c1","c1",800,600);

   float x,y,k,tt;

   c.SetBranchAddress("mc_Q2", &x);
   c.SetBranchAddress("mc_Nu", &y);
   c.SetBranchAddress("mc_TargType", &tt);   

   TH2F *h = new TH2F("h","Q^{2} vs nu for MC",100,0,6,100,0,6);

   for (size_t irow=0; irow<c.GetEntries(); ++irow){
      
      c.GetEntry(irow);  
      k=x;
      if(tt==2)
      {
         if (k>1)
         {
            h->Fill(x,y);  
         }
      }
   }

   h->GetXaxis()->SetRangeUser(0,10);
   h->GetYaxis()->SetTitle("/nu");
   h->GetXaxis()->SetTitle("Q^{2} ((GeV)^{2})");
   double norm;
   norm=1/h->Integral();
   h->Scale(norm);

   h->Draw("Colz");

   gStyle->SetOptStat(0);
   c1->SaveAs("Q2_vs_Nu_SIM_tt,q2>1.pdf");
 
}
