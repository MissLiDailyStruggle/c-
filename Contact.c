#include "Contact.h"

void ContactBookInit(ContactBook *pbook)
{
	assert(pbook);
	pbook->con_array_ = (Contact *)malloc(8 * sizeof(Contact));
	if (pbook->con_array_ == NULL)
	{
		printf("malloc error");
		exit(-1);
	}
	pbook->size_ = 0;
	pbook->capacity = 8;
}

void ContactBookDestroy(ContactBook *pbook)
{
	assert(pbook);
	free(pbook->con_array_);
	pbook->con_array_ = NULL;
	pbook->capacity = pbook->size_ = 0;
}

void ContactBookAppend(ContactBook *pbook, Contact *con)
{
	assert(pbook && con);
	if (pbook->size_ >= pbook->capacity)
	{
		pbook->capacity *= 2;
		Contact *new_array = (Contact *)realloc(pbook->con_array_, sizeof(Contact)*pbook->capacity);
		if (new_array == NULL)
		{
			printf("realloc error");
			exit(-1);
		}
		pbook->con_array_ = new_array;
	}
	strcpy(pbook->con_array_[pbook->size_].name_, con->name_);
	strcpy(pbook->con_array_[pbook->size_].address_, con->address_);
	strcpy(pbook->con_array_[pbook->size_].tel_, con->tel_);
	strcpy(pbook->con_array_[pbook->size_].sex, con->sex);
	pbook->con_array_[pbook->size_].age = con->age;
	pbook->size_++;
}

void ContactBookPrint(ContactBook *pbook)
{
	int i = 0;
	for (i = 0; i < pbook->size_; i++)
	{
		printf("#############################\n");
		printf("������%s\n", pbook->con_array_[i].name_);
		printf("�Ա�%s\n", pbook->con_array_[i].sex);
		printf("���䣺%d\n", pbook->con_array_[i].age);
		printf("�绰��%s\n", pbook->con_array_[i].tel_);
		printf("��ַ��%s\n", pbook->con_array_[i].address_);
		printf("#############################\n");
	}
}

void ContactBookDelet(ContactBook *pbook, const char *name)
{
	Contact *pcon = ContactBookFind(pbook,name);
	if (pcon == 0)
	{
		printf("��������������ڣ�ɾ��ʧ�ܣ�\n");
		return;
	}
	while (pcon < pbook->con_array_ + pbook->size_ - 1)
	{
		memcpy(pcon, pcon + 1, sizeof(Contact));
		pcon++;
	} 
	pbook->size_--;
}

Contact* ContactBookFind(ContactBook *pbook, const char *name)
{
	assert(pbook && name);
	for (size_t i = 0; i < pbook->size_; i++)
	{
		if ((strcmp(pbook->con_array_[i].name_, name)) == 0)
			return &pbook->con_array_[i];
	}
	return 0;
}

void ContactBookRevise(ContactBook *pbook, const char *name)
{
	Contact *pcon = ContactBookFind(pbook, name);
	if (pcon == 0)
	{
		printf("��������������ڣ�ɾ��ʧ�ܣ�\n");
		return;
	}
	else
	{
		printf("������������");
		scanf("%s", pcon->name_);
		printf("�������Ա�");
		scanf("%s", pcon->sex);
		printf("���������䣺");
		scanf("%d", &pcon->age);
		printf("������绰��");
		scanf("%s", pcon->tel_);
		printf("�������ַ��");
		scanf("%s", pcon->address_);
		return;
	}
}

void ContactBookSave(ContactBook *pbook, const char *file)
{
	FILE *fp = fopen(file, "wb");
	if (fp == NULL)
	{
		printf("���ļ�ʧ�ܣ�\n");
		exit(-1);
	}
	Contact *array = pbook->con_array_;
	for (size_t i = 0; i < pbook->size_; i++)
	{
		fwrite(&array[i], sizeof(Contact), 1, fp);
	}
	fclose(fp);
}

void ContactBookLoad(ContactBook *pbook, const char *file)
{
	FILE *fp = fopen(file, "rb");
	if (fp == NULL)
	{
		printf("���ļ�ʧ�ܣ�\n");
		exit(-1);
	}
	Contact con;
	while (fread(&con, sizeof(Contact), 1, fp) == 1)
	{
		ContactBookAppend(pbook, &con);
	}
	fclose(fp);
}
