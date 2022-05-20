#include<stdio.h>

int main(void){

	//declare variables
	int a, b, c;

	//prompts the user for three integer numbers
	printf("Please input three numbers: ");

	//gets the input numbers
	scanf("%d %d %d", &a, &b, &c); 	
	
	//checks for incresing and divisible
	if ((b % a == 0) && (c % a == 0) && (a < b) && (b < c)){
		printf("Divisible & Incresing\n");
		return 0;
	}else if( ((a < b)&&(b < c)) && ((b % a != 0)||(c % a != 0)) ){
		printf("Not divisible & Increasing\n");
		return 1;
	}else if( ((a >= b)||(b >= c)) && ((b % a == 0)&&(c % a == 0)) ){
	        printf("Divisible & Not increasing\n");
		return 2;
	}else{
		printf("Not divisible & Not increasing\n");
		return 3;
	}	

}
