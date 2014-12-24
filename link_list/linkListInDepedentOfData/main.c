#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "linkList.h"
//下面时所有命令的执行函数
void help();
void quit();
void sayHello();

void initMenu(Menu menu)
{
	// 创建help命令
	insertMenuCommand(menu,\
					  "help",\
					  "for Help...",\
					  help);
	// 创建quit命令
	insertMenuCommand(menu,\
					  "quit",\
					  "quit from the program...",\
					  quit);
	// 创建sayHello命令
	insertMenuCommand(menu,\
					  "sayHello",\
					  "print Hello on the screen",\
					  sayHello);
	/*
	...
	这里添加其他的命令控制
	*/
}

Menu fileHelperMenu=NULL;//创建一个全局的menu对象

int main(int argc, char const *argv[])
{
	char buf[100];
	fileHelperMenu = createMenu();
	MenuCommand tempCommand;
	initMenu(fileHelperMenu);
	fprintf(stderr, "%s\n","+++++fileHelperMenu+++++" );
	while(1)
	{
		printf("%s","File Helper>");
		fflush(stdout);
		scanf("%s",buf);
		tempCommand = findCommand(fileHelperMenu , buf);
		if(tempCommand==NULL)
			fprintf(stderr, "%s\n","unknow command" );
		else
			tempCommand->handler();
	}
	return 0;
}

void help()
{
	MenuCommand command; 
	//这里需要跳过第一个空指令节点
	command = getNextMenuCommand(fileHelperMenu,(MenuCommand)fileHelperMenu);
	command = getNextMenuCommand(fileHelperMenu,(MenuCommand)command);
	while(command!=NULL)
	{
		printf("%s\t\t",command->commandName);
		printf("%s"," - " );
		printf("%s\n",command->commandDetailInfo);
		command = getNextMenuCommand(fileHelperMenu,command);
	}
}

void quit()
{
	printf("%s\n", "bye...");
	exit(EXIT_SUCCESS);
}

void sayHello()
{
	printf("%s\n","Hello World");
	return;
}