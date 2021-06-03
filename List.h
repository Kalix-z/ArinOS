#pragma once

template<typename obj> class List {
private:
	int itemCount = 0;
public:
	obj* array;
	List() {
		array = new obj[0];
	}

	obj* toarray() {
		return array;
	}

	void Replace(int index, obj item) {
		array[index + 1] = item;
	}


	void Add(obj object) {
		obj* ar = new obj[itemCount + 1];
		itemCount++;
		for (int i = 0; i < itemCount; i++) {
			ar[i] = array[i];
		}
		ar[itemCount] = object;
		array = ar;
	}

	int count() {
		return itemCount;
	}
	obj get(int index) {
		return array[index + 1];
	}
};