
public class DLLNode<Type> {
	private Type data;
	private DLLNode<Type> next;
	private DLLNode<Type> prev;
	
	/* Constructors */
	public DLLNode(Type data, DLLNode<Type> next, DLLNode<Type> prev){
		 this.data = data;
		 this.next = next;
		 this.prev = prev;
	}
	
	public DLLNode(Type data){
		this.data = data;
		this.next = null;
		this.prev = null;
	}
	
	/* Accessor methods */
	public Type getData(){ return this.data; }
	public DLLNode<Type> getNext(){ return this.next; }
	public DLLNode<Type> getPrev(){ return this.prev; }
	
	/* Setter methods */
	public void setData(Type data){ this.data = data; }
	public DLLNode<Type> setNext(DLLNode<Type> next) { return this.next = next; }
	public void setPrev(DLLNode<Type> prev) { this.prev = prev; }
}
