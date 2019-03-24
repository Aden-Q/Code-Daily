//Factorial
//Check input range to confirm n lie in 0 to 12

public class Factorial {

  public int factorial(int n) {
    // Happy coding :-)
    int fact = 1;

    if(n < 0 || n > 12)
    	throw new IllegalArgumentException();
    else{
    	for(int i = n; i > 0; i--)
    		fact *= i;
    }

    return fact;
  }
}