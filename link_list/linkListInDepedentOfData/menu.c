#include "menu.h"
#include <string.h>


Menu createMenu()
{
	Menu newMenu =(Menu)malloc(sizeof(struct menu_s));
	newMenu->list = createLinkList();//创建一个链表
	newMenu->handler=NULL;
	return newMenu;
}

void insertMenuCommand(Menu menu ,\
					   char * commandName,\
					   char * commandDetailInfo,\
					   void (*handler)())
{
	//创建一个新的指令
	MenuCommand newCommand = (MenuCommand)malloc(sizeof(struct menu_s));
	if(newCommand==NULL)
	{
		perror("create menu command failed");
		return;
	}
	//将有效数据赋值给新命令结构
	strcpy(newCommand->commandName , commandName);
	strcpy(newCommand->commandDetailInfo , commandDetailInfo);
	newCommand->handler= handler;
	insertLinkListNode(menu->list,(LinkListNode)newCommand);//将原本的MenuCommand 类型转为LinkListNode，调用函数指针
}

MenuCommand findCommand(Menu menu , char * commandName)
{

	MenuCommand tempNode = menu; 
	while(tempNode!=NULL)
	{
		tempNode=(MenuCommand)getNextNode(menu->list , (LinkListNode)tempNode);//逐次遍历链表结构
		if(strcmp(tempNode->commandName,commandName)==0)
			break;
	}
	return tempNode;
}

void deleteMenuCommand(Menu menu , char * commandName)
{
	MenuCommand deleteCommand = findCommand(menu,commandName);
	if(deleteCommand==NULL)
		return;
	//将在链表里面删除的东西全都反回来再释放
	deleteLinkListNode(menu->list , (LinkListNode)deleteCommand);
	free(deleteCommand);
}


void runCommmand(Menu menu , char * commandName)
{
	MenuCommand command = findCommand(menu,commandName);
	if(command==NULL)
		fprintf(stderr, "%s%s\n", "Error:can not find command ",commandName);
	else
		command->handler();//运行对应的句柄函数
}

MenuCommand getNextMenuCommand(Menu menu , MenuCommand command)
{
	if(command==NULL)
		return NULL;
	else
		return (MenuCommand)getNextNode(menu->list,(LinkListNode)command);
}

