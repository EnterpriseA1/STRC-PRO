import numpy as np

arr = np.array([[-2, 3, 1], [3, 4, -5], [1, -2, 1]])
B = np.array([[9, 0, -4]])
x = [0 for i in range(len(arr))]
detA = int(np.linalg.det(arr))
for i in range(3):
    tempMat = arr.copy()
    tempMat[:, i] = B.copy()
    x[i] = round(int(np.linalg.det(tempMat)) / detA)
for i in x:
    print(f"x{x.index(i)+1} = {i}")
