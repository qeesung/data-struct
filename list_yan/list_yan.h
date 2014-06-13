#ifndef _LIST_YAN_H
#define _LIST_YAN_H

struct Listnode;
typedef struct Listnode * List;

/* create a list  */
List Create_List(int number)
{
	List new_list;
	List temp;
	int i;
	// create the header 
	new_list=malloc(sizeof(struct Listnode));
	if(new_list == NULL)
	{
		printf("out of space create the haeder failed\n");
		return NULL;
	}
	// and now create the body
	temp=new_list;
	for(i=0;i<number;i++)
	{
		temp->next=malloc(sizeof(struct Listnode));
		if(temp->next==NULL)
		{
			printf("create the Listnode failed\n");
			Delete_List(new_list);// delete has been malloc
			return NULL;
		}
		printf("enter #%d number:",i);
		scanf("%d",&(temp->next->number));
		printf("\n");
		printf("enter #%d name:",i);
		scanf("%s",temp->next->name);
		temp=temp->next;// insert done
		
	}
	return new_list;
}

#endif
