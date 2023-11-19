import numpy as np
import matplotlib.pyplot as plt

x = np.arange(-3, 3, 0.3)
y = np.arange(-3, 3, 0.3)
x, y = np.meshgrid(x, y)
levels = 24

z = 3 * (1 - x) ** 2 * np.exp(-x ** 2 - (y + 1) ** 2) - 10 * (x / 5 - x ** 3 - y ** 5) * np.exp(-x ** 2 - y ** 2) - 1 / 3 * np.exp(
    -(x + 1) ** 2 - y ** 2)

fig = plt.figure(figsize=(8, 5))
plt.tick_params(labelsize=18)
plt.xlabel("$x$", fontsize=24)
plt.ylabel("$y$", fontsize=24)

plt.contourf(x, y, z, levels=levels, cmap="rainbow")
line = plt.contour(x, y, z, levels=levels, colors="k")

x_current = -0.15
y_current = 1.2

dx_old = 0
dy_old = 0
beta = 0.8
Vx_old = 0
Vy_old = 0

iterations = 1000  # Training loops
lr = 0.5  # Learning rate

for i in range(iterations):
    pdx = (-6 * x_current ** 3 + 12 * x_current ** 2 - 6) * np.exp(-x_current ** 2 - (y_current + 1) ** 2) - (
            20 * x_current * y_current ** 5 + 20 * x_current ** 4 - 34 * x_current ** 2 + 2) * np.exp(
        -x_current ** 2 - y_current ** 2) + 2 / 3 * (x_current + 1) * np.exp(-(x_current + 1) ** 2 - y_current ** 2)
    pdy = (
            (-6 * x_current ** 2 + 12 * x_current - 6) * y_current - 6 * x_current ** 2 + 12 * x_current - 6) * np.exp(
        -x_current ** 2 - (y_current + 1) ** 2) - (20 * y_current ** 6 - 50 * y_current ** 4 + 20 * x_current ** 3 * y_current - 4 * x_current * y_current) * np.exp(
        -x_current ** 2 - y_current ** 2) + 2 / 3 * y_current * np.exp(-(x_current + 1) ** 2 - y_current ** 2)

    Vx = beta * Vx_old + (1 - beta) * pdx
    Vy = beta * Vy_old + (1 - beta) * pdy

    x_new = x_current - lr * Vx
    y_new = y_current - lr * Vy

    plt.arrow(x_current, y_current, x_new - x_current, y_new - y_current, length_includes_head=False, head_width=0.1, fc='r',
              ec='k')
    x_current = x_new
    y_current = y_new

plt.show()
