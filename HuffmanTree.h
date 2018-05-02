/*
 * HuffmanTree.h
 *
 *  Created on: Apr 20, 2016
 *      Author: Dennis C. Ejorh
 */

#ifndef HUFFMANTREE_H_
#define HUFFMANTREE_H_

#include "InfoNode.h"
#include "BTNode.h"
#include "SortedArrayList.h"
#include <iostream>
#include <string>

using namespace std;

class HuffmanTree {
private:
	BTNode<InfoNode>* root;
	
	void destroy(BTNode<InfoNode>*);
	void buildCodewords(BTNode<InfoNode>*,string*&,string);
public:
	HuffmanTree(unsigned int* freq);
	~HuffmanTree();
	BTNode<InfoNode>* getRoot();
	string* generateCodewords();
};

HuffmanTree::HuffmanTree(unsigned int* freq) {
	SortedArrayList<BTNode<InfoNode> > elemList;
	for(unsigned int i = 0; i < 256; ++i) {
		if(freq[i] != 0) {
			InfoNode* newInfoNode = new InfoNode((char)i, freq[i]);
			BTNode<InfoNode>* newBTNode = new BTNode<InfoNode>(newInfoNode);
			elemList.add(newBTNode);
		}
	}
	const int SIZE = (elemList.size() - 1);
	for(int i = 0; i < SIZE; ++i) {
		BTNode<InfoNode>* p = elemList.get(0);
		elemList.remove(0);
		BTNode<InfoNode>* q = elemList.get(0);
		elemList.remove(0);
		unsigned int sumFreq = p->getElement()->getFrequency() + q->getElement()->getFrequency();
		InfoNode* newInfoNode = new InfoNode(sumFreq);
		BTNode<InfoNode>* newBTNode = new BTNode<InfoNode>(newInfoNode);
		newBTNode->setLeftSubtree(p);
		newBTNode->setRightSubtree(q);
		elemList.add(newBTNode);
	}
	root = elemList.get(0);
}

HuffmanTree::~HuffmanTree() {
	destroy(root);
}

BTNode<InfoNode>* HuffmanTree::getRoot() {
	return root;
}

void HuffmanTree::destroy(BTNode<InfoNode>* node) {
	if(node != NULL) {
		if(!(node->isLeaf())){
			destroy(node->getLeftSubtree());
			destroy(node->getRightSubtree());
		}
		delete node->getElement();
		delete node;
		node = NULL;
	}
}

void HuffmanTree::buildCodewords(BTNode<InfoNode>* node,string* &codewords,string code) {
	if(node != NULL) {
		if(node->isLeaf()) {
			if(code.empty())
				code.append("1");
				
			codewords[(unsigned int)node->getElement()->getCharacter()] = code;			
		}	
		else {
			code.append("0");
			buildCodewords(node->getLeftSubtree(),codewords,code);
			int last = code.length() - 1;
			code.erase(last, 1);
			code.append("1");
			buildCodewords(node->getRightSubtree(),codewords,code);
		}
	}	
}

string* HuffmanTree::generateCodewords() {
	string* codeArray = new string[256]();
	string code = "";
	buildCodewords(root,codeArray,code);
	return codeArray;
}

#endif /* HUFFMANTREE_H_ */