/*
 * Roll no.- 2459
 * Name- Sharvari Sonkusare
 * CNumber- C22019221458
 * Assignment number- 4
 *
 * Problem statement -Implement Queue as ADT using linked list or array. Use Queue ADT to simulate
'waiting list' operations of railway reservation system.
 */



#include<iostream>
#include<queue>
using namespace std;


class Node{
public:
	int data;
	Node* next;
	Node(int d){
		data=d;
		next=NULL;
	}
	Node(){

	}
};
class Queue{
public:
Node* front;
Node* rear;
Node* temp;
int c;



Queue(){

	front=NULL;
	rear=NULL;
	c=0;

}
int isEmpty();
void dequeue();
void enqueue(int x);
void display();
int count();
void waitList();
};

int Queue::isEmpty(){
	if(rear==NULL && front==NULL){
		return(1);
	}
	else{
			return(0);
		}
	}

void Queue::enqueue(int x)
  {

	Node* temp = new Node(x);

	      // If queue is empty
	      if (rear == NULL) {
	          front = rear = temp;
	          //DATA INSERTED
	          c=c+1;
	          return;
	      }

	      // Adding the new node at the end
	      rear->next = temp;
	      rear = temp;
	      //DATA INSERTED
	      c=c+1;
  }



void Queue:: dequeue()
    {
        // for empty queue
        if (front == NULL){
        	cout<<"Queue is empty";
            return;
        }


        // move front one node ahead and then delete previous front
        Node* temp = front;
        front = front->next;
        cout<<"DATA REMOVED"<<endl;
        c=c-1;

        // If front becomes NULL, then change rear also as NULL
        if (front == NULL){
            rear = NULL;
        }

        delete (temp);
    }

void Queue::display(){
	Node* temp = new Node();
	temp = front;
	   if ((front == NULL) && (rear == NULL)) {
	      cout<<"Queue is empty"<<endl;

	      return;
	   }
	   cout<<"Queue elements are: ";
	      while (temp != NULL) {     //traverse the queue to display all elements
	         cout<<temp->data<<" ";
	         temp = temp->next;

	      }
	      cout<<endl;
}
int Queue::count(){
	return c;
}


int main(){

	Queue q;
	int ch,x;


	   do {
		   cout<<"\n1) Insert element to queue"<<endl;
		   cout<<"2) Delete element from queue"<<endl;
     	   cout<<"3) Display all the elements of queue"<<endl;
     	   cout<<"4) Count number of elements"<<endl;
     	   cout<<"5)Use waiting list service for reservation"<<endl;
		   cout<<"6) Exit"<<endl;
	      cout<<"Enter your choice : "<<endl;
	      cin>>ch;
	      int k;
	      switch (ch) {
	         case 1:
	        		 cout<<"enter the value to be inserted"<<endl;
	        		 cin>>x;
	  	        	 q.enqueue(x);
	         break;
	         case 2: q.dequeue();
	         break;
	         case 3: q.display();
	         break;
	         case 4: k=q.count();
	                 cout<<k<<endl;
	         break;
	         case 5:
	        	 q.waitList();
	         break;
	         case 6: cout<<"Exit"<<endl;
	         break;
	         default: cout<<"Invalid choice"<<endl;
	      }
	   } while(ch!=6);
	   return 0;

}

