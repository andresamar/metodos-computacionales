import numpy as np
import matplotlib.pyplot as plt
datos = np.loadtxt("datos1d.txt")
x = datos[:,0]
fi_initial = datos[:,1]
fi_present = datos[:,2]



plt.figure()
plt.figure()
#plt.plot(x,fi_initial)
plt.plot(x,fi_present)
plt.show()
plt.savefig("Resultados_hw.pdf")
