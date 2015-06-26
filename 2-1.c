#include <stdio.h>
#include <limits.h>

main()
{
	printf("max of char is %d \n", CHAR_MAX);
	printf("min of char is %d \n", CHAR_MIN);
	printf("max of unsigned char is %d \n", UCHAR_MAX);

	printf("max of short is %d \n", SHRT_MAX);
	printf("min of short is %d \n", SHRT_MIN);
	printf("max of unsigned short is %d \n", USHRT_MAX);

	printf("max of long is %ld \n", LONG_MAX);
	printf("min of long is %ld \n", LONG_MIN);
	printf("max of unsigned long is %lu \n", ULONG_MAX);

	printf("max of int is %d \n", INT_MAX);
	printf("min of int is %d \n", INT_MIN);
	printf("max of unsigned int is %u \n", UINT_MAX);

}
