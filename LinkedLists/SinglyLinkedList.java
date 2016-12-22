
public class SinglyLinkedList<Type> {
	
	public SLLNode<Type> head = null;
	public SLLNode<Type> end = null;
	private int size;
	
	/*
	 * Constructor methods
	 */
	public SinglyLinkedList(){ size = 0; }
	
	public SinglyLinkedList(Type data){
		SLLNode<Type> tmp = new SLLNode<Type>(data);
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
		head = new SLLNode<Type>(data, head);
		if( size == 0)
			end = head;
		size++;
	}
	
	/*
	 * addLast: Creates a new node and adds it to the end of
	 *     list.
	 */
	public void addLast(Type data){
		SLLNode<Type> tmp = new SLLNode<Type>(data);
		end = isEmpty() ? head=tmp : end.setNext(tmp);
		size++;
	}
	
	/*
	 * removeFirst: Removes the first node and returns it.
	 */
	public void removeFirst(){
		head = head.getNext();
		size--;
	}
	
	/*
	 * remove: Searches for and removes specified data node.
	 */
	public void remove(Type data){
		
		if (head.getData() == data){
			head = head.getNext();
			size--;
		}
		
		else{
			SLLNode<Type> tmp = search(data);
			if (tmp != null){
				tmp.setNext(tmp.getNext().getNext());
				if (tmp.getNext() == null) {end = tmp;}
				size--;
			}
		}
	}
	
	/*
	 * search: Private method that searches list for data.
	 */
	private SLLNode<Type> search(Type data){
		SLLNode<Type> tmp = head;
		if (head.getData() == data || head.getNext().getData() == data)
			return tmp;
		while (tmp.getNext() != null){
			if (tmp.getNext().getData() == data)
				return tmp;
			else
				tmp = tmp.getNext();
		}
		
		return null;
	}
	
	/*
	 * toString: builds a return string the linked list for 
	 *    print out.
	 */
	public String toString(){
		String returnString = "";
		SLLNode<Type> tmp = head;
		
		for (int i = 0; i < size; i++){
			returnString += tmp.getData() + " ";
			tmp = tmp.getNext();
		}
		return returnString;
	}

}
