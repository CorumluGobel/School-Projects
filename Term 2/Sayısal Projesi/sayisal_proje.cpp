#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MAX 100
typedef struct polyFunction{
	int exponents[MAX];
	float coefficients[MAX]; 
}P;

int degreeGet();
float errorGet();
void polyGet(int degree, P poly);
void MENU();
float incrementGet();
void derivativeSelect();
void simpsonSelect();
int factorial(int i);

int main(){
	
	int method, i, degree, iteration = 0, isSolved = false, n, j, k, choice, fact;
	float f = 0, g = 0, h = 0, t = 0, u = 0, a, b, c, tmp, x, increment, S = 0, xn, division = 0, result;
	float error, difference, matrix[MAX][MAX] = {0}, inverseMatrix[MAX][MAX] = {0}, seidalMatrix[3][4], list[MAX][6] = {0}, interpolation[MAX][MAX] = {0}, eliminationMatrix[MAX][MAX] = {0}, roots[MAX] = {0};
	P poly={0};
	
	MENU();
	scanf("%d", &method);
	system("cls");
	
	switch(method){
		case 0:
			break;
		
		case 1:			//Bisection
			
			degree = degreeGet();
			
			for(i = degree; i > -1 ; i--){
				printf("%d. Terimin Katsayisini Giriniz \n", degree-i+1);
				scanf("%f", &poly.coefficients[degree-i]);
				poly.exponents[degree-i] = i;
			}
			error = errorGet();
			
			do{
				printf("Araligi Giriniz: ");
				scanf("%f %f", &a, &b);
				for(i = 0; i <= degree; i++){
					f = f + pow(a,poly.exponents[i])*poly.coefficients[i];
					g = g + pow(b,poly.exponents[i])*poly.coefficients[i];
				}
			}while(f*g >= 0);
			
			while(isSolved == false){
				c = (a+b)/2;
				for(i = 0; i <= degree; i++){
					h = h + pow(c,poly.exponents[i])*poly.coefficients[i];
				}
				difference = fabs(a-b);
				if(h*f<0)
					b = c;
				else
					a = c;
				f = 0; g = 0; h = 0;
				for(i = 0; i <= degree; i++){
					f = f + pow(a,poly.exponents[i])*poly.coefficients[i];
					g = g + pow(b,poly.exponents[i])*poly.coefficients[i];
				}
				iteration++;
				if(difference/pow(2,iteration) <= error)
					isSolved = true;
			}
			printf("Iteration: %d\n", iteration);
			printf("Root: %f", c);
			
			break;
			
		case 2: // Regula-Falsi
			degree = degreeGet();
			
			for(i = degree; i > -1 ; i--){
				printf("%d. Terimin Katsayisini Giriniz \n", degree-i+1);
				scanf("%f", &poly.coefficients[degree-i]);
				poly.exponents[degree-i] = i;
			}
			error = errorGet();
			
			do{
				printf("Araligi Giriniz: ");
				scanf("%f %f", &a, &b);
				for(i = 0; i <= degree; i++){
					f = f + pow(a,poly.exponents[i])*poly.coefficients[i];
					g = g + pow(b,poly.exponents[i])*poly.coefficients[i];
				}
			}while(f*g >= 0);
			
			while(isSolved == false){
				c = (b*f-a*g)/(f-g);
				for(i = 0; i <= degree; i++){
					h = h + pow(c,poly.exponents[i])*poly.coefficients[i];
				}
				difference = fabs(a-b);
				printf("Iteration: %d\n", iteration+1);
				printf("f(c): %f\n", h);
				printf("a: %f\n", a);printf("b: %f\n", b);printf("c: %f\n", c);
				if(h*f<0)
					b = c;
				else
					a = c;
				f = 0; g = 0; h = 0;
				for(i = 0; i <= degree; i++){
					f = f + pow(a,poly.exponents[i])*poly.coefficients[i];
					g = g + pow(b,poly.exponents[i])*poly.coefficients[i];
				}
				iteration++;
				if(difference/pow(2,iteration) <= error)
					isSolved = true;
			}
			printf("Iteration: %d\n", iteration);
			printf("Root: %f", c);
			
			break;
		case 3://newton raphson
			degree = degreeGet();
			
			for(i = degree; i > -1 ; i--){
				printf("%d. Terimin Katsayisini Giriniz \n", degree-i+1);
				scanf("%f", &poly.coefficients[degree-i]);
				poly.exponents[degree-i] = i;
			}
			error = errorGet();
			
			do{
				printf("Araligi Giriniz: ");
				scanf("%f %f", &a, &b);
				for(i = 0; i <= degree; i++){
					f = f + pow(a,poly.exponents[i])*poly.coefficients[i];
					g = g + pow(b,poly.exponents[i])*poly.coefficients[i];
				}
			}while(f*g >= 0);
			
			while(isSolved == false){
				f = 0; g = 0;
				for(i = 0; i <= degree; i++){
					f = f + pow(a,poly.exponents[i])*poly.coefficients[i];
					g = g + pow(a,poly.exponents[i+1])*poly.coefficients[i]*poly.exponents[i];
				}
				printf("\nIteration: %d\n", iteration+1);
				printf("a: %f\n", a);
				printf("c: %f\n", c);
				printf("f(a): %f\n", f);
				printf("f'(a): %f\n", g);
				c = a - (f/g);
				
				difference = fabs(c-a);
				a = c;
				if(difference < error)
					isSolved = true;
				iteration++;
			}
			printf("\nIteration: %d\n", iteration);
			printf("Root: %f", c);
			
			break;
			
		case 4://inverse matrix
			
			do{
				printf("Matris buyuklugunu giriniz: ");
				scanf("%d", &n);
			}while(n > MAX);
			
			for(i = 0; i < n; i++){
				for(j = 0; j < n; j++){
					printf("a%d%d: ", i+1, j+1);
					scanf("%f", &matrix[i][j]);
				}
			}
			for(i = 0, j = 0; i < n, j <n ; i++, j++){
				inverseMatrix[i][j] = 1;
			}
			printf("Matrix: \n");
			for(i = 0; i < n; i++){
				for(j = 0; j < n; j++){
					printf("%f ", matrix[i][j]);
				}
				printf("\n");
			}
			
			for(i = 0; i < n; i++){
				for(j = 0; j < n; j++){
					if(i != j){
						division = matrix[j][i]/matrix[i][i];
						for(k = 0; k < n; k++){
							matrix[j][k] = matrix[j][k] - division*matrix[i][k];
							inverseMatrix[j][k] = inverseMatrix[j][k] - division*inverseMatrix[i][k];
						}
					}
					
				}
			}
			
			
			for(i = 0; i < n; i++){
				for(j = 0; j < n; j++){
					inverseMatrix[i][j] = inverseMatrix[i][j]/matrix[i][i];
					matrix[i][j] = matrix[i][j]/matrix[i][i];
				}
			}
			printf("\n\nInverse Matrix: \n");
			for(i = 0; i < n; i++){
				for(j = 0; j < n; j++){
					printf("%f ", inverseMatrix[i][j]);
				}
				printf("\n");
			}
			break;
		case 5://gauss elimination
			do{
				printf("Matris buyuklugunu giriniz: ");
				scanf("%d", &n);
			}while(n > MAX);
			
			for(i = 0; i < n; i++){
				for(j = 0; j < n; j++){
					printf("a%d%d: ", i+1, j+1);
					scanf("%f", &eliminationMatrix[i][j]);
				}
			}
			for(i = 0; i < n; i++){
				printf("c%d: ", i+1);
				scanf("%f", &eliminationMatrix[i][n]);
			}
			for(i = 0; i < n; i++){
				for(j = 0; j < n; j++){
					if(i != j && j > i){
						division = eliminationMatrix[j][i]/eliminationMatrix[i][i];
						for(k = 0; k < n+1; k++){
							eliminationMatrix[j][k] = eliminationMatrix[j][k] - division*eliminationMatrix[i][k];
						}
					}	
				}
			}
			
			for(i = 0; i < n; i++){
				tmp = eliminationMatrix[i][i];
				for(j = 0; j < n+1; j++){
					
					eliminationMatrix[i][j] = eliminationMatrix[i][j]/tmp;
				}
			}
			printf("\n");
			for(i = 0; i < n; i++){
				for(j = 0; j < n+1; j++){
					printf("%f ", eliminationMatrix[i][j]);
				}
				printf("\n");
			}
			for(i = n-1; i >= 0; i--){
				for(j = 0; j < n; j++){
					if(i != j)
						f = f + eliminationMatrix[i][j]*roots[j];
				}
				roots[i] = eliminationMatrix[i][j] - f;
			}
			printf("\n");
			for(i = 0; i < n; i++){
				printf("x%d = %f\n", i+1, roots[i]);
			}
			
			break;
		case 6://Gauss seidal
			errorGet();
			for(i = 0; i < 3; i++){
				printf("%d. denklemi giriniz: ", i+1);
				scanf("%f %f %f %f", &seidalMatrix[i][0], &seidalMatrix[i][1], &seidalMatrix[i][2], &seidalMatrix[i][3]);
			}
			if(fabs(seidalMatrix[1][0]) > fabs(seidalMatrix[0][0]) && fabs(seidalMatrix[1][0]) >= fabs(seidalMatrix[2][0])){
				tmp = seidalMatrix[0][0];
				seidalMatrix[0][0] = seidalMatrix[1][0];
				seidalMatrix[1][0] = tmp;
				tmp = seidalMatrix[0][1];
				seidalMatrix[0][1] = seidalMatrix[1][1];
				seidalMatrix[1][1] = tmp;
				tmp = seidalMatrix[0][2];
				seidalMatrix[0][2] = seidalMatrix[1][2];
				seidalMatrix[1][2] = tmp;
				tmp = seidalMatrix[0][3];
				seidalMatrix[0][3] = seidalMatrix[1][3];
				seidalMatrix[1][3] = tmp;
			}
			else if(fabs(seidalMatrix[2][0]) > fabs(seidalMatrix[0][0]) && fabs(seidalMatrix[2][0]) >= fabs(seidalMatrix[1][0])){
				tmp = seidalMatrix[0][0];
				seidalMatrix[0][0] = seidalMatrix[2][0];
				seidalMatrix[2][0] = tmp;
				tmp = seidalMatrix[0][1];
				seidalMatrix[0][1] = seidalMatrix[2][1];
				seidalMatrix[2][1] = tmp;
				tmp = seidalMatrix[0][2];
				seidalMatrix[0][2] = seidalMatrix[2][2];
				seidalMatrix[2][2] = tmp;
				tmp = seidalMatrix[0][3];
				seidalMatrix[0][3] = seidalMatrix[2][3];
				seidalMatrix[2][3] = tmp;
			}
			if(fabs(seidalMatrix[2][1]) > fabs(seidalMatrix[1][1])){
				tmp = seidalMatrix[1][0];
				seidalMatrix[1][0] = seidalMatrix[2][0];
				seidalMatrix[2][0] = tmp;
				tmp = seidalMatrix[1][1];
				seidalMatrix[1][1] = seidalMatrix[2][1];
				seidalMatrix[2][1] = tmp;
				tmp = seidalMatrix[1][2];
				seidalMatrix[1][2] = seidalMatrix[2][2];
				seidalMatrix[2][2] = tmp;
				tmp = seidalMatrix[1][3];
				seidalMatrix[1][3] = seidalMatrix[2][3];
				seidalMatrix[2][3] = tmp;
			}
			printf("\n");
			for(i = 0; i < 3; i++){
				for(j = 0; j < 4; j++){
					printf("%f ", seidalMatrix[i][j]);
				}
				printf("\n");
			}
			list[0][0] = 1; list[0][2] = 1; list[0][4] = 1;
			
			i = 1; b = 1; c = 1;
			
			do{

				a = (seidalMatrix[0][3] - seidalMatrix[0][1]*b - seidalMatrix[0][2]*c)/seidalMatrix[0][0];
				list[i][0] = a;
				list[i][1] = fabs(a-list[i-1][0]);
				b = (seidalMatrix[1][3] - seidalMatrix[1][0]*a - seidalMatrix[1][2]*c)/seidalMatrix[1][1];
				list[i][2] = b;
				list[i][3] = fabs(b-list[i-1][2]);
				c = (seidalMatrix[2][3] - seidalMatrix[2][0]*a - seidalMatrix[2][1]*b)/seidalMatrix[2][2];
				list[i][4] = c;
				list[i][5] = fabs(c-list[i-1][4]);
				
				
				i++; iteration++;
			}while(list[i-1][1] >= error && list[i-1][3] >= error && list[i-1][5] >= error && list[i-1][1] != 0 && list[i-1][3] != 0 && list[i-1][5] != 0);
			
			printf("\n\n\n");
			for(i = 0; i < iteration; i++){
				for (j = 0; j < 6; j++){
					printf("%f ", list[i][j]);
				}
				printf("\n");
			}
			printf("Iteration: %d", iteration);
			break;
		case 7: //sayýsal türev
			
			degree = degreeGet();
			
			for(i = degree; i > -1 ; i--){
				printf("%d. Terimin Katsayisini Giriniz \n", degree-i+1);
				scanf("%f", &poly.coefficients[degree-i]);
				poly.exponents[degree-i] = i;
			}
			increment = incrementGet();
			printf("x: ");
			scanf("%f", &x);
			derivativeSelect();
			scanf("%d", &choice);
			
			switch(choice){
				case 1:
					for(i = 0; i <= degree; i++){
						f = f + pow(x+increment,poly.exponents[i])*poly.coefficients[i];
						g = g + pow(x,poly.exponents[i])*poly.coefficients[i];
					}
					h = (f - g)/increment;
					break;
				case 2:
					for(i = 0; i <= degree; i++){
						f = f + pow(x-increment,poly.exponents[i])*poly.coefficients[i];
						g = g + pow(x,poly.exponents[i])*poly.coefficients[i];
					}
					h = (g - f)/increment;
					break;
				case 3:
					for(i = 0; i <= degree; i++){
						f = f + pow(x-increment,poly.exponents[i])*poly.coefficients[i];
						g = g + pow(x+increment,poly.exponents[i])*poly.coefficients[i];
					}
					h = (g - f)/(2*increment);
					break;
			}
			printf("f'(x) = %f", h);
			break;
		case 8:
			simpsonSelect();
			scanf("%d", &choice);
			switch(choice){
				case 1:
					degree = degreeGet();
			
					for(i = degree; i > -1 ; i--){
						printf("%d. Terimin Katsayisini Giriniz \n", degree-i+1);
						scanf("%f", &poly.coefficients[degree-i]);
						poly.exponents[degree-i] = i;
					}
					printf("n: ");
					scanf("%d", &n);
					printf("x: ");
					scanf("%f", &x);
					printf("xn: ");
					scanf("%f", &xn);
				
					increment = (xn-x)/n;
				
					for(i = 0; i <= degree; i++){
						f = f + pow(x,poly.exponents[i])*poly.coefficients[i];
						g = g + pow(xn,poly.exponents[i])*poly.coefficients[i];
					}
					for(i = 2, k = 1; i <= n-2, k <= n-1; i = i+2, k = k+2){
						for(j = 0; j <= degree; j++){
							h = h + pow(x + k*increment,poly.exponents[j])*poly.coefficients[j];
							t = t + pow(x + i*increment,poly.exponents[j])*poly.coefficients[j];
						}
					}
					S = (increment/3)*(f + g + 4*h + 2*t);
					printf("S = %f", S);
					break;
				case 2:
					degree = degreeGet();
			
					for(i = degree; i > -1 ; i--){
						printf("%d. Terimin Katsayisini Giriniz \n", degree-i+1);
						scanf("%f", &poly.coefficients[degree-i]);
						poly.exponents[degree-i] = i;
					}
					printf("n: ");
					scanf("%d", &n);
					printf("x: ");
					scanf("%f", &x);
					printf("xn: ");
					scanf("%f", &xn);
					
					increment = (xn-x)/3;
					
					for(i = 0; i <= degree; i++){
						f = f + pow(x,poly.exponents[i])*poly.coefficients[i];
						g = g + pow(xn,poly.exponents[i])*poly.coefficients[i];
					}
					for(k = 1; k <= n-1; k = k+1){
						if(k % 3 != 0){
							for(j = 0; j <= degree; j++){
								h = h + pow(x + k*increment,poly.exponents[j])*poly.coefficients[j];
							}
						}
						else{
							for(j = 0; j <= degree; j++){
								t = t + pow(x + k*increment,poly.exponents[j])*poly.coefficients[j];
							}
						}
					}
					
					S = ((xn-x)/8)*(f + g + 3*h + 2*t);
					printf("S = %f", S);
					break;
			}
			break;
		case 9:
			degree = degreeGet();
			
			for(i = degree; i > -1 ; i--){
				printf("%d. Terimin Katsayisini Giriniz \n", degree-i+1);
				scanf("%f", &poly.coefficients[degree-i]);
				poly.exponents[degree-i] = i;
			}
			printf("n: ");
			scanf("%d", &n);
			printf("x: ");
			scanf("%f", &x);
			printf("xn: ");
			scanf("%f", &xn);
					
			increment = (xn-x)/n;
					
			for(i = 0; i <= degree; i++){
				f = f + pow(x,poly.exponents[i])*poly.coefficients[i];
				g = g + pow(xn,poly.exponents[i])*poly.coefficients[i];
			}
			for(j = 1; j <= n-1; j++){
				for(i = 0; i <= degree; i++){
					h = h + pow(x + j*increment,poly.exponents[i])*poly.coefficients[i];
				}
			}
			S = increment*((f + g)/2 + h);
			printf("S = %f", S);
			
			break;
		case 10:
			printf("Gireceginiz x degerlerinin sayisi: ");
			scanf("%d", &n);
			printf("x degerlerini girin: \n");
			for(i = 0; i < n; i++){
				printf("x%d: ", i);
				scanf("%f", &interpolation[i][0]);
			}
			for(i = 0; i < n; i++){
				printf("f(x%d): ", i);
				scanf("%f", &interpolation[i][1]);
			}
			i = 1;
			k = n-1;
			do{
				for(j = 0; j < k; j++){
					interpolation[j][i+1] = interpolation[j+1][i] - interpolation[j][i];
				}
				i++;
				k--;
			}while(interpolation[0][i] != interpolation[1][i] && interpolation[1][i] != 0);
			
			for(k = 0; k < n; k++){
				for(j = 0; j < i+1; j++){
					printf(" %f ", interpolation[k][j]);
				}
				printf("\n");
			}
			increment = interpolation[1][0] - interpolation[0][0];
			
			
			for(j = 0; j < i; j++){
				fact = factorial(i-j-1);
				poly.coefficients[j] = interpolation[0][i-j]/(pow(increment,i-j-1)*fact);
			}
			printf("F(x) = ");
			for(j = 0; j < i-1; j++){
				n = i-j;
				printf("%g", poly.coefficients[j]);
				for(k = n-2; k >= 0 ;k--){
					printf("(x-%g)", interpolation[k][0]);
					n--;
				}
				printf(" + ");
			}
			printf("%g", poly.coefficients[i-1]);
			
			printf("\n Bulmak istediginiz degeri girin: ");
			scanf("%f", &x);
			
			for(j = 0; j < i-1; j++){
				n = i-j;
				for(k = n-2; k >= 0 ;k--){
					poly.coefficients[j] = poly.coefficients[j]*(x-interpolation[k][0]);
					n--;
				}
				result = result + poly.coefficients[j];
			}
			result = result + poly.coefficients[i-1];
			printf("\nSonuc: %g", result);
			
			
			break;
	}
	return 0;
}

