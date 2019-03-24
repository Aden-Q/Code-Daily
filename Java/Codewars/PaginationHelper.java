// PaginationHelper
// For this exercise you will be strengthening your page-fu mastery. You will complete the PaginationHelper class, which is a utility class helpful for querying paging information related to an array.
//The class is designed to take in an array of values and an integer indicating how many items will be allowed per each page. The types of values contained within the collection/array are not relevant.

import java.util.List;
import java.util.*;

//TODO: complete this object/class

public class PaginationHelper<I> {

  /**
   * The constructor takes in an array of items and a integer indicating how many
   * items fit within a single page
   */
  int total_pages = 0;
  int itemsPerPage;
  ArrayList list = new ArrayList();
  public PaginationHelper(List<I> collection, int itemsPerPage) {
    this.itemsPerPage = itemsPerPage;
    int itemscount = -1;
    for(int i=0;i<collection.size();i++){
        list.add(collection.get(i));  //append element
        itemscount++;
        if(itemscount % itemsPerPage == 0)
            total_pages++;
    }
  }

  /**
   * returns the number of items within the entire collection
   */
  public int itemCount() {
    return list.size();
  }

  /**
   * returns the number of pages
   */
  public int pageCount() {
    return this.total_pages;
  }

  /**
   * returns the number of items on the current page. page_index is zero based.
   * this method should return -1 for pageIndex values that are out of range
   */
  public int pageItemCount(int pageIndex) {
    if(pageIndex >= total_pages || pageIndex < 0)
        return -1;
    else if(list.size() - (pageIndex+1) * itemsPerPage >= 0 )
        return itemsPerPage;
    else
        return list.size() - pageIndex * itemsPerPage;
  }

  /**
   * determines what page an item is on. Zero based indexes
   * this method should return -1 for itemIndex values that are out of range
   */
  public int pageIndex(int itemIndex) {
      if(itemIndex >= list.size() || itemIndex < 0)
         return -1;
      else
          return itemIndex / itemsPerPage;
  }

  public static void main(String[] args){
    PaginationHelper<Character> helper = new PaginationHelper(Arrays.asList('a', 'b', 'c', 'd', 'e', 'f'), 4);
    int test;
    //test = helper.itemCount(); //should == 6
    //test = helper.pageCount(); //should == 2
    //test = helper.pageItemCount(0); //should == 4
    //test = helper.pageItemCount(1); // last page - should == 2
    //test = helper.pageItemCount(2); // should == -1 since the page is invalid

    //return pageindex
    //test = helper.pageItemCount(2); // should == -1 since the page is invalid
    //test = helper.pageIndex(2); //should == 0
    //test = helper.pageIndex(20); //should == -1
    test = helper.pageIndex(-10); //should == -1

    System.out.println(test);
  }
}
