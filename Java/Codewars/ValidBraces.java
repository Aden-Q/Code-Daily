//Take a string of braces, deterines if the order of the braces if valid


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
                else
                    BC.push(c);
                break;
            case ']':
                if(BC.peek() == '[')
                    BC.pop();
                else
                    BC.push(c);
                break;
            case '}':
                if(BC.peek() == '{')
                    BC.pop();
                else
                    BC.push(c);
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
}