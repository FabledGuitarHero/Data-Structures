
public class BSTNode<Type> {
	private Type data;
	public BSTNode<Type> right;
	public BSTNode<Type> left;
	
	/*
	 * Constructor Method
	 */
	public BSTNode(Type data){
		this.data = data;
	}
	public BSTNode(Type data, BSTNode<Type> next, BSTNode<Type> prev){
		this.data = data;
		this.left = next;
		this.right = prev;
	}
	
	/*
	 * Accessor Methods
	 */
	public Type getData(){ return this.data; }
	public BSTNode<Type> getLeft(){ return this.left; }
	public BSTNode<Type> getRight(){ return this.right; }
	
	/*
	 * Setter Methods
	 */
	public void setData(Type data) { this.data = data; }
	public void setLeft(BSTNode<Type> next) { this.left = next; }
	public void setRight(BSTNode<Type> prev) { this.right = prev; }
}
