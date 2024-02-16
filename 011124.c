
#include <stdio.h>
#include <stdlib.h>
int main()
{
	const int SZ_INT = 10;
	const int SZ_LONG = sizeof(int) * SZ_INT / sizeof(long);
	int i = 0;
	int *pInt;
	int *pTmp;
	long *pLong;
	pInt = (int *)malloc(sizeof(int) * SZ_INT);
	for (i = 0; i < SZ_INT; ++i)
	{
		pInt[i] = i;
	}
	printf("SZ_INT : %d\n", SZ_INT);
	printf("SZ_LONG : %d\n", SZ_LONG);
	printf("Int Values:\n");
	pTmp = pInt;
	for (i = 0; i < SZ_INT; ++i)
	{
		printf("%d ", *pTmp);
		pTmp++;
	}
	printf("\n\n");
	printf("Long Values:\n");
	pLong = (long *)pInt;
	for (i = 0; i < SZ_LONG; ++)i
	{
		printf("%d ", (int)*pLong);
		pLong++;
	}
	printf("\n\n");
	pLong = (long *)pInt;
	for (i = 0; i < SZ_LONG; ++i)
	{
		printf("%lx ", *pLong);
		pLong++;
	}
	printf("\n\n");
	return 0;
}
