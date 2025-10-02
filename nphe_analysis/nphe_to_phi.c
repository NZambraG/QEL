#include <TROOT.h>
void nphe_to_phi()
{
    TChain cd("ntuple_data");
    TChain cs("ntuple_sim");   
    cd.Add("/home/zambra/root_files/clusterdata/out/GetSimpleTuple_data/C/prunedC_4210*.root");
    cs.Add("/home/zambra/root_files/clusterdata/out/GetSimpleTuple_HSim/C1/prunedC_*.root");
    cs.Add("/home/zambra/root_files/clusterdata/out/GetSimpleTuple_HSim/C2/prunedC_1*.root");
    cs.Add("/home/zambra/root_files/clusterdata/out/GetSimpleTuple_HSim/C2/prunedC_4*.root");
    float phipqd,philabd,thetalabd,thetapqd,nphed,timescd,timesceld,timeecd,timeeceld,ttd,pidd,pd,pzd;
    float phipqs,philabs,thetalabs,thetapqs,nphes,timescs,timescels,timeecs,timeecels,tts,pids,ps,pzs;

    float PhiPQ,PhiLab,ThetaLab,ThetaPQ,Nphe,TimeSC,TimeSCEl,TimeEC,TimeECEl,TargType,pid,P,Pz;

    TFile f("phipq_structure_arround_zero.root", "RECREATE");
    TTree t0("data","data");
    t0.Branch("PhiPQ",&PhiPQ,"PhiPQ/F");
    t0.Branch("PhiLab",&PhiLab,"PhiLab/F");
    t0.Branch("ThetaLab",&ThetaLab,"ThetaLab/F");
    t0.Branch("ThetaPQ",&ThetaPQ,"ThetaPQ/F");
    t0.Branch("Nphe",&Nphe,"Nphe/F");
    t0.Branch("TimeSC",&TimeSC,"TimeSC/F");
    t0.Branch("TimeSCEl",&TimeSCEl,"TimeSCEl/F");
    t0.Branch("TimeEC",&TimeEC,"TimeEC/F");
    t0.Branch("TimeECEl",&TimeECEl,"TimeECEl/F");
    t0.Branch("TargType",&TargType,"TargType/F");
    t0.Branch("pid",&pid,"pid/F");
    t0.Branch("P",&P,"P/F");
    t0.Branch("Pz",&Pz,"Pz/F");

    TTree t1("sim","sim");
    t1.Branch("PhiPQ",&PhiPQ,"PhiPQ/F");
    t1.Branch("PhiLab",&PhiLab,"PhiLab/F");
    t1.Branch("ThetaLab",&ThetaLab,"ThetaLab/F");
    t1.Branch("ThetaPQ",&ThetaPQ,"ThetaPQ/F");
    t1.Branch("Nphe",&Nphe,"Nphe/F");
    t1.Branch("TimeSC",&TimeSC,"TimeSC/F");
    t1.Branch("TimeSCEl",&TimeSCEl,"TimeSCEl/F");
    t1.Branch("TimeEC",&TimeEC,"TimeEC/F");
    t1.Branch("TimeECEl",&TimeECEl,"TimeECEl/F");
    t1.Branch("TargType",&TargType,"TargType/F");
    t1.Branch("pid",&pid,"pid/F");
    t1.Branch("P",&P,"P/F");
    t1.Branch("Pz",&Pz,"Pz/F");

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
    cd.SetBranchAddress("pid",&pidd);
    cd.SetBranchAddress("P",&pd);
    cd.SetBranchAddress("Pz",&pzd);
    
    cs.SetBranchAddress("PhiPQ",&phipqs);
    cs.SetBranchAddress("PhiLab", &philabs);
    cs.SetBranchAddress("ThetaLab", &thetalabs);
    cs.SetBranchAddress("ThetaPQ", &thetapqs);
    cs.SetBranchAddress("Nphe", &nphes);
    cs.SetBranchAddress("TimeSC", &timescs);
    cs.SetBranchAddress("TimeSCEl", &timescels);
    cs.SetBranchAddress("TimeEC", &timeecs);
    cs.SetBranchAddress("TimeECEl", &timeecels);
    cs.SetBranchAddress("TargType", &tts);
    cs.SetBranchAddress("pid",&pids);
    cs.SetBranchAddress("P",&ps);
    cs.SetBranchAddress("Pz",&pzs);
float ppqlr;
ppqlr=-40;
   for (size_t irow=0; irow<cd.GetEntries(); ++irow){
      cd.GetEntry(irow);
        if(phipqd>ppqlr & phipqd<-ppqlr){
                                PhiPQ=phipqd;
                                PhiLab=philabd;
                                ThetaLab=thetalabd;
                                ThetaPQ=thetapqd;
                                Nphe=nphed;
                                TimeSC=timescd;
                                TimeSCEl=timesceld;
                                TimeEC=timeecd;
                                TimeECEl=timeeceld;
                                TargType=ttd;
                                pid=pidd;
                                P=pd;
                                Pz=pzd;
                                t0.Fill();
        }
    }
   for (size_t irow=0; irow<cs.GetEntries(); ++irow){
      cs.GetEntry(irow);
        if(phipqs>ppqlr & phipqs<-ppqlr){
                                PhiPQ=phipqs;
                                PhiLab=philabs;
                                ThetaLab=thetalabs;
                                ThetaPQ=thetapqs;
                                Nphe=nphes;
                                TimeSC=timescs;
                                TimeSCEl=timescels;
                                TimeEC=timeecs;
                                TimeECEl=timeecels;
                                TargType=tts;
                                pid=pids;
                                P=ps;
                                P=pzs;
                                t1.Fill();
        }
 
    }
    t0.Write();
    t1.Write();
}