from fractions import Fraction as Fraction


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
    x = {i: 0 for i in range(1, 4)}
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


mat = [
    [Fraction(-2), Fraction(3), Fraction(1), Fraction(9)],
    [Fraction(3), Fraction(4), Fraction(-5), Fraction(0)],
    [Fraction(1), Fraction(-2), Fraction(1), Fraction(-4)],
]
print("Matrix A Augmented (Before Elimination)")
for i in mat:
    print([str(output) for output in i])
print()
print("Matrix A Augmented (After Elimination)")
mat = gaussElimination(mat)
for i in mat:
    print([str(output) for output in i])
print()
solveX(mat)
