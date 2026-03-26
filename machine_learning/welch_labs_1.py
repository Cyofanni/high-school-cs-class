import numpy as np

class neural_network(object):
  def __init__(self):
    #define hyperparameters
    self.input_layer_size = 2
    self.output_layer_size = 1
    self.hidden_layer_size = 3

  def forward(self, X):
    #propagate inputs through network; use matrix multiplication

    '''
       X =
       [
        [3,5],
        [5,1],
        [10,2]
       ]

       Wijk: weight of connection between i-th neuron of of k-th layer
              and j-th neuron of (k+1)-th layer
       W__0 =
       [
        [W000, W010, W020],
        [W100, W110, W120]
       ]

       z1 = X * W__0
       z1 (a matrix) is the level of activation of layer 1,
       once we have z1, we apply the activation function on it

       a1 = sigmoid(z1)

       z2 = a1 * W__1

       y_hat = a2 = sigmoid(z2)
    '''

    self.W__0 = np.random.randn(self.input_layer_size, \
                                self.hidden_layer_size)
    self.W__1 = np.random.randn(self.hidden_layer_size, \
                                self.output_layer_size)

    self.z1 = np.dot(X, self.W__0)
    self.a1 = self.sigmoid(self.z1)
    self.z2 = np.dot(self.a1, self.W__1)

    y_hat = self.sigmoid(self.z2)

    return y_hat

  def sigmoid(self, z):
    return 1 / (1 + np.exp(-z))
