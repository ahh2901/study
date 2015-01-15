#include<stdio.h>

struct Node{
	int data;
	Node *node;
};

Node node;
Node *head;

void initialize();
void destroy();
Node* pop(Node *target);
void push(Node *prev, int data);
void printNodes(Node *node, int count);

void main(){
	initialize();

	push(&node, 1);
	push(&node, 2);
	push(&node, 3);
	push(&node, 4);

	printNodes(&node, 1);

	pop(node.node->node);

	printNodes(&node, 1);

	destroy();
}

void initialize(){
	node.data = 0;
	node.node = NULL;

	head = &node;
}

void destroy(){
	Node *deleter;
	Node *temp;
	while(node.node != head){
		deleter = &node;

		while(deleter->node != head){
			deleter = deleter->node;
		}

		temp = deleter->node;
		head = deleter;
		delete(temp);
	}
}

Node* pop(Node *target){
	//data 쓸곳 없으니까 뽑은 내역 바로 지우는걸로 만듬
	Node *poper;
	Node *temp;
	poper = &node;

	if(target == NULL){
		return NULL;	
	}

	while(poper->node != target){
		poper = poper->node;
	}

	temp = poper->node; //temp = target
	poper->node = poper->node->node;
	
	delete(temp);
	return poper;
}

void push(Node *prev, int data){
	if(prev->node != NULL){
		push(prev->node, data);
	}else{
		prev->node = new Node;
		prev->node->node = NULL;
		prev->node->data = data;
		head = prev->node;
	}
}

void printNodes(Node *node, int count){
	printf("[%d]:%d \n",count ,node->data);
	if(node->node != NULL){
		printNodes(node->node, ++count);
	}else{
		printf("\n");
	}
}