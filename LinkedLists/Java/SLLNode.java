
public class SLLNode<Type> {
	private Type data;
	private SLLNode<Type> next;
	
	/* Constructors */
	public SLLNode(Type data, SLLNode<Type> next){
		 this.data = data;
		 this.next = next;
	}
	
	public SLLNode(Type data){
		this.data = data;
		this.next = null;
	}
	
	/* Accessor methods */
	public Type getData(){ return this.data; }
	public SLLNode<Type> getNext(){ return this.next; }
	
	/* Setter methods */
	public void setData(Type data){ this.data = data; }
	public SLLNode<Type> setNext(SLLNode<Type> next) { return this.next = next; }
}
