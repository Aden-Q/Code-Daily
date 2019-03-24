// Grill it!
// 基本任务是解码字符串，给一个十进制code，翻译成二级制，0的位表示丢弃，1的
// 位表示decode出来
// 做法思路明确，但我把接受到的message做了个倒序，主要是因为我转出的二进制是从
// 左往右的，用StringBuffer的逆序方法就很方便
// 好吧，我承认做法比较蠢，这样前面后面StringBuffer到String要转来转去的，还
// 不如一开始的时候直接把二进制逆序一下。。。


public class GrillIt {

    public static String grille(String message, int code) {
        // Your code here
        StringBuffer rmessage = new StringBuffer(message);
        rmessage.reverse();
        String bin = "";
        StringBuffer res = new StringBuffer("");
        int r;
        r = code;
        while(r!=0){
            bin += r % 2;
            r /= 2;
        }
        for(int i = 0; i < bin.length() && i < message.length(); i++){
            if(bin.charAt(i) == '1')
                res.append(rmessage.charAt(i));
        }
        res.reverse();
        return res.toString();  //转回String
    }
    
    public static void main(String[] args){
        String res = "";
        GrillIt test = new GrillIt();
        res = test.grille("abcdef", 5);
        System.out.println(res);
    }
}
