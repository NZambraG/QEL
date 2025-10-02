#include <TROOT.h>
void proposed_cut()
{
    TChain cd("data");   
    cd.Add("/home/zambra/root_files/local_codes/nphe_analysis/Nphe_structure_for_cuts.root");

    float phipqd,philabd,thetalabd,thetapqd,nphed,timescd,timesceld,timeecd,timeeceld,ttd,pidd,pd,pzd;
    float phipqs,philabs,thetalabs,thetapqs,nphes,timescs,timescels,timeecs,timeecels,tts,pids,ps,pzs;

    
    cd.SetBranchAddress("PhiPQ",&phipqd);
    //cd.SetBranchAddress("PhiLab", &philabd);
    //cd.SetBranchAddress("ThetaLab", &thetalabd);
    //cd.SetBranchAddress("ThetaPQ", &thetapqd);
    cd.SetBranchAddress("Nphe", &nphed);
    //cd.SetBranchAddress("TimeSC", &timescd);
    //cd.SetBranchAddress("TimeSCEl", &timesceld);
    //cd.SetBranchAddress("TimeEC", &timeecd);
    //cd.SetBranchAddress("TimeECEl", &timeeceld);
    //cd.SetBranchAddress("TargType", &ttd);
    cd.SetBranchAddress("pid", &pidd);
    cd.SetBranchAddress("P",&pd);
    cd.SetBranchAddress("Pz",&pzd);
    
float ppqlr; //phipq lower and higher value

ppqlr=200;
float x,y;

    //TH2F *hd = new TH2F("hd"," phiPQ vs nphe electron",100,-ppqlr,ppqlr,100,0,300);    
    TH1F *hd = new TH1F("hd"," phiPQ vs nphe electron",100,-200,200);    


    for (size_t irow=0; irow<cd.GetEntries(); ++irow){
    cd.GetEntry(irow);
    //if(pidd==211){
        x=phipqd;
        y=nphed;
        if(y>0 ){
        if(  y<0.0375*x*x+20){
    //hd->Fill(phipqd,nphed);
    hd->Fill(phipqd);  
           }}}

        TCanvas *c1 = new TCanvas("c1","c1",800,600);
    hd->Draw("Colz");
    
     //c1->SaveAs("PHIpq_vs_nphe_electron_gamma.pdf");
}