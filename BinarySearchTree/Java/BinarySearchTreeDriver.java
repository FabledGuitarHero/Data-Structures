
public class BinarySearchTreeDriver {
	
	public static void main (String args[]){
		BinarySearchTree tmp = new BinarySearchTree();
		tmp.root = tmp.addNode(10, tmp.root);
		tmp.root = tmp.addNode(15, tmp.root);
		tmp.root = tmp.addNode(3, tmp.root);
		tmp.root = tmp.addNode(2, tmp.root);
		tmp.root = tmp.addNode(1, tmp.root);
		tmp.root = tmp.addNode(12, tmp.root);
		tmp.root = tmp.addNode(14, tmp.root);
		tmp.PostOrder(tmp.root);
		System.out.println("");
		tmp.PreOrder(tmp.root);
		System.out.println("");
		
		tmp.deleteNode(3, tmp.root);
		
		tmp.PreOrder(tmp.root);
		System.out.println("root: " + tmp.root.getData());
		System.out.println(tmp.treeHeight(tmp.root));
	}

}
