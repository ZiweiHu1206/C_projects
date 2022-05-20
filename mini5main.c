#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mini5phone.h"

int menu() {
	int user_input;
	char garbage;
	printf("Phonebook Menu: (1)Add, (2)Find, (3)List, (4)Quit> ");
	scanf("%d", &user_input);
	scanf("%c", &garbage);
	
	while(user_input > 4 || user_input < 1){
		printf("Incorrect input.\n");
		user_input = menu();
	}
	return user_input;
}


int main(){
	int num_record = 0;
	char garbage;
	
	loadCSV(phonebook, &num_record);
	
	int user_input = menu();
	while(user_input != 4){
		if(user_input == 1){
                	char input_name[50];
                	char input_birthday[12];
                	char input_phone[15];

                	printf("Name: ");
                	fgets(input_name, 49, stdin);
			input_name[strlen(input_name) - 1] = '\0';

                	printf("Birth: ");
                	fgets(input_birthday, 11, stdin);
			input_birthday[strlen(input_birthday) - 1] = '\0';

                	printf("Phone: ");
                	fgets(input_phone, 14, stdin);
			input_phone[strlen(input_phone) - 1] = '\0';

                	addRecord(phonebook, &num_record, input_name, input_birthday, input_phone);
        	}

       		if(user_input == 2){
                	char input_name[50];
                	printf("Find name: ");
                	fgets(input_name, 49, stdin);
			input_name[strlen(input_name) - 1] = '\0';

                	findRecord(phonebook, num_record, input_name);
        	}
                 
        	if(user_input == 3){
                	listRecords(phonebook, num_record);
        	}
		
		user_input = menu();
	}
	
	saveCSV(phonebook, num_record);
	printf("End of phonebook program\n");
	memset(phonebook, 0, sizeof(struct PHONE_RECORD)*10);
	return 0;
}
















