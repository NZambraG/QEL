#include <TROOT.h>

void iftest()
{
    TChain c("ntuple_data");

    c.Add("/eos/user/n/nzambra/out/GetSimpleTuple_data/C/prunedC_*.root");


    float pzc,pc,mxfc,lc,qc,wc,xbc,ybc,ttc,nuc,pt2c,zhc;
    float mp,mn,mppion;
    float sr1c,sr2c,sr3c;
    float E;
    float dE;

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

    TH1F *hd = new TH1F("hd","Energy for +Pions, w>2  Q^{2}>1 mod X_{f}>0.1  X_{b}<1",100,0.5,2.7);
    TH1F *hmc = new TH1F("hmc"," ",100,0.5,2.7);

//C
    for (size_t irow=0; irow<c.GetEntries(); ++irow){
        c.GetEntry(irow);

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
                        
                        hd->Fill(E);
                    }
                }
            }
            
         }
      }
   }
   }
   }
    hd->Scale(1./hd->Integral());

//TH1F *hmc[101];
Double_t ks2=0;
for (int i = 10; i <= 20; i++){
//TString name = "hmc"+std::to_string(i);
dE=-0.001*i;
//hmc[i] = new TH1F(name, " ",100,1,2.7);


//modified D
    for (size_t irow=0; irow<c.GetEntries(); ++irow){
        c.GetEntry(irow);

         E=zhc*nuc+dE;
      if(ttc==1){
         if (lc==211)
         {
            
            sr1c=sqrt((pc+dE)*(pc+dE)-(1+(dE/pc))*(1+(dE/pc))*pt2c);
            sr2c=sqrt((wc*wc-mn*mn+mppion*mppion)*(wc*wc-mn*mn+mppion*mppion)-4*wc*wc*mppion*mppion);
            sr3c=sqrt(qc*qc+nuc*nuc);
            mxfc=2*((nuc+mp)*(sr1c-((sr3c*(zhc*nuc+dE))/(nuc+mn))))/(sr2c);
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
                        hmc->Fill(E);

                    }
                }
            }
            
         }
      }
   }
   }
   }
    hmc->Scale(1./hmc->Integral());
    ks2 = hd->KolmogorovTest(hmc);
   if (ks2<0.04)
{

        cout <<"energia =" << dE << "  ks=" << ks2 ;
        hmc->Reset("ICESM");
    }
    else{
        dE=-0.001*(i-1);
    for (size_t irow=0; irow<c.GetEntries(); ++irow){
        c.GetEntry(irow);

         E=zhc*nuc+dE;
      if(ttc==1){
         if (lc==211)
         {
            
            sr1c=sqrt((pc+dE)*(pc+dE)-(1+(dE/pc))*(1+(dE/pc))*pt2c);
            sr2c=sqrt((wc*wc-mn*mn+mppion*mppion)*(wc*wc-mn*mn+mppion*mppion)-4*wc*wc*mppion*mppion);
            sr3c=sqrt(qc*qc+nuc*nuc);
            mxfc=2*((nuc+mp)*(sr1c-((sr3c*(zhc*nuc+dE))/(nuc+mn))))/(sr2c);
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
                        hmc->Fill(E);

                    }
                }
            }
            
         }
      }
   }
   }
   }
        hmc->Scale(1./hmc->Integral());
        ks2 = hd->KolmogorovTest(hmc);
        cout <<"esta si que si=" << dE << "  ks=" << ks2 ;
        break;
    }
    }
    TCanvas *c1 = new TCanvas("c1","c1",800,600);
    hd->SetLineColor(kBlue);
    hmc->SetLineColor(kGreen); 
    hd->GetYaxis()->SetTitle("Entries");
    hd->GetXaxis()->SetTitle("Z_{h}*nu (GeV) ");
    hd->Draw();
    hmc->Draw("SAME");
    TLegend* leg = new TLegend(0.6,0.7,0.9,0.9);
    leg->AddEntry(hd,"C","l");
    leg->AddEntry(hmc,"mod D","l");
    leg->AddEntry(((TObject*)0), TString::Format("dE=  %g",dE), "");
    leg->AddEntry(((TObject*)0), TString::Format("KS mod %g",ks2), "");
    leg->Draw("SAME");
    gStyle->SetOptStat(0);
    c1->SaveAs("ifwork.pdf");
}
