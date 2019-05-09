#include<stdio.h>
//#include<conio.h>
#include<stdlib.h>
#include<dos.h>
#define TRUE 1
typedef struct code
{
	char alphaNum;
	struct code *next,*child;
}Tries;
Tries* createTries(char name[],Tries* root);
Tries* createDictionary(char name[][8],int count);
void displayTrie(Tries *parent,unsigned int offset,int length);
main()
{
	char name[5][8]={"ankit","saurabh","anuj","navjot","anbhav"};
	Tries *root=NULL;
	//clrscr();
	root = createDictionary(name,5);
	printf("\n\t=================\n\t");
	displayTrie(root,0,5);
//	getch();
}
Tries* createDictionary(char name[][8],int count)
{
	int offset,index;
	Tries *root=NULL;
	for(offset=0;offset<count;offset++)
	{
		root=createTries(name[offset],root);
	}
	return(root);
}
Tries* createTries(char name[],Tries* root)
{
	Tries* node,*previous=NULL,*temp=root;
	int offset=0;
	if(root==NULL)
	{
		root=node=(Tries*)malloc(sizeof(Tries));
		for(;;)
		{
			node->alphaNum=name[offset];
			node->next=node->child=NULL;
			if(previous!=NULL)previous->child=node;
			if(name[offset]=='\0')break;
			previous=node;
			node=(Tries*)malloc(sizeof(Tries));
			offset++;
		}
		return(root);
	}
	while(TRUE)
	{
		while(temp->alphaNum==name[offset])
		{
			printf("\n\t%c matched...",name[offset]);
			offset++;
			temp=temp->child;
		}
		if(temp->next==NULL)break;
		temp=temp->next;
	}
	temp->next=node=(Tries*)malloc(sizeof(Tries));
	for(;;)
	{
		printf("\n\t%c is linked...",name[offset]);
		node->alphaNum=name[offset];
		node->next=node->child=NULL;
		if(previous!=NULL)previous->child=node;
		if(name[offset]=='\0')break;
		previous=node;
		node=(Tries*)malloc(sizeof(Tries));
		offset++;
	}
	return(root);
}
void displayTrie(Tries *traverse,unsigned int offset,int length)
{
	static char *ary;
	static unsigned int count;
	if(offset==0)
	{
		if(ary!=NULL)free(ary);
		ary=(char*)calloc(length,sizeof(char));
		if(ary==NULL)
		{
			printf("\n\tno memory allocation in display");
		//	getch();
			exit(0);
		}
	}
	if(traverse!=NULL)
	{
		ary[offset]=traverse->alphaNum;
		displayTrie(traverse->child,offset+1,length);
		if(traverse->next==NULL)return;
		displayTrie(traverse->next,offset,length);
	}
	else
	{
//		ary[offset]='\0';
		count++;
		printf("\n\tary : %-10s count : %u",ary,count);
	//	delay(50);
	}
}

