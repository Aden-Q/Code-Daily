// Simpson's Rule-Approximate Integration
// 这道题虽然测试样例看起来需要保留到小数点后几位，但是我不做trunc试了一下也
// AC了，就懒得再做trunc了
// 思路反正也就那样，唯一做的就是封装了一个函数，让代码看起来简洁了很多呀



public class SimpsonIntegration {

    public static double simpson(int n) {
        // your code
        double appvalue = 0;
        int i;
        double h = (Math.PI-0)/n;
        for(i=1;i<n/2;i++)
            appvalue += 4 * func(0+(2*i-1)*h) + 2 * func(0+2*i*h);
        appvalue += 4 * func(0 + (2*i-1)*h);
        return (appvalue+func(0)+func(Math.PI)) * (Math.PI-0)/(3*n);
    }

    public static double func(double x){
        double fvalue = 3*Math.pow(Math.sin(x),3)/2;
        return fvalue;
    }

    public static void main(String[] args){
        SimpsonIntegration test = new SimpsonIntegration();
        double rvalue;
        rvalue = test.simpson(290);
        System.out.println(rvalue);
    }
}
