#include<stdio.h>
#include"chuoi.h"
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
#include<Windows.h>

typedef struct {
	char light;
	char fan;
	char motor;
}smartHome_t;

const char* data = "HTTP1.1 200 OK{"\
"\"light\": \"on\","\
"\"fan\" : \"off\","\
"\"motor\" : \"off\"}";

smartHome_t pair_data(const char* data)
{
	smartHome_t x;
	char* key = "\"light\": \"";
	char* key1 = "\"fan\": \"";
	char* key2 = "\"motor\": \"";
	char* find_key = find_string(data, key) + get_len(key);
	int index = 0;
	while (find_key[index] != '"')
	{
		index++;
	}
	char* key_str = malloc(index + 1);
	memset(key_str, 0, index + 1);
	memcpy(key_str, find_key, index);
	int len = sizeof(key_str) - sizeof(key_str[0]);
	if (len=3)
		x.light = 0x31;
	else if (len=4)
		x.light = 0x30;
	return x;
}

int main()
{
	smartHome_t x = pair_data(data);
	printf("light: %c\r\n", x.light);
	printf("fan: %c\r\n", x.fan);
	printf("motor: %c\r\n", x.motor);
	return 0;
}