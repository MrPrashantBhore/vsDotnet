#include <iostream>
using namespace std;

#include "Queue.h"

int main(int argc, char** argv) 
{
	ABC a(1);
	ABC b(2);
	ABC c(3);
	ABC d(4);
	ABC e(5);
	ABC f(6);
	
	Queue<ABC> q(5);
	try{
		q.insert(a);
		q.insert(b);
		q.insert(c);
		q.insert(d);
		q.insert(e);
		q.insert(f);
		
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
		else
		{
			cout<<"Something got wrong.."<<endl;
		}
	}
}


