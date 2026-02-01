import numpy as np

class Algorithms:
    def __init__(self):
        pass

    def r_calculus(X,Y):
        n = len(X)
        nom = n*np.sum(X*Y) - np.sum(X)*np.sum(Y)
        denom = ((n*np.sum(X**2) - np.sum(X)**2)*(n*np.sum(Y**2) - np.sum(Y)**2))**(1/2)
        if denom == 0:
            return np.nan
        return nom / denom
    
    def corr_matrix(self,arr):
        array = np.array(arr)
        print("Array analisado: ",array)
        corr_matrix = np.zeros(shape=array.shape)
        for c1 in range(array.shape[1]):
            column1 = array[:, c1]
            for c2 in range(array.shape[1]):
                column2 = array[:, c2]
                corr_matrix[c1][c2] = self.r_calculus(column1,column2)
        corr_matrix = np.array(corr_matrix)
        return corr_matrix
    
    