/*
 * InfoNode.h
 *
 *  Created on: Apr 20, 2016
 *      Author: Dennis C. Ejorh
 */

#ifndef INFONODE_H_
#define INFONODE_H_

#include <iostream>

using namespace std;

class InfoNode {
		char character;
		unsigned int frequency;
	
	public:
		InfoNode(unsigned int frequency);
		InfoNode(char character, unsigned int frequency);
		void setCharacter(char);
		char getCharacter();
		void setFrequency(unsigned int);
		unsigned int getFrequency();
		
		bool operator == (const InfoNode &node);
		bool operator > (const InfoNode &node);
		bool operator < (const InfoNode &node);
};

InfoNode::InfoNode(unsigned int frequency) {
	this->frequency = frequency;
}

InfoNode::InfoNode(char character, unsigned int frequency) {
	this->character = character;
	this->frequency = frequency;
}

void InfoNode::setCharacter(char character) {
	this->character = character;
}

char InfoNode::getCharacter() {
	return character;
}

void InfoNode::setFrequency(unsigned int frequency) {
	this->frequency = frequency;
}

unsigned int InfoNode::getFrequency() {
	return frequency;
}

bool InfoNode::operator == (const InfoNode &node) {
	return (frequency == node.frequency);
}

bool InfoNode::operator > (const InfoNode &node) {
	return (frequency > node.frequency);
}

bool InfoNode::operator < (const InfoNode &node) {
	return (frequency < node.frequency);
}

#endif /* INFONODE_H_ */