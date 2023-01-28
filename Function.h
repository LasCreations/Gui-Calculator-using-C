#include<math.h>
#include<stddef.h>
#include<stdint.h>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>
#include<gtk/gtk.h>


/*       BASIC MATH EQUATIONS       */
static double Add(float x, float y){
	g_print("\n%lf",x+y);
	return x+y;
}

static double Subtract(float x, float y){
	g_print("\n%lf",x-y);
	return x-y;
}

static double Multiply(float x, float y){
	g_print("\n%lf",x*y);
	return x*y;
}

static double Divide(float x, float y){
	g_print("\n%lf",x/y);
	return x/y;
}

/*     MATHEMATIC FUNCTIONS      */
static long double Power(int base, int exponent){
	double x = pow(base, exponent);
	g_print("%lf",x);
	return x;	
}

static float Factorial(int num){
	float factorial=1;
	for(size_t i = 1; i<=num; i++){
		factorial = factorial * i;	
	}
	//g_print("\n%f", factorial);
	return factorial;
}

static long double CubeRoot(double x){
	double result;
	result = cbrt(x);
	g_print("\n%lf",result);
	return result;
}

static long double SquareRoot(double x){
	double result;
	result = sqrt(x);
	g_print("\n%lf",result);
	return result;
}

/*       Trigonomitry       */
static long double SinFunc(int x){

	double result = sin(x);
	g_print("\n%lf",result);
	return result;
}

static long double InverseSinFunc(double x){

	double result = asin(x);
	g_print("\n%lf",result);
	return result;
}

static long double CosFunc(double x){
	double result = cos(x);
	g_print("\n%lf",result);
	return result;
}

static long double InverseCosFunc(double x){
	double result = acos(x);
	g_print("\n%lf",result);
	return result;
}

static long double TanFunc(double x){
	double result = tan(x);
	g_print("\n%lf",result);
	return result;
}

static long double InverseTanFunc(double x){
	double result = atan(x);
	g_print("\n%lf",result);
	return result;
}


static long double HyperbolicSinFunc(double x){
	double result = sinh(x);
	g_print("\n%lf", result);
	return result;
}

static long double HyperbolicCosFunc(double x){
	double result = cosh(x);
	g_print("\n%lf", result);
	return result;
}

static long double HyperbolicTanFunc(double x){
	double result = tanh(x);
	g_print("\n%lf", result);
	return result;
}

static long double InverseHyperbolicSinFunc(double x){
	double result = asinh(x);
	g_print("\n%lf", result);
	return result;
}

static long double InverseHyperbolicCosFunc(double x){
	double result = acosh(x);
	g_print("\n%lf", result);
	return result;
}

static long double InverseHyperbolicTanFunc(double x){
	double result = atanh(x);
	g_print("\n%lf", result);
	return result;
}

static long double ExponentialFunc(double x){
	double result = exp(x);
	g_print("\n%lf", result);
	return result;
}

static long double Pi(){
	g_print("%lf", M_PI);	
}

//Natural logarithm
static long double NaturalLogarithm(double x){
	double result = log(x);
	g_print("%lf", result);
	return result;
}





/*
nCr is referred as the combination.
nCr is the selection of r objects from a set of n objects,
where the order of objects does not matter.

nPr is referred as the permutation. 
nPr is arrangement of 'r' objects from a set of 'n' objects,
which should be in an order or sequence.
*/

/*
The logic used to find nPr is as follows −
result = factorial(n)/factorial(n-r);
 */
static long double nPrFunc(double N, double R){
	if(N<R){
		g_print("Math Error"); 
		return 0;
	}
	double result = Factorial(N)/Factorial(N-R);
	g_print("\n%lf", result);
	return result;
}

/*
The logic used to find nCr is as follows −
result = factorial(n)/(factorial(r)*factorial(n-r));
*/
static long double nCrFunc(double N, double R){
	if(N<R){
		g_print("Math Error"); 
		return 0;
	}
	double result = Factorial(N)/(Factorial(R) * Factorial(N-R));
	g_print("\n%lf", result);
	return result;
}


static long double RandomNumber(){
	 srand((unsigned int) time(NULL));
	 g_print("\n%.3f", ((float) rand() / (float)(RAND_MAX)));
}
