//Codewars上一个decode摩斯码的题，输入是摩斯码，格式为单个空格分割字符，三个空格分割单词，要求从给定的摩斯码解密出原字符串
//做法是先对输入string做trim预处理，去掉头尾空格，然后分两次split，分别解码每个词，最后连接起来返回就可以了，貌似是比较简单的做法了
//Codewars上有一个测试点就是给定输入头上有空串，所以我想到对输入做trim预处理

public class MorseCodeDecoder {
    public static String decode(String morseCode) {
        // your brilliant code here, remember that you can access the preloaded Morse code table through MorseCode.get(code)
        morseCode = morseCode.trim();
        String[] wordstring = morseCode.split("   ");	//three spaces
      	String[] charstring;
      	String destring = new String("");		//decoded string
      	for(String a:wordstring){
      		charstring = a.split(" ");		//extract single character
      		for(String c:charstring)
      			destring += MorseCode.get(c);    
      		destring += " ";
     		}
        return destring.trim();
    }
}