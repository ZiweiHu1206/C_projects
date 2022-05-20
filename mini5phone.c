#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mini5phone.h"

struct PHONE_RECORD phonebook[10];

int loadCSV(struct PHONE_RECORD phonebook[], int *num_record){
	FILE *f = fopen("phonebook.csv","rt");
	char line[100];
        char first_line[100];	
        int i = 0;

	if(f == NULL){
		return 0;
	}

	fgets(first_line, 99, f);
	while(fgets(line, 99, f)){
		char *tok;
		tok = strtok(line, ",");
		if(tok != NULL){
			strcpy(phonebook[i].name, tok);
			tok = strtok(NULL, ",");
		}
		if(tok != NULL){
			strcpy(phonebook[i].birthdate, tok);
			tok = strtok(NULL, ",");
		}
		if(tok != NULL){
			strcpy(phonebook[i].phone, tok);
		}
		i++;
		*num_record = *num_record + 1;

		if(*num_record == 10){
			break;
		}
	}
	fclose(f);
	return 0;
}


int saveCSV(struct PHONE_RECORD phonebook[], int num_record){
	FILE *f = fopen("phonebook.csv", "wt");
	
	fputs("Name,birthdate,phone", f);
	for(int i=0; i<num_record; i++){
		fprintf(f, "%s,%s,%s\n", phonebook[i].name, phonebook[i].birthdate, phonebook[i].phone);
	}
	fclose(f);
	return 0;
}


int addRecord(struct PHONE_RECORD phonebook[], int *num_record, char name[],char birthdate[],char phone[]){
	if(*num_record == 10){
		printf("No more space in the CSV file.\n");
		return 1;
	}
	strcpy(phonebook[*num_record].name, name);
	strcpy(phonebook[*num_record].birthdate, birthdate);
	strcpy(phonebook[*num_record].phone, phone);

	*num_record = *num_record + 1;
	return 0;
}


int findRecord(struct PHONE_RECORD phonebook[], int num_record, char name[]){
	if(num_record == 0){
		printf("Phonebook.csv does not exist\n");
		return 1;
	}
	for(int i=0; i<num_record; i++){
		if(strcmp(phonebook[i].name, name) == 0){
			printf("----NAME--------- ------BIRTH------ -----PHONE-------\n");
			printf("%-17s %-17s %-17s\n",phonebook[i].name,phonebook[i].birthdate,phonebook[i].phone);
			return 0;
		}
	}
	printf("Does not exist\n");
	return 1;
}


int listRecords(struct PHONE_RECORD phonebook[], int num_record){
	if(num_record == 0){
		printf("Phonebook.csv does not exist\n");
		return 1;
	}
	printf("----NAME--------- ------BIRTH------ -----PHONE-------\n");
	for(int i=0; i<num_record; i++){
		printf("%-17s %-17s %-17s\n",phonebook[i].name,phonebook[i].birthdate,phonebook[i].phone);
	}
	return 0;
}











