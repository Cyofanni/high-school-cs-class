class QueueIntArrayBased{
	private int[] v;
	private int size;
	private final int headIndex = 0;
	private int tailIndex;
	
	QueueIntArrayBased(int size){
		this.v = new int[size];
		this.tailIndex = -1;
		this.size = size;
	}
	
	int enqueue(int item){
		if (this.tailIndex < this.size - 1){
			this.tailIndex++;
			this.v[this.tailIndex] = item;
		}
		
		return this.tailIndex;
	}
	
	int dequeue(){
		//runs in O(n), not a great idea!
		if (this.tailIndex >= 0){
			if (this.tailIndex >= 1){
				for (int i = 0; i <= this.tailIndex - 1; i++){
					this.v[i] = this.v[i + 1];
				}
			}
		
			this.tailIndex--;
		}
		
		return this.tailIndex;
	}
	
	void print(){
		for (int i = this.headIndex; i <= this.tailIndex; i++){
			System.out.print(this.v[i]);
			if (i < this.tailIndex){
				System.out.print("-->");
			}
		}
		System.out.println();
	}
}