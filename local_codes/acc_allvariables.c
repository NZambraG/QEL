#include <TROOT.h>
void acc_allvariables()
{
    TChain cd("ntuple_data");
    TChain cs("ntuple_sim");   
    cd.Add("/home/zambra/root_files/clusterdata/out/GetSimpleTuple_data/C/prunedC*.root");
    cs.Add("/home/zambra/root_files/clusterdata/out/GetSimpleTuple_HSim/C*/prunedC*.root");
    
    float pzcd,pcd,lcd,qcd,wcd,xbcd,ybcd,ttcd,nucd,pt2cd,zhcd,phipqcd;
    float pzcs,pcs,lcs,qcs,wcs,xbcs,ybcs,ttcs,nucs,pt2cs,zhcs,phipqcs;
    float mcpzcs,mcpcs,mclcs,mcqcs,mcwcs,mcxbcs,mcybcs,mcttcs,mcnucs,mcpt2cs,mczhcs,mcphipqcs;


    float PhiPQ,Zh,Q2,Xb,Pt2,Pz,P,pid,W,Yb,Nu,TargType;
    TFile f("Acc_C_PPion.root", "RECREATE");
    TTree t0("data","data");
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

float pesonu0;
float pesoq20;
float pesoxb0;
float pesopt20;
float pesophi0;
float pesozh0;

float lowerphi,higherphi;
lowerphi=-180;
higherphi=-150;

    for (size_t irow=0; irow<cs.GetEntries(); ++irow){
        cs.GetEntry(irow);
        if(lcs==211){
        if(phipqcs>lowerphi){
        if(phipqcs<higherphi){
        if(mcphipqcs>lowerphi){
        if(mcphipqcs<higherphi){
        if(mczhcs>0.0){
        if(mczhcs<1.0){
        if(zhcs>0.0){
            if(zhcs<1.0){
                pesozh0=zhcs/mczhcs;
                pesophi0=phipqcs/mcphipqcs;
                pesoq20=qcs/mcqcs;
                pesoxb0=xbcs/mcxbcs;
                pesopt20=pt2cs/mcpt2cs;
                pesonu0=nucs/mcnucs;
    }}}}}}}}}}
    for (size_t irow=0; irow<cd.GetEntries(); ++irow){
        cd.GetEntry(irow);
                if(phipqcd>lowerphi){
                    if(phipqcd<higherphi){
                if(zhcd>0){
            if(zhcd<1){
            Zh=zhcd/pesozh0;
            PhiPQ=phipqcd/pesophi0;
            Q2=qcd/pesoq20;
            Xb=xbcd/pesoxb0;
            Pt2=pt2cd/pesopt20;
            Nu=nucd/pesonu0;
            Pz=pzcd;
            P=pcd;
            pid=lcd;
            W=wcd;
            Yb=ybcd;
            TargType=ttcd;
            t0.Fill();
    }}}}}
                        
    cout <<"     "<< "PhiPQ"<<"  "<<"Zh"<<"  "<<"Nu"<<"  "<<"Q2"<<"  "<<"Xb"<<"  "<<"Pt2"<<"  "<<"\n";
    cout <<"     " << pesophi0 << "  " << pesozh0 << "  " << pesonu0 << "  "<< pesoq20 << "  "<< pesoxb0 << "  "<< pesopt20 << "  "<<"\n";

    t0.Write();
}