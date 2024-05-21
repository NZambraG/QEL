#include <TROOT.h>
void Energy_Pion_Extracted_D()
{
    TChain c("ntuple_data");
    TChain fe("ntuple_data");
    TChain pb("ntuple_data");

    c.Add("/eos/user/n/nzambra/out/GetSimpleTuple_data/C/prunedC_*.root");
    fe.Add("/eos/user/n/nzambra/out/GetSimpleTuple_data/Fe/prunedFe_*.root");
    pb.Add("/eos/user/n/nzambra/out/GetSimpleTuple_data/Pb/prunedPb_*.root");

    float pzc,pc,mxfc,lc,qc,wc,xbc,ybc,ttc,nuc,pt2c,zhc;
    float pzf,pf,mxff,lf,qf,wf,xbf,ybf,ttf,nuf,pt2f,zhf;
    float pzp,pp,mxfp,lp,qp,wp,xbp,ybp,ttp,nup,pt2p,zhp;

    float mp,mn,mppion;
    mp=0.938;
    mn=0.938;
    mppion=0.139;
    float sr1c,sr2c,sr3c;
    float sr1f,sr2f,sr3f;
    float sr1p,sr2p,sr3p;


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

    fe.SetBranchAddress("Pz", &pzf);
    fe.SetBranchAddress("P", &pf);
    fe.SetBranchAddress("pid", &lf);
    fe.SetBranchAddress("Q2", &qf);
    fe.SetBranchAddress("W", &wf);
    fe.SetBranchAddress("Xb", &xbf);
    fe.SetBranchAddress("Yb", &ybf);
    fe.SetBranchAddress("Nu", &nuf);
    fe.SetBranchAddress("Pt2", &pt2f);
    fe.SetBranchAddress("Zh", &zhf);
    fe.SetBranchAddress("TargType", &ttf);
    
    pb.SetBranchAddress("Pz", &pzp);
    pb.SetBranchAddress("P", &pp);
    pb.SetBranchAddress("pid", &lp);
    pb.SetBranchAddress("Q2", &qp);
    pb.SetBranchAddress("W", &wp);
    pb.SetBranchAddress("Xb", &xbp);
    pb.SetBranchAddress("Yb", &ybp);
    pb.SetBranchAddress("Nu", &nup);
    pb.SetBranchAddress("Pt2", &pt2p);
    pb.SetBranchAddress("Zh", &zhp);
    pb.SetBranchAddress("TargType", &ttp);

    TH1F *hc = new TH1F("hd","Energy for Pion^{+} using D reconstructed from every material data  , w>2  Q^{2}>1 mod X_{f}>0.1  X_{b}<1",100,0,2);
    TH1F *hfe = new TH1F("hfe"," ",100,0,2);
    TH1F *hpb = new TH1F("hpb"," ",100,0,2);
//D from C
    for (size_t irow=0; irow<c.GetEntries(); ++irow){
        c.GetEntry(irow);

     
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
                        hc->Fill(pc);
                    }
                }
            }
            
         }
      }
   }
   }
   }
//D from Fe
     for (size_t irow=0; irow<fe.GetEntries(); ++irow){
        fe.GetEntry(irow);

     
      if(ttf==1){
 
         if (lf==211)
         {
            sr1f=sqrt(pf*pf-pt2f*pt2f);
            sr2f=sqrt((wf*wf-mn*mn+mppion*mppion)*(wf*wf-mn*mn+mppion*mppion)-4*wf*wf*mppion*mppion);
            sr3f=sqrt(qf*qf+nuf*nuf);
            mxff=2*((nuf+mp)*(sr1f-((sr3f*zhf*nuf)/(nuf+mn))))/(sr2f);
      if (mxff>0.1)
      {
            if (qf>1)
         {
            if (wf>2)
            {
                if (xbf<1)
                {
                    if (ybf<0.85)
                    {
                        hfe->Fill(pf);
                    }
                }
            }
            
         }
      }
   }
   }
   //D from Pb
   }    for (size_t irow=0; irow<pb.GetEntries(); ++irow){
        pb.GetEntry(irow);

     
      if(ttp==1){
 
         if (lp==211)
         {
            sr1p=sqrt(pp*pp-pt2p*pt2p);
            sr2p=sqrt((wp*wp-mn*mn+mppion*mppion)*(wp*wp-mn*mn+mppion*mppion)-4*wp*wp*mppion*mppion);
            sr3p=sqrt(qp*qp+nup*nup);
            mxfp=2*((nup+mp)*(sr1p-((sr3p*zhp*nup)/(nup+mn))))/(sr2p);
      if (mxfp>0.1)
      {
            if (qp>1)
         {
            if (wp>2)
            {
                if (xbp<1)
                {
                    if (ybp<0.85)
                    {
                        hpb->Fill(pp);
                    }
                }
            }
            
         }
      }
   }
   }
   }
    TCanvas *c1 = new TCanvas("c1","c1",800,600);
    hc->SetLineColor(kBlue);
    hfe->SetLineColor(kRed);
    hpb->SetLineColor(kGreen);   

    hc->Scale(1./hc->Integral());
    hfe->Scale(1./hfe->Integral());
    hpb->Scale(1./hpb->Integral());

    hc->GetYaxis()->SetTitle("Entries");
    hc->GetXaxis()->SetTitle("Z_{h}\nu (GeV) ");

    hc->Draw("");
    hfe->Draw("SAME");
    hpb->Draw("SAME");

    TLegend* leg = new TLegend(0.6,0.7,0.9,0.9);
    leg->AddEntry(hc,"C","l");
    leg->AddEntry(hfe,"Fe","l");
    leg->AddEntry(hpb,"Pb","l");

    leg->Draw("SAME");
    gStyle->SetOptStat(0);
    c1->SaveAs("P_Pion_D_from_C_Fe_Pb_norm_CFR_100bin_mxf01.pdf");
 
}
