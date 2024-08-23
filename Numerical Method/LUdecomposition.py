from fractions import Fraction as Fraction


def decomposition(mat, b):
    # row = 3, col = 3
    row = len(mat)
    col = len(mat[0])

    l = [[Fraction(0) for j in range(col)] for i in range(row)]
    u = [
        [Fraction(1) if i == j else Fraction(0) for j in range(col)] for i in range(row)
    ]

    l[0][0] = mat[0][0]
    u[0][1] = mat[0][1] / l[0][0]
    u[0][2] = mat[0][2] / l[0][0]
    l[1][0] = mat[1][0]
    l[1][1] = mat[1][1] - (l[1][0] * u[0][1])
    u[1][2] = (mat[1][2] - (l[1][0] * u[0][2])) / l[1][1]
    l[2][0] = mat[2][0]
    l[2][1] = mat[2][1] - (l[2][0] * u[0][1])
    l[2][2] = mat[2][2] - (l[2][0] * u[0][2]) - (l[2][1] * u[1][2])

    l = [[Fraction(j) for j in i] for i in l]
    u = [[Fraction(j) for j in i] for i in u]

    y = [Fraction(0) for i in range(row)]
    y[0] = b[0] / l[0][0]
    y[1] = (b[1] - (l[1][0] * y[0])) / l[1][1]
    y[2] = (b[2] - (l[2][0] * y[0]) - (l[2][1] * y[1])) / l[2][2]

    x = [Fraction(0) for i in range(row)]
    x[2] = y[2]
    x[1] = y[1] - (u[1][2] * x[2])
    x[0] = y[0] - (u[0][1] * x[1]) - (u[0][2] * x[2])

    print("Lower Triangular Matrix")
    for i in l:
        print([str(a) for a in i])
    print()
    print("Upper Triangular Matrix")
    for i in u:
        print([str(a) for a in i])
    print()
    for i in y:
        print(f"y{y.index(i)+1} = {i}")
    print()
    for i in x:
        print(f"x{x.index(i)+1} = {i}")


mat = [
    [Fraction(-2), Fraction(3), Fraction(1)],
    [Fraction(3), Fraction(4), Fraction(-5)],
    [Fraction(1), Fraction(-2), Fraction(1)],
]
b = [Fraction(9), Fraction(0), Fraction(-4)]
decomposition(mat, b)
