///সারকুলার কিউ.................................
Q=[];
head = -1;
tail = -1;
capacity = 5;
staring_point = 2;
def enqueue(value):
    if((tail+1)%capacity==head){
        cout<<"Q is full"<<endl;
        return;
    }
    if(head==-1){
        head=starting_point;
        tail=head;
        Q[tail]=head;
    }
    else{
        tail=(tail+1)%capacity;
        Q[tail]=value;
    }

def deque():
    if(head==-1){
        cout<<"Q is empty"<<endl;
        return;
    }
    q[head]=None;
    if(head==tail){
        head=-1;
        tail=-1;
    }
    else{
        head=(head+1)%capacity;
    }
