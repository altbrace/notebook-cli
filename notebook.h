#ifndef NOTEBOOK_H
#define NOTEBOOK_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N_ENTRY_SIZE 201 
// bytes combined


typedef struct n_entry {
	unsigned int id;
	char lname[20];   // 20 chars
	char fname[20];   // 20 chars
	char pname[20];   // 20 chars
	char bdate[10];   // 10 chars (dd.mm.yyyy format)
	char address[100];// 100 chars
	char mobile[12];  // 12 chars (+71234567890 format)
	char wphone[12];  // 12 chars
} n_entry;

int entry_alloc(n_entry* entry) {
	entry = (n_entry*)malloc(sizeof(n_entry));
/*
	entry->lname = (char*)malloc(20 * sizeof(char));
	entry->fname = (char*)malloc(20 * sizeof(char));
	entry->pname = (char*)malloc(20 * sizeof(char));
	entry->bdate = (char*)malloc(10 * sizeof(char));
	entry->address = (char*)malloc(100 * sizeof(char));
	entry->mobile = (char*)malloc(12 * sizeof(char));
	entry->wphone = (char*)malloc(12 * sizeof(char));
*/
	return 0;
}

int create_db(char* filename) {
	FILE* database;
	database = fopen(filename, "w+b");

	if (database == NULL) return 1;
	
	fclose(database);
	return 0;
}

int entry_print(n_entry* entry) {
	if (entry == NULL) return 1;

	printf("%u.\nФИО: %s %s %s\nДата рождения: %s\nАдрес: %s\nМоб: %s\nРаб:%s\n",
		entry->id, entry->lname, entry->fname, entry->pname,
		entry->bdate, entry->address, entry->mobile, entry->wphone);

	return 0;
}

int list_entries(char* filename) {
	FILE* database;
	database = fopen(filename, "rb");

	if (database == NULL) return 1;

	n_entry* entry = (n_entry*)malloc(sizeof(n_entry));
//	entry_alloc(entry);

	while (!feof(database)) {
		fread(entry, sizeof(struct n_entry), 1, database);
		entry_print(entry);
	}
	
	fclose(database);
	return 0;
}

int entry_add(char* filename, n_entry* entry) {
	FILE* database;
	database = fopen(filename, "a+b");

	if (database == NULL) return 1;
	
	fwrite(entry, sizeof(struct n_entry), 1, database);
	
	fclose(database);
	return 0;
}


#endif
