class QueueStringNode{
    private String key;
    private QueueStringNode next;

    QueueStringNode(String key, QueueStringNode next){
        this.key = key;
        this.next = next;
    }

    //called on tail pointer
    QueueStringNode enqueue(String item){
        /*"this" is the current tail pointer, its next member must point to the new node
           returns a reference to the new tail
        */
        this.next = new QueueStringNode(item, null);
        return this.next;
    }

    //called on head pointer
    QueueStringNode dequeue(){
        return this.next;
    }

    void print(){
        QueueStringNode it = this;
        while (it != null){
            System.out.print(it.key + " ");
            it = it.next;
        }
        System.out.println();
    }
}
