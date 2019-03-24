//Dubstep
//"WUB" is inserted before the first word of the song
//restore the song
//It is a valuable problem!!!!!!!!

public class Dubstep {
  public static String SongDecoder (String song)
  {
      song = (song.replace("WUB", " ")).trim();
      song = song.replaceAll("\\s+", " ");
     return song;
   }

   public static void main(String[] args){
   		Dubstep test = new Dubstep();
   		String r = "";
   		r = test.SongDecoder("RWUBWUBWUBLWUB");
   		System.out.println(r);
   }
}