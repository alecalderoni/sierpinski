import matplotlib.pyplot as plt
import numpy as np

x, y = np.loadtxt("fractal.dat", unpack = True, usecols = (0,1))

plt.plot(x, y, 'r.', markersize = 1)
plt.savefig('fractal.png')
plt.show()