void MENU(){
	printf("0-Exit\n1-Bisection Method\n2-Regula-Falsi Method\n3-Newton-Raphson Method\n4-Inverse of a NxN Matrix\n5-Gauss Elimination Method\n6-Gauss-Seidal Method\n7-Numerical Derivative\n8-Simpson Method\n9-Trapezoid Method\n10-Gregory Newton Interpolation\n\n");
	printf("Kullanmak Istediginiz Metodu Seciniz: ");
}
int degreeGet(){
	int i;
	do{
		printf("Polinomun Derecesini Giriniz: ");
		scanf("%d", &i);
	}while(i > MAX);
	return i;
}
float errorGet(){
	float i;
	printf("Hata Payini Giriniz: ");
	scanf("%f", &i);
	return i;
}
float incrementGet(){
	float i;
	printf("h: ");
	scanf("%f", &i);
	return i;
}
void derivativeSelect(){
	printf("1-Ileri\n2-Geri\n3-Merkezi\n");
	printf("Seciniz: ");
}
void simpsonSelect(){
	printf("1-1/3 Simpson\n2-3/8 Simpson\n");
	printf("Seciniz: ");
}
int factorial(int i){
	int j;
	int a = 1;
	if(i == 0)
		return 1;
	else{
		for(j = 1; j <= i; j++){
			a = a*j;
		}
	}
	return a;
}






