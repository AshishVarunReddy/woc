#include<bits/stdc++.h>
using namespace std;
#define ends "\n"


struct StackNode{
	int data;
	StackNode* next;
};

StackNode* createNode(int val){
		StackNode* newNode = new(StackNode);
		newNode->data = val;
		newNode->next = NULL;
		return newNode;
}

void push(StackNode**top_p, int val){
	StackNode* newNode = createNode(val);	
	if(*top_p != NULL){
		newNode->next = *top_p;
	}
	*top_p = newNode;
}

void pop(StackNode** top_p){
	StackNode*d = *top_p;
	if(*top_p == NULL){
		cout<<"Severe Underflow detected"<<ends;
		return;
	}
	*top_p = (*top_p) -> next;
	delete(d);
}

bool isEmpty(StackNode** top_p){
	if(*top_p == NULL){
	return true;
	}
	return false;
}

int peek(StackNode** top_p){
	if(*top_p == NULL){
		cout<<"Severe Underflow detected"<<ends;
		return INT_MIN;
	}else{
		return (*top_p)->data;
	}
}

StackNode** queuing(StackNode** top_p){
	StackNode* top2 = NULL;
	while(!isEmpty(top_p)){
		push(&top2, (*top_p)->data);
		pop(top_p);
	}
	StackNode** a = &top2;
	return a;
}

int main(){
	StackNode* top = NULL;
	push(&top, 2);
	push(&top, 32);
	push(&top, 7);
	push(&top, 21);
	push(&top, 11);
	pop(&top);
	cout<<peek(&top)<<ends;
	StackNode** q = queuing(&top);
	StackNode* qt = *q;
	cout<<peek(&qt)<<ends;
	return 0;
}
