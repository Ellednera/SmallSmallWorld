#pragma once

#include <iostream>

class Iterator1D {
private:
	const char** data;
	int currentIndex;
	int size;

public:
	Iterator1D(const char* array[], int size);

	int getCurrentIndex(void);
	void resetIndex(void);

	Iterator1D operator++(int);  // i++ style
	Iterator1D operator--(int);
	bool operator==(Iterator1D* another);
	const char* operator*(void);

};