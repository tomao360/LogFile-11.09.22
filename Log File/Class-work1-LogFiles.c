#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#pragma warning(disable : 4996)

//A function that writes a Log file
void Log(char message[100])
{
	//Enters the current date + time 
	time_t t;
	time(&t);
	struct tm* timeinfo;
	timeinfo = localtime(&t);

	char str[100];
	sprintf(str, "%d.%d.%d: %d:%d:%d - ", timeinfo->tm_year + 1900, timeinfo->tm_mon + 1, timeinfo->tm_mday, timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
	//////////////////////////////////

	FILE* f = fopen("LogFileExe1.log", "a");

	fputs(str, f);
	fputs(message, f);
	fputs("\n", f);

	fclose(f);
}

//We will call this function when we have ERROR
void LogError(char message[100])
{
	char str[100];
	sprintf(str, "%s %s", "Error - ", message);
	Log(str);
}

//We will call this function when we have an EVENT
void LogEvent(char message[100])
{
	char str[100];
	sprintf(str, "%s %s", "Event - ", message);
	Log(str);
}

int main()
{
	LogEvent("System Is Starting"); //Start the Log file 

	//Get a number from the user
	char num[100];
	printf("Please enter a number of up to 100 characters: ");
	gets(num);

	//Creating a string (to tell which number the user entered) with sprintf to call the Log function
	char str[100];
	sprintf(str, "%s %s", "The user entered the number: ", num);
	LogEvent(str);


	//Open a .txt file and enter the numbers from 1 to the number the user entered
	FILE* f = fopen("userNumber.txt", "w");
	int a = atoi(num);
	char str2[100]; //For the sprintf

	//Write to the .txt file
	if (f != NULL)
	{
		LogEvent("The .txt file has been successfully opened");
		for (int i = 1; i <= a; i++)
		{
			sprintf(str2, "%d", i);
			fputs(str2, f);
			fputs("\n", f);
		}
	}
	else
	{
		LogError("The .txt file not opened");
	}


	LogEvent("System Is Ending"); //End the Log file

	return 0;
}