/*
 * program to compute square root of a number
 *
 * Ayush, 1910990093, 22/7/2001
 *
 * Assignment 1
*/

#include <stdio.h>

float squareRoot(float,int);

int main(){

  float number = 0;
  int precision = 0;

  printf("Enter a number :");
  scanf("%f",&number);
  printf("Enter precision :");
  scanf("%d",&precision);

  float result = squareRoot(number,precision);
  printf("%.*lf",precision,result);
	
  return 0;
}

//function to compute sqroot of a number

float squareRoot(float number,int precision)
{
  //variables
  float start=0, end, ans, mid, increment;
  increment = 0.1;
  end= number/2;

  // integer part
 while(start<=end)
 {
   mid = (start+end)/2;
   if(mid*mid == number)
   {
    ans = mid;
    break;
   }
   else if(mid*mid < number)
   {
    start = mid+1;
    ans = mid;
   }
   else
   {
    end = mid-1;
   }
 }

 // fractional part
   for(int i=0; i<precision ;i++)
   {
    while(ans*ans<=number)
    {
     ans += increment;
    }
    ans -= increment;
    increment = increment/10;
   }
return ans;
}
