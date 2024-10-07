def gaussJordan(mat):
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
    current -= 1
    while current != -1:
        for i in range(current, -1, -1):
            pivot = mat[current][current]
            temp = mat[i][current]
            for j in range(len(mat[0])):
                if i == current:
                    mat[i][j] /= pivot
                else:
                    mat[i][j] -= temp * mat[current][j]
        current -= 1
    return mat


n = int(input("Input number of data :"))
x = [int(input("x : ")) for i in range(n)]
y = [int(input("y : ")) for i in range(n)]
sumX = sum(x)
sumXsquare = sum([x[i] ** 2 for i in range(n)])
sumXY = sum([x[i] * y[i] for i in range(n)])
sumY = sum(y)

matA = [[n, sumX, sumY], [sumX, sumXsquare, sumXY]]
solved = gaussJordan(matA)

a0 = solved[0][len(matA)]
a1 = solved[1][len(matA)]

xToSolve = int(input("Input x: "))
print(f"f({xToSolve}) = {a0} + {a1}({xToSolve})")
print(f"f({xToSolve}) = {a0 + a1 * xToSolve}")
