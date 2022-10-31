#pragma once
#include <iostream>

#include "Object.h"

#define r return

enum e_family_status { SINGLE, MARRIED };

class Human : public Object {
private:
	const char* fFirstName;
	const char* fLastName;
	const char* fGender;
	e_family_status fFamilyStatus;

public:
	Human(const char* owner, const char* id, int x, int y, \
		unsigned int maxHP, unsigned int currentHP, unsigned int maxEnergy,
		unsigned int currentEnergy, const char* gameState, const char* gender, \
		const char* firstName, const char* lastName, const char* familyStatus);
	Human();
	~Human();

	const char* getFirstName(void);
	void setFirstName(const char* firstName);

	const char* getLastName(void);
	void setLastName(const char* lastName);

	const char* getGender(void);
	void setGender(const char* gender);

	const char* getFamilyStatus(void);
	void setFamilyStatus(const char* familyStatus);

	void displayInfo(void) override;

};