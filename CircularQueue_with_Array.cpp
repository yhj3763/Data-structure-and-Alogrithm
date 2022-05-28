//It is implementing circular queue in c++
//With array, queue has problems for two cases
//1. When we use rear value to dequeue, we need to move each value to front, so it has cost problem
//2. When we use front value to dequeue, rear value cannot go futher when it reaches end of the array
//Therefore, Circular queue is normal way to implement queue with array

#include <iostream>

#define QUEUE_LEN 100		//Length for queue

typedef int Data;

//Class for Circular Queue
class CQueue {
private:
	int front;				//Front value that has first value in queue
	int rear;				//Rear value that has last value in queue
	Data arrque[QUEUE_LEN]; //Array that stores values for queue
	int nextpos(int pos);   //It is function calculates next pos 

public:
	CQueue();				//Constructor for Circular Queue
	void enqueue(Data data);//Enqueue to add value into queue
	Data dequeue();         //Dequeue to remove value from queue
	Data qpeek();			//Peek first value from queue
	bool QIsEmpty();		//Check whether queue is empty 

};

//Consturctor function for class
CQueue::CQueue() {
	front = 0;
	rear = 0;
}

//Function that calculates next pos for queue
int CQueue::nextpos(int pos) {
	//If pos hits the last index of array, it goes to 0 to recycle 
	if (pos == QUEUE_LEN - 1) {
		return 0;
	}
	//If pos does not hit last index, it just goes to next position
	else {
		return pos + 1;
	}
}

//Function that checks whether queue is empty
bool CQueue::QIsEmpty() {

	if (front == rear) {
		return true;
	}
	else {
		return false;
	}

}

//Function that adds value into queue
void CQueue::enqueue(Data data) {

	//if next position is equal to front, it means queue is full
	if (nextpos(rear) == front) {
		std::cout << "Queue is full" << std::endl;
		exit(-1);
	}

	//Move to next position and add value into it
	rear = nextpos(rear);
	arrque[rear] = data;

}

//Function that removes value from queue
Data CQueue::dequeue() {

	//If queue is empty, print error message and exit
	if (QIsEmpty()) {
		std::cout << "Queue is empty" << std::endl;
		exit(-1);
	}

	//Move to next position and remove value from it, and print value
	front = nextpos(front);
	return arrque[front];
}

//Fucntion that peeks value from queue
Data CQueue::qpeek() {

	//If queue is empty, print error message and exit
	if (QIsEmpty()) {
		std::cout << "Queue is empty" << std::endl;
		exit(-1);
	}

	//return value to peek
	return arrque[nextpos(front)];
}


int main() {

	CQueue cq;

	cq.enqueue(1);
	cq.enqueue(2);
	cq.enqueue(3);
	cq.enqueue(4);
	cq.enqueue(5);

	cq.dequeue();

	std::cout << cq.qpeek() << std::endl;

	while (!cq.QIsEmpty()) {
		std::cout << cq.dequeue() << std::endl;
	}


	
}
