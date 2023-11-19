# -*- coding: utf-8 -*-
import numpy as np
import matplotlib.pyplot as plt
    
def cost_gradient(W, X, Y, n):
    Z = X @ W
    print(Z.shape)
    exp = np.exp(Z - np.max(Z,axis=1,keepdims=True))
    Y_hat = exp /np.sum(exp,axis=1,keepdims=True)
    G = (X.T @ (Y_hat - Y)) / n###### Gradient
    j = -np.mean(Y*np.log(Y_hat))###### cost with respect to current W
    return (j, G)

def train(W, X, Y, n, lr, iterations):
    J = np.zeros([iterations, 1])

    for i in range(iterations):
        (J[i], G) = cost_gradient(W, X, Y, n)
        W = W - lr*G

    return (W,J)

def error(W, X, Y):
    Z = X @ W
    exp = np.exp(Z - np.max(Z,axis=1,keepdims=True))
    Y_hat = exp /np.sum(exp,axis=1,keepdims=True)###### Output Y_hat by the trained model
    pred = np.argmax(Y_hat, axis=1)
    label = np.argmax(Y, axis=1)
    
    return (1-np.mean(np.equal(pred, label)))

iterations = 1000
lr = 0.1

data = np.loadtxt('SR.txt', delimiter=',')

n = data.shape[0]
X = np.concatenate([np.ones([n, 1]),
                    np.expand_dims(data[:,0], axis=1),
                    np.expand_dims(data[:,1], axis=1),
                    np.expand_dims(data[:,2], axis=1)],
                   axis=1)
Y = data[:, 3].astype(np.int32)
c = np.max(Y)+1
Y = np.eye(c)[Y]

W = np.random.random([X.shape[1], c])

(W,J) = train(W, X, Y, n, lr, iterations)

plt.figure()
plt.plot(range(iterations), J)

print(error(W,X,Y))