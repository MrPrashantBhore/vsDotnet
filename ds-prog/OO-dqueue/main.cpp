#include <iostream>
using namespace std;

#include "DQueue.h"

int main(int argc, char** argv) 
{
	try{
		
		DQueue q;
		q.enqueue_f(10);
		q.enqueue_r(20);
		q.enqueue_f(30);
		q.enqueue_r(40);
		q.dequeue_f();
		q.dequeue_r();
		q.dequeue_r();
		q.enqueue_r(50);
		q.show();
		
	}
	catch(int x)
	{
		if(x==1)
		{
			cout<<"Queue Overflow"<<endl;
		}
		else if(x==2)
		{
			cout<<"Queue Underflow"<<endl;
		}

		else if(x==3)
		{
			cout<<"DQueue is empty.."<<endl;
		}		
		else
		{
			cout<<"Something got wrong.."<<endl;
		}
	}
}


