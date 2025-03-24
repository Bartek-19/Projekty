import random as r
import numpy as np
import matplotlib.pyplot as plt

array = []
n = 100000
k = 20

for i in range(0, n):
    array.append(r.randint(0, k))

plt.hist(x=array, bins=k, edgecolor="black", color="blue")
plt.show()

array = []
for i in range(0, n):
    array.append(r.randrange(0, k))

plt.hist(x=array, bins=k, edgecolor="black", color="blue")
plt.show()

array = []
for i in range(0, n):
    array.append(np.random.randint(0, k))

plt.hist(x=array, bins=k, edgecolor="black", color="blue")
plt.show()

array = np.random.normal(size=n)
plt.hist(x=array, bins=k, edgecolor="black", color="blue")
plt.show()

array = np.random.normal(loc=5.0, scale=5.0, size=n)
plt.hist(x=array, bins=k, edgecolor="black", color="blue")
plt.show()