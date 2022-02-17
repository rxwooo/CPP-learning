#include <stdio.h>
#include<windows.h>


int main()
{
    FILE *fp1,*fp2,*fp3;
    char fn1[100],fn2[100],fn3[100];
    puts("please input file name 1:");
    gets(fn1);
    
    puts("please input file name 2:");
    gets(fn2);
    puts("please ouput file name:");
    gets(fn3);
	fp1=fopen(fn1,"rb+");
	fp2=fopen(fn2,"rb+");
    fp3=fopen(fn3,"wb+");
    while(!feof(fp1))
    {
    	fputc(fgetc(fp1),fp3);
	}
	while(!feof(fp2))
    {
    	fputc(fgetc(fp2),fp3);
	}
    return 0;
}

