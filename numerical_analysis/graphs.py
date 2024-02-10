import numpy, math
from matplotlib import pyplot

#x's: [-2pi, +2pi], 1000 points
xs = numpy.linspace(-2*math.pi, 2*math.pi, 1000)
#y = sin(x)
ys_sin = [math.sin(x) for x in xs]
#y = cos(x)
ys_cos = [math.cos(x) for x in xs]

pyplot.plot(xs, ys_sin)
pyplot.plot(xs, ys_cos)

pyplot.show()
