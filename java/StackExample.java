import java.util.*;

public class StackExample{
    public static void main(String[] args){

	Stack<Integer> stack = new Stack<Integer>();

	stack.push(1);
	stack.push(2);
	stack.push(3);	
	stack.push(4);

	System.out.println(stack.pop());
	System.out.println(stack.pop());
	System.out.println(stack.pop());
	System.out.println(stack.pop());

	Stack<Boolean> stackbool = new Stack<Boolean>();

	stackbool.push(true);
	stackbool.push(false);
	stackbool.push(5 == 5);	
	stackbool.push(3 != 3);

	System.out.println(stackbool.pop());
	System.out.println(stackbool.pop());
	System.out.println(stackbool.pop());
	System.out.println(stackbool.pop());	

    }
}
