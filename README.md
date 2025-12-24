# spacecraft-orbit-propagator

## Overview
A C++ two-body orbital dynamics propagator implementing Euler and 4th-order Runge–Kutta (RK4) numerical integration methods for spacecraft trajectory simulation. The software is designed using flight software–inspired principles with deterministic execution and explicit state representation. Python is used for post-processing, data formatting, and trajectory visualization.
---
## Features and Design Considerations
- Two-body spacecraft state propagation using Euler and Runge-Kutta 4th order integrators
- File-based state output for analysis and verification
- Python-based post-processing and 3D trajectory visualization

### Design Considerations
The propagator is structured using flight software–inspired design principles with an emphasis on determinism, separation of concerns, and verifiability.
- Deterministic, fixed-memory state propagation suitable for time-critical execution
- Clear separation between dynamics modeling and numerical integration
- Observer pattern used to stream state telemetry to file without coupling I/O to propagation logic
- Side-effect-free dynamics evaluation for improved verifiability

---

## Model and Integration
Spacecraft motion is modeled under central-body gravity only:

ṙ = v  
v̇ = −μ r / ||r||³  

Perturbations (drag, J2, third-body effects) are intentionally excluded to isolate numerical integration behavior.

---

## Initial State Vectors
\[
\mathbf{x} = [\, r_x,\; r_y,\; r_z,\; v_x,\; v_y,\; v_z \,]
\]

Case 1: LEO Circular
x = [6778000.0, 0.0, 0.0, 0.0, 7668.6, 0.0]

Case 2: LEO Elliptical
x = [6878000.0, 0.0, 0.0, 0.0, 9000.0, 0.0]

Case 3: MEO Inclined
x = [16378000.0, 0.0, 0.0, 1000.0, 3000.0, 3000.0]

---

### Build and Run
'''
g++ src/main.cpp src/dynamics.cpp src/integrator.cpp src/state.cpp src/propagator.cpp src/IO/csv_orbit_logger.cpp -o orbit
'''
'''
.\orbit
'''
'''
python .\plotting\orbit_plot.py
'''

---

### Future Work

