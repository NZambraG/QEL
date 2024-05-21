void normZh_m3_allsim()
{

   TChain cs("ntuple_sim");
   TChain cd("ntuple_data");

    cs.Add("/eos/user/n/nzambra/out/GetSimpleTuple_HSim/C1/prunedC_*.root");
    cs.Add("/eos/user/n/nzambra/out/GetSimpleTuple_HSim/C2/prunedC_*.root");
    cs.Add("/eos/user/n/nzambra/out/GetSimpleTuple_HSim/C3/prunedC_*.root");

   float x,y;

   cs.SetBranchAddress("mc_Zh", &x);
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

   hs->GetYaxis()->SetTitle("Entries");
   hs->GetXaxis()->SetTitle("Zh");

   TH1F*h1 = (TH1F*)(hs->Clone("h1"));
   TH1F*h2 = (TH1F*)(hd->Clone("h2"));

   Double_t factor = 1.; 
   //h1->Scale(factor/h1->GetEntries());
   //h2->Scale(factor/h2->GetEntries());

   h1->Scale(1./h1->Integral(), "width");
   h2->Scale(1./h2->Integral(), "width");

   h1->Draw();
   h2->Draw("SAME");

   TLegend* leg = new TLegend(0.2,0.2,0.2,0.2);
   leg->AddEntry(hs,"Sim","l");
   leg->AddEntry(hd,"Data","l");
   leg->Draw("SAME");
   gStyle->SetOptStat(1);
   c1->SaveAs("norm_Zh_m3.pdf");
 
}


