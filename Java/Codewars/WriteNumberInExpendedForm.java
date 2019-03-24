// Write Number in Expended Form
// Given a number and return its expended form
// 大概就是给一个数，然后返回几个10进制数相加形式的字符串


public class Kata
{
    public static String expandedForm(int num)
    {
        //your code here
        int temp = num;
        int numdigits = 0;
        // in case 0 input occurs
        do{
            temp /= 10;
            numdigits++;
        }while(temp!=0);
        
        String res = "";
        temp = num;
        int r;
        int s;
        while(temp!=0){
            numdigits--;
            s = temp / (int)Math.pow(10, numdigits); // 9
            if(s == 0)
                continue;
            if(!res.equals(""))  // handle the beginning plus sign
                res += " + ";
            res += s * (int)Math.pow(10, numdigits); //900
            temp = temp % (int)Math.pow(10, numdigits); // 99
        }
        // System.out.println(numdigits);
        return res;
    }
    public static void main(String[] args){
        String res = "";
        Kata test = new Kata();
        res = test.expandedForm(70304);
        System.out.println(res);
    }
}