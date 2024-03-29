#include <stdio.h>

double functionM(void);
int functionN(int n, double x);
double functionO(double, int, double, int);
double functionP(int a, int n, int b, int c);

int main(void)
{
    int a, b, c, d, e;
    double r, s, t, u, v;

    functionM();// ไม่มีข้อผิดพลาด
    a = functionM();// ไม่มีข้อผิดพลาด
    b = functionN(a, b);// ไม่มีข้อผิดพลาด
    r = functionO(r, a, s, b);// ไม่มีข้อผิดพลาด
    // s = functionP(a, b, c, d, e);// argument เกิน
    u = functionM();// ไม่มีข้อผิดพลาด
    c = d + functionN(r, s);// ไม่มีข้อผิดพลาด
    t = s * functionO(r, a, r, a);// ไม่มีข้อผิดพลาด
    a = v + functionP(r, s, t, t);// ไม่มีข้อผิดพลาด
    functionP(functionN(a, a), s, t, t + r);// ไม่มีข้อผิดพลาด
    v = functionP(functionN(a, a), s, t, t + r); // ไม่มีข้อผิดพลาด
}