from MlAlgo import Algorithms
import numpy as np
import matplotlib.pyplot as plt
import pandas as pd

obj = Algorithms()

array = np.array([[1,2,3],
                [2,4,6],
                [3,1,5]])

corr_matrix = obj.corr_matrix(array)

print(corr_matrix)

print()

X = np.array([1,2,5,2,5,7,2,3,5])

Y = np.array([3,1,5,7,3,2,6,8,3])

obj.Regression(X,Y)
print(f"Coeficient: {obj.coef_}\nIntercept: {obj.intercept_}")

y_pred = obj.coef_*X + obj.intercept_

plt.scatter(x = X, y = Y)
plt.plot(X,y_pred)
plt.show()





