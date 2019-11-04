#include<stdio.h>
#include<stdlib.h>
int *arr;
void bubbleSort(int *arr,int n)
{
	int i=0,j=0,t=0;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				t=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=t;
			}
		}
	}
}
void selectionSort(int *arr,int n)
{
	int i=0,j=0,l=-9999,pos=0;
	for(i=0;i<n;i++)
	{
		l=-9999;
		for(j=0;j<n-i;j++)
		{
			if(l<arr[j])
			{
				l=arr[j];
				pos=j;
			}
		}
		arr[pos]=arr[n-i-1];
		arr[n-i-1]=l;	
	}
}
void insertionSort(int *arr,int n)
{
	int i=0,j=0,key;
	for(i=1;i<n;i++)
	{
		key=arr[i];
		j=i-1;
		while(j>=0 && key<arr[j])
		{
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=key;
	}
}

void main()
{
	int n,i,ch;
	printf("Enter the size of the ARRAY :");
	scanf("%d",&n);
	arr=(int *)malloc(n*sizeof(int));
	printf("Enter Elements\n");
	for(i=0;i<n;i++)
	{
		printf("Enter a number :");
		scanf("%d",&arr[i]);
	}
	for(i=0;i<n;i++)
		printf("%d\t",arr[i]);
	printf("\n");
	printf("Choices\n1. Bubble Sort\n2. Selection Sort\n3. Insertion Sort\n4. Enter any other number to exit\nEnter Choice :");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:bubbleSort(arr,n);
			break;
		case 2:selectionSort(arr,n);
			break;
		case 3:insertionSort(arr,n);;
			break;
		default:printf("Thank You for using the program.....");
	}
	printf("\nAfter Sorting..........   ");
	for(i=0;i<n;i++)
		printf("%d\t",arr[i]);
	printf("\n");
}
