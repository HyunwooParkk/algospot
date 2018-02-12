#include <stdio.h>
#include <string.h>
#define BLACK 'b'
#define WHITE 'w'
#define SUB 'x'

#define DEBUG 1
struct node {
	char val;
	struct node* string[4];
};

char input[1001];
int input_idx;
struct node nodes[220*220/4];
int nodes_idx;

struct node* quadtree(){
	struct node *ul, *ur, *dl, *dr;
	int idx2;
	int idx;
	
	idx=nodes_idx++;
	if(input[input_idx]==BLACK || input[input_idx]==WHITE){
		nodes[idx].val=input[input_idx];
		input_idx++;
		return &(nodes[idx]);
	}
	input_idx++;
	ul=quadtree();
	ur=quadtree();
	dl=quadtree();
	dr=quadtree();

	idx2=nodes_idx++;
	nodes[idx2].val='x';
	nodes[idx2].string[0]=dl;
	nodes[idx2].string[1]=dr;
	nodes[idx2].string[2]=ul;
	nodes[idx2].string[3]=ur;

	return &(nodes[idx2]);
}
int print_string(struct node* output){
	int i;
	printf("%c", (*output).val);
	if((*output).val==SUB){
		for(i=0;i<4;i++)
			print_string((*output).string[i]);
	}
	return 0;
}

int main(void){
	int c;
	struct node *output;

	scanf("%d", &c);
	while(c--){
		memset(input, 0, sizeof(char)*1001);
		memset(nodes, 0, sizeof(nodes));
		scanf("%s", input);
		input_idx=0;
		nodes_idx=0;

		output = quadtree();
		print_string(output);
		printf("\n");

	}
	return 0;
}