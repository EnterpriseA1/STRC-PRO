def linearSpline(data, x):
    n = len(data)
    for i in range(n - 1):
        if data[i][0] <= x <= data[i + 1][0]:
            slope = (data[i + 1][1] - data[i][1]) / (data[i + 1][0] - data[i][0])
            return data[i][1] + slope * (x - data[i][0])


def slope(data):
    n = len(data)
    for i in range(n - 1):
        slope = (data[i + 1][1] - data[i][1]) / (data[i + 1][0] - data[i][0])
        print(f"Slope {i+1} : {slope}")


n = int(input("Input number of data :"))
data = [[float(input("x : ")), float(input("y : "))] for i in range(n)]
solve = float(input("Input x : "))

slope(data)
print(f"Value of f({solve}) : {linearSpline(data, solve)}")

# 5
# 2
# 9.5
# 4
# 8.0
# 6
# 10.5
# 8
# 39.5
# 10
# 72.5
# 4.5
