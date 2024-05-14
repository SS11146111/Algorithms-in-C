/*sorting program-done by -:Sangita Saha,B16CS011*/
#include<stdio.h>
#include<conio.h>
void printarray(int arr[],int size)   /*function to print the array elements*/
{
  int i,j;
  for(i=0;i<size;i++)
  printf("[%d]",arr[i]);
  printf("\n");
}

void swap(int *a,int *b)           /*function to swap two integer values*/
{
  int t;
  t=*a;
  *a=*b;
  *b=t;
}

/* start of merge sort*/
void merge(int arr[],int l,int m,int r)     /*function to merge the sublists in merge sort*/
{
  int i,j,k,l1[100],r1[100];
  int n1=m-l+1;
  int n2=r-m;
  for(i=0;i<n1;i++)
  l1[i]=arr[l+i];
  for(j=0;j<n2;j++)
  r1[j]=arr[m+1+j];
  i=0;
  j=0;
  k=l;
  while(i<n1&&j<n2)
  {
   if(l1[i]<=r1[j])
    {
      arr[k]=l1[i];
      i++;
    }
   else
    {
      arr[k]=r1[j];
      j++;
    }
   k++;
  }
  while(i<n1)
  {
   arr[k]=l1[i];
   i++;
   k++;
  }
  while(j<n2)
  {
   arr[k]=r1[j];
   j++;
   k++;
  }
}
void merge_sort(int arr[],int l,int r)      /*merge sort function*/
{
  if(l<r)
  {
    int m;
    m=(l+r)/2;
    merge_sort(arr,l,m);
    merge_sort(arr,m+1,r);
    merge(arr,l,m,r);
  }

}
/*end of merge sort*/

/*start of quick sort*/
int partition(int arr[],int low,int high)
{
  int j;
  int pivot=arr[high];
  int i=low-1;
  for(j=low;j<=high-1;j++)
  {
    if(arr[j]<=pivot)
    {
      i++;
      swap(&arr[i],&arr[j]);
    }
  }
  swap(&arr[i+1],&arr[high]);
  return (i+1);
}
void quick_sort(int arr[],int low,int high)
{
    if(low<high)
    {
      int pi=partition(arr,low,high);
      quick_sort(arr,low,pi-1);
      quick_sort(arr,pi+1,high);
    }
}
/*end of quick sort*/

/*start of heap sort*/
void maxheapify(int arr[],int i)
{
  int n,j,l,r,largest;
  n=arr[0];
  l=2*i;
  r=2*i+1;
  if(l<=n&&arr[l]>arr[i])
    largest=l;
  else
    largest=i;
  if(r<=n&&arr[r]>arr[largest])
    largest=r;
  if(largest!=i)
  {
    swap(&arr[i],&arr[largest]);
    maxheapify(arr,largest);
  }
}
void buildmaxheap(int arr[])
{
  int i,n;
  n=arr[0];
  for(i=n/2;i>=1;i--)
    maxheapify(arr,i);
}
void heapsort(int arr[])
{
  int i,n;
  buildmaxheap(arr);
  for(i=arr[0];i>=2;i--)
  {
    swap(&arr[1],&arr[i]);
    arr[0]=arr[0]-1;
    maxheapify(arr,1);
  }
}
/*end of heap sort*/

/*start of radix sort*/
void radixsort(int arr[],int n)
{
  int bucket[10][5],buck[10],b[10];
  int i,j,k,l,num,div,large,passes;
  div=1;
  num=0;
  large=arr[0];
  for(i=0;i<n;i++)
  {
    if(arr[i]>large)
    large=arr[i];
    while(large>0)
     {
       num++;
       large=large/10;
     }
    for(passes=0;passes<num;passes++)
     {
       for(k=0;k<10;k++)
	buck[k]=0;
       for(i=0;i<n;i++)
       {
	l=((arr[i]/div)%10);
	bucket[l][buck[l]++]=arr[i];
       }
       i=0;
       for(k=0;k<10;k++)
       {
	for(j=0;j<buck[k];j++)
	 arr[i++]=bucket[k][j];
       }
       div*=10;
     }
  }
}
/*end of radix sort*/


void main()
{
  clrscr();
  int arr[100],n,i,j,k=0,ch,c;
  do
  {
   printf("\nSORTING METHODS\n1)Merge Sort\n2)Quick sort\n3)Heap Sort\n4)Radix Sort\nEnter your choice\n");
   scanf("%d",&ch);
   switch(ch)
    {
      case 1: printf("Enter the number of elements in the array\n");
	      scanf("%d",&n);
	      printf("Enter the array elements\n");
	      for(i=0;i<n;i++)
	       scanf("%d",&arr[i]);
	      printf("Given array is\n");
	      printarray(arr,n);
	      merge_sort(arr,k,n-1);
	      printf("Sorted array using merge sort is:\n");
	      printarray(arr,n);
	      break;
     case 2:  printf("Enter the number of elements in the array\n");
	      scanf("%d",&n);
	      printf("Enter the array elements\n");
	      for(i=0;i<n;i++)
	       scanf("%d",&arr[i]);
	      printf("Given array is\n");
	      printarray(arr,n);
	      quick_sort(arr,k,n-1);
	      printf("Sorted array using quick sort is:\n");
	      printarray(arr,n);
	      break;
     case 3:  printf("Enter the number of elements in the array\n");
	      scanf("%d",&n);
	      printf("Enter the array elements\n");
	      for(i=1;i<=n;i++)
	       scanf("%d",&arr[i]);
	      printf("Given array is\n");
	      for(i=1;i<=n;i++)
	       printf("[%d]",arr[i]);
	       printf("\n");
	      arr[0]=n;
	      heapsort(arr);
	      printf("Sorted array using heap sort is:\n");
	      for(i=1;i<=n;i++)
	       printf("[%d]",arr[i]);
	       printf("\n");
	      break;
     case 4:  printf("Enter the number of elements in the array\n");
	      scanf("%d",&n);
	      printf("Enter the array elements\n");
	      for(i=0;i<n;i++)
	       scanf("%d",&arr[i]);
	      printf("Given array is\n");
	      printarray(arr,n);
	      radixsort(arr,n);
	      printf("Sorted array using radix sort is:\n");
	      printarray(arr,n);
	      break;
     default: printf("\nInvalid Choice\n");

    }

   printf("\nPress 1 to continue\n");
   scanf("%d",&c);

  }while(c==1);

}