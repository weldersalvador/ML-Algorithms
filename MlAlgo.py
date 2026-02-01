import numpy as np

class Algorithms:
    def __init__(self):
        self.a = 0
        self.b = 0
        pass

    def r_calculus(self,X,Y):
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
    
    def Regression(self,X,Y):
        X =  np.array(X)
        Y = np.array(Y)
        n = len(X)
        self.b = (n*np.sum(X*Y) - np.sum(X)*np.sum(Y)) / (n*np.sum(X**2) - (np.sum(X))**2)
        self.a = np.mean(Y) - self.b*np.mean(X)
        
    @property
    def intercept_(self):
        return self.a
    @property
    def coef_(self):
        return self.b
        


    
    