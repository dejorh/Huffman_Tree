/*
 * SortedArrayList.h
 *
 *  Created on: Dec 17, 2014
 *      Author: B
 */

#ifndef SORTEDARRAYLIST_H_
#define SORTEDARRAYLIST_H_

#include <cmath>
#include <iostream>
using namespace std;

template<class T>
class SortedArrayList {

private:
	int maxLength;
	T** elements;
	int length;

	void resize();
	void removeFromValidPosition(int position);

public:
	SortedArrayList();
	virtual ~SortedArrayList();
	int size();
	int add(T* element);
	bool remove(T* element);
	bool remove(int position);
	int getPosition(T* element);
	T* get(int position);
};

template<class T>
SortedArrayList<T>::SortedArrayList(void) {
	maxLength = 100;
	elements = new T*[maxLength];
	for (int var = 0; var < maxLength; ++var) {
		elements[var] = NULL;
	}
	length = 0;
}

template<class T>
SortedArrayList<T>::~SortedArrayList(void) {
	delete[] elements;
}

template<class T>
int SortedArrayList<T>::size() {
	return length;
}

template<class T>
int SortedArrayList<T>::add(T* element) {
	if (element == NULL) {
		return -1;
	}
	bool notBigEnough = (maxLength == length);
	if (notBigEnough) {
		resize();
	}
	//what is the position?
	int position = 0;
	if (length > 0) {
		position = getPosition(element);
		position = fabs(position);

		for (int var = length; var > position; --var) {
			elements[var] = elements[var - 1];
		}
	}
	elements[position] = element;
	++length;
	return position;
}

template<class T>
void SortedArrayList<T>::removeFromValidPosition(int position) {
	--length;
	for (int var = position; var < length; ++var) {
		elements[var] = elements[var + 1];
	}
	elements[length] = NULL;
}

template<class T>
bool SortedArrayList<T>::remove(T* element) {
	if (element == NULL || length == 0) {
		return false;
	}
	int position = getPosition(element);
	if (position < 0 || (position == 0 && *element != *elements[0])) {
		return false;
	}
	removeFromValidPosition(position);
	return true;
}

template<class T>
bool SortedArrayList<T>::remove(int position) {
	bool notValidPosition = (position < 0 || position >= length);
	if (notValidPosition) {
		return false;
	}
	removeFromValidPosition(position);
	return true;
}

template<class T>
int SortedArrayList<T>::getPosition(T* element) {
	if (element == NULL) {
		return 0;
	}
	int left = 0;
	int right = length - 1;
	int middle = left + ((right - left) / 2);

	while (left <= right) {
		if (*element == *elements[middle])
			return middle;
		else if (*element < *elements[middle])
			right = (middle - 1);
		else
			left = middle + 1;
		middle = left + ((right - left) / 2);
	}
	return -middle;
}

template<class T>
T* SortedArrayList<T>::get(int position) {
	bool notValidPosition = (position < 0 || position >= length);
	if (notValidPosition) {
		return NULL;
	}
	return elements[position];
}

template<class T>
void SortedArrayList<T>::resize() {
	maxLength = 2 * maxLength;
	T** oldArray = elements;
	elements = new T*[maxLength];
	for (int var = 0; var < length; ++var) {
		elements[var] = oldArray[var];
	}
	for (int var = length; var < maxLength; ++var) {
		elements[var] = NULL;
	}
	delete[] oldArray;
	oldArray = NULL;
}

#endif /* ARRAYLIST_H_ */