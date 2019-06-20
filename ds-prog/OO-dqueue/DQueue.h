#include <iostream>
using namespace std;

#define SIZE 5

class DQueue
{
	int arr[SIZE] ;
	int f;
	int r;	
	
public:
	DQueue();
	~DQueue();
	void enqueue_f(int data);
	void enqueue_r(int data);
	int dequeue_r();
	int dequeue_f();
	void show();	
};

