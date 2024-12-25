import numpy as np
from matplotlib import pyplot

t = np.linspace(-6, 6, 500)
#function
ft = np.sin(t)
#exact derivative
df_dt = np.cos(t)
pyplot.plot(t, df_dt, 'g')

delta_t = 0.2

#forward-finite-difference derivative
df_dt_F = (np.sin(t + delta_t) - np.sin(t)) / delta_t
pyplot.plot(t, df_dt_F, 'r')

#backward-finite-difference derivative
df_dt_B = (np.sin(t) - np.sin(t - delta_t)) / delta_t
pyplot.plot(t, df_dt_B, 'b')

#central-finite-difference derivative
df_dt_C = (np.sin(t + delta_t) - np.sin(t - delta_t)) / (2 * delta_t)
pyplot.plot(t, df_dt_C, 'y')

pyplot.show()
