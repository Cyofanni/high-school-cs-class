class ListNode{
	private int key;
	private ListNode next;
	
	ListNode(int key, ListNode next){
		this.key = key;
		this.next = next;
	}
	
	void printList() {
		System.out.print("Linked list's content is: ");
		
		ListNode iterator = this;
		while (iterator != null) {
			System.out.print(iterator.key + "    ");
			iterator = iterator.next;
		}
		System.out.println();
	}
	
	void printListRecursive(ListNode it) {
		if (it == null) {
			System.out.println();
			return;
		}
		System.out.print(it.key + "    ");
		printListRecursive(it.next);
	}
	
	void printListReverseRecursive(ListNode it) {
		if (it == null) {
			return;
		}
		printListReverseRecursive(it.next);
		System.out.print(it.key + "    ");
	}
	
	int searchKey(int searchedKey) {
		ListNode iterator = this;
		int positionOfKey = -1;
		boolean foundItem = false;
		
		while (!foundItem && iterator != null) {
			if (iterator.key == searchedKey) {
				foundItem = true;
			}
			iterator = iterator.next;
			positionOfKey++;
		}
		
		if (foundItem == false) {
			positionOfKey = -1;
		}
		
		return positionOfKey;
	}
	
	ListNode getNodeAt(int pos) {
		ListNode it = this;
		int index = 0;
		
		while (index < pos && it != null) {
			it = it.next;
			index++;
		}
		if (pos < 0) {		
			it = null;
		}
		
		return it;
	}	
	
	ListNode insertAt(int key, int pos){
		ListNode it = this;
		int index = 0;
		ListNode retNode = this;  //node that must be returned
		
		ListNode previousNode = null;
		
		while (it != null && index < pos) {
			previousNode = it;
			it = it.next;
			index++;
		}
		
		ListNode newNode = new ListNode(key, it);
		
		if (pos == 0){
			retNode = newNode;
		}
		else {
			previousNode.next = newNode;
		}
		
		return retNode;
	}
	
	
	ListNode deleteAt(int pos){
		ListNode iterator = this;
		ListNode previousNode = null;
		int index = 0;
		ListNode retNode = this;
		
		while (iterator != null && index < pos) {
			previousNode = iterator;
			index++;
			iterator = iterator.next;
		}
		
		if (pos == 0) {
			retNode = this.next;
		}
		else if (pos < 0) {
			retNode = this;
		}
		else {
			//if didn't pass the end
			if (iterator != null) {
				previousNode.next = iterator.next;
			}
		}
		
		return retNode;
	}
	
	int getSizeRecursive() {
		if (this.next == null) {
			return 1;
		}
		int sizeOfRemainder = this.next.getSizeRecursive();
		return sizeOfRemainder + 1;
	}
}