from fractions import Fraction as Fraction


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


mat = [
    [Fraction(-2), Fraction(3), Fraction(1)],
    [Fraction(3), Fraction(4), Fraction(-5)],
    [Fraction(1), Fraction(-2), Fraction(1)],
]
b = [Fraction(9), Fraction(0), Fraction(-4)]
print("Matrix I")
matI = identityMatrix(len(mat))
for i in matI:
    print([str(output) for output in i])
print()
print("Matrix A")
for i in mat:
    print([str(output) for output in i])
print()
print("Matrix A (Inverted)")
mat = matrixInversion(mat, matI)
for i in mat:
    print([str(output) for output in i])
print()
solveX(matI, b)
