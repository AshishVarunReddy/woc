import pandas as pd
import numpy as np
import matplotlib.pyplot as plt


def accuracy(y_pred, y):
    y_predr = y_pred.round(0)
    value = 0
    n = len(y)
    for i in range(n):
        if y[i][0] == y_predr[i][0]:
            value += 1
    accuracy_score = (value/n)*100
    return accuracy_score
 
 # Sigmoid function
def sigmoid(z):
    value = (1 / (1 + np.exp(-z))).round(2)
    return value

# Cost function
def compute_cost(X, y, w, b):
    m = len(y)
    z = np.dot(X, w) + b
    predictions = sigmoid(z)
    print(f"accuracy is : {accuracy(predictions, y)}")
    loss = y * np.log(predictions) + (1 - y) * np.log(1 - predictions)
    cost = -(1 / m) * np.sum(loss)
    return cost


# Gradient computation
def compute_gradients(X, y, w, b):
    m = len(y)
    z = np.dot(X, w) + b
    predictions = sigmoid(z)
    error = predictions - y
    dw = (1 / m) * np.dot(X.T, error)
    db = (1 / m) * np.sum(error)
    return dw, db

# Gradient descent
def gradient_descent(X, y, w, b, alpha, num_iterations):
    for i in range(num_iterations):
        dw, db = compute_gradients(X, y, w, b)
        w -= alpha * dw
        b -= alpha * db
        if i % 10 == 0:  # Print cost every 100 iterations
            cost = compute_cost(X, y, w, b)
            print(f"Iteration {i}: Cost = {cost}")
    return w, b

def hello():
    print("Hello World")