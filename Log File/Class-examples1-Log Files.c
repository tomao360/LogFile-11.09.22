#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996)

//Log Files - ���� ����� �� ���� ������
//����� �� ����� ���� ������:
//1. ERROR - ����� �������
//2. Warnings - �����
//3. Events - (������� (�� ��� �� ����� ����� ������


int main_1()
{
	FILE* f = fopen("firstLogFile.log", "w");

	fputs("line1\n", f);
	fputs("line2\n", f);
	fputs("line3\n", f);
	fclose(f);

	char str[1000];

	f = fopen("firstLogFile.log", "r"); //You don't need to read a file in the loop if you know the size of the file
	while (fgets(str, 1000, f) != NULL)
	{
		printf("%s", str);
	}

	fclose(f);

	return 0;
}