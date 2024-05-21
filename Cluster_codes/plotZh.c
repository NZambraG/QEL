void plotZh()
{

   TChain cs("ntuple_sim");
   TChain cd("ntuple_data");

    cs.Add("/eos/user/n/nzambra/out/GetSimpleTuple_HSim/C1/prunedC_*.root");
    cd.Add("/eos/user/n/nzambra/out/GetSimpleTuple_data/C/prunedC_42*.root");

   float x,y;

   cs.SetBranchAddress("Zh", &x);
   cd.SetBranchAddress("Zh", &y);

    TH1F *hs = new TH1F("hs","Zh",100,-2,10);
    TH1F *hd = new TH1F("hd","",100,-2,10);

   for (size_t irow=0; irow<cs.GetEntries(); ++irow){
      cs.GetEntry(irow);
      hs->Fill(x);
   }
   for (size_t irow=0; irow<cd.GetEntries(); ++irow){
      cd.GetEntry(irow);
      hd->Fill(y);
   }

   TCanvas *c1 = new TCanvas("c1","c1",800,600);

   hs->SetLineColor(kBlue);
   hd->SetLineColor(kRed);

   hs->GetYaxis()->SetRangeUser(0,350000);
   hs->GetYaxis()->SetTitle("Entries");
   hs->GetXaxis()->SetTitle("Zh");

   hs->Draw();
   hd->Draw("SAME");

   TLegend* leg = new TLegend(0.2,0.2,0.2,0.2);
   leg->AddEntry(hs,"Sim","l");
   leg->AddEntry(hd,"Data","l");
   leg->Draw("SAME");
   gStyle->SetOptStat(0);
   c1->SaveAs("plot_Zh.pdf");
 
}
