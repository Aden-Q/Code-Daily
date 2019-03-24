//Number of People in the Bus
//Given an arraylist, within which each element is an int array(the first element represents people gets on and the secend for people get off)
//Calculate the final number of People still in Bus

import java.util.ArrayList;

class Metro {

  public static int countPassengers(ArrayList<int[]> stops) {
  //Code here!
    int sum = 0;

    for(int[] o:stops)
        sum = sum + o[0] - o[1];

    return sum;
  }
}