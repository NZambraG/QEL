#include <TROOT.h>
void plotP_allcuts_C_Fe_Pb()
{
    TChain c("ntuple_data");
    TChain fe("ntuple_data");
    TChain pb("ntuple_data");

    c.Add("/eos/user/n/nzambra/out/GetSimpleTuple_data/C/prunedC_*.root");
    fe.Add("/eos/user/n/nzambra/out/GetSimpleTuple_data/Fe/prunedFe_*.root");
    pb.Add("/eos/user/n/nzambra/out/GetSimpleTuple_data/Pb/prunedPb_*.root");

    float x,y,k,l,q,w,xb,tt;
    float xf,yf,kf,lf,qf,wf,xbf,ttf;
    float xp,yp,kp,lp,qp,wp,xbp,ttp;

    c.SetBranchAddress("Pz", &x);
    c.SetBranchAddress("P", &y);
    c.SetBranchAddress("pid", &l);
    c.SetBranchAddress("Q2", &q);
    c.SetBranchAddress("W", &w);
    c.SetBranchAddress("Xb", &xb);
    c.SetBranchAddress("TargType", &tt);

    fe.SetBranchAddress("Pz", &xf);
    fe.SetBranchAddress("P", &yf);
    fe.SetBranchAddress("pid", &lf);
    fe.SetBranchAddress("Q2", &qf);
    fe.SetBranchAddress("W", &wf);
    fe.SetBranchAddress("Xb", &xbf);
    fe.SetBranchAddress("TargType", &ttf);

    pb.SetBranchAddress("Pz", &xp);
    pb.SetBranchAddress("P", &yp);
    pb.SetBranchAddress("pid", &lp);
    pb.SetBranchAddress("Q2", &qp);
    pb.SetBranchAddress("W", &wp);
    pb.SetBranchAddress("Xb", &xbp);
    pb.SetBranchAddress("TargType", &ttp);

    TH1F *hc = new TH1F("hc","P for +Pions, w>2  Q^{2}>1 X_{f}>0.1 X_{b}<1",1000,0,2);
    TH1F *hfe = new TH1F("hfe","P for +Pions, w>2  Q^{2}>1 X_{f}>0.1 X_{b}<1",1000,0,2);
    TH1F *hpb = new TH1F("hpb","P for +Pions, w>2  Q^{2}>1 X_{f}>0.1 X_{b}<1",1000,0,2);

    for (size_t irow=0; irow<c.GetEntries(); ++irow){
       c.GetEntry(irow);

       k=x/y;
        if (k>0.1)
        {
            if (tt==2)
            {
                if (l==211)
                {
                    if (q>1)
                    {
                        if (w>2)
                        {
                           if (xb<1)   
                           {
                                hc->Fill(y);
                           }

                        }

                    }      
                }
            }
        }
    }

    for (size_t irow=0; irow<fe.GetEntries(); ++irow){
       fe.GetEntry(irow);

       kf=xf/yf;
       if (kf>0.1)
       {
        if(ttf==2)
        {
            if (lf==211)
            {
                if (qf>1)
                {
                    if (wf>2)
                    {
                        if (xbf<1)
                        {
                            hfe->Fill(yf);
                        }

                    }
            
                }      
            }
        }
   }
    }

    for (size_t irow=0; irow<pb.GetEntries(); ++irow){
       pb.GetEntry(irow);

       kp=xp/yp;
       if (kp>0.1)
       {
        if(ttp==2)
        {
            if (lp==211)
            {
                if (qp>1)
                {
                    if (wp>2)
                    {
                        if (xbp<1)
                        {
                            hpb->Fill(yp);
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
    hc->GetXaxis()->SetTitle("P (GeV) ");

    hc->Draw();
    hfe->Draw("SAME");
    hpb->Draw("SAME");

    TLegend* leg = new TLegend(0.6,0.7,0.9,0.9);
    leg->AddEntry(hc,"C","l");
    leg->AddEntry(hfe,"Fe","l");
    leg->AddEntry(hpb,"Pb","l");
    leg->Draw("SAME");
    gStyle->SetOptStat(0);
    c1->SaveAs("P_Pion_C_Fe_Pb_norm_cuts_q_w_xf_xb_tt_bin1000.pdf");
 
}
