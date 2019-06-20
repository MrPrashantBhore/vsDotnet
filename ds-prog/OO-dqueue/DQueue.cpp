#include <iostream>
using namespace std;

#include "DQueue.h"

DQueue::DQueue()
{
	f=r=-1;
}

DQueue::~DQueue()
{	
	f=r=-1;
}

void DQueue::enqueue_r(int data) 
{
	//Full....
	if(f==0 && r==SIZE-1)
		throw 1;
	
	if(f==-1)
	{
		f=r=0;
	}
	else if(r!=SIZE-1)
	{
		r++;
	}
	else
	{
		//shift all data towards r...
		f--;
		int i=f;
		while(i!=r)
		{
			arr[i] = arr[i+1];
			i++;
		}
	}
	arr[r] = data;
}
void DQueue::enqueue_f(int data) 
{
	//Full....
	if(f==0 && r==SIZE-1)
		throw 1;
	
	if(f==-1)
	{
		f=r=0;
	}	
	else if(f!=0)
	{
		f--;
	}
	else
	{
		//shift all data towards r...
		r++;
		int i=r;
		while(i!=f)
		{
			arr[i] = arr[i-1];
			i--;
		}
	}
	arr[f] = data;
}

int DQueue::dequeue_r()
{
	if(f==-1)
		throw 2;
	
	int tmp=arr[r];
	
	if(f==r)
		f=r=-1;
	else
		r--;
	
	return tmp;
}

int DQueue::dequeue_f()
{
	if(f==-1)
		throw 2;
	
	int tmp=arr[f];
	
	if(f==r)
		f=r=-1;
	else
		f++;
		
	return tmp;
}

void DQueue::show()
{
	if(f==-1)
		throw 3;
	
	int i=f-1;
	do
	{
		i++;
		cout<<arr[i]<<", ";			
	}while(i!=r);
	
	cout<<endl;
}
	
