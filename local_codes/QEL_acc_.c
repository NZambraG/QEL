#include <TROOT.h>

void E_distri_acc_noacc()
{
    TChain cd("ntuple_data");
    TChain cc("PPions");

    cc.Add("/home/zambra/root_files/local_codes/Acc_C_PPions.root");
    cd.Add("/home/zambra/root_files/clusterdata/out/GetSimpleTuple_data/C/prunedC*.root");

    float pzc,pc,mxfc,lc,qc,wc,xbc,ybc,ttc,nuc,pt2c,zhc;
    float mp,mn,mppion;
    float sr1c,sr2c,sr3c;
    float qcc,xbcc,pt2cc,mxfcc;
    float sr1cc,sr2cc,sr3cc;
    float E;

    mp=0.938;
    mn=0.938;
    mppion=0.139;
    //variables for no data root
    cd.SetBranchAddress("Pz", &pzc);
    cd.SetBranchAddress("P", &pc);
    cd.SetBranchAddress("pid", &lc);
    cd.SetBranchAddress("Q2", &qc);
    cd.SetBranchAddress("W", &wc);
    cd.SetBranchAddress("Xb", &xbc);
    cd.SetBranchAddress("Yb", &ybc);
    cd.SetBranchAddress("Nu", &nuc);
    cd.SetBranchAddress("Pt2", &pt2c);
    cd.SetBranchAddress("Zh", &zhc);
    cd.SetBranchAddress("TargType", &ttc);
    //variables for acc root
    cc.SetBranchAddress("Q2", &qcc);
    cc.SetBranchAddress("Xb", &xbcc);
    cc.SetBranchAddress("Pt2", &pt2cc);

    TH1F *hdd = new TH1F("hd","Energy for +Pions, w>2  Q^{2}>1 mod X_{f}>0.1  X_{b}<1",100,0,2.7);
    TH1F *hcd = new TH1F("hmc"," ",100,0,2.7);


//C
    for (size_t irow=0; irow<cd.GetEntries(); ++irow){
        cd.GetEntry(irow);

         E=zhc*nuc;
      if(ttc==2){
 
         if (lc==211)
         {
            sr1c=sqrt(pc*pc-pt2c);
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
                        
                        hdd->Fill(E);
                    }
                }
            }
            
         }
      }
         }}}
    for (size_t irow=0; irow<cc.GetEntries(); ++irow){
        cc.GetEntry(irow);
        cd.GetEntry(irow);
         E=zhc*nuc;
               if(ttc==2){
 
         if (lc==211)
         {
            sr1cc=sqrt(pc*pc-pt2cc);
            sr2cc=sqrt((wc*wc-mn*mn+mppion*mppion)*(wc*wc-mn*mn+mppion*mppion)-4*wc*wc*mppion*mppion);
            sr3cc=sqrt(qcc*qcc+nuc*nuc);
            mxfcc=2*((nuc+mp)*(sr1cc-((sr3cc*zhc*nuc)/(nuc+mn))))/(sr2cc);
      if (mxfcc>0.1)
      {
            if (qcc>1)
         {
            if(qcc<4){
            if (wc>2)
            {
                if (xbcc<0.57)
                {
                    if(xbcc>0.12){
                    if (ybc<0.85)
                    {
                        
                        hcd->Fill(E);
                    }
                }
                }
            }
            }
         }
      }
   }
   }
    }
    hdd->Scale(1./hdd->Integral());
    hcd->Scale(1./hcd->Integral());

    TCanvas *c1 = new TCanvas("c1","c1",800,600);
    hdd->SetLineColor(kBlue);
    hcd->SetLineColor(kGreen); 
    hdd->GetYaxis()->SetTitle("Entries");
    hdd->GetXaxis()->SetTitle("Z_{h}*nu (GeV) ");
    hdd->Draw();
    hcd->Draw("SAME");
    TLegend* leg = new TLegend(0.6,0.7,0.9,0.9);
    leg->AddEntry(hdd,"no correction","l");
    leg->AddEntry(hcd,"acceptance corrected","l");
    leg->Draw("SAME");
    gStyle->SetOptStat(0);
    c1->SaveAs("binschemeACC_vs_noacc.pdf");
}
