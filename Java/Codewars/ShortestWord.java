//return the length of shortest word in a string
public class Kata {
    public static int findShort(String s) {
        int length = 100 ;
        String[] words = s.split(" ");
        for(String c:words){
          if(c.length()<length)
            length = c.length();
        }
        return length;
    }
}
