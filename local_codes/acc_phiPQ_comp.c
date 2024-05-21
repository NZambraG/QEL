#include <TROOT.h>
void acc_phiPQ_comp()
{
    TChain cd("ntuple_data");
    TChain cs("ntuple_sim");
    TChain ac("Xb_0");
    cd.Add("/home/zambra/root_files/clusterdata/out/GetSimpleTuple_data/C/prunedC*.root");
    cs.Add("/home/zambra/root_files/clusterdata/out/GetSimpleTuple_HSim/C1/prunedC*.root");
    ac.Add("/home/zambra/root_files/local_codes/Acc_C_PPion_q2_*.root");
    float cdphi,csphi,acphi,mcphi,l,ld,tt,ttd,tta,cdxb,csxb,mcxb;

    cd.SetBranchAddress("PhiPQ", &cdphi);
    cs.SetBranchAddress("PhiPQ", &csphi);
    cs.SetBranchAddress("mc_PhiPQ", &mcphi);
    
    cd.SetBranchAddress("Xb", &cdxb);
    cs.SetBranchAddress("Xb", &csxb);
    cs.SetBranchAddress("mc_Xb", &mcxb);

    ac.SetBranchAddress("PhiPQ", &acphi);

    cd.SetBranchAddress("pid", &ld);
    cd.SetBranchAddress("TargType",&ttd);
    cs.SetBranchAddress("pid", &l);
    cs.SetBranchAddress("mc_TargType",&tt);
    ac.SetBranchAddress("TargType",&tta);
    TH1F *hd = new TH1F("zh","Acc PhiPQ for +Pions ",100,-200,200);
    TH1F *hs = new TH1F(" "," ",100,-200,200);
    TH1F *mchs = new TH1F(" "," ",100,-200,200 );
    TH1F *AccCorrected = new TH1F(" "," ",100,-200,200 );

   for (size_t irow=0; irow<cs.GetEntries(); ++irow){
      cs.GetEntry(irow);



                if(csxb>0.12){
                    if(csxb<0.21){
                    hs->Fill(csphi);
                    mchs->Fill(mcphi);
                    }
                }
            
      }
   
   for (size_t irow=0; irow<cd.GetEntries(); ++irow){
      cd.GetEntry(irow);

                if(cdxb>0.12){
                    if(cdxb<0.21){
                    hd->Fill(cdphi);
                    
                    
            }
         }
   }
      for (size_t irow=0; irow<ac.GetEntries(); ++irow){
      ac.GetEntry(irow);


                    AccCorrected->Fill(acphi);
                
        }

   TCanvas *c1 = new TCanvas("c1","c1",800,600);

    AccCorrected->SetLineColor(kRed);
    hd->SetLineColor(kBlack);
    hs->SetLineColor(kBlue);
    mchs->SetLineColor(kGreen);


    hd->GetYaxis()->SetTitle("Entries");
    hd->GetXaxis()->SetTitle("PhiPQ");
    hd->Draw();
    AccCorrected->Draw("SAME");
    hs->Draw("SAME");
    mchs->Draw("SAME");


    TLegend* leg = new TLegend(0.6,0.7,0.9,0.9);
    leg->AddEntry(hd,"Data","l");
    leg->AddEntry(hs,"reconstructed","l");
    leg->AddEntry(mchs,"generated","l");    
    leg->AddEntry(AccCorrected,"Acc","l");

    leg->Draw("SAME");
    gStyle->SetOptStat(0);

    c1->SaveAs("Acc_phiPQ_Comp_nopidtt.pdf");

 
}
