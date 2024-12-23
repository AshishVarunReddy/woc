import pandas as pd
import numpy as np
import matplotlib.pyplot as plt


def hello():
    print('hello world')

def generate_combinations(features, degree, current_combo=[], start=0):
    
    if degree == 0:
        return [current_combo]
    
    combinations = []
    for i in range(start, features):
        combinations += generate_combinations(features, degree - 1, current_combo + [i], i)
    return combinations

def create_polynomial_features(X, degree):
    # Ensure X is a 2D array
    X = np.array(X)
    if X.ndim == 1:
        X = X[:, np.newaxis]
    
    n_samples, n_features = X.shape
    # Start with a column of ones (intercept)
    poly_features = np.ones((n_samples, 1))
    
    # Generate polynomial terms using manual combinations
    for d in range(1, degree + 1):
        combos = generate_combinations(n_features, d)
        for combo in combos:
            term = np.prod(X[:, combo], axis=1, keepdims=True)
            poly_features = np.hstack((poly_features, term))
    
    return poly_features




def cost(X, y, degree, w, b):
    poly_features = create_polynomial_features(X, degree)
    costsum = 0
    m = len(X)
    costsum = np.sum((y - poly_features.dot(w) - b)**2)
    cost = (1/(2*m)) * costsum
    return cost


def gradients(X, y, degree, w, b):
   
    # Number of samples
    m = len(X)

    # Create polynomial features
    poly_features = create_polynomial_features(X, degree)  # Shape: (m, features)
    samples, features = poly_features.shape

    # Compute predictions
    predictions = poly_features.dot(w) + b  # Shape: (m, 1)

    # Calculate errors
    error = predictions - y  # Shape: (m, 1)

    # Gradients
    dw = (1 / m) * (poly_features.T.dot(error))  # Shape: (features, 1)
    db = (1 / m) * np.sum(error)  # Scalar

    return dw, db

#Always remember that the axis 1 of X and axis 0 of w should always be kept equal and the other dimension of w is usually 1.

def train(X, y, degree,  alpha, iters, notifier):
    pf = create_polynomial_features(X, degree)
    samples, features = pf.shape
    w = np.zeros([features, 1])
    b = 0
    for i in range(iters):
        dw, db = gradients(X, y, degree, w, b)
        w = w - alpha * dw
        b = b - alpha * db
        if i % notifier == 0: 
            print(f"cost {i}:{cost(X, y, degree, w, b)}")
            

    print("The final cost is: ", cost(X, y, degree, w, b))
    print(f"w:{w}, b:{b}")
    return w, b
      


def predict(x, degree, w, b):
    poly_x = create_polynomial_features(x, degree)
    y = np.dot(poly_x, w) + b
    return y












    
