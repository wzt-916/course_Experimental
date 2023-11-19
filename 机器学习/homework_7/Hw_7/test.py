# -*- coding: utf-8 -*-
import numpy as np
import matplotlib.pyplot as plt

def softmax(X):
      exp=np.exp(X-np.max(X,axis=1,keepdims=True))
      A=exp/np.sum(exp,axis=1,keepdims=True)
      return A

def sigmoid(x):
    x = np.clip(x, -500, 500)
    s = np.where(x >= 0, 1 / (1 + np.exp(-x)), np.exp(x) / (1 + np.exp(x)))
    return s  


#Utilities
def onehotEncoder(Y, ny):
      return np.eye(ny)[Y]

#Xavier Initialization
def initWeights(M):
      l = len(M)
      W = []
      B = []
      
      for i in range(1, l):
            W.append(np.random.randn(M[i-1], M[i]))
            B.append(np.zeros([1, M[i]]))
            
      return W, B

#Forward propagation
def networkForward(X, W, B):
      l = len(W)
      
      A = [X]
      for i in range(l):
            Z = np.dot(A[i], W[i]) + B[i]
            if i == l - 1: # Output layer
                  A_next = softmax(Z)
            else:
                  A_next = sigmoid(Z) # it can be other activation function like np.tanh(Z), relu etc.
            A.append(A_next)

      ##### Calculate the output of every layer A[i], where i = 0, 1, 2, ..., l

      return A
#--------------------------

#Backward propagation
def networkBackward(Y, A, W):
      l = len(W)
      dW = []
      dB = []
      A[l]-=Y
      N = Y.shape[0]
      for i in range(l-1,-1,-1):
            dW.insert(0,np.dot(A[i].T,A[i+1]) / N)
            dB.insert(0,np.mean(A[i+1],axis=0))
            A[i]=np.dot(A[i+1],W[i].T)*A[i]*(1-A[i])
 


      ##### Calculate the partial derivatives of all w and b in each layer dW[i] and dB[i], where i = 1, 2, ..., l

      return dW, dB
#--------------------------

#Update weights by gradient descent
def updateWeights(W, B, dW, dB, lr):
      l = len(W)


      for i in range(l):
            W[i] = W[i] - lr*dW[i]
            B[i] = B[i] - lr*dB[i]

      return W, B

#Compute regularized cost function
def cost(A_l, Y, W):
      n = Y.shape[0]
      A_l = np.clip(A_l, 1e-10, 1-1e-10)
      c = -np.sum(Y*np.log(A_l)) / n

      return c

def train(X, Y, M, lr = 0.1, iterations = 3000):
      costs = []
      W, B = initWeights(M)
      print(len(W[0]))
      print(len(W[0][0]))
      print(len(W[1]))
      print(len(W[1][0]))
      


      for i in range(iterations):
            A = networkForward(X, W, B)
            c = cost(A[-1], Y, W)
            dW, dB = networkBackward(Y, A, W)
            W, B = updateWeights(W, B, dW, dB, lr)

            if i % 100 == 0:
                  if i%2000==0:
                        lr*=0.5
                  print("Cost after iteration %i: %f" %(i, c))
                  costs.append(c)

      return W, B, costs

def predict(X, W, B, Y):
      Y_out = np.zeros([X.shape[0], Y.shape[1]])
      
      A = networkForward(X, W, B)
      idx = np.argmax(A[-1], axis=1)
      Y_out[range(Y.shape[0]),idx] = 1
      
      return Y_out

def test(Y, X, W, B):
      Y_out = predict(X, W, B, Y)
      acc = np.sum(Y_out*Y) / Y.shape[0]
      print("Training accuracy is: %f" %(acc))
      
      return acc

iterations = 10001
lr = 0.01

data = np.load("data.npy")

X = data[:,:-1]
Y = data[:,-1].astype(np.int32)
(n, m) = X.shape
Y = onehotEncoder(Y, 10)

M = [400, 25, 10]
W, B, costs = train(X, Y, M, lr, iterations)

plt.figure()
plt.plot(range(len(costs)), costs)

test(Y, X, W, B)
