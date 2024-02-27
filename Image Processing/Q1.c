#include<stdio.h>
#include"lodepng.h"

int main(){
	unsigned char* image;
	unsigned int w,h;
	int i;
	unsigned int error;
	
	//decoding image
	error= lodepng_decode32_file(&image, &w, &h, "dice.png");
	printf("Returned: %d,%s",error,lodepng_error_text(error));
	// printting values of rgb indexes
//	for(i=0;i<h*w*4;i=i+4){
//		printf("%d, %d, %d, %d",image[i],image[i+1],image[i+2],image[i+3]);
//	}
	
	//manupulation of pixelsj
	for(i=0;i<h*w*4;i=i+4){
		image[i]=255-image[i];
		image[i+1]=255-image[i+1];
		image[i+2]=255-image[i+2];
	}
	
	//encoding image
	lodepng_encode32_file("output.png", image,w,h);
}