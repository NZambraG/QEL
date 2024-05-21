void plotP_Xf01()
{

   TChain cs("ntuple_data");
   TChain cs1("ntuple_data");
   TChain cs2("ntuple_data");   

cs.Add("/home/zambra/root_files/clusterdata/out/GetSimpleTuple_data/C/prunedC_42*.root");
cs1.Add("/home/zambra/root_files/clusterdata/out/GetSimpleTuple_data/C/prunedC_42*.root");
cs2.Add("/home/zambra/root_files/clusterdata/out/GetSimpleTuple_data/C/prunedC_42*.root");

   float x,y,k,l;

   cs.SetBranchAddress("Pz", &x);
   cs1.SetBranchAddress("P", &y);
   cs2.SetBranchAddress("pid", &l);

    TH1F *hs = new TH1F("hs","X_f",1000,0,1.5);


   for (size_t irow=0; irow<cs1.GetEntries(); ++irow){
      cs.GetEntry(irow);
      cs1.GetEntry(irow);
      cs2.GetEntry(irow);
      k=x/y;
      if (k>0.1)
      {
         if (l==211)
         {
            hs->Fill(y);
         }
      }
   }
   TCanvas *c1 = new TCanvas("c1","c1",800,600);

   hs->SetLineColor(kBlue);

   hs->GetYaxis()->SetTitle("Entries");
   hs->GetXaxis()->SetTitle("P");

   hs->Draw();

   TLegend* leg = new TLegend(0.2,0.2,0.2,0.2);
   leg->AddEntry(hs,"data","l");
   leg->Draw("SAME");
   gStyle->SetOptStat(1);
   c1->SaveAs("data_plot_P_Pion_C_xf01.pdf");
 
}
//average mass of nucleon ...
//acceptance correction stuff
//how many particles are really detected
//binning scheme q2 : 3 pt2 : 100 nu:3 zh: 10
//semi incllusive final state, not measure everything
//n thrwon is called truth
// n reconstructed 
// Acc = nr/nt