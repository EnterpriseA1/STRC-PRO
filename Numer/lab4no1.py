import numpy as np
arr = np.array([[-2 ,3 ,1],
                [3 , 4 ,-5],
                [1, -2 ,1]])
B = np.array([[9,0,-4]])
C = [0 for i in range(len(arr))]
detA = int(np.linalg.det(arr))
counter = 0
for i in range(3):
    tempMat = arr.copy()
    tempMat[:,i] = B.copy()
    C[i] = round(int(np.linalg.det(tempMat))/detA)
print(C)