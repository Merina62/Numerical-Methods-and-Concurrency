#include <stdio.h>
int main(){
	int userChoice;
	do{
		printf("Choose an option:\n");
		printf("1.Print Hello \n");
		printf("2.Quit \n");
		
		scanf("%d", &userChoice);
		
		switch(userChoice){
			case 1:
				printf("Hello \n");
				break;
			case 2:
				printf("Exiting program. \n");
				break;
			default:
				printf("Invalid choice. Try Again. \n");
				
		}
		
	} while(userChoice!=2);
	return 0;
}
