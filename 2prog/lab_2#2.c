#include <stdio.h>
#include <math.h>
long double summ(long double, long double, int*);
int preob_eps(long double);
int main() {
	long double num;
	int counter = 0;
	int * count = &counter;
	printf("Введите переменную\n");
	if(!scanf("%Lf", &num)){printf("ERROR\n"); return 0;}
	printf("Введите точность\n");
	long double eps;
	if(!scanf("%Lf", &eps)){printf("ERROR\n"); return 0;}
	int l = preob_eps(eps);
	long double sum = summ(num, eps, count);
	printf("cos = %.*Lf\n", l, sum);
	printf("Количество требуемых членов ряда: %d\n", *count + 1);    // + 1 тк sum = 1 уже первый член ряда
	printf("Accuracy : %.19Lf\n", cos(num) - sum);
	return 0;
}
int preob_eps(long double eps) {
	int counter = 0;
	while (eps < 2) {
		eps *= 10;
		counter += 1;
	}
	return counter - 1;
}


long double summ(long double x, long double eps, int * counter) {
	long double sum = 1;
	long double sum_before;
	long double y = x * x;
	long double peremen = 1;
	int a = 0;
	while (fabsl(peremen) > eps) {
		sum_before = sum;
		peremen = peremen * (-y / ((a + 1) * (a + 2)));
		a += 2;
		sum = sum + peremen;
		*counter += 1;
	}
	return sum;
}

