from numpy import *
from matplotlib import pyplot as plt
#square wave

t = linspace(-3, 3, 1000)
f = 1  #fundamental frequency
A = 1  #amplitude
h1 = cos(2*pi*f*t)
h2 = (-1/3) * cos(2*pi*3*f*t)
h3 = (1/5) * cos(2*pi*5*f*t)
h4 = (-1/7) * cos(2*pi*7*f*t)
h5 = (1/9) * cos(2*pi*9*f*t)
h6 = (-1/11) * cos(2*pi*11*f*t)
h7 = (1/13) * cos(2*pi*13*f*t)
h8 = (-1/15) * cos(2*pi*15*f*t)
h9 = (1/17) * cos(2*pi*17*f*t)
h10 = (-1/19) * cos(2*pi*19*f*t)
h11 = (1/21) * cos(2*pi*21*f*t)
h12 = (-1/23) * cos(2*pi*23*f*t)
h13 = (1/25) * cos(2*pi*25*f*t)
h14 = (-1/27) * cos(2*pi*27*f*t)
h15 = (1/29) * cos(2*pi*29*f*t)
h16 = (-1/31) * cos(2*pi*31*f*t)

s = (4*A/pi) * (h1 + h2+ h3 + h4 + h5 + h6)

plt.plot(t, s)
plt.show()

#sawtooth
