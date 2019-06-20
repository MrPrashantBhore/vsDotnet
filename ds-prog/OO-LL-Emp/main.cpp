
#include <iostream>
#include "LinkedList.h"

int main(int argc, char** argv) 
{
	{
		LinkedList l1;
		l1.append("Shayam", 10);
		l1.append("Gopal", 20);
		l1.insert("Rahul",30);
		cout<<l1<<endl;				
		cout<<l1.getIDByName("Gopal")<<endl;
		cout<<l1.getNameByID(20)<<endl;
	}
	cout<<"Bye"<<endl;
}

