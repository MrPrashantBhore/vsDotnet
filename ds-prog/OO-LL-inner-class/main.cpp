
#include <iostream>
#include "LinkedList.h"

int main(int argc, char** argv) 
{

	{
		LinkedList::Node tmp;		
		LinkedList l1;
		l1.append(10);
		l1.append(20);
		l1.append(30);
		l1.append(40);
		
		cout<<l1<<endl;
		l1.reverse();				
		cout<<l1<<endl;
		l1.append(100);
		l1.insert(200);
		cout<<l1<<endl;
		l1.reverse();				
		cout<<l1<<endl;
		
	}			
	cout<<"Bye"<<endl;
}

