class StackIntNode{
	int key;
	StackIntNode next;
	StackIntNode stackPointerPrevious;

	StackIntNode(int key, StackIntNode next){
		this.key = key;
		this.next = next;
	}
	
	StackIntNode push(int item){
		this.next = new StackIntNode(item, null);
		this.next.stackPointerPrevious = this;
		return this.next;
	}
	
	StackIntNode pop(){
		if (stackPointerPrevious != null){
			stackPointerPrevious.next = null;
			return stackPointerPrevious;
		}
		else{
			return this;
		}
	}
	
	int getKey(){
		return key;
	}
}