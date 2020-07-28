import numpy as np
import numpy.random as rd
import tensorflow as tf
def numpy_open(path) :
        #파일 열기
        data = np.genfromtxt(path)
        return data

def Sigmoid(a):
        return (1 / (1 + np.exp(-a)))

def Relu(b):
        return np.maximum(0,b)
def SoftMax(s):
        e_x = np.exp(x - np.max(x))
        return e_x / e_x.sum()
path = './training.dat'
data = numpy_open(path)
W1 = 2*rd.rand(4,4)-1
W2 = 2*rd.rand(4,3)-1
W3 = 2*rd.rand(3,3)-1

rate = 0.7
for i in range(75) :
        x = data[i]
        print("x : ",x)
        if 0 <= i < 25 :
                d = [1,0,0]
        if 25 <= i <50 :
                d = [0,1,0]
        if 50 <= i <75:
                d = [ 0,0,1]

        v1 = np.matmul(x,W1)
        y1 = Relu(v1)
        v2 = np.matmul(y1,W2)
        y2 = Relu(v2)
        print("y2 :",y2)
        
        v3 = np.matmul(y2,W3) # 1,3 3 * 3
        y3 = SoftMax(v3)
        print("y3 : ",y3)
        

        
