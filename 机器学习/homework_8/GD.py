import numpy as np
import matplotlib.pyplot as plt

x = np.arange(-3,3,0.3)
y = np.arange(-3,3,0.3)
x,y = np.meshgrid(x,y)
levels = 24

# 3*(1-x)^2*exp(-(x^2)-(y+1)^2)-10*(x/5-x^3-y^5)*exp(-x^2-y^2)-1/3*exp(-(x+1)^2-y^2)
z = 3*(1-x)**2*np.exp(-x**2-(y+1)**2)-10*(x/5-x**3-y**5)*np.exp(-x**2-y**2)-1/3*np.exp(-(x+1)**2-y**2)

fig = plt.figure(figsize=(8,5))
plt.tick_params(labelsize=18)
plt.xlabel("$x$", fontsize=24)
plt.ylabel("$y$", fontsize=24)

plt.contourf(x,y,z,levels=levels,cmap="rainbow")
line = plt.contour(x,y,z,levels=levels,colors="k")

# x = np.random.uniform(-2,2)
# y = np.random.uniform(-2,2)
x = -0.15
y = 1.2

beta = 0.9
Vx_old = 0
Vy_old = 0
Sx_old = 0
Sy_old = 0

iterations = 1000###### Training loops
lr =  0.2 ###### Learning rate
for  i in range(iterations):
    pdx = (-6*x**3+12*x**2-6)*np.exp(-x**2-(y+1)**2)-(20*x*y**5+20*x**4-34*x**2+2)*np.exp(-x**2-y**2)+2/3*(x+1)*np.exp(-(x+1)**2-y**2)
    pdy = ((-6*x**2+12*x-6)*y-6*x**2+12*x-6)*np.exp(-x**2-(y+1)**2)-(20*y**6-50*y**4+20*x**3*y-4*x*y)*np.exp(-x**2-y**2)+2/3*y*np.exp(-(x+1)**2-y**2)

    ###### Revise the code and use different GD algorithm to reach the global optimum
    "这是GDM,beta=0.9,lr=0.2可以求出最低"
    Vx = beta * Vx_old + (1 - beta) * pdx
    Vy = beta * Vy_old + (1 - beta) * pdy
    dx = - lr * Vx
    dy = - lr * Vy
    Vx_old = Vx
    Vy_old = Vy

    "这是RMSProp,没有办法求出最低"
    # Sx = beta * Sx_old + (1 - beta) * (pdx ** 2)
    # Sy = beta * Sy_old + (1 - beta) * (pdy ** 2)
    # dx = - (lr/np.sqrt(Sx + 0.001)) * pdx
    # dy = - (lr/np.sqrt(Sy + 0.001)) * pdy
    # Sx_old = Sx
    # Sy_old = Sy

    "这是RMSProp + GDM"
    # Vx = beta * Vx_old + (1 - beta) * pdx
    # Vy = beta * Vy_old + (1 - beta) * pdy
    # Sx = beta * Sx_old + (1 - beta) * (pdx ** 2)
    # Sy = beta * Sy_old + (1 - beta) * (pdy ** 2)
    # dx = - (lr/np.sqrt(Sx + 0.001)) * Vx
    # dy = - (lr/np.sqrt(Sy + 0.001)) * Vy
    # Vx_old = Vx
    # Vy_old = Vy
    # Sx_old = Sx
    # Sy_old = Sy
    ###### Revise the code and use different GD algorithm to reach the global optimum
    plt.arrow(x, y, dx, dy, length_includes_head=False, head_width=0.1, fc='r', ec='k')
    x += dx
    y += dy
