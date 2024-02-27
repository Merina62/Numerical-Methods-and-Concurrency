#include <stdio.h>
void midpoint(int x1, int x2, int y1, int y2);
int main(){
	int x1,x2,y1,y2;
	printf("Enter the value for x1: \n");
	scanf("%d",&x1);
	printf("Enter the value for y1: \n");
	scanf("%d",&y1);
	printf("Enter the value for x2: \n");
	scanf("%d",&x2);
	printf("Enter the value for y2: \n");
	scanf("%d",&y2);
	
	midpoint(x1,x2,y1,y2);
	return 0;
	
}

void midpoint(int x1, int x2, int y1, int y2){
	int midpointx= (x1+x2)/2;
	int midpointy=(y1+y2)/2;
	printf("Mid Point Coordinates: (%d,%d) \n",midpointx,midpointy);
}
