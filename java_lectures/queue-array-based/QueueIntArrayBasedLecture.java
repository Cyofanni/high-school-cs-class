class QueueIntArrayBasedLecture{
	public static void main(String[] args){
		QueueIntArrayBased q = new QueueIntArrayBased(10);
		
		q.enqueue(9);
		q.enqueue(8);
		q.enqueue(6);
		q.enqueue(4);
		q.enqueue(3);
		q.enqueue(8);
		q.enqueue(45);
		q.enqueue(34);
		q.enqueue(23);
		q.enqueue(78);
		q.enqueue(67);
		q.enqueue(34);
		q.enqueue(35);
		q.enqueue(13);
		
		q.print();
		
		q.dequeue();
		q.print();
	}
}