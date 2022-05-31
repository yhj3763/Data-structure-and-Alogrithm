//It is implementing Binary Tree in c++
//It is implemented based on class for node

#include <iostream>

typedef int Data;

//It is class for Binary Tree node
class BTree {
public:
	Data data;		//Variable to store data
	BTree* left;	//It stores address to left node
	BTree* right;	//It stores address to right node
};

//It is function to initialize BTree node and return pointer for node
BTree* create() {

	BTree* bn = new BTree;
	bn->left = NULL;
	bn->right = NULL;
	return bn;
}

//It is function to return data in the node
Data getdata(BTree* bn) {
	return bn->data;
}

//It is function to set up value for node
void setdata(BTree* bn, const Data value) {

	bn->data = value;
}

//It is function to get addree for left node
BTree* getleftsubtree(BTree* bn) {
	
	//If there is no node in the left, it returns error message
	if (bn->left == NULL) {
		std::cout << "This node does not have Left Sub Tree" << std::endl;
		exit(-1);
	}
	
	return bn->left;
}

//It is function to get addree for right node
BTree* getrightsubtree(BTree* bn) {

	//If there is no node in the right, it returns error message
	if (bn->right == NULL) {
		std::cout << "This node does not have Right Sub Tree" << std::endl;
		exit(-1);
	}

	return bn->right;
}

//It is function to connect parent node to left child node
void makeleftsubtree(BTree* bn, BTree* sub) {

	//If there is left node already, it deletes previous node and connect new left node to it
	if (bn->left != NULL) {
		delete bn->left;
	}

	bn->left = sub;

}
//It is function to connect parent node to right child node
void makerightsubtree(BTree* bn, BTree* sub) {

	//If there is right node already, it deletes previous node and connect new right node to it
	if (bn->right != NULL) {
		delete bn->right;
	}

	bn->right = sub;
}

//It is function to travel tree in preorder
void preorder(BTree* bn) {

	if (bn == NULL) {
		return;
	}

	std::cout << bn->data << " ";
	preorder(bn->left);
	preorder(bn->right);
}


//It is function to travel tree in inorder
void inorder(BTree* bn) {
	if (bn == NULL) {
		return;
	}

	inorder(bn->left);
	std::cout << bn->data << " ";
	inorder(bn->right);
}

//It is function to travel tree in postorder
void postorder(BTree* bn) {
	if (bn == NULL) {
		return;
	}

	postorder(bn->left);
	postorder(bn->right);
	std::cout << bn->data << " ";
}

int main() {

	BTree* a = create();
	BTree* b = create();
	BTree* c = create();
	BTree* d = create();
	BTree* e = create();
	BTree* f = create();
	
	setdata(a, 1);
	setdata(b, 2);
	setdata(c, 3);
	setdata(d, 4);
	setdata(e, 5);
	setdata(f, 6);

	makeleftsubtree(a, b);
	makerightsubtree(a, c);
	makeleftsubtree(b, d);
	makerightsubtree(b, e);
	makerightsubtree(c, f);

	preorder(a);
	std::cout << std::endl;
	inorder(a);
	std::cout << std::endl;
	postorder(a);

	
}
