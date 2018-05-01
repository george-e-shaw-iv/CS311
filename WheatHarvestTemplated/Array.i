/*
 * Array.i
 *
 *  Created on: Feb 8, 2018
 *      Author: Joe
 */

#include <stdexcept>

#include "Array.h"

/**
 * Constants
 */
static const int ARRAY_CAPACITY_BLOCK_SIZE = 10;

/**
 * Iterator default constructor
 */
template <class T>
ArrayIterator<T>::ArrayIterator() : container(nullptr), index(-1)
{
}

/**
 * Iterator constructor allowing caller to specify pointer to array and index
 */
template <class T>
ArrayIterator<T>::ArrayIterator(const Array<T> *container, int index) : container(container), index(-1)
{
	if (container) {
		if (index < 0)
			index = 0;
		if (index >= container->arraySize)
			index = -1;
		this->index = index;
	}
}

/**
 * Iterator destructor
 */
template <class T>
ArrayIterator<T>::~ArrayIterator()
{
}

/**
 * Iterator overloaded equality operator ==
 */
template <class T>
bool ArrayIterator<T>::operator ==(const ArrayIterator<T>& iterator) const
{
	int index1 = (container && index == -1) ? container->arraySize : index;
	int index2 = (iterator.container && iterator.index == -1) ? iterator.container->arraySize : iterator.index;

	return (container == iterator.container && index1 == index2);
}

/**
 * Iterator overloaded inequality operator !=
 */
template <class T>
bool ArrayIterator<T>::operator !=(const ArrayIterator<T>& iterator) const
{
	int index1 = (container && index == -1) ? container->arraySize : index;
	int index2 = (iterator.container && iterator.index == -1) ? iterator.container->arraySize : iterator.index;

	return (container != iterator.container || index1 != index2);
}

/**
 * Iterator overloaded relational operator <
 */
template <class T>
bool ArrayIterator<T>::operator <(const ArrayIterator<T>& iterator) const
{
	int index1 = (container && index == -1) ? container->arraySize : index;
	int index2 = (iterator.container && iterator.index == -1) ? iterator.container->arraySize : iterator.index;

	return (container == iterator.container && index1 < index2);
}

/**
 * Iterator overloaded relational operator >
 */
template <class T>
bool ArrayIterator<T>::operator >(const ArrayIterator<T>& iterator) const
{
	int index1 = (container && index == -1) ? container->arraySize : index;
	int index2 = (iterator.container && iterator.index == -1) ? iterator.container->arraySize : iterator.index;

	return (container == iterator.container && index1 > index2);
}

/**
 * Iterator overloaded relational operator <=
 */
template <class T>
bool ArrayIterator<T>::operator <=(const ArrayIterator<T>& iterator) const
{
	int index1 = (container && index == -1) ? container->arraySize : index;
	int index2 = (iterator.container && iterator.index == -1) ? iterator.container->arraySize : iterator.index;

	return (container == iterator.container && index1 <= index2);
}

/**
 * Iterator overloaded relational operator >=
 */
template <class T>
bool ArrayIterator<T>::operator >=(const ArrayIterator<T>& iterator) const
{
	int index1 = (container && index == -1) ? container->arraySize : index;
	int index2 = (iterator.container && iterator.index == -1) ? iterator.container->arraySize : iterator.index;

	return (container == iterator.container && index1 >= index2);
}

/**
 * Iterator overloaded pre-increment operator ++
 */
template <class T>
ArrayIterator<T>& ArrayIterator<T>::operator ++()
{
	// Increment iterator to next item in array (do only if not already at end)
	if (container) {
		int index1 = (index == -1) ? container->arraySize : index;
		index = index1 + 1;
		if (index >= container->arraySize)
			index = -1;
	}

	// Return iterator (modified)
	return *this;
}

/**
 * Iterator overloaded post-increment operator ++
 */
template <class T>
ArrayIterator<T> ArrayIterator<T>::operator ++(int)
{
	// Create temporary iterator
	ArrayIterator<T> tempIterator = *this;

	// Increment iterator to next item in array (do only if not already at end)
	if (container) {
		int index1 = (index == -1) ? container->arraySize : index;
		index = index1 + 1;
		if (index >= container->arraySize)
			index = -1;
	}

	// Return temporary iterator (unmodified)
	return tempIterator;
}

/**
 * Iterator overloaded pre-decrement operator --
 */
template <class T>
ArrayIterator<T>& ArrayIterator<T>::operator --()
{
	// Decrement iterator to previous item in array (do only if not already at begin)
	if (container) {
		int index1 = (index == -1) ? container->arraySize : index;
		index = index1 - 1;
		if (index < 0)
			index = 0;
		if (index >= container->arraySize)
			index = -1;
	}

	// Return iterator (modified)
	return *this;
}

