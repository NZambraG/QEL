#include <TROOT.h>

void plots_for_ppt()
{
    //TChain c("Xb_0");
    //c.Add("/home/zambra/root_files/local_codes/fast_acc.root");

        TChain c("ntuple_data");
    c.Add("/home/zambra/root_files/clusterdata/out/GetSimpleTuple_data/C/prunedC_4210*.root");

    float pzc,pxc,pyc,pc,mxfc,lc,qc,wc,xbc,ybc,ttc,nuc,pt2c,zhc,nphed,phipqd,tscd,philabd,thetalabd,thetapqd;
    float mp,mn,mppion;
    float sr1c,sr2c,sr3c;
    float sr1cd,sr2cd,sr3cd,mxfcd;
    float E,E1;
    float dE;

    mp=0.938;
    mn=0.938;
    mppion=0.139;
    c.SetBranchAddress("PhiLab", &philabd);
    c.SetBranchAddress("ThetaLab", &thetalabd);
    c.SetBranchAddress("ThetaPQ", &thetapqd);
    c.SetBranchAddress("TimeECEl", &tscd);
    c.SetBranchAddress("Nphe",&nphed);
    c.SetBranchAddress("Pz", &pzc);
    c.SetBranchAddress("Px", &pxc);
    c.SetBranchAddress("Py", &pyc);
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
    c.SetBranchAddress("PhiPQ",&phipqd);
    float lowerrange;
    lowerrange=0;

    TH1F *hd = new TH1F("hd","Energy for #pi^{+}, W>2  Q^{2}<4 mod X_{f}>0.1  X_{b}<0.56",100,-190,190);
    TH1F *hcomp = new TH1F("hd"," ",100,-190,190);
    TH1F *hn = new TH1F("hd"," ",100,-190,190);
    //TH2F *hd = new TH2F("hd","X_{f} vs #Phi_{PQ}",100,-200,200,100,0,300);
float k;
//no selected target, only positive pions
    for (size_t irow=0; irow<c.GetEntries(); ++irow){
        c.GetEntry(irow);

         E=zhc*nuc;
      //if(ttc==1){
        if(lc==211){
            //if(nphed>=25){
            if (qc>1 & qc<4.0)
         {
                if(nuc>2.2){
                    if(nuc<4.2){
            if (wc>2)
            {
                if (xbc>0.12 & xbc<0.56)
                {
                    if (ybc<0.85)
                    {
            sr1c=sqrt(pc*pc-pt2c);
            sr2c=sqrt((wc*wc-mn*mn+mppion*mppion)*(wc*wc-mn*mn+mppion*mppion)-4*wc*wc*mppion*mppion);
            sr3c=sqrt(qc*qc+nuc*nuc);
            mxfc=2*((nuc+mp)*(sr1c-((sr3c*zhc*nuc)/(nuc+mn))))/(sr2c);
            k=(sqrt(pxc*pxc+pyc*pyc))/pc;
            hcomp->Fill(phipqd);
            if(nphed>=25){hn->Fill(phipqd);}
            if(thetapqd/k>70){
                        //hd->Fill(phipqd,nphed*k);
                        hd->Fill(phipqd);
            } 
                }  
            }
            }
         }
      }
   }
   }
   }


 
    hd->GetYaxis()->SetTitle("X_F");
    hd->GetXaxis()->SetTitle("#Phi_{PQ}");
        hd->SetLineColor(kBlue);
    hcomp->SetLineColor(kRed);
    hn->SetLineColor(kGreen);
    hd->Draw("Colz");
    hcomp->Draw("SAME");
    hn->Draw("SAME");

    //gStyle->SetOptStat(0);
    //c1->SaveAs("prao_no_norm.pdf");

    }


