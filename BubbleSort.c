/*

Run Time analysis of bubble sort for differnt cases

Ayush Kalra
1910990093

*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

// type 1-> Random
//  type 2-> Sorted(Ascending)
//  type 3-> Sorted(Descending)

void inputType(int *a, int n, int type)
{

   if (type == 1)
   {
      for (int i = 0; i < n; i++)
      {
         a[i] = rand() % n + 1;
      }
   }

   else if (type == 2)
   {
      for (int i = 1; i <= n; i++)
      {
         a[i] = i;
      }
   }

   else if (type == 3)
   {
      for (int i = n; i >= 1; i--)
      {
         a[i - 1] = i;
      }
   }
}

void bubbleSort(int *a, int n) {
    int swap=0;
    
    for(int i = 0; i < n-1; i++) {
        swap=0;
        
        for(int j=0; j < n-i-1; j++) {
            
            if(a[j] > a[j + 1]) {
                
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
                
                swap=1;
            }
        }
        
        if(swap==0) {
            break;
        }
    }
}

int main(void)
{

   int n, type;
   printf("Enter size:");
   scanf("%d", &n);

   printf("Select Type:");
   scanf("%d", &type);

   int a[n];

   inputType(a, n, type);
   
     struct timeval t;
    
    gettimeofday(&t, NULL);
    
    long long int startTime = t.tv_sec * 1000 + t.tv_usec / 1000;
    
    bubbleSort(a, n);
    
    gettimeofday(&t, NULL);
    
    long long endTime = t.tv_sec * 1000 + t.tv_usec / 1000;
    
    printf("Time Taken: ");
    
    printf("%lld",endTime - startTime);

}
