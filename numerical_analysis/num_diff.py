import numpy as np

t = np.linspace(2, 10, 500)
#function
ft = np.sin(t)
delta_t = 0.2

#forward-finite-difference derivative
df_dt_F = (np.sin(t + delta_t) - np.sin(t)) / delta_t

#backward-finite-difference derivative
df_dt_B = (np.sin(t) - np.sin(t - delta_t)) / delta_t

#central-finite-difference derivative
df_dt_C = (np.sin(t + delta_t) - np.sin(t - delta_t)) / (2 * delta_t)

#approximate second derivative
def g(t):
    return np.arctan(t)

def h(t):
    return t**3 + 0.5*t

#function
gt = np.arctan(t)

delta_t = 0.1

#forward-finite-difference second derivative
dg2_dt2_F_num = (g(t+2*delta_t)-g(t+delta_t))/delta_t-(g(t+delta_t)-g(t))/delta_t
dg2_dt2_F = dg2_dt2_F_num / delta_t
#forward-finite-difference second derivative
dh2_dt2_F_num = (h(t+2*delta_t)-h(t+delta_t))/delta_t-(h(t+delta_t)-h(t))/delta_t
dh2_dt2_F = dh2_dt2_F_num / delta_t

print('{')
for item in zip(t, dg2_dt2_F):
    print(item, end = '')
    print(',')
print('}')
print()
print('{')
for item in zip(t, dh2_dt2_F):
    print(item, end = '')
    print(',')
print('}')