/**
 * Iterator overloaded post-decrement operator --
 */
template <class T>
ArrayIterator<T> ArrayIterator<T>::operator --(int)
{
	// Create temporary iterator
	ArrayIterator<T> tempIterator = *this;

	// Decrement iterator to previous item in array (do only if not already at begin)
	if (container) {
		int index1 = (index == -1) ? container->arraySize : index;
		index = index1 - 1;
		if (index < 0)
			index = 0;
		if (index >= container->arraySize)
			index = -1;
	}

	// Return temporary iterator (unmodified)
	return tempIterator;
}

/**
 * Iterator overloaded arithmietic addition assignment operator += (index can be pos/neg)
 */
template <class T>
ArrayIterator<T>& ArrayIterator<T>::operator +=(int index)
{
	// Increment iterator an indexed number of items in array
	if (container) {
		int index1 = (this->index == -1) ? container->arraySize : this->index;
		this->index = index1 + index;
		if (this->index < 0)
			this->index = 0;
		if (this->index >= container->arraySize)
			this->index = -1;
	}

	// Return iterator (modified)
	return *this;
}

/**
 * Iterator overloaded arithmietic subtraction assignment operator -=
 */
template <class T>
ArrayIterator<T>& ArrayIterator<T>::operator -=(int index)
{
	// Decrement iterator an indexed number of items in array
	if (container) {
		int index1 = (this->index == -1) ? container->arraySize : this->index;
		this->index = index1 - index;
		if (this->index < 0)
			this->index = 0;
		if (this->index >= container->arraySize)
			this->index = -1;
	}

	// Return iterator (modified)
	return *this;
}

/**
 * Iterator overloaded arithmietic addition operator +
 */
template <class T>
ArrayIterator<T> ArrayIterator<T>::operator +(int index) const
{
	// Create temporary iterator
	ArrayIterator<T> tempIterator = *this;

	// Increment iterator an indexed number of items from this iterator in array
	if (tempIterator.container) {
		int index1 = (tempIterator.index == -1) ? tempIterator.container->arraySize : tempIterator.index;
		tempIterator.index = index1 + index;
		if (tempIterator.index < 0)
			tempIterator.index = 0;
		if (tempIterator.index >= tempIterator.container->arraySize)
			tempIterator.index = -1;
	}

	// Return temporary iterator
	return tempIterator;
}

/**
 * Iterator overloaded arithmietic subtraction operator -
 */
template <class T>
ArrayIterator<T> ArrayIterator<T>::operator -(int index) const
{
	// Create temporary iterator
	ArrayIterator<T> tempIterator = *this;

	// Decrement iterator an indexed number of items from this iterator in array
	if (tempIterator.container) {
		int index1 = (tempIterator.index == -1) ? tempIterator.container->arraySize : tempIterator.index;
		tempIterator.index = index1 - index;
		if (tempIterator.index < 0)
			tempIterator.index = 0;
		if (tempIterator.index >= tempIterator.container->arraySize)
			tempIterator.index = -1;
	}

	// Return temporary iterator
	return tempIterator;
}

/**
 * Iterator overloaded arithmietic subtraction operator -
 */
template <class T>
int ArrayIterator<T>::operator -(const ArrayIterator<T>& iterator) const throw (std::invalid_argument)
{
	// Determine indexed number of items in array between this iterator and iterator provided
	if (container && iterator.container) {
		int index1 = (index == -1) ? container->arraySize : index;
		int index2 = (iterator.index == -1) ? iterator.container->arraySize : iterator.index;
		return (index1 - index2);
	}

	throw std::invalid_argument("Uninitialized iterator");
}

/**
 * Iterator overloaded dereference operator *
 */
template <class T>
T& ArrayIterator<T>::operator *() const throw (std::out_of_range)
{
	if (container) {
		int index1 = (index == -1) ? container->arraySize : index;
		if (index1 < container->arraySize)
			return container->array[index1];
	}

	throw std::out_of_range("Trying to derefernce outside of array boundaries");
}

/**
 * Iterator overloaded member pointer operator ->
 */
template <class T>
T* ArrayIterator<T>::operator ->() const throw (std::out_of_range)
{
	if (container) {
		int index1 = (index == -1) ? container->arraySize : index;
		if (index1 < container->arraySize)
			return &container->array[index1];
	}

	throw std::out_of_range("Trying to derefernce outside of array boundaries");
}

/**
 * Iterator overloaded array operator []
 */
