#include"chuoi.h"
int get_len(char* str)
{
	int len = 0;
	while (str[len] != 0)
	{
		len++;
	}
	return len;
}
char* find_character(char c, char* str)
{
	unsigned int str_len = get_len(str);
	for (unsigned int i = 0; i < str_len; i++)
	{
		if (str[i] == c)
			return str + i;
	}
	return 0;
}

char* find_string(char* str, char* Substr)
{
	unsigned int str_len = get_len(str);
	unsigned int substr_len = get_len(Substr);
	for (int i = 0; i < str_len; i++)
	{
		int j = 0;
		for (; j < substr_len; j++)
		{
			if (str[i + j] != Substr[j])
				break;
		}
		if (j >= substr_len)
			return str + i;
	}
	return 0;
}