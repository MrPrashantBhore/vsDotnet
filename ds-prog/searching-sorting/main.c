
#include<stdio.h>
#include<stdlib.h>



int binarySearch(int *ptr, int searchValue, int size)
{
	int l=0;
	int h=size-1;
	
	while(h >= l)
	{

#ifdef DEBUG
		printf("l=%d, h=%d\n", l,h);
		system("pause");
#endif
		int m = (int)((l + h)/2);
		
		if(searchValue == ptr[m])
			return m+1;
		else if (searchValue < ptr[m])
		{
			h=m-1;
		}
		else
		{
			l=m+1;			
		}
	}
	return -1;
	
}


int normalSearch(int *ptr, int searchValue, int size)
{
	int i=0;
	int j=0;
	for(i;i<size;i++)
		if(ptr[i] == searchValue) 
			return i+1;	
		
	return -1;	
}

void swap(int *a, int *b)
{
	int tmp=*a;
	*a=*b;
	*b=tmp;	
}

void selectionSort(int *ptr, int size)
{
	int i=0, pos=0;
	
	for(pos=0;pos<size;pos++)
	{
		for(i=pos;i<size;i++)
		{
			if(ptr[pos] > ptr[i])
				swap(&ptr[pos], &ptr[i]);
		}
	}
}

void insertionSort(int *arr, int size)
{
	int i=1; 
	
	for(i=1;i<size;i++)
	{
		int j=i-1;
		while(j>=0 && arr[i] < arr[j]) j--;
		
		j=j+1;
		
		int ii=i;
		while(ii>j)
		{
			swap(&arr[ii-1], &arr[ii]);
			ii--;
		}
	}
}

void bubbleSort(int *arr, int size)
{
	int i,j;
	for(i=0;i<size-1;i++)
	{
		for(j=0;j<size-1;j++)
		{
			if(arr[j] > arr[j+1])
				swap(&arr[j], &arr[j+1]);
		}
	}
}

void part(int *arr, int l, int h)
{
	int c=l;
	int i=l;
	int p=h;
	
	while(c<p)
	{
		if(arr[c] < arr[p])
		{
			swap(&arr[c], &arr[i]);
			i++;
		}
		c++;
	}
	
	swap(&arr[i], &arr[p]);
	
	return i;
}

void quickSort(int *arr, int l, int h)
{
	if(l<h)
	{
		int index = part(arr, l, h);
		quickSort(arr,l,index-1);
		quickSort(arr,index+1,h);
	}
}

void printArray(int *ptr, int size)
{
	int i=0;
	for(i=0;i<size;i++)
		printf("%d, ", ptr[i]);
	
	printf("\n");
}

int main()
{
	
	int arr [] = {2,4,10,67,3,7,-1,-4,20,16};
	int searchIndex = normalSearch(arr, -12, 10);
	printf("%d found at %d index.", -12, searchIndex);
	
	
	int arr [] = {-4,-1,2,3,4,7,10,16,20,67};
	int searchIndex = binarySearch(arr, 20, 10);
	printf("%d found at %d index.", 20, searchIndex);
	
	
	
	int arr [] = {-2,0,10,67,30,-7,-11,-4,20,16};
	printArray(arr, 10);
	selectionSort(arr, 10);
	insertionSort(arr, 10);
	bubbleSort(arr, 10);
	quickSort(arr, 0, 9);
	printArray(arr, 10);
		
}






