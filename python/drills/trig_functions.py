import numpy, math
from matplotlib import pyplot
#x's: [-2pi, +2pi], 1000 points
xs = numpy.linspace(-2*math.pi, 2*math.pi, 1000)
#y = sin(x)
ys_sin = [math.sin(x) for x in xs]
#y = cos(x)
ys_cos = [math.cos(x) for x in xs]

#y = 4sin(2x)
ys_sin_0 = [4 * math.sin(2*x) for x in xs]

#[sin(x), sin(2x), sin(3x), ... sin(5x)]
sins = [[math.sin(omega*x) for x in xs] for omega in range(1, 6)]
for func in sins:
  pyplot.plot(xs, func)
