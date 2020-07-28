import tensorflow as tf
import numpy as np

data = np.genfromtxt('./training.dat')
data2 = np.genfromtxt('./testing.dat')
data3 = np.genfromtxt('./target.dat')
x_data = data[:,0:]
input_data = data2[:,0:]
d_data = data3[:,:]

def printClass(classNum,checkNum):
    if(np.argmax(classNum) == checkNum):
        print("match class ", np.argmax(classNum),"       ",np.round(classNum,3))
    else:
        print("     err    ", np.argmax(classNum),"       ",np.round(classNum,3))
keep_prob = tf.placeholder(tf.float32)
X = tf.placeholder(tf.float32,[None,4])
Y = tf.placeholder(tf.float32,[None,3])

W1 = tf.Variable(tf.random_uniform([4,75],-1,1))
b1 = tf.Variable(tf.random_normal([75]))
L1 = tf.nn.relu(tf.matmul(X,W1)+b1)
L1 = tf.nn.dropout(L1,keep_prob=keep_prob)

w1 = tf.get_variable("w1",shape=[4,75],initializer=tf.contrib.layers.xavier_initializer())
l1 = tf.nn.relu(tf.matmul(X,w1)+b1)
l1 = tf.nn.dropout(l1,keep_prob=keep_prob)

W2 = tf.Variable(tf.random_uniform([75,75],-1,1))
b2 = tf.Variable(tf.random_normal([75]))
L2 = tf.nn.relu(tf.matmul(L1,W2)+b2)
L2 = tf.nn.dropout(L2,keep_prob=keep_prob)

w2 = tf.get_variable("w2",shape=[75,75],initializer=tf.contrib.layers.xavier_initializer())
l2 = tf.nn.relu(tf.matmul(l1,w2)+b2)
l2 = tf.nn.dropout(l2,keep_prob=keep_prob)


W3 = tf.Variable(tf.random_uniform([75,3],-1,1))
b3 = tf.Variable(tf.random_normal([3]))
stay = tf.matmul(L2,W3)+b3

w3 = tf.get_variable("w3",shape=[75,3],initializer=tf.contrib.layers.xavier_initializer())
stay2 = tf.matmul(l2,w3)+b3


Out = tf.nn.softmax(tf.matmul(L2,W3)+b3)
Out2 = tf.nn.softmax(tf.matmul(l2,w3)+b3)

cost = tf.reduce_mean(tf.nn.softmax_cross_entropy_with_logits_v2(logits =stay,labels=Y))
optimizer = tf.train.GradientDescentOptimizer(learning_rate = 0.001).minimize(cost)

cost2 = tf.reduce_mean(tf.nn.softmax_cross_entropy_with_logits_v2(logits = stay2, labels=Y))
optimizer2 = tf.train.AdamOptimizer(learning_rate = 0.001).minimize(cost2)


init = tf.global_variables_initializer()
sess = tf.Session()
sess.run(init)
batch_size = 25
total_batch = int(75 / batch_size)
for step in range(5000):
    for batch in range(total_batch) :
        batch_x = x_data[batch*batch_size:batch*batch_size+batch_size]
        batch_y = d_data[batch*batch_size:batch*batch_size+batch_size] 
        sess.run(optimizer,feed_dict = {X:batch_x , Y:batch_y, keep_prob:0.75})
        sess.run(optimizer2,feed_dict = {X:batch_x , Y:batch_y, keep_prob:0.75})
#학습 끝
train  = sess.run(Out,feed_dict = {X:x_data, keep_prob:1})
train2 = sess.run(Out2, feed_dict = {X:x_data, keep_prob:1})
result = sess.run(Out,feed_dict = {X:input_data,keep_prob:1})
result2 = sess.run(Out2,feed_dict = {X:input_data,keep_prob:1})
for i in range(75):
     if i <25:
        printClass(result[i],0)
     elif i<50:
        printClass(result[i],1)
     elif i<75:
        printClass(result[i],2)
print("*****xavier use******")
for i in range(75):
     if i <25:
        printClass(result2[i],0)
     elif i<50:
        printClass(result2[i],1)
     elif i<75:
        printClass(result2[i],2)




        
        
