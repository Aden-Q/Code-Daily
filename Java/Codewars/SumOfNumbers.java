//Sum of numbers from 0 to N
//Print the calculation string
//这个题有点蠢，0=0的输出里面等号两边不允许有多余空格，但是其他的=两边是有空格的，直接导致条件控制多了一个分支

public class SequenceSum{

  public static String showSequence(int value){
    //for
    //  while
    String rs = "";
    int result = 0;
    if(value < 0)
    	return "" + value + "<0";
    else{
	    for(int i = 0; i <= value; i++){
	    	result += i;
	    	if(i < value)
	    		rs = rs + i + "+";
	    	else if(i != 0)
	    		rs = rs + i + " = " + result;
	    	else
	    		rs = rs + i + "=" + result;
	    }
	}
    return rs;
  }

  /*public static void main(String args[]){
    int param=Integer.ParseInt(args[0]);
    SequenceSum.showSequence(param);
  }*/
}