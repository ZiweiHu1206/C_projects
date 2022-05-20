#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main(int argc, char *argv[]){

	//checks the length of two strings are the same
	if (strlen(argv[1]) != strlen(argv[2])){
		printf("Not an anagram\n");
		return 1;
	}

	//declares two arrays to store the frequency of each letters
	//initializes each slot to zero
	int first_frequency[256];
	int second_frequency[256];
	int i, j, k;

	for(i=0; i<256; i++){
		first_frequency[i] = 0;
		second_frequency[i] = 0;
	}

	//count the frequency of each letter of the first string
	for(j=0; j<strlen(argv[1]); j++){
		int ascii_first = argv[1][j];
		int ascii_second = argv[2][j];
		first_frequency[ascii_first]++;
		second_frequency[ascii_second]++;
	}

	//checks the frequency of each character is the same
	for(k=0; k<256; k++){
		if (first_frequency[k] != second_frequency[k]){
			printf("Not an anagram\n");
			return 1;
		}
	}
	
	printf("Anagram\n");
	return 0;
}
