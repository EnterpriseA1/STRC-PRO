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


def sumXk(x):
    sumXk = sum(x[i] for i in range(len(x)))
    return sumXk


def sumX1X2(x, k, index):
    sumX1X2 = sum(x[index][i] * x[k][i] for i in range(len(x[0])))
    return sumX1X2


def sumXY(x, y, index):
    sumXY = sum(x[index][i] * y[i] for i in range(len(x[0])))
    return sumXY


n = int(input("Input number of data : "))
k = int(input("Input k : "))
x = [[int(input("x : ")) for i in range(n)] for j in range(k)]
y = [int(input("y : ")) for i in range(n)]

matA = [[n] + [sumXk(i) for i in x]]
for i in range(k):
    matA.append([sumXk(x[i])] + [sumX1X2(x, j, i) for j in range(k)])
matB = [sumXk(y)] + [sumXY(x, y, i) for i in range(k)]
for i in range(len(matA)):
    matA[i].append(matB[i])

solved = gaussJordan(matA)
a = [matA[i][len(matA)] for i in range(k + 1)]

print()
xToSolve = [int(input(f"Input x{i+1}: ")) for i in range(k)]
print()
print(f"f({xToSolve}) = ", end="")
for i in range(k + 1):
    if i == 0:
        print(f"{a[i]}", end="")
    else:
        print(f" + {a[i]}({xToSolve[i-1]})", end="")
print()
print(f"f({xToSolve}) = {a[0]+sum([a[i]*xToSolve[i-1] for i in range(1,k+1)])}")
