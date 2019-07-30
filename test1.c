#include "Contact.h"

void menu()
{
	printf("*************************\n");
	printf("*****  1.添加联系人 *****\n");
	printf("*****  2.删除联系人 *****\n");
	printf("*****  3.查找联系人 *****\n");
	printf("*****  4.修改联系人 *****\n");
	printf("*****  5.保存到文件 *****\n");
	printf("*****  6.从文件加载 *****\n");
	printf("*****  7.打印通讯录 *****\n");
	printf("*****  0.退出       *****\n");
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
				  printf("请输入姓名：");
				  scanf("%s", &con1.name_);
				  printf("请输入性别：");
				  scanf("%s", &con1.sex);
				  printf("请输入年龄：");
				  scanf("%d", &con1.age);
				  printf("请输入电话：");
				  scanf("%s", &con1.tel_);
				  printf("请输入地址：");
				  scanf("%s", &con1.address_);
				  ContactBookAppend(&pbook, &con1);
				  break;
		}
		case 2:
		{
				  printf("请输入要删除的名字:");
				  char name1[24];
				  scanf("%s", name1);
				  ContactBookDelet(&pbook, name1);
				  break;
		}
		case 3:
		{
				  ContactBookPrint(&pbook);
				  printf("请输入要查找的名字:");
				  char name2[24];
				  scanf("%s", name2);
				  Contact *con = ContactBookFind(&pbook, name2);
				  if (con == 0)
					  printf("查找失败！\n");
				  else
				  {
					  printf("#############################\n");
					  printf("姓名：%s\n", con->name_);
					  printf("性别：%s\n", con->sex);
					  printf("年龄：%d\n", con->age);
					  printf("电话：%s\n", con->tel_);
					  printf("地址：%s\n", con->address_);
					  printf("#############################\n");
				  }
				  break;
		}
		case 4:
		{
				  printf("请输入要修改的名字:");
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
	//strcpy(con1.address_, "西安未央区浐灞半岛");
	//strcpy(con1.tel_, "18241321212");
	//strcpy(con1.sex ,"男");
	//con1.age = 18;
	//Contact con2;
	//strcpy(con2.name_, "baby");
	//strcpy(con2.address_, "西安长安区财经学院");
	//strcpy(con2.tel_, "15619609033");
	//strcpy(con2.sex, "男");
	//con2.age = 22;
	//ContactBookAppend(&pbook, &con1);
	//ContactBookAppend(&pbook, &con2);
	//ContactBookPrint(&pbook);
	//ContactBookSave(&pbook, "ContactBookBin.txt");
	ContactBookLoad(&pbook, "ContactBookBin.txt");
	ContactBookPrint(&pbook);
	printf("请输入要查找的名字:");
	char name2[24];
	scanf("%s", name2);
	Contact *con = ContactBookFind(&pbook, name2);
	if (con == 0)
		printf("查找失败！\n");
	else
	{
		printf("#############################\n");
		printf("姓名：%s\n", con->name_);
		printf("性别：%s\n", con->sex);
		printf("年龄：%d\n", con->age);
		printf("电话：%s\n", con->tel_);
		printf("地址：%s\n", con->address_);
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