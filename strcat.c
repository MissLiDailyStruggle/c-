//#define _CRE_SECURE_NO_WARNNGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <assert.h>
//
//char *my_strcat(char *dst,const char *src)
//{
//	char *ret = dst;
//	assert(dst && src);
//	while(*dst)
//		dst++;
//	while(*src)
//	{
//		*dst = *src;
//		dst++;
//		src++;
//	}
//	*dst = *src;
//	return ret;
//}
//int main()
//{
//	char dst[20] = {"hello"};
//	char src[] = " world!";
//
//	printf("%s\n",my_strcat(dst,src));
//
//	system("pause");
//	return 0;
//}