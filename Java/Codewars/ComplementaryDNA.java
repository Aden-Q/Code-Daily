//Complementary DNA
//In DNA strings, symbols "A" and "T" are complements of each other,
//as "C" and "G".

public class DnaStrand {
  public static String makeComplement(String dna) {
    String rstring = "";    //store the result
    char c;
    for(int i = 0; i <dna.length();i++){
      c = dna.charAt(i);
      switch(c){
        case 'A':
          rstring += 'T';
          break;
        case 'T':
          rstring += 'A';
          break;
        case 'C':
          rstring += 'G';
          break;
        case 'G':
          rstring += 'C';
          break;
      }
    }
    return rstring;
  }
}