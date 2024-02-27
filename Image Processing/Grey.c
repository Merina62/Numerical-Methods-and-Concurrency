#nclude<stdio.h>
#include"lodepng.h"

int main(){
	unsigned char* image;
	unsigned int w,h;
	int i;
//	unsigned int error;
	
	//decoding image
	lodepng_decode32_file(&image, &w, &h, "dice.png");
//	printf("Returned: %d,%s",error,lodepng_error_text(error));
	// printting values of rgb indexes
//	for(i=0;i<h*w*4;i=i+4){
//		printf("%d, %d, %d, %d",image[i],image[i+1],image[i+2],image[i+3]);
//	}
	
	//manupulation of pixelsj
	for(i=0;i<h*w*4;i=i+4){
		int gs= (image[i]+image[i+1]+image[i+2])/3;
		image[i]=gs;
		image[i+1]=gs;
		image[i+2]=gs;
	}
	
	//encoding image
	lodepng_encode32_file("second.png", image,w,h);
}