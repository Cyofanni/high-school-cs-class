import numpy as np
from matplotlib import pyplot as plt
#square wave
t = np.linspace(-3, 3, 1000)
f = 1  #fundamental frequency
A = 1  #amplitude
h1 = np.cos(2*np.pi*f*t)
h2 = (-1/3) * np.cos(2*np.pi*3*f*t)
h3 = (1/5) * np.cos(2*np.pi*5*f*t)
h4 = (-1/7) * np.cos(2*np.pi*7*f*t)
h5 = (1/9) * np.cos(2*np.pi*9*f*t)
h6 = (-1/11) * np.cos(2*np.pi*11*f*t)
h7 = (1/13) * np.cos(2*np.pi*13*f*t)
h8 = (-1/15) * np.cos(2*np.pi*15*f*t)
h9 = (1/17) * np.cos(2*np.pi*17*f*t)
h10 = (-1/19) * np.cos(2*np.pi*19*f*t)
h11 = (1/21) * np.cos(2*np.pi*21*f*t)
h12 = (-1/23) * np.cos(2*np.pi*23*f*t)
h13 = (1/25) * np.cos(2*np.pi*25*f*t)
h14 = (-1/27) * np.cos(2*np.pi*27*f*t)
h15 = (1/29) * np.cos(2*np.pi*29*f*t)
h16 = (-1/31) * np.cos(2*np.pi*31*f*t)

s = (4*A/np.pi) * (h1 + h2 + h3 + h4 + h5 + h6 + h7 + h8 + h9 +
                 h10 + h11 + h12 + h13 + h14 + h15 + h16)

plt.plot(t, s)
plt.show()
