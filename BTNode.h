/*
 * BTNode.h
 *
 *  Created on: Apr 4, 2015
 *      Author: Beata
 */

#ifndef BTNODE_H_
#define BTNODE_H_

#include <iostream>
using namespace std;

template<class T>
class BTNode {
private:
	T* element;
	BTNode<T>* leftSubtree;
	BTNode<T>* rightSubtree;
public:
	BTNode(T* newElement) {
		this->element = newElement;
		leftSubtree = NULL;
		rightSubtree = NULL;
	}

	T* getElement() const{
		return element;
	}

	void setElement(T* element) {
		this->element = element;
	}

	BTNode<T>* getLeftSubtree() {
		return leftSubtree;
	}

	void setLeftSubtree(BTNode<T>* leftSubtree) {
		this->leftSubtree = leftSubtree;
	}

	BTNode<T>* getRightSubtree() {
		return rightSubtree;
	}

	void setRightSubtree(BTNode<T>* rightSubtree) {
		this->rightSubtree = rightSubtree;
	}

	bool isLeaf() {
		return (leftSubtree == NULL && rightSubtree == NULL);
	}
	
	bool operator == (const BTNode &node){
		return (*element == *node.getElement());
	}
		bool operator > (const BTNode &node){
		return (*element > *node.getElement());
	}
		bool operator < (const BTNode &node){
		return (*element < *node.getElement());
	}
};

#endif /* BTNODE_H_ */