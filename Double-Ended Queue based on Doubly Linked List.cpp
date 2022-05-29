//It is implementing Double-Ended queue in c++
//It is based on doubly Linke List

#include <iostream>

typedef int Data;

//Node for queue
struct Node {
	Node* next;
	Node* prev;
	Data data;
};

//Class for Linekd List Queue
class DQueue {
private:
	Node* front;			//Front value that has first value in queue
	Node* rear;				//Rear value that has last value in queue
 
public:
	DQueue();						//Constructor for Circular Queue
	void enqueuefront(Data data);	//Enqueue to add value into beginning of the queue
	void enqueuerear(Data data);    //Enqueue to add value into end of the queue
	Data dequeuefront();			//Dequeue to remove value from beginning of the queue
	Data dequeuerear();				//Dequeue to remove value fron end of the queue
	Data peekfront();				//Peek first value from queue
	Data peekrear();				//Peek last value from queue
	bool QIsEmpty();				//Check whether queue is empty 

};

//Consturctor function for class
DQueue::DQueue() {
	front = NULL;
	rear = NULL;
}


//Function that checks whether queue is empty
bool DQueue::QIsEmpty() {

	//If front is NULL, it means queue is empty
	if (front == NULL) {
		return true;
	}
	else {
		return false;
	}

}

//Function that adds value into queue
void DQueue::enqueuefront(Data data) {

	//Make newnode to put into queue
	Node* newnode = new Node;
	newnode->prev = NULL;
	newnode->next = NULL;
	newnode->data = data;

	//If front is NULL, make front and rear indicate newnode
	if (front == NULL) {
		front = newnode;
		rear = newnode;
	}
	//If there is more than one node in the queue, make newnode next indicate front, front previous indicate newnode, and make newnode as front
	else {
		
		newnode->next = front;
		front->prev = newnode;
		front = newnode;
	}

}

void DQueue::enqueuerear(Data data) {

	//Make newnode to put into queue
	Node* newnode = new Node;
	newnode->next = NULL;
	newnode->prev = NULL;
	newnode->data = data;

	//If front is NULL, make front and rear indicate newnode
	if (front == NULL) {
		front = newnode;
		rear = newnode;
	}
	//If there is more than one node in the queue, make rear next indicate newnode, newnode previous indicate rear, and make newnode as rear
	else {

		rear->next = newnode;
		newnode->prev = rear;
		rear = newnode;
	}
}

//Function that removes value from queue
Data DQueue::dequeuefront() {

	//If queue is empty, print error message and exit
	if (QIsEmpty()) {
		std::cout << "Queue is empty" << std::endl;
		exit(-1);
	}
	
	//Store node and data to remove
	Node* rnode = front;
	Data rdata = front->data;

	//Move front to next front and remove node and return data
	front = front->next;
	delete rnode;

	//If front becomes NULL after remove, we need to also make rear as NULL
	if (front == NULL) {
		rear == NULL;
	}
	//If there is more than one node after we remove, we need to make front previous indicates NULL
	else {
		front->prev = NULL;
	}

	return rdata;
}

Data DQueue::dequeuerear() {

	//If queue is empty, print error message and exit
	if (QIsEmpty()) {
		std::cout << "Queue is empty" << std::endl;
		exit(-1);
	}

	//Store node and data to remove
	Node* rnode = rear;
	Data rdata = rear->data;

	//Move rear to prev rear and remove node and return data
	rear = rear->prev;

	delete rnode;

	//If rear becomes NULL after remove, we need to also make front as NULL
	if (rear == NULL) {
		front == NULL;
	}
	//If there is more than one node after we remove, we need to make rear next indicates NULL
	else {
		rear->next = NULL;
	}

	return rdata;

}

//Fucntion that peeks value from queue
Data DQueue::peekfront() {

	//If queue is empty, print error message and exit
	if (QIsEmpty()) {
		std::cout << "Queue is empty" << std::endl;
		exit(-1);
	}

	//return value to peek
	return front->data;
}

//Fucntion that peeks value from queue
Data DQueue::peekrear() {

	//If queue is empty, print error message and exit
	if (QIsEmpty()) {
		std::cout << "Queue is empty" << std::endl;
		exit(-1);
	}

	//return value to peek
	return rear->data;
}

int main() {

	DQueue dq;

	dq.enqueuefront(3);
	dq.enqueuefront(2);
	dq.enqueuefront(1);
	dq.enqueuerear(4);
	dq.enqueuerear(5);
	dq.enqueuerear(6);


	while (!dq.QIsEmpty()) {
		std::cout << dq.dequeuefront() << std::endl;
	}
	dq.enqueuefront(3);
	dq.enqueuefront(2);
	dq.enqueuefront(1);
	dq.enqueuerear(4);
	dq.enqueuerear(5);
	dq.enqueuerear(6);

	std::cout << std::endl;
	std::cout << std::endl;
	
	while (!dq.QIsEmpty()) {
		std::cout << dq.dequeuerear() << std::endl;
	}
}
