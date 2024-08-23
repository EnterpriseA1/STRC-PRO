from fractions import Fraction as Fraction
from math import sqrt, pow


def cholesky(mat, b):
    def isSymm():
        for i in range(len(mat)):
            for j in range(len(mat[0])):
                if mat[i][j] != mat[j][i]:
                    return False
        return True

    if not isSymm():
        print("Matrix is not symmetric")
        return
    else:
        row = len(mat)
        col = len(mat[0])

        l = [[Fraction(0) for j in range(col)] for i in range(row)]

        l[0][0] = sqrt((mat[0][0]))
        l[1][0] = mat[0][1] / l[0][0]
        l[2][0] = mat[0][2] / l[0][0]
        l[1][1] = sqrt(mat[1][1] - pow(l[1][0], 2))
        l[2][1] = (mat[2][1] - (l[1][0] * l[2][0])) / l[1][1]
        l[2][2] = sqrt(mat[2][2] - pow(l[2][0], 2) - pow(l[2][1], 2))

        lt = [[l[j][i] for j in range(len(l))] for i in range(len(l[0]))]

        print("Lower Triangular Matrix")
        for i in l:
            print([str(a) for a in i])
        print()
        print("Upper Triangular Matrix")
        for i in lt:
            print([str(a) for a in i])
        print()

        y = [Fraction(0) for i in range(row)]
        y[0] = b[0] / l[0][0]
        y[1] = (b[1] - (l[1][0] * y[0])) / l[1][1]
        y[2] = (b[2] - (l[2][0] * y[0]) - (l[2][1] * y[1])) / l[2][2]

        for i in y:
            print(f"y{y.index(i)+1} = {i}")

        x = [Fraction(0) for i in range(row)]
        x[2] = y[2] / lt[2][2]
        x[1] = (y[1] - (lt[1][2] * x[2])) / lt[1][1]
        x[0] = (y[0] - (lt[0][1] * x[1]) - (lt[0][2] * x[2])) / lt[0][0]
        print()
        for i in x:
            print(f"x{x.index(i)+1} = {i}")


# y1 = 7.0  x1 = 3.0
# y2 = -27.0 x2 = -6.0
# y3 = 5.0 x3 = 1.0
# mat = [
#     [Fraction(4), Fraction(2), Fraction(14)],
#     [Fraction(2), Fraction(17), Fraction(-5)],
#     [Fraction(14), Fraction(-5), Fraction(83)],
# ]
# b = [Fraction(14), Fraction(-101), Fraction(155)]
mat = [
    [Fraction(4), Fraction(3), Fraction(1)],
    [Fraction(3), Fraction(5), Fraction(2)],
    [Fraction(1), Fraction(2), Fraction(6)],
]
b = [Fraction(3125), Fraction(3150), Fraction(2800)]
cholesky(mat, b)
