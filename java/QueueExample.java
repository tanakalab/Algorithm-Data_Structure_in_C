import java.util.*;

public class QueueExample{
    public static void main(String[] args){

	Queue<Integer> queue = new ArrayDeque<Integer>();

	queue.add(1);
	queue.add(2);
	queue.add(3);	
	queue.add(4);

	System.out.println(queue.poll());
	System.out.println(queue.poll());
	System.out.println(queue.poll());
	System.out.println(queue.poll());

	ArrayDeque<Boolean> queuebool = new ArrayDeque<Boolean>();

	queuebool.push(true);
	queuebool.push(false);
	queuebool.push(5 == 5);	
	queuebool.push(3 != 3);

	System.out.println(queuebool.pop());
	System.out.println(queuebool.pop());
	System.out.println(queuebool.pop());
	System.out.println(queuebool.pop());	

    }
}
