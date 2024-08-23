from fractions import Fraction as fr
import numpy as np

def identityMatrix(n):
    mat = []
    for i in range(n):
        temp = []
        for j in range(n):
            if i == j:
                temp.append(1)
            else:
                temp.append(0)
        mat.append(temp)
    return mat


def matrixInversion(mat, matI):

    current = 0
    while current != len(mat):
        for i in range(current, len(mat)):
            pivot = mat[current][current]
            temp = mat[i][current]
            for j in range(len(mat[0])):
                if i == current:
                    mat[i][j] /= pivot
                    matI[i][j - 1] /= pivot
                else:
                    mat[i][j] -= temp * mat[current][j]
                    matI[i][j - 1] -= temp * matI[current][j - 1]
        current += 1
    current -= 1
    while current != -1:
        for i in range(current, -1, -1):
            pivot = mat[current][current]
            temp = mat[i][current]
            for j in range(len(mat[0])):
                if i == current:
                    mat[i][j] /= pivot
                    matI[i][j - 1] /= pivot
                else:
                    mat[i][j] -= temp * mat[current][j]
                    matI[i][j - 1] -= temp * matI[current][j - 1]
        current -= 1

    return matI


def solveX(mat, b):
    x = {i: 0 for i in range(1, 4)}
    row, col = len(mat) - 1, len(mat[0]) - 1
    index = 1
    for i in range(row + 1):
        temp = 0
        for j in range(col + 1):
            temp += mat[i][j] * b[j]
        x[index] = temp
        index += 1
    for i in range(1, 4):
        print(f"x{i} = {round(x[i])}")


arr = np.array([[fr(-2), fr(3), fr(1)], [fr(3), fr(4), fr(-5)], [fr(1), fr(-2), fr(1)]])
b = np.array([fr(9), fr(0), fr(-4)])
print("Matrix I")
matI = identityMatrix(len(arr))
for i in matI:
    print([str(element) for element in i])
print()
print("Matrix A (Augmented)")
for i in arr:
    print([str(element) for element in i])
print()
print("Matrix A (Inverted)")
arr = matrixInversion(arr, matI)
for i in arr:
    print([str(element) for element in i])
solveX(matI, b)