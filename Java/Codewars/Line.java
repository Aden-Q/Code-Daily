// Vasya - Clerk
// New Avengers movie has just been released. A lot of people standing in
// a huge line. Each has a single 100, 50, 25 dollars bill. One ticket cost
// 25 dollars. 
// 思路：记下收了几张25，几张50，几张100，来了50的那么用25的抵，来了100的优先
// 考虑用50的抵，然后再用25的抵，如果可以给出charge，那么success，否则fail
// 其实这里可以不用记录100的张数，因为不需要用100来找零钱，但为了规范，还是
// 记进去了

public class Line {
  public static String Tickets(int[] peopleInLine)
  {
        //Your code is here...
        int[] bill_count = new int[] {0,0,0};
        int j;
        for(int i = 0;i<peopleInLine.length;i++){
            //System.out.println(bill_count[i]);
            switch(peopleInLine[i]){
                case 25:
                    bill_count[0]++;
                    break;
                case 50:
                    bill_count[1]++;
                    bill_count[0]--;
                    break;
                case 100:
                    bill_count[2]++;
                    // if there are 50 dollars bill left
                    if(bill_count[1]>0){
                        bill_count[1]--;
                        bill_count[0]--;
                    }
                    // if there are no 50 dollars bill left
                    else
                        bill_count[0]-=3;
                    break;
                default:
                    break;
            }
            // check bills
            for(j=0;j<3;j++)
                if(bill_count[j]<0)
                    return "NO";
        }
        return "YES";
  }
  public static void main(String[] args){
    Line test = new Line();
    //String rstring = test.Tickets(new int[] {25, 25, 50});
    String rstring = test.Tickets(new int []{25, 100});
    System.out.println(rstring);
  }
}


