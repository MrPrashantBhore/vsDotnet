#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int arr[SIZE];
int f=-1;
int r=-1;


void printFandR_Before()
{
	printf("Before: f=%d, r=%d\n", f, r);
}

void printFandR_After()
{
	print_queue();
	printf("After: f=%d, r=%d\n", f, r);
	printf("------------------------------\n");
	
}

void enqueue(int data)
{
	printFandR_Before();
	//check for full..	
	if(f == r+1%SIZE)
	//if((f==r+1) || (f==0 && r==SIZE-1))
	{
		printf("Queue is full...\n");
		return;
	}
		
	if(f==-1)		//first element?
		f=r=0;
	else			//We have space in queue..
		r=++r%SIZE;	

	arr[r] = data;
	printFandR_After();
}

int dequeue()
{
	printFandR_Before();
	//check for empty..;
	if(f==-1)
	{
		printf("Queue is empty\n");
		return -1;
	}
	
	int tmp = arr[f];  //we have data in queue.. but not sure 1 or many...
	
	if(f==r)  //ooooohhhhh  this was the only element in queue...
	{
		f=r=-1;
		return tmp;
	}
	else	//Make sure f point to next element of queue...
		f=++f%SIZE;
	
	printFandR_After();	
}

void print_queue()
{	
	//check for empty..
	//printFandR_Before();
	if(f==-1)
	{
		printf("Queue is empty\n");
		return;
	}
	
	int i=f;
	
	for(;1;)
	{
		printf("%d, ", arr[i]);
		if(i==r)
		{
			break;
		}
		else
		{
			if(i==SIZE-1)
				i=0;
			else
				i++;
		}
	}
	printf("\n");
}

int main(int argc, char *argv[]) 
{
	enqueue(10);
	enqueue(20);
	enqueue(30);
	enqueue(40);
	enqueue(50);
	
	dequeue();
	dequeue();
	dequeue();
	dequeue();
	enqueue(60);
	
	//dequeue();
	//enqueue(70);
	//enqueue(80);
	
	print_queue();
	return 0;
}







