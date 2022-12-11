class ListLecture{
    public static void main(String[] args){
        ListNode ln = new ListNode(5, new ListNode(7, null));
        ln.printList();
        System.out.println("ln's size is: " + ln.getSizeRecursive());
    }
}