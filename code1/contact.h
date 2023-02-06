#pragma once
#include "common.h"
#define MAX_NAME 20
#define MAX_SEX 10
#define MAX_TELE 12
#define MAX_ADDR 30
#define MAX 1000
#define DEFAULT_SZ 3
#define INC_SZ 2
typedef struct PeoInfo
{
	char _name[MAX_NAME];
	char _sex[MAX_SEX];
	int _age;
	char _tele[MAX_TELE];
	char _addr[MAX_ADDR];
} PeoInfo;
//typedef struct Contact
//{
//	PeoInfo data[MAX];
//	int sz;
//} Contact; 
typedef struct Contact
{
	PeoInfo* _data;
	int _sz;
	int _capacity;
} Contact;
void InitContact(Contact* pc);
void AddContact(Contact* pc);
void PrintContact(Contact* pc);
void DelContact(Contact* pc);
void SearchContact(Contact* pc);
void ModifyContact(Contact* pc);
void SortContact(Contact* pc);
void DestroyContact(Contact* pc);
void SaveContact(Contact* pc);
void LoadContact(Contact* pc);
void CheckCapacity(Contact* pc);