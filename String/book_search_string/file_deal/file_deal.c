/*
 * =====================================================================================
 *
 *       Filename:  file_deal.c
 *
 *    Description:  file deal c file
 *
 *        Version:  1.0
 *        Created:  2014年06月30日 23时59分13秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  qeesung (), 1245712564@qq.com
 *   Organization:  STAY HUNGRY STAY FOOLISH
 *
 * =====================================================================================
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"file_deal.h"
#include"../link_list/string_list/string_list.h"

char * daily_word[]={"an", "and", "a","of", "the","to"};
//++++++++++++++++++++++++++++++++++++++++++++++++++
void Deal_File(char * filename, String_list list)
{
	FILE * file;
	char my_buf[255];
	char word[20];
	int i;
	int j;
	int k;
	char * index_number;
	char * bookword;
	file=fopen(filename, "r+");
	if(file==NULL)
	{
		fprintf(stderr,"\n open the file :%s  failed \n ", filename);
		return;
	}
	while(fgets(my_buf,255,file)!=NULL)
	{
		i=0;
		j=0;
		while(my_buf[i]!=' ')
		{
			word[j]=my_buf[i];
			j++;
			i++;
		}
		strcpy(index_number , word);
		printf("index--->%s\n",index_number);
		j=0;
		i++;
		for(k=0;k<20;k++)
		{
			word[k]='\0';
		}
		while(my_buf[i]!='\n')
		{
			if(my_buf[i]==' ')
			{
				strcpy(bookword, word);
				printf("%s\n",bookword);
				Insert_String_List(list,word,index_number);
				for(k=0;k<20;k++)
				{
					word[k]='\0';
				}
				i++;
				j=0;
					
			}

			word[j]=my_buf[i];
			i++;
			j++;
			
		}
		strcpy(bookword, word);
		printf("%s\n",bookword);
		Insert_String_List(list,word,index_number);
		for(k=0;k<20;k++)
		{
			word[k]='\0';
		}
		for(k=0;k<255;k++)
		{
			my_buf[k]='\0';
		}
	}


	if(ferror(file))
	{	
		fprintf(stderr,"\n read the file : %s failed \n ", filename);
		return;
	
	}
	
}



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Str_Check
 *  Description:  checko if the word is a normal word
 * =====================================================================================
 */
	int
Str_Check (char * msg )
{
	int size;
	int i;
	size=sizeof(daily_word)/sizeof(char *);
	for(i=0;i<size;i++)
	{
		if(strcmp(msg,daily_word[i])==0)
		{
			return 1;
		}
	}
	return 0;
}		/* -----  end of function Str_Check  ----- */
