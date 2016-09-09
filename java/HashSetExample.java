import java.util.*;

public class HashSetExample{
    public static void main(String[] args){

	HashSet<String> set = new HashSet<String>();

	set.add("one");
	set.add("two");
	set.add("three");
	set.add("four");	

	System.out.println(set.contains("one"));
	System.out.println(set.contains("two"));
	System.out.println(set.contains("four"));
	System.out.println(set.contains("five"));	
    } 
}
