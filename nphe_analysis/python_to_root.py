import uproot
import pandas as pd
from ydata_profiling import ProfileReport


file = uproot.open("/home/zambra/root_files/local_codes/nphe_analysis/phipq_structure_arround_zero.root")
simpy = file["data"]
#df = simpy.pd.DataFrame(["PhiPQ","Nphe","pid"])


df = pd.DataFrame({"pid": simpy["pid"].array(),"P": simpy["P"].array(),"Pz": simpy["Pz"].array(), "PhiPQ": simpy["PhiPQ"].array(), "ThetaPQ": simpy["ThetaPQ"].array(),"ThetaLab": simpy["ThetaLab"].array(), "PhiLab": simpy["PhiLab"].array(), "Nphe": simpy["Nphe"].array(),"TimeEC": simpy["TimeEC"].array(),"TimeSC": simpy["TimeSC"].array()})
report=ProfileReport(df)
report.to_file(output_file="hola.html")