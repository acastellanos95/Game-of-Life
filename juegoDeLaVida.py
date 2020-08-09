import numpy as np
import seaborn as sns
import matplotlib.pyplot as plt
from matplotlib import animation

class GameOfLife:
    def __init__(self, row_m, col_n, num_iter):
        self.row_m = row_m
        self.col_n = col_n
        self.num_iter = num_iter
        #create a 3D array with row_m height, row_m width and num_iter depth
        self.golArray = np.ndarray((num_iter, row_m, col_n),dtype = int)
        #Initialize 3D array with zeros
        for i in np.arange(num_iter):
            self.golArray[i] = np.zeros((row_m, col_n),dtype = int)

    def golRules(self, c1, c2, c3, c4, c5, c6, c7, c8, c9):
        total = c2 + c3 + c4 + c5 + c6 + c7 + c8 + c9
        if c1 == 1:
            if (total < 2) or (total > 3):
                return 0
            if (total == 2) or (total == 3):
                return 1
        elif c1 == 0:
            if (total == 3):
                return 1
            else:
                return 0
    
    def play(self):
        #randomize 1 and 0 in array
        self.golArray[0] = np.random.randint(low = 0, high = 2, size = (self.row_m, self.col_n), dtype = int)

        #apply it
        for j in range(self.num_iter-1):
            for l in range(self.row_m):
                for m in range(self.col_n):
                    self.golArray[j+1,l,m] = self.golRules(self.golArray[j,l%self.row_m,m%self.col_n], self.golArray[j,(l-1)%self.row_m,(m-1)%self.col_n], self.golArray[j,(l-1)%self.row_m,(m)%self.col_n], self.golArray[j,(l-1)%self.row_m,(m+1)%self.col_n],
                                            self.golArray[j,(l)%self.row_m,(m-1)%self.col_n], self.golArray[j,(l)%self.row_m,(m+1)%self.col_n], self.golArray[j,(l+1)%self.row_m,(m-1)%self.col_n], self.golArray[j,(l+1)%self.row_m,(m)%self.col_n],
                                            self.golArray[j,(l+1)%self.row_m,(m+1)%self.col_n])
        return self.golArray


if __name__ == "__main__":
    game1 = GameOfLife(15, 10, 5)
    gameArray = game1.play()
    for times in range(game1.num_iter):
        print(gameArray)

""" row_m = 10
col_n = 15
num_iter = 10
nIter = num_iter
CA = np.ndarray((30,row_m, col_n), dtype = int)

#Create array
for i in np.arange(nIter):
    CA[i] = np.zeros((row_m, col_n), dtype = int)


#Rule
def gameLife(c1,c2,c3,c4,c5,c6,c7,c8,c9):
    total = c2 + c3 + c4 + c5 + c6 + c7 + c8 + c9
    if c1 == 1:
        if (total < 2) or (total > 3):
            return 0
        if (total == 2) or (total == 3):
            return 1
    elif c1 == 0:
        if (total == 3):
            return 1
        else:
            return 0


#randomize 1 and 0 in array
CA[0] = np.random.randint(low = 0, high = 2, size = (row_m, col_n), dtype = int)

#apply it
for j in range(nIter-1):
    for l in range(row_m):
        for m in range(col_n):

            CA[j+1,l,m] = gameLife(CA[j,l%row_m,m%col_n], CA[j,(l-1)%row_m,(m-1)%col_n], CA[j,(l-1)%row_m,(m)%col_n], CA[j,(l-1)%row_m,(m+1)%col_n],
                                    CA[j,(l)%row_m,(m-1)%col_n], CA[j,(l)%row_m,(m+1)%col_n], CA[j,(l+1)%row_m,(m-1)%col_n],CA[j,(l+1)%row_m,(m)%col_n],
                                    CA[j,(l+1)%row_m,(m+1)%col_n]) """