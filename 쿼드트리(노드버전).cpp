#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/*
4
w
xbwwb
xbwxwbbwb
xxwwwbxwxwbbbwwxxxwwbbbwwwwbb
*/
typedef struct Tree
{
	char key;
	Tree *n1;
	Tree *n2;
	Tree *n3;
	Tree *n4;
	bool chk;
}Node;

Node *root=NULL;

Node *newNode(char data)
{
	Node* newN;
	newN=(Node*)malloc(sizeof(Node));

	newN->key=data;
	newN->n1=NULL;
	newN->n2=NULL;
	newN->n3=NULL;
	newN->n4=NULL;
	newN->chk=false;

	return newN;
}

void addTo(Node* ptr, char data)
{
	Node* newT=newNode(data);

	if(data != 'x')
	{
		newT->chk=true;
	}
	if(ptr==NULL)
	{
		root=newT;
		return;
	}

	while(ptr)
	{
		if(ptr->n1==NULL)
		{
			ptr->n1=newT;
			break;
		}
		else if(ptr->n1->key=='x' && ptr->n1->chk==false)
		{
			ptr=ptr->n1;
			continue;
		}


		if(ptr->n2==NULL)
		{
			ptr->n2=newT;
			break;
		}
		else if(ptr->n2->key=='x' && ptr->n2->chk==false)
		{
			ptr=ptr->n2;
			continue;
		}

		if(ptr->n3==NULL)
		{
			ptr->n3=newT;
			break;
		}
		else if(ptr->n3->key=='x' && ptr->n3->chk==false)
		{
			ptr=ptr->n3;
			continue;
		}

		
		if(ptr->n4==NULL)
		{
			ptr->chk=true;
			ptr->n4=newT;
			break;
		}
		else if(ptr->n4->key=='x' && ptr->n4->chk==false)
		{
			ptr=ptr->n4;
			continue;
		}
	}

}

void UpandDown(Node *a)
{
	printf("%c", a->key);
	if(a->n3)
		UpandDown(a->n3);
	if(a->n4)
		UpandDown(a->n4);
	if(a->n1)
		UpandDown(a->n1);
	if(a->n2)
		UpandDown(a->n2);
}

void delNode(Node *a)
{
	if(a->n1)
		delNode(a->n1);
	if(a->n2)
		delNode(a->n2);
	if(a->n3)
		delNode(a->n3);
	if(a->n4)
		delNode(a->n4);

	free(a);
}
int main(void)
{
	Node* T;
	int C;
	scanf("%d", &C);
	for(int i=0; i<C; i++)
	{
		char S[1001];
		scanf("%s", S);

		for(unsigned int i=0; i<strlen(S); i++)
			addTo(root,S[i]);
		
		T=root;
		UpandDown(T);
		printf("\n");
		delNode(root);
		root=NULL;

	}
	return 0;
}