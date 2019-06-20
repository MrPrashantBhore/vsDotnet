#include <iostream>
using namespace std;

template <typename T>
class Queue
{
	T *arr ;
	int f;
	int r;
	int size;
	
public:
	Queue(int size)
	{
		arr = new T[sizeof(T) * size];
		f=r=-1;
		this->size = size;
	}
	
	~Queue()
	{
		delete [] arr;
		f=r=-1;
	}
	
	void insert(T value) 
	{
		//first element? set f=r=0
		if(f==-1)
		{
			f=r=0;
			arr[r] = value;
		}		
		else if(r== (size-1))
		{
			throw 1;
		}
		else
		{
			r++;
			arr[r] = value;
		}
		
		//show();
	}
	
	T remove()
	{
		if(f==-1)
		{
			throw 2;		
		}
		
		T ret = arr[f];
		
		if(f==r)
			f=r=-1;
		else
			f++;
			
		return ret;
	}
	
	void show()
	{
		if(f==-1)
		{
			cout<<"Empty"<<endl;
		}
		else
		{
			int i=f;
			while(i<=r)
			{
				cout<<arr[i]<<", ";
				i++;
			}
		}
		cout<<endl;
	}
	
};


class ABC
{
	int i;
public:
	ABC()
	{
		i=0;
	}
	ABC(int x)
	{
		i=x;
	}	
	friend ostream& operator<<(ostream& out, ABC &x);
};

ostream& operator<<(ostream& out, ABC &x)
{
	out<<x.i;	
	return out;
}


