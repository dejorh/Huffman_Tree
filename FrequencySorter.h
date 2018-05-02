/*
 * FrequencySorter.h
 *
 *  Created on: Apr 20, 2016
 *      Author: Dennis C. Ejorh
 */

#ifndef FREQUENCYSORTER_H_
#define FREQUENCYSORTER_H_

#include <iostream>
#include <string>

using namespace std;

class FrequencySorter {
	public:
		FrequencySorter();
		~FrequencySorter();
		unsigned int* calculateFrequencies(string text);
};

FrequencySorter::FrequencySorter() {

}

FrequencySorter::~FrequencySorter() {

}

unsigned int* FrequencySorter::calculateFrequencies(string text) {
	unsigned int *freq = new unsigned int[256]();
	const unsigned int TEXT_SIZE = text.length();
	for(unsigned int i = 0; i < TEXT_SIZE; ++i) {
		char mychar = text[i];
		freq[(unsigned int)mychar]++;
	}
	return freq;
}
	
#endif /* FREQUENCYSORTER_H_ */