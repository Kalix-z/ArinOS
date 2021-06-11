#pragma once
#include "Color.h"
template<typename obj> class List {
public:
	/* Amount of objects in the list */
	int count = 0;
	/* the array */
	obj* array = nullptr;
	/* Dynamically Resizing Array */
	List() {
		array = nullptr;
	}
	/* Replaces the object at index with the new object specified */
	void Replace(int index, obj item) {
		array[index + 1] = item;
		count = 0;
	}

	/* Adds Object at the End of The List */
	void Add(obj object) {
		obj* ar = new obj[count + 1];

		int i =0;
		for (; i < count; i++) {
			ar[i] = array[i];
		}
		ar[i] = object;
		count++;
		delete [] array;
		array = ar;
	}
	/* Removes Last Object In The List */
	void RemoveLast() {
		if(count-1 < 0) {
			Printf("ERROR\n", Red);
		}
		obj* tempArray = new obj[count - 1];
		count--;
		for (int i = 0; i < count; i++) {
			tempArray[i] = array[i];
		}
		delete [] array;
		array = tempArray;
		
	}

	/* Gets the object at the specified index */
	obj get(int index) {
		return array[index];
	}
	/* Resets List */
	void Clear() {
		delete [] array;
		array = nullptr;
		count = 0;
	}
};