//Beginner Series #3 Sum of Numbers
//Given two integers a and b, which can be positive or negtive, find the sum of all the numbers between

public class Sum
{
   public int GetSum(int a, int b){
   	  int sum = 0;
   	  int begin = (a<b)?a:b;
   	  int end = (a<b)?b:a;
   	  for(int i = begin; i<=end; i++)
   	  	sum += i;
   	  return sum;
   }
}