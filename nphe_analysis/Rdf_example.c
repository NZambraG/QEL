void Rdf_example(){
    //ROOT::RDataFrame df(1);
    //ROOT::EnableImplicitMT();

    ROOT::RDataFrame d("data","/home/zambra/root_files/local_codes/nphe_analysis/Nphe_structure_for_cuts.root",{"PhiPQ", "Nphe"});


//TCanvas *c1 = new TCanvas("c1","c1",800,600);
auto h = d.Histo1D("PhiPQ");
h->Draw();

    
    //auto histoB = d.Histo1D("Nphe");
    
    //histoA->Draw();
    //histoB->Draw();
}