
public class DoublyLinkedList<Type> {
	private DLLNode<Type> head = null;
	private DLLNode<Type> end = null;
	private int size;
	
	/*
	 * Constructor methods
	 */
	public DoublyLinkedList(){ size = 0; }
	
	public DoublyLinkedList(Type data){
		DLLNode<Type> tmp = new DLLNode<Type>(data);
		this.head = tmp;
		this.end = tmp;
		size = 1;
	}
	
	/*
	 * Accessor methods
	 */
	public int getSize(){ return size;}
	public boolean isEmpty(){ return size == 0; }
	public Type first(){ return head.getData(); }
	public Type last(){ return end.getData(); }
	
	
	/*
	 * addFirst: Creates a new node and adds it to the front of
	 *     list.
	 */
	public void addFirst(Type data){
		head = new DLLNode<Type>(data, head, null); 
		if(isEmpty())
			end = head;
		else
			head.getNext().setPrev(head);
		size++;
	}
	
	/*
	 * addLast: Creates a new node and adds it to the end of
	 *     list.
	 */
	public void addLast(Type data){
		DLLNode<Type> tmp = new DLLNode<Type>(data, null, end);
		if (isEmpty()) head = tmp;
		end.setNext(tmp);
		end = tmp;
		size++;
	}
	
	/*
	 * removeFirst: Removes the first node and returns it.
	 */
	public void removeFirst(){
		head.getNext().setPrev(null);
		head = head.getNext();
		size--;
	}
	
	/*
	 * remove: Searches for and removes specified data node.
	 */
	public void remove(Type data){
		
		DLLNode<Type> tmp = search(data);
		if (head == tmp)
			removeFirst();
		else{
			if (tmp != null){
				tmp.getPrev().setNext(tmp.getNext());
				tmp.getNext().setPrev(tmp.getPrev());
				size--;
			}
		}
	}
	
	/*
	 * search: Private method that searches list for data.
	 */
	private DLLNode<Type> search(Type data){
		DLLNode<Type> tmp = head;
		
		while (tmp.getNext() != null){
			if (tmp.getData().equals(data))
				return tmp;
			else if (tmp.getNext() == head)
				return null;
			else
				tmp = tmp.getNext();
		}
		//All else fails
		return null;
	}
	
	/*
	 * toString: builds a return string the linked list for 
	 *    print out.
	 */
	public String toString(){
		String returnString = "";
		DLLNode<Type> tmp = head;
		for (int i = 0; i < size; i++){
			returnString += tmp.getData() + " ";
			tmp = tmp.getNext();
		}
		return returnString;
	}

}
