#include <TROOT.h>
void acc_generator()
{
    TChain cd("ntuple_data");
    TChain cs("ntuple_sim");   
    cd.Add("/home/zambra/root_files/clusterdata/out/GetSimpleTuple_data/C/prunedC*.root");
    cs.Add("/home/zambra/root_files/clusterdata/out/GetSimpleTuple_HSim/C1/prunedC*.root");
    
    float pzcd,pcd,lcd,qcd,wcd,xbcd,ybcd,ttcd,nucd,pt2cd,zhcd,phipqcd;
    float pzcs,pcs,lcs,qcs,wcs,xbcs,ybcs,ttcs,nucs,pt2cs,zhcs,phipqcs;
    float mcpzcs,mcpcs,mclcs,mcqcs,mcwcs,mcxbcs,mcybcs,mcttcs,mcnucs,mcpt2cs,mczhcs,mcphipqcs;


    float PhiPQ,Zh,Q2,Xb,Pt2,Pz,P,pid,W,Yb,Nu,TargType;
    TFile f("Acc_C_PPions_phi_1.root", "RECREATE");
float lowerphi,higherphi;
lowerphi=-180;
higherphi=-150;
    TTree t0("Zh0","Zh0");
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

    TTree t1("Zh1","Zh1");
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

    TTree t2("Zh2","Zh2");
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
    

    TTree t3("Zh3","Zh3");
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

    TTree t4("Zh4","Zh4");
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

    TTree t5("Zh5","Zh5");
    t5.Branch("PhiPQ",&PhiPQ,"PhiPQ/F");
    t5.Branch("Zh",&Zh,"Zh/F");
    t5.Branch("Q2",&Q2,"Q2/F");
    t5.Branch("Xb",&Xb,"Xb/F");
    t5.Branch("Pt2",&Pt2,"Pt2/F");
    t5.Branch("Pz",&Pz,"Pz/F");
    t5.Branch("P",&P,"P/F");
    t5.Branch("pid",&pid,"pid/F");
    t5.Branch("W",&W,"W/F");
    t5.Branch("Yb",&Yb,"Yb/F");
    t5.Branch("Nu",&Nu,"Nu/F");
    t5.Branch("TargType",&TargType,"TargType/F");

    TTree t6("Zh6","Zh6");
    t6.Branch("PhiPQ",&PhiPQ,"PhiPQ/F");
    t6.Branch("Zh",&Zh,"Zh/F");
    t6.Branch("Q2",&Q2,"Q2/F");
    t6.Branch("Xb",&Xb,"Xb/F");
    t6.Branch("Pt2",&Pt2,"Pt2/F");
    t6.Branch("Pz",&Pz,"Pz/F");
    t6.Branch("P",&P,"P/F");
    t6.Branch("pid",&pid,"pid/F");
    t6.Branch("W",&W,"W/F");
    t6.Branch("Yb",&Yb,"Yb/F");
    t6.Branch("Nu",&Nu,"Nu/F");
    t6.Branch("TargType",&TargType,"TargType/F");

    TTree t7("Zh7","Zh7");
    t7.Branch("PhiPQ",&PhiPQ,"PhiPQ/F");
    t7.Branch("Zh",&Zh,"Zh/F");
    t7.Branch("Q2",&Q2,"Q2/F");
    t7.Branch("Xb",&Xb,"Xb/F");
    t7.Branch("Pt2",&Pt2,"Pt2/F");
    t7.Branch("Pz",&Pz,"Pz/F");
    t7.Branch("P",&P,"P/F");
    t7.Branch("pid",&pid,"pid/F");
    t7.Branch("W",&W,"W/F");
    t7.Branch("Yb",&Yb,"Yb/F");
    t7.Branch("Nu",&Nu,"Nu/F");
    t7.Branch("TargType",&TargType,"TargType/F");

    TTree t8("Zh8","Zh8");
    t8.Branch("PhiPQ",&PhiPQ,"PhiPQ/F");
    t8.Branch("Zh",&Zh,"Zh/F");
    t8.Branch("Q2",&Q2,"Q2/F");
    t8.Branch("Xb",&Xb,"Xb/F");
    t8.Branch("Pt2",&Pt2,"Pt2/F");
    t8.Branch("Pz",&Pz,"Pz/F");
    t8.Branch("P",&P,"P/F");
    t8.Branch("pid",&pid,"pid/F");
    t8.Branch("W",&W,"W/F");
    t8.Branch("Yb",&Yb,"Yb/F");
    t8.Branch("Nu",&Nu,"Nu/F");
    t8.Branch("TargType",&TargType,"TargType/F");

    TTree t9("Zh9","Zh9");
    t9.Branch("PhiPQ",&PhiPQ,"PhiPQ/F");
    t9.Branch("Zh",&Zh,"Zh/F");
    t9.Branch("Q2",&Q2,"Q2/F");
    t9.Branch("Xb",&Xb,"Xb/F");
    t9.Branch("Pt2",&Pt2,"Pt2/F");
    t9.Branch("Pz",&Pz,"Pz/F");
    t9.Branch("P",&P,"P/F");
    t9.Branch("pid",&pid,"pid/F");
    t9.Branch("W",&W,"W/F");
    t9.Branch("Yb",&Yb,"Yb/F");
    t9.Branch("Nu",&Nu,"Nu/F");
    t9.Branch("TargType",&TargType,"TargType/F");

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

float pesonu0,pesonu1,pesonu2,pesonu3,pesonu4,pesonu5,pesonu6,pesonu7,pesonu8,pesonu9;
float pesoq20,pesoq21,pesoq22,pesoq23,pesoq24,pesoq25,pesoq26,pesoq27,pesoq28,pesoq29;
float pesoxb0,pesoxb1,pesoxb2,pesoxb3,pesoxb4,pesoxb5,pesoxb6,pesoxb7,pesoxb8,pesoxb9;
float pesopt20,pesopt21,pesopt22,pesopt23,pesopt24,pesopt25,pesopt26,pesopt27,pesopt28,pesopt29;
float pesophi0,pesophi1,pesophi2,pesophi3,pesophi4,pesophi5,pesophi6,pesophi7,pesophi8,pesophi9;
float pesozh0,pesozh1,pesozh2,pesozh3,pesozh4,pesozh5,pesozh6,pesozh7,pesozh8,pesozh9;

   for (size_t irow=0; irow<cs.GetEntries(); ++irow){
      cs.GetEntry(irow);

                if(phipqcs>lowerphi){
                    if(phipqcs<higherphi){
                        if(zhcs>0.0){
                            if(zhcs<0.1){
                                pesozh0=zhcs/mczhcs;
                                pesophi0=phipqcs/mcphipqcs;
                                pesoq20=qcs/mcqcs;
                                pesoxb0=xbcs/mcxbcs;
                                pesopt20=pt2cs/mcpt2cs;
                                pesonu0=nucs/mcnucs;
                            }
                        }
                        if(zhcs>0.1){
                            if(zhcs<0.2){
                                pesozh1=zhcs/mczhcs;
                                pesophi1=phipqcs/mcphipqcs;
                                pesoq21=qcs/mcqcs;
                                pesoxb1=xbcs/mcxbcs;
                                pesopt21=pt2cs/mcpt2cs;
                                pesonu1=nucs/mcnucs;
                            }
                        }
                        if(zhcs>0.2){
                            if(zhcs<0.3){
                                pesozh2=zhcs/mczhcs;
                                pesophi2=phipqcs/mcphipqcs;
                                pesoq22=qcs/mcqcs;
                                pesoxb2=xbcs/mcxbcs;
                                pesopt22=pt2cs/mcpt2cs;
                                pesonu2=nucs/mcnucs;
                        }
                        }
                        if(zhcs>0.3){
                            if(zhcs<0.4){
                                pesozh3=zhcs/mczhcs;
                                pesophi3=phipqcs/mcphipqcs;
                                pesoq23=qcs/mcqcs;
                                pesoxb3=xbcs/mcxbcs;
                                pesopt23=pt2cs/mcpt2cs;
                                pesonu3=nucs/mcnucs; 
                        }
                        }
                        if(zhcs>0.4){
                            if(zhcs<0.5){
                                pesozh4=zhcs/mczhcs;
                                pesophi4=phipqcs/mcphipqcs;
                                pesoq24=qcs/mcqcs;
                                pesoxb4=xbcs/mcxbcs;
                                pesopt24=pt2cs/mcpt2cs;
                                pesonu4=nucs/mcnucs;
                        }
                        }
                        if(zhcs>0.5){
                            if(zhcs<0.6){
                                pesozh5=zhcs/mczhcs;
                                pesophi5=phipqcs/mcphipqcs;
                                pesoq25=qcs/mcqcs;
                                pesoxb5=xbcs/mcxbcs;
                                pesopt25=pt2cs/mcpt2cs;
                                pesonu5=nucs/mcnucs;
                        }
                        }
                        if(zhcs>0.6){
                            if(zhcs<0.7){
                                pesozh6=zhcs/mczhcs;
                                pesophi6=phipqcs/mcphipqcs;
                                pesoq26=qcs/mcqcs;
                                pesoxb6=xbcs/mcxbcs;
                                pesopt26=pt2cs/mcpt2cs;
                                pesonu6=nucs/mcnucs;
                        }
                        }
                        if(zhcs>0.7){
                            if(zhcs<0.8){
                                pesozh7=zhcs/mczhcs;
                                pesophi7=phipqcs/mcphipqcs;
                                pesoq27=qcs/mcqcs;
                                pesoxb7=xbcs/mcxbcs;
                                pesopt27=pt2cs/mcpt2cs;
                                pesonu7=nucs/mcnucs;
                        }
                        }
                        if(zhcs>0.8){
                            if(zhcs<0.9){
                                pesozh8=zhcs/mczhcs;
                                pesophi8=phipqcs/mcphipqcs;
                                pesoq28=qcs/mcqcs;
                                pesoxb8=xbcs/mcxbcs;
                                pesopt28=pt2cs/mcpt2cs;
                                pesonu8=nucs/mcnucs;
                        }
                        }
                        if(zhcs>0.9){
                            if(zhcs<1.0){
                                pesozh9=zhcs/mczhcs;
                                pesophi9=phipqcs/mcphipqcs;
                                pesoq29=qcs/mcqcs;
                                pesoxb9=xbcs/mcxbcs;
                                pesopt29=pt2cs/mcpt2cs;
                                pesonu9=nucs/mcnucs;
                        }
                    }
                }                                
            }
   }
   for (size_t irow=0; irow<cd.GetEntries(); ++irow){
      cd.GetEntry(irow);

                if(phipqcd>lowerphi){
                    if(phipqcd<higherphi){
                        if(zhcd>0.0){
                            if(zhcd<0.1){
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
                            }
                        }
                        if(zhcd>0.1){
                            if(zhcd<0.2){
                                Zh=zhcd/pesozh1;
                                PhiPQ=phipqcd/pesophi1;
                                Q2=qcd/pesoq21;
                                Xb=xbcd/pesoxb1;
                                Pt2=pt2cd/pesopt21;
                                Nu=nucd/pesonu1;
                                Pz=pzcd;
                                P=pcd;
                                pid=lcd;
                                W=wcd;
                                Yb=ybcd;
                                TargType=ttcd;
                                t1.Fill();
                            }
                        }
                        if(zhcd>0.2){
                            if(zhcd<0.3){
                                Zh=zhcd/pesozh2;
                                PhiPQ=phipqcd/pesophi2;
                                Q2=qcd/pesoq22;
                                Xb=xbcd/pesoxb2;
                                Pt2=pt2cd/pesopt22;
                                Nu=nucd/pesonu2;
                                Pz=pzcd;
                                P=pcd;
                                pid=lcd;
                                W=wcd;
                                Yb=ybcd;
                                TargType=ttcd;
                                t2.Fill();
                            }
                        }
                        if(zhcd>0.3){
                            if(zhcd<0.4){
                                Zh=zhcd/pesozh3;
                                PhiPQ=phipqcd/pesophi3;
                                Q2=qcd/pesoq23;
                                Xb=xbcd/pesoxb3;
                                Pt2=pt2cd/pesopt23;
                                Nu=nucd/pesonu3;
                                Pz=pzcd;
                                P=pcd;
                                pid=lcd;
                                W=wcd;
                                Yb=ybcd;
                                TargType=ttcd;
                                t3.Fill();
                            }
                        }
                        if(zhcd>0.4){
                            if(zhcd<0.5){
                                Zh=zhcd/pesozh4;
                                PhiPQ=phipqcd/pesophi4;
                                Q2=qcd/pesoq24;
                                Xb=xbcd/pesoxb4;
                                Pt2=pt2cd/pesopt24;
                                Nu=nucd/pesonu4;
                                Pz=pzcd;
                                P=pcd;
                                pid=lcd;
                                W=wcd;
                                Yb=ybcd;
                                TargType=ttcd;
                                t4.Fill();
                            }
                        }
                        if(zhcd>0.5){
                            if(zhcd<0.6){
                                Zh=zhcd/pesozh5;
                                PhiPQ=phipqcd/pesophi5;
                                Q2=qcd/pesoq25;
                                Xb=xbcd/pesoxb5;
                                Pt2=pt2cd/pesopt25;
                                Nu=nucd/pesonu5;
                                Pz=pzcd;
                                P=pcd;
                                pid=lcd;
                                W=wcd;
                                Yb=ybcd;
                                TargType=ttcd;
                                t5.Fill();
                            }
                        }
                        if(zhcd>0.6){
                            if(zhcd<0.7){
                                Zh=zhcd/pesozh6;
                                PhiPQ=phipqcd/pesophi6;
                                Q2=qcd/pesoq26;
                                Xb=xbcd/pesoxb6;
                                Pt2=pt2cd/pesopt26;
                                Nu=nucd/pesonu6;
                                Pz=pzcd;
                                P=pcd;
                                pid=lcd;
                                W=wcd;
                                Yb=ybcd;
                                TargType=ttcd;
                                t6.Fill();
                            }
                        }
                        if(zhcd>0.7){
                            if(zhcd<0.8){
                                Zh=zhcd/pesozh7;
                                PhiPQ=phipqcd/pesophi7;
                                Q2=qcd/pesoq27;
                                Xb=xbcd/pesoxb7;
                                Pt2=pt2cd/pesopt27;
                                Nu=nucd/pesonu7;
                                Pz=pzcd;
                                P=pcd;
                                pid=lcd;
                                W=wcd;
                                Yb=ybcd;
                                TargType=ttcd;
                                t7.Fill();
                            }
                        }
                        if(zhcd>0.8){
                            if(zhcd<0.9){
                                Zh=zhcd/pesozh8;
                                PhiPQ=phipqcd/pesophi8;
                                Q2=qcd/pesoq28;
                                Xb=xbcd/pesoxb8;
                                Pt2=pt2cd/pesopt28;
                                Nu=nucd/pesonu8;
                                Pz=pzcd;
                                P=pcd;
                                pid=lcd;
                                W=wcd;
                                Yb=ybcd;
                                TargType=ttcd;
                                t8.Fill();
                            }
                        }
                        if(zhcd>0.9){
                            if(zhcd<1.0){
                                Zh=zhcd/pesozh9;
                                PhiPQ=phipqcd/pesophi9;
                                Q2=qcd/pesoq29;
                                Xb=xbcd/pesoxb9;
                                Pt2=pt2cd/pesopt29;
                                Nu=nucd/pesonu9;
                                Pz=pzcd;
                                P=pcd;
                                pid=lcd;
                                W=wcd;
                                Yb=ybcd;
                                TargType=ttcd;
                                t9.Fill();
                            }
                        }
                    }
                }
            
        
    }
    cout <<"     "<< "PhiPQ"<<"  "<<"Zh"<<"  "<<"Nu"<<"  "<<"Q2"<<"  "<<"Xb"<<"  "<<"Pt2"<<"  "<<"\n";
    cout <<"     " << pesophi0 << "  " << pesozh0 << "  " << pesonu0 << "  "<< pesoq20 << "  "<< pesoxb0 << "  "<< pesopt20 << "  "<<"\n";
    cout <<"     " << pesophi1 << "  " << pesozh1 << "  " << pesonu1 << "  "<< pesoq21 << "  "<< pesoxb1 << "  "<< pesopt21 << "  "<<"\n";
    cout <<"     " << pesophi2 << "  " << pesozh2 << "  " << pesonu2 << "  "<< pesoq22 << "  "<< pesoxb2 << "  "<< pesopt22 << "  "<<"\n";
    cout <<"     " << pesophi3 << "  " << pesozh3 << "  " << pesonu3 << "  "<< pesoq23 << "  "<< pesoxb3 << "  "<< pesopt23 << "  "<<"\n";
    cout <<"     " << pesophi4 << "  " << pesozh4 << "  " << pesonu4 << "  "<< pesoq24 << "  "<< pesoxb4 << "  "<< pesopt24 << "  "<<"\n";
    cout <<"     " << pesophi5 << "  " << pesozh5 << "  " << pesonu5 << "  "<< pesoq25 << "  "<< pesoxb5 << "  "<< pesopt25 << "  "<<"\n";
    cout <<"     " << pesophi6 << "  " << pesozh6 << "  " << pesonu6 << "  "<< pesoq26 << "  "<< pesoxb6 << "  "<< pesopt26 << "  "<<"\n";
    cout <<"     " << pesophi7 << "  " << pesozh7 << "  " << pesonu7 << "  "<< pesoq27 << "  "<< pesoxb7 << "  "<< pesopt27 << "  "<<"\n";
    cout <<"     " << pesophi8 << "  " << pesozh8 << "  " << pesonu8 << "  "<< pesoq28 << "  "<< pesoxb8 << "  "<< pesopt28 << "  "<<"\n";
    cout <<"     " << pesophi9 << "  " << pesozh9 << "  " << pesonu9 << "  "<< pesoq29 << "  "<< pesoxb9 << "  "<< pesopt29 << "  "<<"\n";
    t0.Write();
    t1.Write();
    t2.Write();
    t3.Write();
    t4.Write();
    t5.Write();
    t6.Write();
    t7.Write();
    t8.Write();
    t9.Write();
}