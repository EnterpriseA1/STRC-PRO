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


def sumXSquareOrder(x, m):
    sumXsquare = sum([x[i] ** m for i in range(len(x))])
    return sumXsquare


def sumXYsquareOrder(x, y, m):
    sumXYsquare = sum([x[i] ** m * y[i] for i in range(len(x))])
    return sumXYsquare


n = int(input("Input number of data : "))
order = int(input("Input order : "))
x = [int(input("x : ")) for i in range(n)]
y = [int(input("y : ")) for i in range(n)]

matA = []
for i in range(0, order + 1):
    matA.append([sumXSquareOrder(x, j) for j in range(i, i + order + 1)])
matB = [sumXYsquareOrder(x, y, i) for i in range(0, order + 1)]

for i in range(len(matA)):
    matA[i].append(matB[i])

solved = gaussJordan(matA)
a = [matA[i][len(matA)] for i in range(order + 1)]

print()
xToSolve = int(input("Input x: "))
print(f"f({xToSolve}) = ", end="")
for i in range(order + 1):
    if i == 0:
        print(f"{a[i]}", end="")
    else:
        print(f" + {a[i]}({xToSolve})^{i}", end="")
print()
print(f"f({xToSolve}) = {a[0]+sum([a[i]*xToSolve**i for i in range(1,order+1)])}")