template <class T>
T& ArrayIterator<T>::operator [](int index) const throw (std::out_of_range)
{
	if (container) {
		int index1 = (this->index == -1) ? container->arraySize : this->index;
		if (index1 + index < container->arraySize)
			return container->array[index1 + index];
	}

	throw std::out_of_range("Trying to derefernce outside of array boundaries");
}

/**
 * Iterator non-member overloaded arithmietic addition operator +
 */
template <class T2>
ArrayIterator<T2> operator +(int index, const ArrayIterator<T2>& iterator)
{
	// Create temporary iterator
	ArrayIterator<T2> tempIterator = iterator;

	// Increment iterator an indexed number of items from this iterator in array
	if (tempIterator.container) {
		int index1 = (tempIterator.index == -1) ? tempIterator.container->arraySize : tempIterator.index;
		tempIterator.index = index1 + index;
		if (tempIterator.index < 0)
			tempIterator.index = 0;
		if (tempIterator.index >= tempIterator.container->arraySize)
			tempIterator.index = -1;
	}

	// Return temporary iterator
	return tempIterator;
}

/**
 * Iterator non-member overloaded arithmietic subtraction operator -
 */
template <class T2>
ArrayIterator<T2> operator -(int index, const ArrayIterator<T2>& iterator)
{
	// Create temporary iterator
	ArrayIterator<T2> tempIterator = iterator;

	// Decrement iterator an indexed number of items from this iterator in array
	if (tempIterator.container) {
		int index1 = (tempIterator.index == -1) ? tempIterator.container->arraySize : tempIterator.index;
		tempIterator.index = index1 - index;
		if (tempIterator.index < 0)
			tempIterator.index = 0;
		if (tempIterator.index >= tempIterator.container->arraySize)
			tempIterator.index = -1;
	}

	// Return temporary iterator
	return tempIterator;
}

/*
	Array default constructor initializes member variables to 0 values
*/
template <class T>
Array<T>::Array() : arrayCapacity(0), arraySize(0) {
	this->array = new T[this->arrayCapacity];
}

/*
	Array copy constructor allows a new instance of the class to be
	initailized with another array class as a parameter.

	@param "list" of type Array
		The class to copy into the new instance of the class
*/
template <class T>
Array<T>::Array(const Array<T>& list) {
	this->array = new T[list.arrayCapacity];

	for(unsigned int i = 0; i < list.arraySize; i++) {
		this->array[i] = list.array[i];
	}

	this->arrayCapacity = list.arrayCapacity;
	this->arraySize = list.arraySize;
}

/*
	Array deconstructor makes sure to de-allocate free memory
*/
template <class T>
Array<T>::~Array() {
	delete[] this->array;
}

/*
	Overloaded array assignment operator allows a new instance of
	the class to be copied into the left side of the equals sign

	@param "list" of type array
		The old instance of the class ready to be assigned
*/
template <class T>
const Array<T>& Array<T>::operator =(const Array<T>& list) {
	if(&list == this) {
		return *this;
	}

	delete[] this->array;
	this->array = new T[list.arrayCapacity];

	for(unsigned int i = 0; i < list.arraySize; i++) {
		this->array[i] = list.array[i];
	}

	this->arrayCapacity = list.arrayCapacity;
	this->arraySize = list.arraySize;

	return *this;
}

/*
	Array index operator overload allows items to be read from
	an index.

	@param "index" of type unsigned int
		The index of the item to read
*/
template <class T>
T Array<T>::operator [](int index) const {
	if(index <= this->arraySize) {
		return this->array[index];
	}
	return T();
}

/*
	Function to return the current size of the array

	@return int
		The size of the array
*/
template <class T>
int Array<T>::size() const {
	return this->arraySize;
}

/*
	Function add allows addition of more items into the class

	@param "item" of type T
		The item to add to the class' internal array
*/
template <class T>
void Array<T>::add(const T& item) {
	this->arraySize++;

	if(this->arraySize > this->arrayCapacity) {
		this->arrayCapacity = this->arraySize + 3;
		T *newArray = new T[this->arrayCapacity];

		for(int i = 0; i < this->arraySize - 1; i++) {
			newArray[i] = this->array[i];
		}
		newArray[this->arraySize - 1] = item;

		delete[] this->array;
		this->array = newArray;

		return;
	}

	this->array[this->arraySize - 1] = item;
}

// Return an iterator to the beginning of the array
template <class T>
ArrayIterator<T> Array<T>::begin() {
	return ArrayIterator<T>(this, 0);
}

// Return an iterator to the end of the array (does not include last item)
template <class T>
ArrayIterator<T> Array<T>::end() {
	return ArrayIterator<T>(this, this->arraySize);
}
