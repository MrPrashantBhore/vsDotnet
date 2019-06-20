
#include <iostream>
#include "DLinkedList.h"

int main(int argc, char** argv) 
{
	{
		try
		{
			DLinkedList l1;
			l1.append(10);
			l1.append(20);
			l1.append(30);
			l1.append(40);
						
			cout<<l1<<endl;
			
			l1.deleteLast();
			cout<<l1<<endl;
			l1.deleteLast();
			cout<<l1<<endl;
			l1.deleteLast();
			l1.append(10);			
			cout<<l1<<endl;
			l1.deleteLast();
			cout<<l1<<endl;		
			l1.append(10);
			l1.append(20);
			l1.append(30);
			l1.append(40);
			cout<<l1<<endl;
			
			DLinkedList l2=l1;
			cout<<l2<<endl;
			
			l2.reverse();
			cout<<l2<<endl;
			
			l1=l2;
			cout<<l1<<endl;
			
			l1.deleteByPos(3);
			cout<<l1<<endl;
			cout<<"hi..."<<endl;
			l1.reverse();
			cout<<l1<<endl;
			
		}
		catch(char *str)
		{
			cout<<"ERROR: "<<str<<endl;
			delete [] str;
		}
		
	}			
	cout<<"Bye"<<endl;
}

