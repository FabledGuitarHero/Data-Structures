
public class BinarySearchTree{
	public BSTNode<Integer> root;
	private int size;
	
	/*
	 * Constructors
	 */
	public BinarySearchTree(){
		root = null;
		size = 0;
	}
	
	public BinarySearchTree(Integer data){
		BSTNode<Integer> tmp = new BSTNode<Integer>(data, null, null);
		this.root = tmp;
		this.size = 1;
	}
	
	/*
	 * Accessor Methods
	 */
	public int getSize() { return this.size; }
	
	/*
	 * addNode: Add's new node recursively to the BST.
	 */
	public BSTNode<Integer> addNode(Integer data, BSTNode<Integer> Node){
		if (Node == null)
			Node = new BSTNode<Integer>(data, null, null);	
		else if (data < root.getData())
			Node.left = addNode(data, Node.getLeft());
		else
			Node.right = addNode(data, Node.getRight());
		return Node;
	}
	
	/*
	 * deleteNode: Finds node by looking at it's children, if there's a match,
	 *    sets its next child to the next appropriate child node.
	 */
	public BSTNode<Integer> deleteNode(Integer data, BSTNode<Integer> Node){
		if (data == Node.left.getData())
			return Node.left = Node.left.left;
		if (data == Node.right.getData())
			return Node.right = Node.right.right;
		if (data < Node.left.getData())
			Node.left = deleteNode(data, Node.left);
		if (data > Node.right.getData())
			Node.right = deleteNode(data, Node.right);
		
		return Node;
	}
	
	/*
	 * Search: searches the BST for a specific node.
	 */
	public BSTNode<Integer> Search(Integer data, BSTNode<Integer> Node){
		if (Node == null)
			return null;
		else if (data == Node.getData())
			return Node;
		else if (data < Node.getData())
			return Search(data, Node.left);
		else if (data > Node.getData())
			return Search(data, Node.right);
		else
			return null;
	}
	
	/*
	 * PostOrder: Displays the tree in Post Order
	 */
	public void PostOrder(BSTNode<Integer> Node){
		if (Node.left != null)
			PostOrder(Node.getLeft());
		if (Node.right != null)
			PostOrder(Node.getRight());
		
		System.out.print(Node.getData() + ", ");
	}
	
	/*
	 * PreOrder: Displays the tree in Pre Order
	 */
	public void PreOrder(BSTNode<Integer> Node){
		System.out.print(Node.getData() + ", ");
		if (Node.left != null)
			PreOrder(Node.left);
		if (Node.right != null)
			PreOrder(Node.right);
	}
	
	/*
	 * treeHeight: Finds the height of the tree
	 */
	public int treeHeight(BSTNode<Integer> Node){
		if (Node == null)
			return 0;
		else{
			int leftHeight = treeHeight(Node.left);
			int rightHeight = treeHeight(Node.right);
			
			if (leftHeight > rightHeight)
				return (leftHeight + 1);
			else
				return (rightHeight + 1);
		}
	}

}
