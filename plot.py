import subprocess
import numpy as np
import matplotlib.pyplot as plt

array_sizes = []
execution_times = []

for i in range(1000000, 1000500, 10):
    time = subprocess.run(['./sequential', str(i)], stdout=subprocess.PIPE).stdout.decode('utf-8').split('\n')[1].split(' ')[2]

    array_sizes.append(i)
    execution_times.append(time)

plt.figure(figsize=(15, 20))
plt.plot(array_sizes, execution_times)
plt.title('Sequential Sum calculation')
plt.xlabel('Array size')
plt.ylabel('Execution time')
plt.savefig('output/sequential.png')
