// Apply a negative filter on an image file. This is the process of reversing the RGB values.
// For example, if the Red value of the pixel is 100, the inverse is 155. NOTE: 0 is minimum
// and 255 is maximum.
 
#include<stdio.h>
#include"lodepng.h"

int main(){
	unsigned char* image;
	unsigned int w,h;
	int i;
	unsigned int error;
	
	//decoding image
	error= lodepng_decode32_file(&image, &w, &h, "Mario.png");
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
	lodepng_encode32_file("output1.png", image,w,h);
}