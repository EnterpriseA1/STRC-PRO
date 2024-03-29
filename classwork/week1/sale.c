#include <stdio.h>

int main(void)
{
	float a, b, c;
	float a_promo, b_promo, c_promo;
	float a_vat, b_vat, c_vat;

	scanf("%f", &a);
	a_promo = a - (a * 0.05);
	printf("%-7s%.2f\n", "PROMO", a_promo);
	a_vat = a_promo + (0.07 * a_promo);
	printf("%-7s%.2f\n\n", "VAT", a_vat);

	scanf("%f", &b);
	b_promo = a + b;
	b_promo = b_promo - (b_promo * 0.15);
	printf("%-7s%.2f\n", "PROMO", b_promo);
	b_vat = b_promo + (0.07 * b_promo);
	printf("%-7s%.2f\n\n", "VAT", b_vat);

	scanf("%f", &c);
	c_promo = a + b + c;
	c_promo = c_promo - (c_promo * 0.3);
	printf("%-7s%.2f\n", "PROMO", c_promo);
	c_vat = c_promo + (0.07 * c_promo);
	printf("%-7s%.2f\n", "VAT", c_vat);
}
