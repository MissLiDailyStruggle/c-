//#define _CRE_SECURE_NO_WARNNGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <assert.h>
//
//int my_strcmp(const char *str1,const char *str2)
//{
//	int ret = 0;
//	assert(str1 && str2);
//	while(!(ret = *(unsigned char *)str1 - *(unsigned char *)str2) &&*str2)
//	{
//		str1++;
//		str2++;
//	}
//	if(ret > 0)
//		return 1;
//	else if(ret < 0)
//		return -1;
//	else
//		return 0;
//}
//
//int main()
//{
//	char str1[] = "hello world!";
//	char str2[] = "helloworld!";
//	int ret = my_strcmp(str1,str2);
//
//	printf("%d\n",ret);
//
//	system("pause");
//	return 0;
//}
//
//	