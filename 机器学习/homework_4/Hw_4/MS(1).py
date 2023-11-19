# -*- coding: utf-8 -*-
import numpy as np
from sklearn.preprocessing import PolynomialFeatures
import matplotlib.pyplot as plt
# def generate_poly_features(X, degree=6):
#     poly = PolynomialFeatures(degree)
#     return poly.fit_transform(X)
def sigmoid(z):
    return 1 / (1 + np.exp(-z))
def read_data(addr):
    data = np.loadtxt(addr, delimiter=',')

    n = data.shape[0]
    # X_raw = data[:,:-1]
    # X_ploy = generate_poly_features(X_raw)
    ###### You may modify this section to change the model
    X_raw= np.concatenate([np.ones([n, 1]), data[:,0:6]], axis=1)
    # X = np.concatenate([np.ones([n, 1]), X], axis=1)
    ###### You may modify this section to change the model
    # X_raw = data[:, :-1]

    # 生成多项式特征
    poly = PolynomialFeatures(degree=3)  # 可以更改degree为你想要的值
    X_poly = poly.fit_transform(X_raw)

    # 将偏置项（一列1）和多项式特征连接起来
    # 注意：因为PolynomialFeatures会自动为我们生成偏置项（即一列1），所以我们不需要再次手动添加。
    X = X_poly
    Y = None
    if "train" in addr:
        Y = np.expand_dims(data[:, 6], axis=1)
    
    return (X,Y,n)

def cost_gradient(W, X, Y, n):
    h = sigmoid(X@W)
    j = -np.mean(Y * np.log(h) + (1 - Y) * np.log(1 - h))

    G = (1/n) * X.T @ (h - Y)###### Gradient梯度
    # j =###### cost with respect to current W价值

    return (j, G)

def train(W, X, Y, lr, n, iterations):
    ###### You may modify this section to do 10-fold validation
    J = np.zeros([iterations, 1])
    E_trn = np.zeros([iterations, 1])
    E_val = np.zeros([iterations, 1])
    n = int(0.9*n)
    X_trn = X[:n]
    Y_trn = Y[:n]
    X_val = X[n:]
    Y_val = Y[n:]

    for i in range(iterations):
        (J[i], G) = cost_gradient(W, X_trn, Y_trn, n)
        W = W - lr*G
        E_trn[i] = error(W, X_trn, Y_trn)
        E_val[i] = error(W, X_val, Y_val)

    print(E_val[-1])
    ###### You may modify this section to do 10-fold validation

    return (W,J,E_trn,E_val)

def error(W, X, Y):
    Y_hat = 1 / (1 + np.exp(-X@W))
    Y_hat[Y_hat<0.5] = 0
    Y_hat[Y_hat>0.5] = 1

    return (1-np.mean(np.equal(Y_hat, Y)))


def k_fold_train(X, Y, W, lr, iterations, k=10):
    fold_size = int(Y.shape[0] / k)
    E_vals = []
    Ws = []
    Js = []
    E_trns = []
    for fold in range(k):
        start = fold * fold_size
        end = (fold + 1) * fold_size

        X_val = X[start:end]
        Y_val = Y[start:end]

        X_trn = np.vstack((X[:start], X[end:]))
        Y_trn = np.vstack((Y[:start], Y[end:]))

        W1, J1, E1, E_val = train(W, X_trn, Y_trn, lr, X_trn.shape[0], iterations)
        E_vals.append(E_val[-1])
        Ws.append(W1)
        Js.append(J1)
        E_trns.append(E1)
    return np.mean(E_vals),E_vals,Ws,Js,E_trns


def predict(W):
    (X, _, _) = read_data("test_data.csv")

    Y_hat = 1 / (1 + np.exp(-X@W))
    Y_hat[Y_hat<0.5] = 0
    Y_hat[Y_hat>0.5] = 1

    idx = np.expand_dims(np.arange(1,201), axis=1)
    np.savetxt("predict.csv", np.concatenate([idx, Y_hat], axis=1), header = "Index,ID", comments='', delimiter=',')

iterations = 100000###### Training loops
lr = 0.0001###### Learning rate

(X, Y, n) = read_data("train.csv")
W = np.random.random([X.shape[1], 1])

# (W,J,E_trn,E_val) = train(W, X, Y, lr, n, iterations)

k_fold_error,E_vals,Ws,Js,E_trns= k_fold_train(X, Y, W, lr, iterations, 10)
print(f"10-Fold Validation Error: {k_fold_error}")
print(E_vals)
###### You may modify this section to do 10-fold validation
# plt.figure()
# plt.plot(range(iterations), Js[9])
# plt.figure()
# plt.ylim(0,1)
# plt.plot(range(iterations), E_trns[9], "b")
# plt.plot(range(iterations), E_vals[9], "r")
# plt.show()
###### You may modify this section to do 10-fold validation

predict(Ws[9])
