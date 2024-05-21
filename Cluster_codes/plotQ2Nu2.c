void plotQ2Nu2()
{

   TChain c("ntuple_e");

   c.Add("/eos/user/n/nzambra/out/GetSimpleTuple_HSim/C1/prunedC_*.root");
   
   TCanvas *c1 = new TCanvas("c1","c1",800,600);
   c.Draw("mc_Q2:mc_Nu","mc_Q2>1","Colz");

   gStyle->SetOptStat(1);
   c1->SaveAs("plot_Q2_Nu2.pdf");
}
