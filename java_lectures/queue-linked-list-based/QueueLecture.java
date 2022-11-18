class QueueLecture{
	public static void main(String[] args){
		QueueIntNode head = new QueueIntNode(80, null);
		QueueIntNode tail = head;
		
		tail = tail.enqueue(5);
		tail = tail.enqueue(8);
		tail = tail.enqueue(7);
		tail = tail.enqueue(73);
		tail = tail.enqueue(77);
		
		head.print();
		System.out.println("head's key is: " + head.key);
		System.out.println("tail's key is: " + tail.key);
		if (head != null){
			head = head.dequeue();
			head.print();
		}
		
		System.out.println("head's key is: " + head.key);
		System.out.println("tail's key is: " + tail.key);
		if (head != null){
			head = head.dequeue();
			head.print();
		}
		
		System.out.println("head's key is: " + head.key);
		System.out.println("tail's key is: " + tail.key);
		if (head != null){
			head = head.dequeue();
			head.print();
		}
		
		System.out.println("head's key is: " + head.key);
		System.out.println("tail's key is: " + tail.key);
		if (head != null){
			head = head.dequeue();
			head.print();
		}

		System.out.println("head's key is: " + head.key);
		System.out.println("tail's key is: " + tail.key);
		if (head != null){
			head = head.dequeue();
			head.print();
		}
		
		System.out.println("head's key is: " + head.key);
		System.out.println("tail's key is: " + tail.key);
		
		if (head != null){
			head = head.dequeue();
		}
		
		if (head == null){
			tail = null;
			System.out.println("queue is empty");
		}
		
	}
}