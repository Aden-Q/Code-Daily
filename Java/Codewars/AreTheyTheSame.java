//Are they the "same"?
//Given two arrays a and b, write a function comp(a,b) that checks whether the two arrays have the "same" elements in view of squared number, regardless order.
//这个题有点迷，这份两个点不能pass掉，但真的是看不出有啥漏洞，该检查都检查过了，还是不pass。两个点一个error，一个test failed

import java.util.Arrays;

public class AreSame {
	
	public static boolean comp(int[] a, int[] b) {
		boolean isin = true;
	    Arrays.sort(a);   //sort before binary search
	    Arrays.sort(b);   //sort before binary search
	
	if(a == null && b == null)
		return true;
    if(a.length != b.length)
      	return false;

    for(int i = 0; i < a.length; i++){
      	if(b[i] != a[i] * a[i]){
        	isin = false;
        	break;
      	}
    }

    return isin;
  }

  public static void main(String[] args){
  	//AreSame test = new AreSame();
  	boolean r;
  	int[] a = new int[]{121, 144, 19, 161, 19, 144, 19, 11};
  	int[] b = new int[]{121, 14641, 20736, 361, 25921, 361, 20736, 361};
  	//r = test.comp(a, b);
  	//System.out.println(r);
    for(int test:a)
    	System.out.println(test);
    Arrays.sort(a);
    System.out.println();
    for(int test:a)
      	System.out.println(test);
  	}
}
