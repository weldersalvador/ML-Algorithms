from MlAlgo import Algorithms
import numpy as np
import matplotlib.pyplot as plt
import pandas as pd

obj = Algorithms

array = np.array([[1,2,3],
                [2,4,6],
                [3,1,5]])

corr_matrix = obj.corr_matrix(obj,array)

print(corr_matrix)





