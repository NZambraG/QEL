#include <TROOT.h>
void acc_PPion_no_zh_nu()
{
    TChain cd("ntuple_data");
    TChain cs("ntuple_sim");   
    cd.Add("/home/zambra/root_files/clusterdata/out/GetSimpleTuple_data/C/prunedC*.root");
    cs.Add("/home/zambra/root_files/clusterdata/out/GetSimpleTuple_HSim/C1/prunedC*.root");
    cs.Add("/home/zambra/root_files/clusterdata/out/GetSimpleTuple_HSim/C2/prunedC*.root");
    cs.Add("/home/zambra/root_files/clusterdata/out/GetSimpleTuple_HSim/C3/prunedC*.root"); 


    float pzcd,pcd,lcd,qcd,wcd,xbcd,ybcd,ttcd,nucd,pt2cd,zhcd,phipqcd;
    float pzcs,pcs,lcs,qcs,wcs,xbcs,ybcs,ttcs,nucs,pt2cs,zhcs,phipqcs;
    float mcpzcs,mcpcs,mclcs,mcqcs,mcwcs,mcxbcs,mcybcs,mcttcs,mcnucs,mcpt2cs,mczhcs,mcphipqcs;

    float PhiPQ,Zh,Q2,Xb,Pt2,Pz,P,pid,W,Yb,Nu,TargType;

    float lowerq2,higherq2;
    lowerq2=3.5;
    higherq2=4.0;

    TFile f("Acc_C_PPion_q2_5.root", "RECREATE");
    TTree t0("Xb_0","Xb_0");
    t0.Branch("PhiPQ",&PhiPQ,"PhiPQ/F");
    t0.Branch("Zh",&Zh,"Zh/F");
    t0.Branch("Q2",&Q2,"Q2/F");
    t0.Branch("Xb",&Xb,"Xb/F");
    t0.Branch("Pt2",&Pt2,"Pt2/F");
    t0.Branch("Pz",&Pz,"Pz/F");
    t0.Branch("P",&P,"P/F");
    t0.Branch("pid",&pid,"pid/F");
    t0.Branch("W",&W,"W/F");
    t0.Branch("Yb",&Yb,"Yb/F");
    t0.Branch("Nu",&Nu,"Nu/F");
    t0.Branch("TargType",&TargType,"TargType/F");

    TTree t1("Xb_1","Xb_1");
    t1.Branch("PhiPQ",&PhiPQ,"PhiPQ/F");
    t1.Branch("Zh",&Zh,"Zh/F");
    t1.Branch("Q2",&Q2,"Q2/F");
    t1.Branch("Xb",&Xb,"Xb/F");
    t1.Branch("Pt2",&Pt2,"Pt2/F");
    t1.Branch("Pz",&Pz,"Pz/F");
    t1.Branch("P",&P,"P/F");
    t1.Branch("pid",&pid,"pid/F");
    t1.Branch("W",&W,"W/F");
    t1.Branch("Yb",&Yb,"Yb/F");
    t1.Branch("Nu",&Nu,"Nu/F");
    t1.Branch("TargType",&TargType,"TargType/F");

    TTree t2("Xb_2","Xb_2");
    t2.Branch("PhiPQ",&PhiPQ,"PhiPQ/F");
    t2.Branch("Zh",&Zh,"Zh/F");
    t2.Branch("Q2",&Q2,"Q2/F");
    t2.Branch("Xb",&Xb,"Xb/F");
    t2.Branch("Pt2",&Pt2,"Pt2/F");
    t2.Branch("Pz",&Pz,"Pz/F");
    t2.Branch("P",&P,"P/F");
    t2.Branch("pid",&pid,"pid/F");
    t2.Branch("W",&W,"W/F");
    t2.Branch("Yb",&Yb,"Yb/F");
    t2.Branch("Nu",&Nu,"Nu/F");
    t2.Branch("TargType",&TargType,"TargType/F");
    

    TTree t3("Xb_3","Xb_3");
    t3.Branch("PhiPQ",&PhiPQ,"PhiPQ/F");
    t3.Branch("Zh",&Zh,"Zh/F");
    t3.Branch("Q2",&Q2,"Q2/F");
    t3.Branch("Xb",&Xb,"Xb/F");
    t3.Branch("Pt2",&Pt2,"Pt2/F");
    t3.Branch("Pz",&Pz,"Pz/F");
    t3.Branch("P",&P,"P/F");
    t3.Branch("pid",&pid,"pid/F");
    t3.Branch("W",&W,"W/F");
    t3.Branch("Yb",&Yb,"Yb/F");
    t3.Branch("Nu",&Nu,"Nu/F");
    t3.Branch("TargType",&TargType,"TargType/F");

    TTree t4("Xb_4","Xb_4");
    t4.Branch("PhiPQ",&PhiPQ,"PhiPQ/F");
    t4.Branch("Zh",&Zh,"Zh/F");
    t4.Branch("Q2",&Q2,"Q2/F");
    t4.Branch("Xb",&Xb,"Xb/F");
    t4.Branch("Pt2",&Pt2,"Pt2/F");
    t4.Branch("Pz",&Pz,"Pz/F");
    t4.Branch("P",&P,"P/F");
    t4.Branch("pid",&pid,"pid/F");
    t4.Branch("W",&W,"W/F");
    t4.Branch("Yb",&Yb,"Yb/F");
    t4.Branch("Nu",&Nu,"Nu/F");
    t4.Branch("TargType",&TargType,"TargType/F");

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

float pesoq20,pesoq21,pesoq22,pesoq23,pesoq24;
float pesoxb0,pesoxb1,pesoxb2,pesoxb3,pesoxb4;
float pesopt20,pesopt21,pesopt22,pesopt23,pesopt24;
float pesophi0,pesophi1,pesophi2,pesophi3,pesophi4;



    for (size_t irow=0; irow<cs.GetEntries(); ++irow){
        cs.GetEntry(irow);
        if(lcs==211){
        if(qcs>lowerq2){
        if(qcs<higherq2){
        if(mcqcs>lowerq2){
        if(mcqcs<higherq2){
        if(xbcs>0.12){
        if(xbcs<0.21){
        if(mcxbcs>0.12){
        if(mcxbcs<0.21){
                pesophi0=phipqcs/mcphipqcs;
                pesoq20=qcs/mcqcs;
                pesoxb0=xbcs/mcxbcs;
                pesopt20=pt2cs/mcpt2cs;

    }}}}
        if(xbcs>0.21){
        if(xbcs<0.3){
        if(mcxbcs>0.21){
        if(mcxbcs<0.3){
                pesophi1=phipqcs/mcphipqcs;
                pesoq21=qcs/mcqcs;
                pesoxb1=xbcs/mcxbcs;
                pesopt21=pt2cs/mcpt2cs;
    }}}}
        if(xbcs>0.3){
        if(xbcs<0.39){
        if(mcxbcs>0.3){
        if(mcxbcs<0.39){
                pesophi2=phipqcs/mcphipqcs;
                pesoq22=qcs/mcqcs;
                pesoxb2=xbcs/mcxbcs;
                pesopt22=pt2cs/mcpt2cs;
    }}}}
        if(xbcs>0.39){
        if(xbcs<0.48){
        if(mcxbcs>0.39){
        if(mcxbcs<0.48){
                pesophi3=phipqcs/mcphipqcs;
                pesoq23=qcs/mcqcs;
                pesoxb3=xbcs/mcxbcs;
                pesopt23=pt2cs/mcpt2cs;
    }}}}
        if(xbcs>0.48){
        if(xbcs<0.57){
        if(mcxbcs>0.48){
        if(mcxbcs<0.57){
                pesophi4=phipqcs/mcphipqcs;
                pesoq24=qcs/mcqcs;
                pesoxb4=xbcs/mcxbcs;
                pesopt24=pt2cs/mcpt2cs;
    }}}}
    }}}}}}
    for (size_t irow=0; irow<cd.GetEntries(); ++irow){
        cd.GetEntry(irow);
        if(lcd==211){
        if(qcd>lowerq2){
        if(qcd<higherq2){
        if(xbcd>0.12){
        if(xbcd<0.21){
            PhiPQ=phipqcd/pesophi0;
            Q2=qcd/pesoq20;
            Xb=xbcd/pesoxb0;
            Pt2=pt2cd/pesopt20;
            Zh=zhcd;
            Nu=nucd;
            Pz=pzcd;
            P=pcd;
            W=wcd;
            Yb=ybcd;
            TargType=ttcd;
            t0.Fill();
    }}
    if(xbcd>0.21){
        if(xbcd<0.3){
            PhiPQ=phipqcd/pesophi1;
            Q2=qcd/pesoq21;
            Xb=xbcd/pesoxb1;
            Pt2=pt2cd/pesopt21;
            Zh=zhcd;
            Nu=nucd;
            Pz=pzcd;
            P=pcd;
            W=wcd;
            Yb=ybcd;
            TargType=ttcd;
            t1.Fill();
    }}
    if(xbcd>0.3){
        if(xbcd<0.39){
            PhiPQ=phipqcd/pesophi2;
            Q2=qcd/pesoq22;
            Xb=xbcd/pesoxb2;
            Pt2=pt2cd/pesopt22;
            Zh=zhcd;
            Nu=nucd;
            Pz=pzcd;
            P=pcd;
            W=wcd;
            Yb=ybcd;
            TargType=ttcd;
            t2.Fill();
    }}
    if(xbcd>0.39){
        if(xbcd<0.48){
            PhiPQ=phipqcd/pesophi3;
            Q2=qcd/pesoq23;
            Xb=xbcd/pesoxb3;
            Pt2=pt2cd/pesopt23;
            Zh=zhcd;
            Nu=nucd;
            Pz=pzcd;
            P=pcd;
            W=wcd;
            Yb=ybcd;
            TargType=ttcd;
            t3.Fill();
    }}
    if(xbcd>0.48){
        if(xbcd<0.57){
            PhiPQ=phipqcd/pesophi4;
            Q2=qcd/pesoq24;
            Xb=xbcd/pesoxb4;
            Pt2=pt2cd/pesopt24;
            Zh=zhcd;
            Nu=nucd;
            Pz=pzcd;
            P=pcd;
            W=wcd;
            Yb=ybcd;
            TargType=ttcd;
            t4.Fill();
    }}
    }}}}
    cout <<"     "<< "Q2"<<"  "<<"Xb"<<"  "<<"PhiPQ"<<"  "<<"Pt2"<<"\n";
    cout <<"     "<<pesoq20<<"  "<<pesoxb0<<"  "<<pesophi0<<"  "<<pesopt20<<"  "<<"\n";
    cout <<"     "<<pesoq21<<"  "<<pesoxb1<<"  "<<pesophi1<<"  "<<pesopt21<<"  "<<"\n";
    cout <<"     "<<pesoq22<<"  "<<pesoxb2<<"  "<<pesophi2<<"  "<<pesopt22<<"  "<<"\n";
    cout <<"     "<<pesoq23<<"  "<<pesoxb3<<"  "<<pesophi3<<"  "<<pesopt23<<"  "<<"\n";
    cout <<"     "<<pesoq24<<"  "<<pesoxb4<<"  "<<pesophi4<<"  "<<pesopt24<<"  "<<"\n";
    t0.Write();
    t1.Write();
    t2.Write();
    t3.Write();
    t4.Write();
}