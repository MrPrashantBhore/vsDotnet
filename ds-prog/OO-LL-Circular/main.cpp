
#include <iostream>
#include "CLinkedList.h"

int main(int argc, char** argv) 
{
	{
		CLinkedList l1;
		l1.append(10);
		l1.insert(20);
		l1.deleteFirst();
		l1.append(40);
		l1.deleteLast();
		
		cout<<l1<<endl;		
		
		CLinkedList l2;
		l2=l1;
		cout<<l2<<endl;		
	}			
	cout<<"Bye"<<endl;
}

