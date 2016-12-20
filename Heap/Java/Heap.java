public class Heap {
	
	private int[] Heap = new int[1000];
	private int size ;

    /*
     *  Class helper methods:
     *    -Parent: returns parent index of node
     *    -Left: returns left child of node
     *    -Right: returns right child of node
     *    -hasleft: returns true if node has left child
     *    -hasright: return true if node has right child
     */

	public int parent( int j)       {return (j-1)/2;}
	public int left(int j)          {return (j*2)+1;}
	public int right(int j)         {return (j*2)+2;}
	public boolean hasleft(int j)   {return (Heap[left(j)] > 0);}
	public boolean hasright(int j)  {return (Heap[right(j)] > 0);}

	public void Swap(int i, int j)
	{
        int temp = Heap[i];
        Heap[i] = Heap[j];
        Heap[j] = temp;
	}

    /*
     *  Major class methods
     */

	public int getSize(){return size;}
    
    /*
     *  Inserts new data at last index, then shifts the data to
     *    maintain Heap integrity
     */

	public void Insert ( int x )
	{
		if (size == 1000)
			System.out.println("Heap full");
		else{
			Heap[size] = x;
			BubbleUp(size);
			size++;
		}
	}

    /*
     *  Prints heap
     */
	public void PrintHeap()
	{
		System.out.println("root: " + Heap[0]);
		
		for (int i = 1; i < size; i++){
			System.out.print(Heap[i] + ", ");
		}
		System.out.println("\n");
	}
    
    /*
     *  Shifts smallest data up to determine new min after insert.
     *    -Takes last index (heap size) as a initial parameter).
     */
    public void BubbleUp(int nodeIndex){
    	int parent;
    	if (nodeIndex != 0){
    		parent = parent(nodeIndex);
    		if (Heap[parent] > Heap[nodeIndex]){
    			Swap(nodeIndex, parent);
    			BubbleUp(parent);
    		}
    	}

    }
    
    /*
     *  Shifts biggest data down the heap.
     *    -Takes 0 index as initial variable.
     */
    
    public void BubbleDown(int parentIndex){
    	int leftIndex = left(parentIndex);
    	int rightIndex = right(parentIndex);
    	int newParent;
    	
    	//Determine left/right indexes, or if indexes are out of bounds.
    	if (rightIndex >= this.getSize()){
    		if (leftIndex >= this.getSize())
    			return;
    		else
    			newParent = leftIndex;
    	}
    	else {
    		if (Heap[leftIndex] <= Heap[rightIndex])
    			newParent = leftIndex;
    		else
    			newParent = rightIndex;
    	}
    	
    	//Swap and continue bubble
    	if (Heap[parentIndex] >= Heap[newParent]){
    		Swap(parentIndex, newParent);
    		BubbleDown(newParent);
    	}
    }

    /*
     *  Removes minimum value (root node).
     *      Finds new root (BubbleDown) using index of 0.
     */
    public int RemoveMin()
    {
    	int returnVal = Heap[0];
        Heap[0] = Heap[size-1];
        Heap[size-1] = 0;
        size--;
        BubbleDown(0);
        
    	return returnVal;
    }

}
