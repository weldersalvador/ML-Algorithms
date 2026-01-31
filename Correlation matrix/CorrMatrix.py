import numpy as np

class CorrMatrix:
    def __init__(self,arr):
        self.array = arr
        print("Array analisado: ", self.array)
        corr_matrix = np.zeros(shape=self.array.shape)
        for c1 in range(self.array.shape[1]):
            column1 = self.array[:, c1]
            for c2 in range(self.array.shape[1]):
                column2 = self.array[:, c2]
                corr_matrix[c1][c2] = self.r_calculus(column1,column2)
        print(self.corr_matrix)
        

    
    def r_calculus(self,X,Y):
        n = len(X)
        nom = n*np.sum(X*Y) - np.sum(X)*np.sum(Y)
        denom = ((n*np.sum(X**2) - np.sum(X)**2)*(n*np.sum(Y**2) - np.sum(Y)**2))**(1/2)
        if denom == 0:
            return np.nan
        return nom / denom
    
    