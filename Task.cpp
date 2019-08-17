// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include<time.h>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	if (argc == 3)
	{
		FILE *file_Input, *file_Output;

		if (fopen_s(&file_Input, (char*)argv[1], "rb") != NULL)
		{
			cout << "Error open file " << (char*)argv[1] << endl;
			exit(1);
		}
		if (fopen_s(&file_Output, (char*)argv[2], "wb") != NULL)
		{
			cout << "Error open file " << (char*)argv[2] << endl;
			exit(1);
		}

		int lenght = 0;
		fseek(file_Input, 0, SEEK_END);
		lenght = ftell(file_Input) / sizeof(int); //number of elements in the file
		rewind(file_Input);

		int * buf = (int*)malloc(sizeof(int) * lenght);
		fread(buf, sizeof(int), lenght, file_Input);

		for (int i = lenght - 1; i >= 0; i--)
			fwrite(&buf[i], sizeof(int), 1, file_Output);

		free(buf);
		fclose(file_Input);
		fclose(file_Output);
	}
	else
		cout << "Not arguments" << endl;
	system("pause");
	return 0;
}

