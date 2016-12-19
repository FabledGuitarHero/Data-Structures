public class Heap {
	
	private int[] Heap = new int[1000];
	private int size ;

/********************  Helper methods ******************/

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

/********************  Major methods  ******************/

	public int getSize(){return size;}

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

	public void PrintHeap()
	{
		System.out.println("root: " + Heap[0]);
		
		for (int i = 1; i < size; i++){
			System.out.print(Heap[i] + ", ");
		}
		System.out.println("\n");
	}
    
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