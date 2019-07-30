#include "Contact.h"

void menu()
{
	printf("*************************\n");
	printf("*****  1.�����ϵ�� *****\n");
	printf("*****  2.ɾ����ϵ�� *****\n");
	printf("*****  3.������ϵ�� *****\n");
	printf("*****  4.�޸���ϵ�� *****\n");
	printf("*****  5.���浽�ļ� *****\n");
	printf("*****  6.���ļ����� *****\n");
	printf("*****  7.��ӡͨѶ¼ *****\n");
	printf("*****  0.�˳�       *****\n");
	printf("*************************\n");
}

void TestPbook()
{
	ContactBook pbook;
	ContactBookInit(&pbook);
	int option = -1;
	while (option != 0)
	{
		menu();
		scanf("%d", &option);
		switch (option)
		{
		case 1:
		{
				  struct Contact con1;
				  printf("������������");
				  scanf("%s", &con1.name_);
				  printf("�������Ա�");
				  scanf("%s", &con1.sex);
				  printf("���������䣺");
				  scanf("%d", &con1.age);
				  printf("������绰��");
				  scanf("%s", &con1.tel_);
				  printf("�������ַ��");
				  scanf("%s", &con1.address_);
				  ContactBookAppend(&pbook, &con1);
				  break;
		}
		case 2:
		{
				  printf("������Ҫɾ��������:");
				  char name1[24];
				  scanf("%s", name1);
				  ContactBookDelet(&pbook, name1);
				  break;
		}
		case 3:
		{
				  ContactBookPrint(&pbook);
				  printf("������Ҫ���ҵ�����:");
				  char name2[24];
				  scanf("%s", name2);
				  Contact *con = ContactBookFind(&pbook, name2);
				  if (con == 0)
					  printf("����ʧ�ܣ�\n");
				  else
				  {
					  printf("#############################\n");
					  printf("������%s\n", con->name_);
					  printf("�Ա�%s\n", con->sex);
					  printf("���䣺%d\n", con->age);
					  printf("�绰��%s\n", con->tel_);
					  printf("��ַ��%s\n", con->address_);
					  printf("#############################\n");
				  }
				  break;
		}
		case 4:
		{
				  printf("������Ҫ�޸ĵ�����:");
				  char name3[24];
				  scanf("%s", name3);
				  ContactBookRevise(&pbook, name3);
				  break;
		}
		case 5:
		{
				  ContactBookSave(&pbook, "ContactBookBin.txt");
				  break;
		}
		case 6:
		{
				  ContactBookLoad(&pbook, "ContactBookBin.txt");
				  ContactBookPrint(&pbook);
				  break;
		}
		case 7:
		{
				  ContactBookPrint(&pbook);
				  break;
		}
		default:
			break;
		}
	}
	ContactBookDestroy(&pbook);
}

void TestContactBook()
{
	ContactBook pbook;
	ContactBookInit(&pbook);
	//Contact con1;
	//strcpy(con1.name_, "peter");
	//strcpy(con1.address_, "����δ������屰뵺");
	//strcpy(con1.tel_, "18241321212");
	//strcpy(con1.sex ,"��");
	//con1.age = 18;
	//Contact con2;
	//strcpy(con2.name_, "baby");
	//strcpy(con2.address_, "�����������ƾ�ѧԺ");
	//strcpy(con2.tel_, "15619609033");
	//strcpy(con2.sex, "��");
	//con2.age = 22;
	//ContactBookAppend(&pbook, &con1);
	//ContactBookAppend(&pbook, &con2);
	//ContactBookPrint(&pbook);
	//ContactBookSave(&pbook, "ContactBookBin.txt");
	ContactBookLoad(&pbook, "ContactBookBin.txt");
	ContactBookPrint(&pbook);
	printf("������Ҫ���ҵ�����:");
	char name2[24];
	scanf("%s", name2);
	Contact *con = ContactBookFind(&pbook, name2);
	if (con == 0)
		printf("����ʧ�ܣ�\n");
	else
	{
		printf("#############################\n");
		printf("������%s\n", con->name_);
		printf("�Ա�%s\n", con->sex);
		printf("���䣺%d\n", con->age);
		printf("�绰��%s\n", con->tel_);
		printf("��ַ��%s\n", con->address_);
		printf("#############################\n");
	}
	ContactBookDestroy(&pbook);
}

int main()
{
	TestPbook();
	//TestContactBook();
	system("pause");
	return 0;
}