import numpy as np
import matplotlib.pyplot as plt
from scipy.io.wavfile import write
import matplotlib.animation as animation
#import scipy.io.wavfile.write
datos = np.loadtxt("datos1d.txt")
x = np.array(datos[:,0])
fi_initial = np.array(datos[:,1])
fi_present = datos[:,2]
t_2 = datos[:,3]
t_4 = datos[:,4]
t_8 = datos[:,5]
t_2_2 = datos[:,6]
t_4_2 = datos[:,7]
t_8_2 = datos[:,8]


f, axarr = plt.subplots(2, sharex=True)
axarr[0].plot(x,fi_initial)
axarr[0].plot(x,t_2)
axarr[0].plot(x,t_4)
axarr[0].plot(x,t_8)
axarr[0].set_title("$Cuerda$ $extremos$ $fijos$")
axarr[1].plot(x,fi_initial)
axarr[1].plot(x,t_2_2)
axarr[1].plot(x,t_4_2)
axarr[1].plot(x,t_8_2)
axarr[1].set_title("$Cuerda$ $extremo$ $con$ $la$ $funcion$ $sin((2 pi c /L )*t) $")
plt.savefig("Resultados_hw4.pdf")


write('sonido.wav', 10,t_2_2)



def update_line(x, t_2_2, line):
    line.set_data(t_2_2[...,:x])
    return line,

fig1 = plt.figure()
def algo(a):
    for i in range(0,15):
        data = a[i]
    return data
    #return data
l, = plt.plot([], [],)
plt.xlim(0, 1)
plt.ylim(0, 1)
line_ani = animation.FuncAnimation(fig1, update_line, 15, fargs=(algo(t_2_2), l),
    interval=50, blit=True)
#line_ani.save('lines.mp4')
plt.show()

#im_ani.save('im.mp4', metadata={'artist':'Guido'})
