import numpy as np
import matplotlib.pyplot as plt
plt.style.use('seaborn-darkgrid')


filepath ="MediaFiles/filtroMediaMovil.txt"
handler = open(filepath)

data = [row[:-2] for row in handler] 
# sample size 
nSample = int(data[0])
#nPivot = nSample + 1
nOutput = nSample - 4

samples = np.array([float(sample) for sample in data[2:2+nSample]])
tSamples = np.array([i for i in range(1,len(samples)+1,1)])


#pivot = [float(pivot) for pivot in data[3+nSample:3+nSample+nPivot]]
#tPivot = [i for i in range(1,len(pivot)+1,1)]


output = [float(output) for output in data[-1-nOutput:-1]]
tOutput = [i for i in range(1,len(output)+1,1)]


plt.figure()
plt.subplot(1,2,1)
plt.plot(tSamples[1:],samples[1:],color = "red") # eliminar primer elemento
plt.title("Sin Filtro")
plt.ylabel("temperatura (C°)")
plt.xlabel("timesteps(250ms)")
plt.subplot(1,2,2)
plt.plot(tOutput[1:],output[1:]) # eliminar primer elemento
plt.title("Filtro de Media Movil")
plt.ylabel("temperatura (C°)")
plt.xlabel("timesteps(250ms)")
plt.tight_layout(pad=2.0)

plt.show()