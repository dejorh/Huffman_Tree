/*
 * HuffmanUtils.h
 *
 *  Created on: Apr 20, 2016
 *      Author: Dennis C. Ejorh
 */

#ifndef HUFFMANUTILS_H_
#define HUFFMANUTILS_H_

#include "HuffmanTree.h"
#include <string>

class HuffmanUtils {
	
	public:
		HuffmanUtils();
		~HuffmanUtils();
		string encode(string text, string* codewords);
		string decode(string encodedText, HuffmanTree* tree);
};

HuffmanUtils::HuffmanUtils() {

}

HuffmanUtils::~HuffmanUtils() {

}

string HuffmanUtils::encode(string text, string* codewords) {
	if(codewords == NULL)
		return "\0";
	string* code = new string("");
	const unsigned int TEXT_SIZE = text.length();
	for(unsigned int i = 0; i < TEXT_SIZE; ++i) {
		code->append(codewords[(unsigned int)text[i]]);
	}
	string encodedText = *code;
	delete code;
	return encodedText;
}

string HuffmanUtils::decode(string encodedText, HuffmanTree* tree) {
	if(tree == NULL)
		return "\0";
	BTNode<InfoNode>* node = tree->getRoot();
	const unsigned int TEXT_SIZE = encodedText.length();
	string decText = "";
	for(int i = 0; i < TEXT_SIZE; ++i) {
		if(TEXT_SIZE > 1) {
			if(encodedText[i] == '0') {
				node = node->getLeftSubtree();
			}
			if(encodedText[i] == '1') {
			  	node = node->getRightSubtree();
			}
		}	
		if(node->isLeaf()) {
			decText.append(string(1,node->getElement()->getCharacter()));
			node = tree->getRoot();
		}
	}
	return decText;
}

#endif /* HUFFMANUTILS_H_ */