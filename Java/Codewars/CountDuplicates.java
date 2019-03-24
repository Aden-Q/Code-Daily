//Cout the number of Duplications

public class CountingDuplicates {
  public static int duplicateCount(String text) {
  	int count = 0;
  	text = text.toLowerCase();		//preprocess
  	while(text.length() > 0){
  		String c = text.substring(0, 1);
  		text = text.substring(1);		//strip
  		if(text.indexOf(c) != -1)
  			count++;
  		text = text.replace(c, "");		//equal to remove

  	}
  	return count;
  }
}