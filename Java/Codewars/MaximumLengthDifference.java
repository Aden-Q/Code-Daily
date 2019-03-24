//Given two arrays a1 and a2 of strings
//Each string is composed of letters from a to z. 

class MaxDiffLength {
    
    public static int mxdiflg(String[] a1, String[] a2) {
        // Find max and min and compare abs(max) with abs(min), then done
        int maxs1 = 0, maxs2 = 0;
        int mins1 = 10000, mins2 = 10000;
        int maxabs = 0;

        if(a1.length == 0 || a2.length == 0)
        	return -1;

        for(String s:a1){
        	if(s.length()>maxs1)
       			maxs1 = s.length();
       		if(s.length()<mins1)
       			mins1 = s.length();
        }

        for(String s:a2){
        	if(s.length()>maxs2)
       			maxs2 = s.length();
       		if(s.length()<mins2)
       			mins2 = s.length();
        }

        int d1 = Math.abs(maxs1 - mins2);
        int d2 = Math.abs(mins1 - maxs2);
        maxabs = (d1 < d2) ? d2 : d1;
        return maxabs;
    }
}