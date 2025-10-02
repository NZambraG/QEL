#include <TROOT.h>
void nphi_study()
{
    TChain cs("sim");
    TChain cd("ntuple_data");   
    cd.Add("/home/zambra/root_files/clusterdata/out/GetSimpleTuple_data/C/prunedC_4210*.root");
    //cs.Add("/home/zambra/root_files/local_codes/nphe_analysis/Nphe_structure_for_cuts.root");

    float phipqd,philabd,thetalabd,thetapqd,nphed,timescd,timesceld,timeecd,timeeceld,ttd,pidd,pd,pzd,eind,eoutd,etotd,pathecd,pathscd,xec,yec,zec,ccstatusd,scstatusd,dcstatusd;
    float phipqs,philabs,thetalabs,thetapqs,nphes,timescs,timescels,timeecs,timeecels,tts,pids,ps,pzs;

    
    cd.SetBranchAddress("PhiPQ",&phipqd);
    cd.SetBranchAddress("PhiLab", &philabd);
    cd.SetBranchAddress("ThetaLab", &thetalabd);
    cd.SetBranchAddress("ThetaPQ", &thetapqd);
    cd.SetBranchAddress("Nphe", &nphed);
    cd.SetBranchAddress("TimeSC", &timescd);
    cd.SetBranchAddress("TimeSCEl", &timesceld);
    cd.SetBranchAddress("TimeEC", &timeecd);
    cd.SetBranchAddress("TimeECEl", &timeeceld);
    cd.SetBranchAddress("TargType", &ttd);
    cd.SetBranchAddress("pid", &pidd);
    cd.SetBranchAddress("P",&pd);
    cd.SetBranchAddress("Pz",&pzd);
    cd.SetBranchAddress("Ein",&eind);
    cd.SetBranchAddress("Eout",&eoutd);
    cd.SetBranchAddress("Etot",&etotd);
    cd.SetBranchAddress("PathEC",&pathecd);
    cd.SetBranchAddress("PathSC",&pathscd);
    cd.SetBranchAddress("XEC",&xec);
    cd.SetBranchAddress("YEC",&yec);
    cd.SetBranchAddress("ZEC",&zec);
    cd.SetBranchAddress("CCStatus",&ccstatusd);
    cd.SetBranchAddress("SCStatus",&scstatusd);
    cd.SetBranchAddress("DCStatus",&dcstatusd);

   //cs.SetBranchAddress("PhiPQ",&phipqs);
    //cs.SetBranchAddress("PhiLab", &philabs);
    //cs.SetBranchAddress("ThetaLab", &thetalabs);
    //cs.SetBranchAddress("ThetaPQ", &thetapqs);
    //cs.SetBranchAddress("NpheEl", &nphes);
    //cs.SetBranchAddress("TimeSC", &timescs);
    //cs.SetBranchAddress("TimeSCEl", &timescels);
    //cs.SetBranchAddress("TimeEC", &timeecs);
    //cs.SetBranchAddress("TimeECEl", &timeecels);
    //cs.SetBranchAddress("TargType", &tts);
    //cs.SetBranchAddress("pid", &pids);
    //cs.SetBranchAddress("P",&ps);
    //cs.SetBranchAddress("Pz",&pzs);

float ppqlr; //phipq lower and higher value
ppqlr=180;
    //TH2F *hd = new TH2F("hd"," phiPQ vs nphe with electron identification",100,-ppqlr,ppqlr,100,0,300);    
    //TH2F *hd2 = new TH2F("hd"," phiPQ vs nphe electron",100,-ppqlr,ppqlr,100,0,300);   
    TH1F *hd = new TH1F("hd"," phiPQ with electron identification for pi+",100,-ppqlr,ppqlr);    
    TH1F *hd2 = new TH1F("hd2"," phiPQ vs nphe electron",100,-ppqlr,ppqlr);   
    for (size_t irow=0; irow<cd.GetEntries(); ++irow){
    cd.GetEntry(irow);

        if(nphed>0){
            if(timescd>0){
                if(timesceld>0){
                    if(timeecd>0){
                        if(timeeceld>0){
                            if(pzd<20){
                                if(pd<20){
                                    if(eind>0){
                                        if(eoutd>0){
                                            if(etotd>0){
                                                if(pathecd>0){
                                                    if(pathscd>0){
                                                        if(xec>0){
                                                            if(yec>0){
                                                                if(zec>0){
                                                                    if(ccstatusd>0){
                                                                        if(scstatusd>0){
                                                                            if(dcstatusd>0){

          hd2->Fill(phipqd);  
            if(pidd==211){
        hd->Fill(phipqd);
      
        }}}}}}}}}}}}}}}}}}}}
    
        TCanvas *c1 = new TCanvas("c1","c1",800,600);
    //hd->Add(hd2,-1);
    hd2->SetLineColor(kRed);
    hd->Draw();
    hd2->Draw("SAME");

     c1->SaveAs("PHIpq_both.pdf");
}