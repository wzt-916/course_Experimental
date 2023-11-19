# -*- coding: utf-8 -*-
import numpy as np
import matplotlib.pyplot as plt
    
def cost_gradient(W, X, Y, n):
    Y_hat = np.dot(X, W)
    G = np.dot(X.T, (Y_hat - Y)) / n
    j = (1 / (2 * n)) * np.sum((Y_hat - Y) ** 2)

    return (j, G)

def train(W, X, Y, n, lr, iterations):
    J = np.zeros([iterations, 1])

    for i in range(iterations):
        (J[i], G) = cost_gradient(W, X, Y, n)
        W = W - lr * G

    return (W, J)

def error(W, X, Y):
    Y_hat = np.dot(X, W)
    pred = np.argmax(Y_hat, axis=1)
    label = np.argmax(Y, axis=1)
    
    return (1 - np.mean(np.equal(pred, label)))

iterations = 1000 # 填写训练轮数
lr = 0.01 # 填写学习率

data = np.loadtxt('SR.txt', delimiter=',')

n = data.shape[0]
X = np.concatenate([np.ones([n, 1]),
                    np.expand_dims(data[:, 0], axis=1),
                    np.expand_dims(data[:, 1], axis=1),
                    np.expand_dims(data[:, 2], axis=1)],
                   axis=1)
Y = data[:, 3].astype(np.int32)
c = np.max(Y) + 1
Y = np.eye(c)[Y]

W = np.random.random([X.shape[1], c])

(W, J) = train(W, X, Y, n, lr, iterations)

plt.figure()
plt.plot(range(iterations), J)

print(error(W, X, Y))
