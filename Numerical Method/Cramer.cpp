#include <iostream>
void printMatrix(double[][4]);
double det(double[][3]);
void solveX(double[][3], double[]);
int main()
{
    double matrix[3][3] = {
        {-2, 3, 1},
        {3, 4, -5},
        {1, -2, 1}};
    double matDet = det(matrix);
    double b[3] = {9, 0, -4};
    solveX(matrix, b);
    return 0;
}

void printMatrix(double mat[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cout << mat[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

void solveX(double mat[3][3], double b[])
{
    double temp[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            temp[i][j] = mat[i][j];
        }
    }
    int counter = 0;
    double x;
    do
    {

        for (int i = 0; i < 3; i++)
        {
            mat[i][counter] = b[i];
        }

        x = det(mat) / det(temp);
        std::cout << "detA" << counter + 1 << " = " << det(mat) << ", ";
        std::cout << "detA = " << det(temp) << std::endl;
        std::cout << "x" << counter + 1 << " = " << x << std::endl;

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                mat[i][j] = temp[i][j];
            }
        }
        counter++;
    } while (counter != 3);
}

double det(double mat[3][3])
{
    return (mat[0][0] * mat[1][1] * mat[2][2]) + (mat[0][1] * mat[1][2] * mat[2][0]) + (mat[0][2] * mat[1][0] * mat[2][1]) - (mat[0][2] * mat[1][1] * mat[2][0]) - (mat[0][1] * mat[1][0] * mat[2][2]) - (mat[0][0] * mat[1][2] * mat[2][1]);
}