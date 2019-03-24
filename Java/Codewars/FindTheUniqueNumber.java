// Find the unique number
// target: to find the unique number in an array of double numbers
// 好吧我承认三次判断的方法很垃圾，可能二刷的时候会有别的灵感出现
 
 public class Kata {
    public static double findUniq(double arr[]) {
      // Do the magic
      double[] unique =  new double[3];		//at least 3 elemnets taken to compare
      for(int i=0; i+2<arr.length; i++){
      	unique[0] = arr[i];
      	unique[1] = arr[i+1];
      	unique[2] = arr[i+2];
      	double temp = unique[0];
      	if(temp == unique[1] && temp != unique[2]){
      		arr[0] = unique[2];
      		break;
      	}
      	else if (temp == unique[2] && temp !=unique[1]){
      		arr[0] = unique[1];
      		break;
      	}
      	else if (temp != unique[1] && temp != unique[2]){
      		arr[0] = temp;
      		break;
      	}
      	else
      		continue;
      }
      return arr[0];
    }
}