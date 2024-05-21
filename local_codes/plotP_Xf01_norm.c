#include <TROOT.h>
void plotP_Xf01_norm()
{

   TChain cs("ntuple_sim");
   TChain cs1("ntuple_sim");
   TChain cs2("ntuple_sim");   
   TChain cs3("ntuple_sim"); 
   TChain cs4("ntuple_sim"); 

cs.Add("/home/zambra/root_files/clusterdata/out/GetSimpleTuple_HSim/C1/prunedC_*.root");
cs1.Add("/home/zambra/root_files/clusterdata/out/GetSimpleTuple_HSim/C1/prunedC_*.root");
cs2.Add("/home/zambra/root_files/clusterdata/out/GetSimpleTuple_HSim/C1/prunedC_*.root");
cs3.Add("/home/zambra/root_files/clusterdata/out/GetSimpleTuple_HSim/C1/prunedC_*.root");
cs4.Add("/home/zambra/root_files/clusterdata/out/GetSimpleTuple_HSim/C1/prunedC_*.root");

   float x,y,k,l,q,w;

   cs.SetBranchAddress("Pz", &x);
   cs1.SetBranchAddress("P", &y);
   cs2.SetBranchAddress("pid", &l);
   cs3.SetBranchAddress("Q2", &q);
   cs4.SetBranchAddress("W", &w);

    TH1F *hs = new TH1F("hs"," for +Pions, w>2  Q^{2}>1 X_{f}>0.1",1000,0,1.5);


   for (size_t irow=0; irow<cs1.GetEntries(); ++irow){
      cs.GetEntry(irow);
      cs1.GetEntry(irow);
      cs2.GetEntry(irow);
      cs3.GetEntry(irow);
      cs4.GetEntry(irow);      
      k=x/y;
      if (k>0.1)
      {
         if (l==211)
         {
            if (q>1)
         {
            if (w>2)
            {
               hs->Fill(y);
            }
            
         }
      }
   }
   }
   TCanvas *c1 = new TCanvas("c1","c1",800,600);

   hs->SetLineColor(kBlue);
   hs->Scale(1./hs->Integral());
   hs->GetYaxis()->SetTitle("Entries");
   hs->GetXaxis()->SetTitle("P (GeV) ");

   hs->Draw();

   TLegend* leg = new TLegend(0.2,0.2,0.2,0.2);
   leg->AddEntry(hs,"data","l");
   leg->Draw("SAME");
   gStyle->SetOptStat(1);
   c1->SaveAs("Sim_P_Pion_C_xf01_norm_q_w.pdf");
 
}
