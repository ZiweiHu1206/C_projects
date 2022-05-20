struct PHONE_RECORD{
	char name[50];
	char birthdate[12];
	char phone[15];
};

extern struct PHONE_RECORD phonebook[10];

int loadCSV(struct PHONE_RECORD phonebook[], int *num_record);
int saveCSV(struct PHONE_RECORD phonebook[], int num_record);
int addRecord(struct PHONE_RECORD phonebook[], int *num_record, char name[],char birthdate[],char phone[]);
int findRecord(struct PHONE_RECORD phonebook[], int num_record, char name[]);
int listRecords(struct PHONE_RECORD phonebook[], int num_record);
