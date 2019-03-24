// Approximate Pi with a fer decimals
// Calculate how many iterations are needed to approximate Pi
// Using epsilon of language to measure precision


public class PiApprox {

	public static String iterPi2String(Double epsilon) {
		 // your code
         String rstring = "";
         double appvalue = 0;
         int i = 0;
         for(i =0;;i++){
             appvalue += 1.0/(2*i+1)*Math.pow(-1,i);
             //System.out.println(Math.abs(4 * appvalue - Math.PI));
             if(Math.abs(4 * appvalue - Math.PI) < epsilon)
                 break;
         }
         rstring += "[" + (i+1) + ", " + String.format("%.10f",4 * appvalue) + "]";
         return rstring;
	}

    public static void main(String[] args){
        //double rv;
        //rv = Math.PI;
        PiApprox test = new PiApprox();
        String res = test.iterPi2String(0.1);
        System.out.println(res);
    }
}
