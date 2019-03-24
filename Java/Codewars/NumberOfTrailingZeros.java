//Calculate the number of trailing zeros in a factorial of a given number

public class Solution {
  public static int zeros(int n) {
      // your beatiful code here
      int count5 = 0;
      while(n > 4){
        n = n/5;
        count5 += n;
      }

      return count5;
  }

  public static void main(String[] args){
  	Solution s = new Solution();
  	System.out.println(s.zeros(6));
  }
}