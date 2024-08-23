from fractions import Fraction as fr
import numpy as np

def gaussElimination(mat):
    current = 0
    while current != len(mat):
        for i in range(current, len(mat)):
            pivot = mat[current][current]
            temp = mat[i][current]
            for j in range(len(mat[0])):
                if i == current:
                    mat[i][j] /= pivot
                else:
                    mat[i][j] -= temp * mat[current][j]
        current += 1
    return mat


def solveX(mat):
    x = {1: 0, 2: 0, 3: 0}
    row, col = len(mat) - 1, len(mat[0]) - 1
    x[3] = mat[row][col]
    x[2] = mat[row - 1][col] - (mat[row - 1][col - 1] * x[3])
    x[1] = (
        mat[row - 2][col]
        - (mat[row - 2][col - 1] * x[3])
        - (mat[row - 2][col - 2] * x[2])
    )
    for i in range(1, 4):
        print(f"x{i} = {round(x[i])}")


arr = np.array([[fr(-2), fr(3), fr(1), fr(9)], [fr(3), fr(4), fr(-5), fr(0)], [fr(1), fr(-2), fr(1), fr(-4)]])
print("Before Elimination")
for i in arr:
    print([str(element) for element in i])
print()
print("After Elimination")
mat = gaussElimination(arr)
for i in mat:
    print([str(element) for element in i])
solveX(mat)