class StackIntNode{
	private int key;
	private StackIntNode next;
	private StackIntNode previous;
	private boolean isBaseOfStack;
	
	StackIntNode(int key, StackIntNode next, StackIntNode previous, 
				 boolean isBaseOfStack){
		this.key = key;
		this.next = next;
		this.previous = previous;
		this.isBaseOfStack = isBaseOfStack;
	}
	
	StackIntNode push(int item){
		/*"this" is the current stack pointer, must point to the new node
		   returns a reference to the new top
		   the new node cannot be the base: "isBaseOfStack" must be false
		*/
		this.next = new StackIntNode(item, null, this, false);
		return this.next;
	}
	
	StackIntNode pop(){
		StackIntNode ref = this;
		if (this.isBaseOfStack == false){
			//previous doesn't point to popped node anymore
			this.previous.next = null;
			ref = this.previous;
		}
		
		return ref;
	}
	
	boolean isEmpty(){
		return this.isBaseOfStack;
	}
	
	void print(){
		if (this.isBaseOfStack == true){
			return;
		}
		System.out.println("  " + this.key);
		System.out.println("  ==========");
		this.previous.print();
		return;
	}
}