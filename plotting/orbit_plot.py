import numpy as np
import matplotlib.pyplot as plt
import csv

filepath = "output/rk4-orbit.csv"

#create 2d array of data
data = np.genfromtxt(filepath, delimiter=',', skip_header=1)

time = data[:,0]
rx = data[:,1]
ry = data[:,2]
rz = data[:,3]

r = np.sqrt(rx**2 + ry**2 + rz**2)
idx_periapsis = np.argmin(r)
x_periapsis = rx[idx_periapsis]
y_periapsis = ry[idx_periapsis]
z_periapsis = rz[idx_periapsis]

figure = plt.figure()
ax = plt.axes(projection='3d')
ax.plot(rx,ry,rz)
ax.scatter(x_periapsis,y_periapsis,z_periapsis, color='red')
ax.set_title("Euler Orbit Propagation")
ax.set_xlabel('x (m)')
ax.set_ylabel('y (m)')
ax.set_zlabel('z (m)')
figure.show()

#2d plot
figure1 = plt.figure()
ax2 = plt.axes()
ax2.plot(rx, ry)
ax2.scatter(x_periapsis, y_periapsis, color='red', label="Periapsis")
ax2.set_title("Euler Orbit Propagation")
ax2.set_xlabel("x (m)")
ax2.set_ylabel("y (m)")
ax2.axis("equal")
ax2.legend()
plt.show()



# plt.figure()
# plt.plot(time, r)
# plt.title("Radius over time")
# plt.xlabel("Time (s)")
# plt.ylabel("Radius (m)")
# plt.show()