/****Question : 
Write a program that will prompt the user for a filename for
reading from the file, and for a filename for writing to the
file, and open both the files.

Read from the file a line at a time and display it on the monitor with line
numbers.

Read a character from the user at a time , and output it to the file. Stop at EOF *****/

#include <stdio.h>//Includes Standard Input/Output
#include <stdlib.h>//Includes Standard Library 

int main()
{
	FILE *fp, *fp1;//File pointers
	char fname[10], fname1[10];//Name of the files
  char ch[100], c;
	int i = 1;

	printf("Enter the filename that to be read:");
	scanf("%s", fname);

	printf("Enter the filename that to be written into:");
	scanf("%s", fname1);

	fp = fopen(fname, "r");//Read End
	fp1 = fopen(fname1, "w");//Write End

	if(fp == NULL)
	{
		printf("Error, Unable to open file for reading'\n");
		exit(1);
	}
	printf("LineNo      Content\n");
	
	while(!feof(fp))
	{
		if(fgets(ch, 501, fp) != NULL )
		{	
			printf("\033[0;32m%-12d", i);
		        printf("\033[0;31m%s", ch);
	                i++;
		}
	}

        printf("Press CTRL + D to exit from user input\n");

	while((c = getchar()) != EOF)
	{
		putc(c, fp1);
	}
	fclose(fp);
	fclose(fp1);
	exit(0);
}
	
