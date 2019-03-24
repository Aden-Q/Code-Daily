//检测由括号组成的字符串是否具有闭格式，即括号对应封闭且完备，允许使用的括号为"{}, [], ()"

import java.util.Stack;


public class BraceChecker {

  public boolean isValid(String braces) {
    // Add code here
    Stack<Character> BC = new Stack<Character>();
    char c = '0';
    boolean flag = false;
    for(int i = 0; i< braces.length();i++){
        c = braces.charAt(i);
            //如果栈顶元素是和当前字符串匹配的，则pop出栈，否则压入栈中
        if(BC.empty()) {
        	BC.push(c);
        	continue;
        }
        switch(c){
            case ')':
                if(BC.peek() == '(')
                    BC.pop();
                break;
            case ']':
                if(BC.peek() == '[')
                    BC.pop();
                break;
            case '}':
                if(BC.peek() == '{')
                    BC.pop();
                break;
            default:
                BC.push(c);
        }
    }

    if(BC.empty())
        flag = true;
    else
        flag = false;

    return flag;
  }
  
  public static void main(String[] args) {
	  BraceChecker test = new BraceChecker();
	  System.out.println(test.isValid("[(])"));
  }
}