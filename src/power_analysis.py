import numpy as np
import pandas as pd

df = pd.read_csv(r'8s2m_amazon.csv', header=1,index_col=False)
df1= df[["timestamp","12v_aux_curr","12v_aux_vol","12v_pex_curr","12v_pex_vol","vccint_curr","vccint_vol"]]

df2 = df1.to_numpy()

v12_power = 0.0
pci_power = 0.0
int_power = 0.0


for i in range(len(df2)-1):
    time = (df2[i+1][0] - df2[i][0])/1000
    v12_p = ((df2[i+1][1]+df2[i][1])/2)*((df2[i+1][2]+df2[i][2])/2)*time/1e6
    pci_p = ((df2[i+1][3]+df2[i][3])/2)*((df2[i+1][4]+df2[i][4])/2)*time/1e6
    int_p = ((df2[i+1][5]+df2[i][5])/2)*((df2[i+1][6]+df2[i][6])/2)*time/1e6
    
    v12_power += v12_p
    pci_power += pci_p
    int_power += int_p
    
total_power = v12_power+pci_power+int_power

print('12V: ',v12_power)
print('PCIe: ',pci_power)
print('internal: ',int_power) 
print('total:', total_power)


