class StackLecture{
	public static void main(String[] args){
		StackIntNode st = new StackIntNode(0, null, null, true);
		
		int i = 0;
		while (i < 10){
			st = st.push(i);
			i++;
		}
		
		while (st.isEmpty() == false){
			st.print();
			st = st.pop();
		}
		
	}
}