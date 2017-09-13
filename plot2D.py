from math import *
import numpy as np
from pylab import *

data = np.loadtxt('datafile.txt', ndmin=2)

#print(data)

figure()
plot(data[:,0], data[:,1])
title('C++ data')
xlabel('x')
ylabel('y')
show()
