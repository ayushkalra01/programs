/*
 * Selection_sort runtime analysis
 *
 * Ayush Kalra 1910990093
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

/*
* Function to generate Input
* type 1-> Random Numbers
* type 2-> Sorted Numbers (Ascending Order)
* type 3-> Sorted Numbers (Descending Order)
*/

void inputType(int a[], int n, int type)
{

   if (type == 1)
   {
      for (int i = 0; i < n; i++)
      {
         a[i] = rand()%(n*n);
      }
   }

   else if (type == 2)
   {
      for (int i = 1; i <= n; i++)
      {
         a[i-1] = i;
      }
   }

   else if (type == 3)
   {

      for (int i = n; i >= 1; i--)
      {
         a[i-1] = n*n-i;
      }
   }
}


void selectionSort(int *a, int n) {
    
    for(int i=0;i<n;i++) {
        
        int index=i;
        
        for(int j=i+1;j<n;j++) {
            if(a[j]<a[index]) {
                index=j;
            }
        }
        
        if(index!=i) {
            int temp = a[index];
            a[index] = a[i];
            a[i]=temp;
        }
        
    }
    
}

int main() {
    
    int type;
    
    scanf("%d", &type);
    
    int n;
    scanf("%d", &n);
    
    int a[n];
    
    inputType(a,n,type);
    
    struct timeval t;

    gettimeofday(&t, NULL);

    long long int startTime = t.tv_sec * 1000 + t.tv_usec / 1000;

    selectionSort(a, n);

    gettimeofday(&t, NULL);

    long long endTime = t.tv_sec * 1000 + t.tv_usec / 1000;

    printf("Time Taken: ");

    printf("%lld",endTime - startTime);

    
    return 0;
}
