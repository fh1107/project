import numpy as np

def Sigmoid(x) :
  return (1 / (1 + np.exp(-x))

def Relu(x) :
          return np.maximum(0,x)
def SoftMax(x) :
          e_x = np.exp(x - np.max(x))
          return e_x / e_x.sum()
