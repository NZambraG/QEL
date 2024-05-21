#include <TROOT.h>

void histoerror()
{
    TChain cd("ntuple_data");
    TChain cs("ntuple_sim");   
    cd.Add("/home/zambra/root_files/clusterdata/out/GetSimpleTuple_data/C/prunedC_420*.root");
    cs.Add("/home/zambra/root_files/clusterdata/out/GetSimpleTuple_HSim/C1/prunedC*.root");

    float pzcd,pcd,lcd,qcd,wcd,xbcd,ybcd,ttcd,nucd,pt2cd,zhcd,phipqcd;
    float pzcs,pcs,lcs,qcs,wcs,xbcs,ybcs,ttcs,nucs,pt2cs,zhcs,phipqcs;
    float mcpzcs,mcpcs,mclcs,mcqcs,mcwcs,mcxbcs,mcybcs,mcttcs,mcnucs,mcpt2cs,mczhcs,mcphipqcs;

    cd.SetBranchAddress("Pz", &pzcd);
    cd.SetBranchAddress("P", &pcd);
    cd.SetBranchAddress("pid", &lcd);
    cd.SetBranchAddress("Q2", &qcd);
    cd.SetBranchAddress("W", &wcd);
    cd.SetBranchAddress("Xb", &xbcd);
    cd.SetBranchAddress("Yb", &ybcd);
    cd.SetBranchAddress("Nu", &nucd);
    cd.SetBranchAddress("Pt2", &pt2cd);
    cd.SetBranchAddress("Zh", &zhcd);
    cd.SetBranchAddress("TargType", &ttcd);
    cd.SetBranchAddress("PhiPQ",&phipqcd);

    cs.SetBranchAddress("Pz", &pzcs);
    cs.SetBranchAddress("P", &pcs);
    cs.SetBranchAddress("pid", &lcs);
    cs.SetBranchAddress("Q2", &qcs);
    cs.SetBranchAddress("W", &wcs);
    cs.SetBranchAddress("Xb", &xbcs);
    cs.SetBranchAddress("Yb", &ybcs);
    cs.SetBranchAddress("Nu", &nucs);
    cs.SetBranchAddress("Pt2", &pt2cs);
    cs.SetBranchAddress("Zh", &zhcs);
    cs.SetBranchAddress("TargType", &ttcs);
    cs.SetBranchAddress("PhiPQ",&phipqcs);

    cs.SetBranchAddress("mc_Pz", &mcpzcs);
    cs.SetBranchAddress("mc_P", &mcpcs);
    cs.SetBranchAddress("mc_pid", &mclcs);
    cs.SetBranchAddress("mc_Q2", &mcqcs);
    cs.SetBranchAddress("mc_W", &mcwcs);
    cs.SetBranchAddress("mc_Xb", &mcxbcs);
    cs.SetBranchAddress("mc_Yb", &mcybcs);
    cs.SetBranchAddress("mc_Nu", &mcnucs);
    cs.SetBranchAddress("mc_Pt2", &mcpt2cs);
    cs.SetBranchAddress("mc_Zh", &mczhcs);
    cs.SetBranchAddress("mc_TargType", &mcttcs);
    cs.SetBranchAddress("mc_PhiPQ",&mcphipqcs);
   TCanvas *c1 = new TCanvas("c1","c1",800,600);
float pesophi;
        TH1F *hs = new TH1F("hs","Phi_{PQ} distribution",100,-200,200);
                TH1F *hs1 = new TH1F("hs1","Phi_{PQ} distribution",100,-200,200);
            TH1F *hd = new TH1F("hd","X_f",100,-200,200);
            TH1F *hd1 = new TH1F("hd1","X_f",100,-200,200);
    for (size_t irow=0; irow<cs.GetEntries(); ++irow){
        cs.GetEntry(irow);
                pesophi=phipqcs/mcphipqcs;
                hs->Fill(phipqcs);
                hs1->Fill(mcphipqcs);
    }
    for (size_t irow=0; irow<cd.GetEntries(); ++irow){
        cd.GetEntry(irow);
    hd->Fill(phipqcd,pesophi);
    hd1->Fill(phipqcd);

    }

    hs->Scale(1/hs->Integral());
    hs1->Scale(1/hs1->Integral());
    hd->Scale(1/hd->Integral());
    hd1->Scale(1/hd1->Integral());

hs->SetLineColor(kBlue);
hs1->SetLineColor(kRed);
hd->SetLineColor(kGreen);
hd1->SetLineColor(kBlack);

   hs->GetYaxis()->SetTitle("Entries");
   hs->GetXaxis()->SetTitle("Phi_{PQ}");

   hs->Draw();
   hs1->Draw("SAME");
   hd->Draw("SAME");
   hd1->Draw("SAME");

   TLegend* leg = new TLegend(0.2,0.2,0.2,0.2);
   leg->AddEntry(hs,"Sim","l");
   leg->AddEntry(hs1,"Sim mc","l");
   leg->AddEntry(hd,"Acc","l");
   leg->AddEntry(hd1,"data","l");
   leg->Draw("SAME");
   gStyle->SetOptStat(1);
   c1->SaveAs("phiacc.pdf");
 


    }
