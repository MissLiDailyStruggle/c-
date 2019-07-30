#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct Contact
{
	char name_[24];
	char sex [2];
	int tel_[16];
	char address_[64];
	int age;
}Contact;

typedef struct ContactBook
{
	Contact *con_array_;
	size_t size_;
	size_t capacity;
}ContactBook;

void ContactBookInit(ContactBook *pbook);
void ContactBookDestroy(ContactBook *pbook);
void ContactBookAppend(ContactBook *pbook, Contact *con);
void ContactBookDelet(ContactBook *pbook, const char *name);
Contact* ContactBookFind(ContactBook *pbook, const char *name);
void ContactBookRevise(ContactBook *pbook, const char *name);
void ContactBookPrint(ContactBook *pbook);
void ContactBookSave(ContactBook *pbook, const char *file);
void ContactBookLoad(ContactBook *pbook, const char *file);
//清空所有联系人
//以名字排序所有联系人



