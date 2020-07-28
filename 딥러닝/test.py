import numpy as np
import numpy.random as rd
class crate_delta :
    def Create_delta() :
        if mode  == SIGMOID :
            a = 1
        elif  mode  == RELU : 
            a = 1
        elif mode == STEP :
            a = 1
        elif mode == SOFTMAX :
            a = 1
        return
class Activate_Func : 
    def __init__(self):
        super().__init__()
        self.mode = 'Sigmoid'

    def ACT(self, weight_sum) :
        if self.mode == 'Sigmoid' :
            return Sigmoid(weight_sum)
        elif self.mode == 'Relu' :
            return Relu(weight_sum)
        elif self.mode == 'Step' :
            return Step(weight_sum)
        elif self.mode == 'SoftMax' :
            return SoftMax(weight_sum)
        else :
            print("모드 선택 오류")
            return
    def Sigmoid(self, weight_sum) :
        return (1 / (1 + np.exp(-weight_sum)))

    def Relu (self, weight_sum) :
        return np.maximum(0,weight_sum)

    def Step (self, weight_sum) :
        return [ 0 if x<=0 else 1 for x in weight_sum ]

    def SoftMax (self, weight_sum) :
        e_x = np.exp(x - np.max(x))
        return e_x / e_x.sum()
class perceptron :
    def __init__(self):
        super().__init__()
        self.mode = 'Sigmoid'
        self.BIAS = 0.1;
        self.TRAINING_COUNT = 5000;
        self.first_weight = 2*rd.rand(4,4) -1
        self.second_weight = 2*rd.rand(4,4) -1
        self.last_weight = 2*rd.rand(4,3) -1
    def numpy_open(path) :
        #파일 열기
        data = np.genfromtxt(path)
        return data

    def FEEDFORWARD(input) :
        V1 = np.matmul(input, self.first_weight) + self.BIAS
        Y1 = activate.ACT(V1)

        V2 = np.matmul(Y1, self.second_weight) + self.BIAS
        Y2 =  activate.ACT(V2)

        VL = np.matmul(Y2, self.last_weight) + self.BIAS
        YL =  activate.ACT(VL)
        return YL

    def BACKPROP () :
        return YL

def numpy_open(path) :
    #파일 열기

    data = np.genfromtxt(path)
    #print(data)
    return data

def Sigmoid(weight_sum) :
    return (1 / (1 + np.exp(-weight_sum)))

path = './training.dat'
data = numpy_open(path)

#연결 가중치 초기화
first_weight = 2*rd.rand(4,4) -1
second_weight = 2*rd.rand(4,4) -1
last_weight = 2*rd.rand(4,3) -1
print(last_weight)
activate = Activate_Func()
BIAS = 0.1;
alpha = 1

for count in range(0, 75) :
    input = data[count,:]
    print("input : " ,input)
    if 0 <= count < 25 :
        d = [1,0,0]
    elif 25 <= count < 50 :
        d = [0,1,0]
    elif 50 <= count < 75 :
        d = [0,0,1]
    # 순전파
    V1 = np.matmul(input, first_weight) + BIAS
    Y1 = activate.ACT(V1)

    V2 = np.matmul(Y1, second_weight) + BIAS
    Y2 =  activate.ACT(V2)

    VL = np.matmul(Y2, last_weight) + BIAS
    YL =  activate.ACT(VL)
    print("VL : " ,YL)
