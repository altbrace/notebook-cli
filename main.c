#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "notebook.h"


void main() {
	
	n_entry* entry = (n_entry*)malloc(sizeof(n_entry));
//	entry_alloc(&entry);

	create_db("entries.db");
	
	entry->id = 0;
	strcpy(entry->lname, "idiot");
	strcpy(entry->fname, "cock");
	strcpy(entry->pname, "sergeich");
	strcpy(entry->bdate, "11.11.2011");
	strcpy(entry->address, "kekekeke");
	strcpy(entry->mobile, "+79111991111");
	strcpy(entry->wphone, "+79991221111");

	entry_print(entry);

	entry_add("entries.db", entry);

	list_entries("entries.db");
}
