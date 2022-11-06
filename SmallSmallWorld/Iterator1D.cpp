#include "Iterator1D.h"

using namespace std;

Iterator1D::Iterator1D(const char* array[], int size) {
	data = array;
	currentIndex = 0;
	this->size = size;

	//cout << array[0] << endl;
}

int Iterator1D::getCurrentIndex(void) {
	return currentIndex;
}

void Iterator1D::resetIndex(void) {
	currentIndex = 0;
}

Iterator1D Iterator1D::operator++(int) {
	if (currentIndex < size - 1) {
		(this->currentIndex)++;
	}
	else {
		this->currentIndex = 0; // reset, for fun :)
	}

	return *this;
}

Iterator1D Iterator1D::operator--(int) {
	if (currentIndex > 0) {
		(this->currentIndex)--;
	}
	else {
		this->currentIndex = (size - 1); // for fun :)
	}

	return *this;
}

bool Iterator1D::operator==(Iterator1D* another) {
	return this->currentIndex == another->currentIndex;
}

const char* Iterator1D::operator*(void) {
	return data[currentIndex];
}
