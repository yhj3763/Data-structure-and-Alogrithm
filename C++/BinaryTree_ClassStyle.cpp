//It is implementing Binary Tree in c++
//It is implemented based on class for node

#include <iostream>

typedef int Data;


//It is class for Binary Tree node
class BTree {
public:
	BTree();
	Data getdata();
	void setdata(const Data value);
	BTree* getleftsubtree();
	BTree* getrightsubtree();
	void makeleftsubtree(BTree* sub);
	void makerightsubtree(BTree* sub);

private:
	Data data;		//Variable to store data
	BTree* left;	//It stores address to left node
	BTree* right;	//It stores address to right node
};

//It is function to initialize BTree node and return pointer for node
BTree:: BTree() {
	left = NULL;
	right = NULL;
}

//It is function to return data in the node
Data BTree::getdata() {
	return data;
}

//It is function to set up value for node
void BTree::setdata(const Data value) {
	data = value;
}

//It is function to get addree for left node
BTree* BTree::getleftsubtree() {
	
	//If there is no node in the left, it returns error message
	//if (left == NULL) {
	//	std::cout << "This node does not have Left Sub Tree" << std::endl;
	//	exit(-1);
	//}
	
	return left;
}

//It is function to get addree for right node
BTree* BTree::getrightsubtree() {

	//If there is no node in the right, it returns error message
	//if (right == NULL) {
	//	std::cout << "This node does not have Right Sub Tree" << std::endl;
	//	exit(-1);
	//}

	return right;
}

//It is function to connect parent node to left child node
void BTree::makeleftsubtree(BTree* sub) {

	//If there is left node already, it deletes previous node and connect new left node to it
	if (left != NULL) {
		delete left;
	}

	left = sub;

}
//It is function to connect parent node to right child node
void BTree::makerightsubtree(BTree* sub) {

	//If there is right node already, it deletes previous node and connect new right node to it
	if (right != NULL) {
		delete right;
	}

	right = sub;
}

//It is function to travel tree in preorder
void preorder(BTree* bn) {

	if (bn == NULL) {
		return;
	}

	std::cout << bn->getdata() << " ";
	preorder(bn->getleftsubtree());
	preorder(bn->getrightsubtree());
}


//It is function to travel tree in inorder
void inorder(BTree* bn) {
	if (bn == NULL) {
		return;
	}

	inorder(bn->getleftsubtree());
	std::cout << bn->getdata() << " ";
	inorder(bn->getrightsubtree());
}

//It is function to travel tree in postorder
void postorder(BTree* bn) {
	if (bn == NULL) {
		return;
	}

	postorder(bn->getleftsubtree());
	postorder(bn->getrightsubtree());
	std::cout << bn->getdata() << " ";
}

int main() {

	BTree a;
	BTree b;
	BTree c;
	BTree d;
	BTree e;
	BTree f;
	
	a.setdata(1);
	b.setdata(2);
	c.setdata(3);
	d.setdata(4);
	e.setdata(5);
	f.setdata(6);

	a.makeleftsubtree(&b);
	a.makerightsubtree(&c);
	b.makeleftsubtree(&d);
	b.makerightsubtree(&e);
	c.makeleftsubtree(&f);



	preorder(&a);
	std::cout << std::endl;
	inorder(&a);
	std::cout << std::endl;
	postorder(&a);

	
}
