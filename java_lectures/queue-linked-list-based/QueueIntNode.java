class QueueIntNode{
	int key;
	QueueIntNode next;
	
	QueueIntNode(int key, QueueIntNode next){
		this.key = key;
		this.next = next;
	}
	
	//called on tail pointer
	QueueIntNode enqueue(int item){
		/*"this" is the current tail pointer, its next member must point to the new node
		   returns a reference to the new tail
		*/
		this.next = new QueueIntNode(item, null);
		return this.next;
	}
	
	//called on head pointer
	QueueIntNode dequeue(){	
		return this.next;
	}
	
	void print(){
		QueueIntNode it = this;
		while (it != null){
			System.out.print(it.key + " ");
			it = it.next;
		}
		System.out.println();
	}
}