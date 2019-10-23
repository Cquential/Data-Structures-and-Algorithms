#include <stdio.h>
#include <stdlib.h>

int max(int a[],int n);
void countsort(int a[],int n);

int main()
{
  int i,n,a[32];
  printf("Enter no. elements =");
  scanf("%d",&n);
  for (i = 0;i < n;i++) {
    printf("Enter %dth element =",i+1);
    scanf("%d",&a[i]);
  }
  countsort(a,n);
  printf("Sorted Array:\n");
  for (i = 0;i < n;i++) {
    printf("%d ",a[i]);
  }
  printf("\n");
}

int max(int a[],int n)
{
  int i,max;
  max = a[0];
  for (i = 0;i < n;i++) {
    if (a[i] >= max) {
      max = a[i];
    }
  }
  return max;
}

int min(int a[],int n)
{
  int i,min;
  min = a[0];
  for (i = 0;i < n;i++) {
    if (a[i] <= min) {
      min = a[i];
    }
  }
  return min;
}

void countsort(int a[],int n)
{
  int i,Max,Min,j = 0;
  Max = max(a,n);
  Min = min(a,n);
  int b[Max];
  for (i = 0;i <= Max;i++) {
    b[i] = 0;
  }
  for (i = 0;i < n;i++) {
    b[a[i]] = 1;
  }
  for (i = Min;i <= Max;i++) {
    if (b[i] == 1) {
      a[j] = i;
      j++;
    }
  }
}
