//Error rate print funciton, define a character not in range 'a' to 'm' to be a error character. The function return
//the error rate of a specified string. Not Simplified.

import java.util.*;

public class Printer {
    
    public static String printerError(String s) {
        int errorcount = 0;
	      for(int i = 0; i < s.length(); i++){
		    if(!(s.charAt(i)>='a' && s.charAt(i)<='m'))
			      errorcount++;
	      }
	      return "" + errorcount + "/" +s.length();
    }
}