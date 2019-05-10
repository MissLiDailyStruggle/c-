//#define _CRE_SECURE_NO_WARNNGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <assert.h>
//
//char *my_strcpy(char *dst,const char *src)
//{
//	char *temp = dst;
//	assert(src && dst);
//	while(*src)
//	{
//		*dst = *src;
//		dst++;
//		src++;
//	}
//	*dst  = *src;
//	return temp;
//}
//
//int main()
//{
//	char src[]="i miss you ";
//	char dst[20]={0};
//	char *ret =my_strcpy(dst,src);
//	
//	printf("%s\n",ret);
//
//	system("pause");
//	return 0;
//}