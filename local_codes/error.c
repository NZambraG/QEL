#include <TROOT.h>

void error()
{
    TChain c("ntuple_data");

    c.Add("/home/zambra/root_files/clusterdata/out/GetSimpleTuple_data/C/prunedC*.root");

    float pzc,pc,mxfc,lc,qc,wc,xbc,ybc,ttc,nuc,pt2c,zhc;
    float mp,mn,mppion;
    float sr1c,sr2c,sr3c;
    float E;
    float dE;
    dE=-0.12;
    mp=0.938;
    mn=0.938;
    mppion=0.139;
    
    c.SetBranchAddress("Pz", &pzc);
    c.SetBranchAddress("P", &pc);
    c.SetBranchAddress("pid", &lc);
    c.SetBranchAddress("Q2", &qc);
    c.SetBranchAddress("W", &wc);
    c.SetBranchAddress("Xb", &xbc);
    c.SetBranchAddress("Yb", &ybc);
    c.SetBranchAddress("Nu", &nuc);
    c.SetBranchAddress("Pt2", &pt2c);
    c.SetBranchAddress("Zh", &zhc);
    c.SetBranchAddress("TargType", &ttc);

    TH1F *hd = new TH1F("hd","Energy loss for +Pions, w>2  Q^{2}>1 mod X_{f}>0.1  X_{b}<1",250,1,2.7);

//D
    for (size_t irow=0; irow<c.GetEntries(); ++irow){
        c.GetEntry(irow);

         E=zhc*nuc;
      if(ttc==1){
 
         if (lc==211)
         {
            sr1c=sqrt(pc*pc-pt2c*pt2c);
            sr2c=sqrt((wc*wc-mn*mn+mppion*mppion)*(wc*wc-mn*mn+mppion*mppion)-4*wc*wc*mppion*mppion);
            sr3c=sqrt(qc*qc+nuc*nuc);
            mxfc=2*((nuc+mp)*(sr1c-((sr3c*zhc*nuc)/(nuc+mn))))/(sr2c);
      if (mxfc>0.1)
      {
            if (qc>1)
         {
            if (wc>2)
            {
                if (xbc<1)
                {
                    if (ybc<0.85)
                    {
                        
                        hd->Fill(E);
                    }
                }
            }
         }
         }
      
   }
   }
   }


    TCanvas *c1 = new TCanvas("c1","c1",800,600);
    hd->SetLineColor(kBlue);
    float intd =hd->Integral();
    hd->Scale(1./hd->Integral());
    cout <<intd;

    hd->GetYaxis()->SetTitle("Entries");
    hd->GetXaxis()->SetTitle("Z_{h}*nu (GeV) ");

    hd->Draw();
    TLegend* leg = new TLegend(0.6,0.7,0.9,0.9);
    leg->AddEntry(hd,"D","l");
    leg->Draw("SAME");
    gStyle->SetOptStat(0);
    c1->SaveAs("ELoss_Pion_D_C_modD_for0012_bin250_range1_27.pdf");
}
