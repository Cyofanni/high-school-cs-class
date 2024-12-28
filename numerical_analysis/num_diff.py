import numpy as np
from matplotlib import pyplot

t = np.linspace(2, 10, 500)
#function
ft = np.sin(t)
#exact derivative
df_dt = np.cos(t)
#pyplot.plot(t, df_dt, 'g')

delta_t = 0.2

#forward-finite-difference derivative
df_dt_F = (np.sin(t + delta_t) - np.sin(t)) / delta_t
#pyplot.plot(t, df_dt_F, 'r')

#backward-finite-difference derivative
df_dt_B = (np.sin(t) - np.sin(t - delta_t)) / delta_t
#pyplot.plot(t, df_dt_B, 'b')

#central-finite-difference derivative
df_dt_C = (np.sin(t + delta_t) - np.sin(t - delta_t)) / (2 * delta_t)
#pyplot.plot(t, df_dt_C, 'y')

#approximate second derivative
def g(t):
    return np.arctan(t)

#function
gt = np.arctan(t)
#exact second derivative
dg_dt = -2*t/(t**2+1)**2
#pyplot.plot(t, dg_dt, 'g')

delta_t = 0.1

#forward-finite-difference second derivative
dg_dt_F_num = (g(t+2*delta_t)-g(t+delta_t))/delta_t-(g(t+delta_t)-g(t))/delta_t
dg_dt_F = dg_dt_F_num / delta_t

pyplot.plot(t, dg_dt_F, 'r')

print('{')
for item in zip(t, dg_dt_F):
    print(item, end = '')
    print(',')
print('}')

#pyplot.show()
