import java.util.*;

public class HashExample{
    public static void main(String[] args){

	HashMap<Integer,String> map = new HashMap<Integer,String>();

	map.put(1,"one");
	map.put(2,"two");
	map.put(3,"three");
	map.put(4,"four");	

	System.out.println(map.get(1));
	System.out.println(map.get(2));
	System.out.println(map.get(3));
	System.out.println(map.get(4));	
    } 
}
