#include <TROOT.h>
void vertexZcut()
{
    TChain c("ntuple_data");
  //  TChain fe("ntuple_data");
  //  TChain pb("ntuple_data");

    c.Add("/eos/user/n/nzambra/out/GetSimpleTuple_data/C/prunedC_*.root");
 //   fe.Add("/eos/user/n/nzambra/out/GetSimpleTuple_data/Fe/prunedFe_*.root");
   // pb.Add("/eos/user/n/nzambra/out/GetSimpleTuple_data/Pb/prunedPb_*.root");

    float vze,vzec,vzh;
  //  float xf,yf,kf,lf,qf,wf,xbf,ttf;
  //  float xp,yp,kp,lp,qp,wp,xbp,ttp;

    c.SetBranchAddress("vze", &vze);
    c.SetBranchAddress("vzec", &vzec);
    c.SetBranchAddress("vzh", &vzh);

//    fe.SetBranchAddress("Pz", &xf);
//    fe.SetBranchAddress("P", &yf);
//    fe.SetBranchAddress("pid", &lf);

//    pb.SetBranchAddress("Pz", &xp);
//    pb.SetBranchAddress("P", &yp);
//    pb.SetBranchAddress("pid", &lp);

    TH1F *hc1 = new TH1F("hc1","vertex Z cut",500,-60,20);
    TH1F *hc2 = new TH1F("hc2","vertex Z cut",500,-60,20);
    TH1F *hc3 = new TH1F("hc3","vertex Z cut",500,-60,20);

//    TH1F *hfe = new TH1F("hfe","P for +Pions, w>2  Q^{2}>1 X_{f}>0.1 X_{b}<1",100,0,2);
//    TH1F *hpb = new TH1F("hpb","P for +Pions, w>2  Q^{2}>1 X_{f}>0.1 X_{b}<1",100,0,2);

    for (size_t irow=0; irow<c.GetEntries(); ++irow){
        c.GetEntry(irow);

        hc1->Fill(vze);
        hc2->Fill(vzec);
        hc3->Fill(vzh);
    }

//    for (size_t irow=0; irow<fe.GetEntries(); ++irow){
//       fe.GetEntry(irow);
//    }

//    for (size_t irow=0; irow<pb.GetEntries(); ++irow){
//       pb.GetEntry(irow);
//    }
    TCanvas *c1 = new TCanvas("c1","c1",800,600);

    hc1->SetLineColor(kBlue);
    hc2->SetLineColor(kRed);
    hc3->SetLineColor(kGreen);   

    hc1->Scale(1./hc1->Integral());
    hc2->Scale(1./hc2->Integral());
    hc3->Scale(1./hc3->Integral());
   
    hc1->GetYaxis()->SetTitle("Entries");
    hc1->GetXaxis()->SetTitle("V_z (cm)");

    hc1->Draw();
    hc2->Draw("SAME");
    hc3->Draw("SAME");

    TLegend* leg = new TLegend(0.6,0.7,0.9,0.9);
    leg->AddEntry(hc1,"vze","l");
    leg->AddEntry(hc2,"vzec","l");
    leg->AddEntry(hc3,"vzh","l");
    leg->Draw("SAME");
    gStyle->SetOptStat(0);
    c1->SaveAs("VertexZ_C_norm_bin500.pdf");
 
}
