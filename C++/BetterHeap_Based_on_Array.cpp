//--------------------------It is revised version that changes some parts from basic heap, so it is a little bit better heap than before ------------------
//It is implementing Heap in c++
//It is implemented based on array
//It does not use 0 index for array
//Based on search, starting index from 0 or 1 has subtle difference like a little bit more operations 
//However, it does not have significant difference.
//In this case, I did not use 0 index to make code clearer.
#include <iostream>

typedef char Data;

#define ARRAY_LENGTH 100

//It is element struct for heap and it includes priority and data for element 
/*struct Heapelem {
	int prior;
	Data data;
};
*/

//It is class for heap 
class Heap {
public:
	Heap();									//Constructor
	void insert(Data value, int prior);		//Insert 
	Data remove();							//Remove
	bool isEmpty();							//Check whether heap is empty

private:
	int numofdata;							//Number of data in the heap
	Data harr[ARRAY_LENGTH];			//Array for heap

	int gethigherprior(int idx);			//It gets index and return priority for child elements
	int getleftchildidx(int idx);			//It gets index and return index for left child element
	int getrightchildidx(int idx);			//It gets index and return index for right child element
	int getparentidx(int idx);				//It gets index and return index for parent element
	int priorcomb(Data d1, Data d2);

};

//It is constructor for heap and initialize number of data
Heap::Heap() {
	numofdata = 0;
}

//It is function to check whehter heap is empty
bool Heap::isEmpty() {

	if (numofdata == 0) 
		return true;
	else
		return false;
	
}

//It is function to get index for left child
int Heap::getleftchildidx(int idx) {
	return idx *2;
}

//It is function to get index for right child
int Heap::getrightchildidx(int idx) {
	return (idx * 2) + 1;
}

//It is function to get index for parent
int Heap::getparentidx(int idx) {
	return idx / 2;
}

//It is function to compare child elements and give higher priority one between them
int Heap::gethigherprior(int idx) {

	//Get index for left and right children 
	int lchild = getleftchildidx(idx);
	int rchild = getrightchildidx(idx);

	//If left child has bigger index than number of data, it means there is no left child, so it returns 0
	if (lchild > numofdata) {
		return 0;
	}
	//If left child has smae index with number of data, it means there is only left child based on complete binary tree, so it returns index for left child
	else if (lchild == numofdata){
		return lchild;
	}
	//For other case, parent has both children, so we need to compare them
	else {

		//Because I chose minheap, when left child has smaller prior, it returns left child
		if (priorcomb(harr[lchild],harr[rchild]) > 0 ) {
			return lchild;
		}
		else {
			return rchild;
		}
	}
}

int Heap::priorcomb(Data d1, Data d2) {

	return d2 - d1;
}



//It is function to insert values into heap
void Heap::insert(Data value, int prior) {

	//If numofdata has numers as length, heap is full, so we need to return error message
	if (numofdata == ARRAY_LENGTH-1) {
		std::cout << "Array is full, so there is no space to put new value in heap" << std::endl;
		exit(-1);
	}

	//We need to add 1 to numofdata and store it into idx to deal with new value
	int idx = numofdata + 1;

	//We put new element at the end of heap, and we started comapring this value from end of heap to top of heap
	//value 1 for index means top element, so it keeps going until it hits top of heap
	while (idx != 1) {

		//If prior for new element has higher priority, store value at the parent into child
		//Beause we need to make place for new element, so we need to keep moving one value based on priority for new element
		//After we move value, we also need to update index
		if (priorcomb(value, harr[getparentidx(idx)]) > 0 ) {
			harr[idx] = harr[getparentidx(idx)];
			idx = getparentidx(idx);
		}
		//If index for new element meets element that has higher priority, it breaks the loop
		else {
			break;
		}
	}

	//After we finish loop, we need to put new element into the place we made by moving each element
	harr[idx] = value;
	numofdata += 1;

}

//It is function to remove value at the top of heap
Data Heap::remove() {

	//Store data at the top of heap into remove data
	//We also use last element to rearrange heap, we make last element
	Data rdata = harr[1];
	Data lastelm = harr[numofdata];

	int parentidx = 1;
	int childidx;

	//It is loop that works until there is no child or last element meets lower priority element
	//Because we removed the element at the top, so we put last element into top
	//After we put last element into top, we start comparing priority and make last element find its own place
	//While this process, every element fill empty place made by removing element at the top
	while (childidx = gethigherprior(parentidx)) {

		//When last element meets lower priority, it stops comparing priority and exit loop
		if (priorcomb(lastelm, harr[childidx]) >= 0) {
			break;
		}
		//If child has higher priority, move it up to parent to fill empty space
		harr[parentidx] = harr[childidx];
		parentidx = childidx;
	}

	//After we finish rearranging, we put last element into its own place
	harr[parentidx] = lastelm;
	numofdata -= 1;
	return rdata;
}

int main() {

	Heap h;

	h.insert('A', 1);
	h.insert('B', 2);
	h.insert('C', 3);
	std::cout << h.remove() << std::endl;


	h.insert('A', 1);
	h.insert('B', 2);
	h.insert('C', 3);
	std::cout << h.remove() << std::endl;

	while (!h.isEmpty()) {
		std::cout << h.remove() << std::endl;
	}

	
}
