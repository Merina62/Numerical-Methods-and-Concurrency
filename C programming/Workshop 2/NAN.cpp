#include <stdio.h>
 #include <math.h>
 
 //Function to calculate the missing value in the formula "v=u+at"
 
 double velocityCalc(double u, double a, double t, double v){
 
 //Check which variable is set to NAN and calculate the missing value
 if (isnan (v)){
 	v = u + a * t;
 	return v;
 } else if (isnan(u)){
 		u = v - a * t;
 	return u;
 } else if (isnan(a)){
 		a = (v - u)/t;
 	return a;

 } else if (isnan(t)){
 	t = (v - u)/a;
 	return t;
 } else{
 	return NAN;
 	
 }
 }
 int main(){
 	double u,a,t,v;
 	u=10.0;
 	a=5.0;
 	t=4.0;
 	v=NAN;
 	
 	double result = velocityCalc(u,a,t,v);
 	printf("Result: %lf\n", result);
 	
 	return 0;
 }
