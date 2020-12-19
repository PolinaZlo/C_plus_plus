#include "stdafx.h"
#include <cstring>
#include "MLi.h"
int Delete(char *str1, int N1, int N2)
{
	int w = strlen(str1);
	if (N1>w || N2<N1 || N1<0)
	{
		return 0;
	}
	else
	{
		char *see = &str1[N1];
		char *see_2 = &str1[N2 + 1];
		for (int i = N1; i < w; i++)
		{
			*see = *see_2;
			see++; see_2++;
		}
		return 1;
	}
}
void Inception(char *str1, char *str2, int N1)
{
	int w = strlen(str1) + strlen(str2);
	int w_2 = strlen(str1); w_2 -= N1;
	char *see = &str1[N1];
	char *in = &str2[0];
	char buff[1024] = { 0 };
	for (int y = 0; y < w_2; y++)
	{
		buff[y] = *see; see++;
	}
	see = &str1[N1];
	for (int i = N1; i < w; i++)
	{
		*see = *in;
		see++; in++;
	}
	see = &str1[strlen(str1)];
	for (int y = 0; y < w_2; y++)
	{
		*see = buff[y]; see++;
	}
}