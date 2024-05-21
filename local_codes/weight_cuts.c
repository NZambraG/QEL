#include <TROOT.h>
void weight_cuts()
{
    TChain cd("ntuple_data");
    TChain cs("ntuple_sim");   
    cd.Add("/home/zambra/root_files/clusterdata/out/GetSimpleTuple_data/C/prunedC*.root");
    cs.Add("/home/zambra/root_files/clusterdata/out/GetSimpleTuple_HSim/C1/prunedC*.root");
    
   float lcd,qcd,ttcd;
   float lcs,qcs,ttcs;
   float mclcs,mcqcs,mcttcs;
   
    cd.SetBranchAddress("pid", &lcd);
    cd.SetBranchAddress("Q2", &qcd);
    cd.SetBranchAddress("TargType", &ttcd);

    cs.SetBranchAddress("pid", &lcs);
    cs.SetBranchAddress("Q2", &qcs);
    cs.SetBranchAddress("TargType", &ttcs);
    
    cs.SetBranchAddress("mc_pid", &mclcs);
    cs.SetBranchAddress("mc_Q2", &mcqcs);
    cs.SetBranchAddress("mc_TargType", &mcttcs);

   float pesoq2,pesoq2cortado,pesoq2cortadodespues;

   for (size_t irow=0; irow<cs.GetEntries(); ++irow){
      cs.GetEntry(irow);
         if (lcs==211)
         {
            if(ttcs==2){
               pesoq2=qcs/mcqcs;
            }
         }
   }

   cout <<"pesoq2 =" << pesoq2 <<"\n";
   cout <<"pesoq2cortado =" << pesoq2cortado << "\n";
   cout <<"pesoq2cortadodespues =" << pesoq2cortadodespues << "\n";
}