void Queue::waitList(){
	int total,id,cancel,num;
	Queue w;
	cout<<"Total reservations available are 5";
    int a[5];
	cout<<"\nEnter the total number of reservations you want to make"<<endl;
	cin>>total;
    cout<<"\nEnter all the reservation id's";

	for(int i=1; i<=total; i++){
		if(i<=5){
			cin>>a[i];
		}
		if(i>5){
			cin>>id;
		    w.enqueue(id);
		    cout<<"ID NO.- "<<id<<" IN WAITING LIST"<<endl;
		}
	}
	cout<<"Enter 1 if cancellations are present \nEnter 0 if no cancellations are present";
    cin>>cancel;
    if(cancel==1){
    	cout<<"Enter the number of cancellations you want to do"<<endl;
    	cin>>num;
	    for(int i=1; i<=num;i++){
	    	cout<<"Enter the cancellation id";
	    	cin>>id;
	    	a[id]=w.front->data;
	    	w.dequeue();
		    cout<<"Cancellation made for id: "<<id<<"\nUpdated confirm reservation list is: "<<endl;
		    for(int J=1; J<=5; J++){
		    			cout<<a[J]<<" "<<endl;
		    		}
		    cout<<"\nUpdated waiting list: "<<endl;
		    w.display();

	    }
    }
}


/*
 * OUTPUT:
1) Insert element to queue
2) Delete element from queue
3) Display all the elements of queue
4) Count number of elements
5)Use waiting list service for reservation
6) Exit
Enter your choice :
1
enter the value to be inserted
1

1) Insert element to queue
2) Delete element from queue
3) Display all the elements of queue
4) Count number of elements
5)Use waiting list service for reservation
6) Exit
Enter your choice :
1
enter the value to be inserted
2

1) Insert element to queue
2) Delete element from queue
3) Display all the elements of queue
4) Count number of elements
5)Use waiting list service for reservation
6) Exit
Enter your choice :
1
enter the value to be inserted
3

1) Insert element to queue
2) Delete element from queue
3) Display all the elements of queue
4) Count number of elements
5)Use waiting list service for reservation
6) Exit
Enter your choice :
3
Queue elements are: 1 2 3

1) Insert element to queue
2) Delete element from queue
3) Display all the elements of queue
4) Count number of elements
5)Use waiting list service for reservation
6) Exit
Enter your choice :
2
DATA REMOVED

1) Insert element to queue
2) Delete element from queue
3) Display all the elements of queue
4) Count number of elements
5)Use waiting list service for reservation
6) Exit
Enter your choice :
2
DATA REMOVED

1) Insert element to queue
2) Delete element from queue
3) Display all the elements of queue
4) Count number of elements
5)Use waiting list service for reservation
6) Exit
Enter your choice :
3
Queue elements are: 3

1) Insert element to queue
2) Delete element from queue
3) Display all the elements of queue
4) Count number of elements
5)Use waiting list service for reservation
6) Exit
Enter your choice :
1
enter the value to be inserted
5

1) Insert element to queue
2) Delete element from queue
3) Display all the elements of queue
4) Count number of elements
5)Use waiting list service for reservation
6) Exit
Enter your choice :
5
Total reservations available are 5
Enter the total number of reservations you want to make
8

Enter all the reservation id's1
2
3
4
5
6
ID NO.- 6 IN WAITING LIST
7
ID NO.- 7 IN WAITING LIST
8
ID NO.- 8 IN WAITING LIST
Enter 1 if cancellations are present
Enter 0 if no cancellations are present1
Enter the number of cancellations you want to do
3
Enter the cancellation id1
DATA REMOVED
Cancellation made for id: 1
Updated confirm reservation list is:
6
2
3
4
5

Updated waiting list:
Queue elements are: 7 8
Enter the cancellation id3
DATA REMOVED
Cancellation made for id: 3
Updated confirm reservation list is:
6
2
7
4
5

Updated waiting list:
Queue elements are: 8
Enter the cancellation id2
DATA REMOVED
Cancellation made for id: 2
Updated confirm reservation list is:
6
8
7
4
5

Updated waiting list:
Queue is empty

1) Insert element to queue
2) Delete element from queue
3) Display all the elements of queue
4) Count number of elements
5)Use waiting list service for reservation
6) Exit
Enter your choice :
6
Exit

TIME COMPLEXITIES:

1.isEmpty=O(1)
2. dequeue=O(1)
3. enqueue=O(1)
4. display=O(N)
5. count=O(1)
6. waitList=O(N^2)

 *
 */




