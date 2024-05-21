void plotQ2Xb_data()
{

   TChain c("ntuple_e");

   c.Add("/eos/user/n/nzambra/out/GetSimpleTuple_data/C/prunedC_42*.root");

   TCanvas *c1 = new TCanvas("c1","c1",800,600);
   c.Draw("Q2:Xb","Q2>1","Colz");


   gStyle->SetOptStat(1);
   c1->SaveAs("plot_Q2_Xb_data.pdf");
}
