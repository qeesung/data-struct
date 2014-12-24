#ifndef _MENU_H
#define _MENU_H
#include "linkList.h"
#include <stdio.h>
#include <stdlib.h>

struct menu_s
{	
	LinkListNode list;
	char commandName[20];//命令的名字
	char commandDetailInfo[100];//命令的详细说明
	void (*handler)();//命令的调用函数
};

typedef struct menu_s * Menu;
typedef Menu MenuCommand;

// 创建一个菜单程序
Menu createMenu();
//插入一个命令到菜单里面去
void insertMenuCommand(Menu menu ,\
					   char * commandName,\
					   char * commandDetailInfo,\
					   void (*handler)());

void deleteMenuCommand(Menu menu,\
					   char * commandName);
//在菜单里面查询对应的命令，并将对应的指针返回
MenuCommand findCommand(Menu menu,char * commandName);
//运行菜单里面的命令
void runCommmand(Menu menu , char * commandName);
//得到当前的下一个
MenuCommand getNextMenuCommand(Menu menu , MenuCommand curCommand);



#endif