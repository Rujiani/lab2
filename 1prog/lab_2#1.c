#include <stdio.h>
#include <math.h>
long double summ (long double, long double);
long double preob_rad(long double);
int main(){
	long double num, n;
	printf("Enter rad\n");
	if(!scanf("%Lf", &num)){
		printf("ERROR\n");
		return 0;
	}
	long double cos_check = cosl(num);
	printf("Enter the number of row members\n");
	if(!scanf("%Lf", &n)){
		printf("ERROR\n");
		return 0;
	}
	if((int)n != n || n < 1){printf("ERROR\n"); return 0;}
	long double sum = summ(num, n);
	printf("cos(x) = %.19Lf\n", sum);
	printf("infelicity : %Lf\n", cos_check - sum);
	return 0;
}

long double summ(long double x, long double n){
	long double sum = 1;
	long double y = x * x;
	long double peremen = 1;
	int a = 0;
	for(int i = 1; i < n; i++){
		peremen = peremen*(-y/((a + 1) * (a + 2)));
		a += 2;
		sum = sum + peremen;
	}
	return sum;
}
