#include <TROOT.h>

void ELoss_Acc()
{
    TChain *c = new TChain();
    c->Add("/home/zambra/root_files/local_codes/Acc_C_PPion_q2_*.root/Xb_0");
    c->Add("/home/zambra/root_files/local_codes/Acc_C_PPion_q2_*.root/Xb_1");
    c->Add("/home/zambra/root_files/local_codes/Acc_C_PPion_q2_*.root/Xb_2");
    c->Add("/home/zambra/root_files/local_codes/Acc_C_PPion_q2_*.root/Xb_3");
    c->Add("/home/zambra/root_files/local_codes/Acc_C_PPion_q2_*.root/Xb_4");
    //c->Add("/home/zambra/root_files/local_codes/Acc_C_PPions_phi_*.root/Zh0");
//    c->Add("/home/zambra/root_files/local_codes/Acc_C_PPions_phi_*.root/Zh1");
  //  c->Add("/home/zambra/root_files/local_codes/Acc_C_PPions_phi_*.root/Zh2");
    //c->Add("/home/zambra/root_files/local_codes/Acc_C_PPions_phi_*.root/Zh3");
//    c->Add("/home/zambra/root_files/local_codes/Acc_C_PPions_phi_*.root/Zh4");
  //  c->Add("/home/zambra/root_files/local_codes/Acc_C_PPions_phi_*.root/Zh5");
    //c->Add("/home/zambra/root_files/local_codes/Acc_C_PPions_phi_*.root/Zh6");
//    c->Add("/home/zambra/root_files/local_codes/Acc_C_PPions_phi_*.root/Zh7");
  //  c->Add("/home/zambra/root_files/local_codes/Acc_C_PPions_phi_*.root/Zh8");
    //c->Add("/home/zambra/root_files/local_codes/Acc_C_PPions_phi_*.root/Zh9");

      

    float pzc,pc,mxfc,lc,qc,wc,xbc,ybc,ttc,nuc,pt2c,zhc;
    float mp,mn,mppion;
    float sr1c,sr2c,sr3c;
    float E;
    float dE;

    mp=0.938;
    mn=0.938;
    mppion=0.139;
    
    c->SetBranchAddress("Pz", &pzc);
    c->SetBranchAddress("P", &pc);
    //c->SetBranchAddress("pid", &lc);
    c->SetBranchAddress("Q2", &qc);
    c->SetBranchAddress("W", &wc);
    c->SetBranchAddress("Xb", &xbc);
    c->SetBranchAddress("Yb", &ybc);
    c->SetBranchAddress("Nu", &nuc);
    c->SetBranchAddress("Pt2", &pt2c);
    c->SetBranchAddress("Zh", &zhc);
    c->SetBranchAddress("TargType", &ttc);

    float lowerrange;
    lowerrange=1;

    TH1F *hd = new TH1F("hd","Energy for +Pions, w>2  Q^{2}>1 mod X_{f}>0.1  X_{b}<1",100,lowerrange,2.7);
    TH1F *hmc = new TH1F("hmc"," ",100,lowerrange,2.7);

//D
    for (size_t irow=0; irow<c->GetEntries(); ++irow){
        c->GetEntry(irow);
         E=zhc*nuc;
               if(ttc==2){
 
         //if (lc==211)
         
            sr1c=sqrt(pc*pc-pt2c);
            sr2c=sqrt((wc*wc-mn*mn+mppion*mppion)*(wc*wc-mn*mn+mppion*mppion)-4*wc*wc*mppion*mppion);
            sr3c=sqrt(qc*qc+nuc*nuc);
            mxfc=2*((nuc+mp)*(sr1c-((sr3c*zhc*nuc)/(nuc+mn))))/(sr2c);
      if (mxfc>0.1)
      {
            if (qc>1)
         {
            if(qc<4){
            if (wc>2)
            {
                if (xbc<0.57)
                {
                    if(xbc>0.12){
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
   }
    
    hd->Scale(1./hd->Integral());

//TH1F *hmc[101];
Double_t ks2=0;
for (int i = 16; i <= 20; i++){
//TString name = "hmc"+std::to_string(i);
dE=-0.001*i;
//hmc[i] = new TH1F(name, " ",100,1,2.7);
//modified D
    for (size_t irow=0; irow<c->GetEntries(); ++irow){
        c->GetEntry(irow);
         E=zhc*nuc+dE;
      if(ttc==1){
         //if (lc==211)
         
            
                        sr1c=sqrt((pc+dE)*(pc+dE)-(1+(dE/pc))*(1+(dE/pc))*pt2c);
                        sr2c=sqrt((wc*wc-mn*mn+mppion*mppion)*(wc*wc-mn*mn+mppion*mppion)-4*wc*wc*mppion*mppion);
                        sr3c=sqrt(qc*qc+nuc*nuc);
                        mxfc=2*((nuc+mp)*(sr1c-((sr3c*(zhc*nuc+dE))/(nuc+mn))))/(sr2c);
                    if(mxfc>0.1){

            if (qc>1)
         {
            if(qc<4){
            if (wc>2)
            {
                if (xbc<0.57)
                {
                    if(xbc>0.12){
                    if (ybc<0.85){


                        hmc->Fill(E);

                                }
                            }
                        }
                    }
                }
            }
        }
    }
    }
    
            hmc->Scale(1./hmc->Integral());
        ks2 = hmc->KolmogorovTest(hd);
            cout  << dE << " GeV    ks=" << ks2 <<"\n";
                    hmc->Reset("ICESM");
    }




    }
