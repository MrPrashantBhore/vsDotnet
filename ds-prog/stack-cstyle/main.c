#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
	int arr[10];
	int top;
}Stack;

void init(Stack *s)
{
	int i=0;
	for(;i<10;i++)
		s->arr[i]=0;
		
	s->top = -1;
}

void push(Stack *s, int value)
{
	s->top++;
	s->arr[s->top]=value;
}

int pop(Stack *s)
{
	int value = s->arr[s->top];
	s->top--;
	return value;	
}

void print(Stack *s)
{
	int i=0;
	for(;i<=s->top;i++)
		printf("%d\n", s->arr[i]);
}

int main(int argc, char *argv[]) 
{
	Stack s1;
	init(&s1);
	
	push(&s1,10);
	push(&s1,20);
	push(&s1,30);
	push(&s1,40);
	pop(&s1);
	push(&s1,50);
	
	print(&s1);
	
	return 0;
}

