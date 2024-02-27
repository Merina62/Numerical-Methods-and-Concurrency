#include<stdio.h>
#include"lodepng.h"

int main(){
	unsigned char* image;
	unsigned int w,h;
	unsigned int error;
	
	error= lodepng_decode32_file(&image, &w,&h,"dice.png");
	printf("Returned: %d %s",error, lodepng_error_text(error));
	
	for(int i=0;i<h*w*4;i=i+4){
		image[i]= 255-image[i];
		image[i+1]= 255-image[i+1];
		image[i+2]= 255-image[i+2];
	}
	
	lodepng_encode32_file("Result.png",image,w,h);
}