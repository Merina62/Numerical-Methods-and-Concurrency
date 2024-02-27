#include<stdio.h>
void equations(double a, double b, double c, double d,double e, double f);
int main(){
	double a,  b,  c,  d,  e, f;
	printf("Enter number in front of x of equation one: ");
	scanf("%lf",&a);
	printf("Enter number in front of y of equation one: ");
	scanf("%lf",&b);
	printf("Enter constant of equation one: ");
	scanf("%lf",&c);
	printf("Enter number in front of x of equation two: ");
	scanf("%lf",&d);
	printf("Enter number in front of y of equation two: ");
	scanf("%lf",&e);
	printf("Enter constant of equation two: ");
	scanf("%lf",&f);
	equations(a,b,c,d,e,f);
}
void equations(double a, double b, double c, double d,double e, double f){
	float determinant= (a * e) - (b * d);
	if (determinant == 0) {
        printf("Lines are parallel, no intersection.\n");
    } else {
        double x = (c * e - b * f) / determinant;
        double y = (a * f - c * d) / determinant;
        printf("Intersection at (x, y): (%0.2f, %0.2f)\n", x, y);
    }
}
