#include <iostream>
#include <cstring>
#include <string>

using namespace std;

typedef struct Node
{
	char data;
	Node* n1;
	Node* n2;
	Node* n3;
	Node* n4;
	bool chk;
}Node;

Node* root=NULL;
Node* newNode(char data)
{
	Node* newT;
	newT=(Node*)malloc(sizeof(Node));


	newT->data=data;
	newT->n1=NULL;
	newT->n2=NULL;
	newT->n3=NULL;
	newT->n4=NULL;
	newT->chk=false;
	
	return newT;
}
void addNode(Node* a, char data)
{
	Node*ptr;
	Node *newT=newNode(data);
	if(data != 'x')
		newT->chk=true;
	if(a==NULL)
	{
		root=newT;
		return ;
	}

	ptr=a;
	while(ptr)
	{
		if(ptr->n1==NULL)
		{
			ptr->n1=newT;
			break;
		}
		else if(ptr->n1->data=='x'&& !(ptr->n1->chk))
		{
			ptr=ptr->n1;
			continue;
		}

		if(ptr->n2==NULL)
		{
			ptr->n2=newT;
			break;
		}
		else if(ptr->n2->data=='x'&& !(ptr->n2->chk))
		{
			ptr=ptr->n2;
			continue;
		}

		if(ptr->n3==NULL)
		{
			ptr->n3=newT;
			break;
		}
		else if(ptr->n3->data=='x'&& !(ptr->n3->chk))
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
		else if(ptr->n4->data=='x'&& !(ptr->n4->chk))
		{
			ptr=ptr->n4;
			continue;
		}
	}
}
void UpsideDown(Node *T)
{
	printf("%c", T->data);
	if(T->n3)
		UpsideDown(T->n3);
	if(T->n4)
		UpsideDown(T->n4);
	if(T->n1)
		UpsideDown(T->n1);
	if(T->n2)
		UpsideDown(T->n2);
}

void Del(Node *T)
{
	if(T->n1)
		Del(T->n1);
	if(T->n2)
		Del(T->n2);
	if(T->n3)
		Del(T->n3);
	if(T->n4)
		Del(T->n4);
	free(T);
}
int main(void)
{
	Node *ptr;
	int C;
	scanf("%d", &C);
	for(int j=0; j<C; j++)
	{
		char S[1001];
		scanf("%s", S);
		for(int i=0; i<strlen(S); i++)
			addNode(root,S[i]);

		ptr=root;
		UpsideDown(ptr);
		printf("\n");

		Del(root);
		root=NULL;
	}
	return 0;
}

