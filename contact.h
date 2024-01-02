#define _CRT_SECURE_NO_WARNINGS 1

#define DEFAULT_SZ 3
#define MAX_NAME 20
#define MAX_SEX 8
#define MAX_TELE 12
#define MAX_ADDR 30

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

enum Option
{
	EXIT,  //0
	ADD,   //1
	DEL,   //2
	SEARCH,//3
	MODIFY,//4
	SHOW,  //5
	SORT,  //6
	Save   //7
};

typedef struct PeoInfo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
}PeoInfo;

typedef struct Contact
{
	struct PeoInfo *data; 
	int size;             //record how many element now 
	int capacity;         //max capacity now
}Contact;

void InitContact(struct Contact* ps);
void AddContact(struct Contact* ps);
void ShowContact(const struct Contact* ps);
void DelContact(struct Contact* ps);
void SearchContact(const struct Contact* ps);
void ModifyContact(struct Contact* ps);
void SortContact(struct Contact* ps);
void DestroyContact(struct Contact* ps);
void SaveContact(struct Contact* ps);
void LoadContact(struct Contact* ps);