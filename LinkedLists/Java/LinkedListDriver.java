
public class LinkedListDriver {
	
	public static void main (String args[]){
		SinglyLinkedList<Integer> tmp = new SinglyLinkedList<Integer>();
		tmp.addFirst(10);
		tmp.addLast(15);
		tmp.addLast(25);
		tmp.addFirst(5);
		tmp.remove(7);
		
		System.out.println("Singly Linked List:     " + tmp.toString());
		
		DoublyLinkedList<Integer> tmp2 = new DoublyLinkedList<Integer>();
		tmp2.addFirst(100);
		tmp2.addLast(150);
		tmp2.addLast(175);
		tmp2.addFirst(140);
		tmp2.remove(39);
		
		System.out.println("Doubly Linked List:     " + tmp2.toString());
		
		CircularlyLinkedList<Integer> tmp3 = new CircularlyLinkedList<Integer>();
		tmp3.addFirst(200);
		tmp3.addFirst(210);
		tmp3.addLast(215);
		tmp3.addLast(220);
		
		tmp3.removeFirst();
		tmp3.remove(200);
		tmp3.addLast(255);
		tmp3.addFirst(230);
		
		System.out.println("Circularly Linked List: " + tmp3.toString());
	}

}
