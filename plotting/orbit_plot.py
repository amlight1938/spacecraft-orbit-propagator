import matplotlib.pyplot as plt
import pandas as pd
import numpy as np
from mpl_toolkits.mplot3d import Axes3D 

eulerFilepath = "output/euler-orbit.csv"
rk4Filepath = "output/rk4-orbit.csv"
earth_radius = 6378000 #meters

#reading csv
euler = pd.read_csv(eulerFilepath)
rk4 = pd.read_csv(rk4Filepath)

#creating figure
plt.style.use('fast')
figure = plt.figure()
ax = plt.axes(111, projection='3d')
ax.grid(False)
ax.set_title("Euler vs Runge-Kutta 4 Orbit Propagation")
ax.set_xlabel('x (m)')
ax.set_ylabel('y (m)')
ax.set_zlabel('z (m)')

#calculate periapsis
rMag = np.sqrt(euler["rx"]**2 + euler["ry"]**2 + euler["rz"]**2)
idx_periapsis = np.argmin(rMag)
periapsis = (rk4["rx"][idx_periapsis], rk4["ry"][idx_periapsis], rk4["rz"][idx_periapsis])

#prepare to plot earth
theta = np.linspace(0, np.pi, 50)
phi = np.linspace(0, 2*np.pi, 50)

x = earth_radius * np.outer(np.sin(theta), np.cos(phi))
y = earth_radius * np.outer(np.sin(theta), np.sin(phi))
z = earth_radius * np.outer(np.cos(theta),np.ones(np.size(phi)))

all_vals = np.concatenate([euler["rx"], euler["ry"], euler["rz"]])
minAxis = np.min(all_vals)
maxAxis = np.max(all_vals)
ax.set_xlim(minAxis, maxAxis)
ax.set_ylim(minAxis, maxAxis)
ax.set_zlim(minAxis, maxAxis)
ax.set_box_aspect([1, 1, 1])

#plot orbits and earth
ax.plot_surface(x,y,z,color ='blue', alpha=0.5,rstride=3,cstride=3,)
ax.plot(euler["rx"], euler["ry"], euler["rz"], label="Euler", color='orange')
ax.plot(rk4["rx"], rk4["ry"], rk4["rz"], label="RK4", color='g')
ax.scatter(periapsis[0], periapsis[1], periapsis[2], color = 'r', label='Periapsis')

plt.legend()
plt.show()

