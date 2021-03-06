#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef union {
  int i;
  char *str;
  void *p;
} EntryData;

typedef struct stable_s SymbolTable;

struct stable_s {

	EntryData data;
	SymbolTable *left;
	SymbolTable *right;
};

typedef struct {
	int new;
	EntryData *data;
} InsertionResult;

SymbolTable* stable_create(){

	SymbolTable *st;
	st = malloc(sizeof(SymbolTable));
	return st;
};

SymbolTable* stable_find(SymbolTable *st, const char *key){

	if (st == NULL)
		return NULL;

	if (strcmp(key, st->data.str) == 1)
		return stable_find(st->right, key);

	else if (strcmp(key, st->data.str) == -1)
		return stable_find(st->left, key);

	else
		return st;
}

SymbolTable* stable_insert(SymbolTable *st, const char *key){

	if (st == NULL){
		SymbolTable *temp;
		temp = stable_create();
		temp->left = temp->right = NULL;
		temp->data.str = strdup(key);
		return temp;
	}
	if (strcmp(key, st->data.str) > 0)
		st->right = stable_insert(st->right, key);

	else if (strcmp(key, st->data.str) < 0)
		st->left = stable_insert(st->left, key);

	return st;
}

void printInOrder(SymbolTable *st){

	if (st == NULL){
		printf("");
	}
	else {
		printInOrder(st->left);
		printf("%s ", (st->data).str);
		printInOrder(st->right);
	}
}

int main() {

	SymbolTable *st;
	st = NULL;

	st = stable_insert(st, "hello");
	st = stable_insert(st, "its me");
	st = stable_insert(st, "hahah");

	printInOrder(st);


	return 0;
}