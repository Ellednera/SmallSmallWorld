#include "Human.h"


Human::Human(const char* owner, unsigned int id, int x, int y, \
	unsigned int maxHP, unsigned int currentHP, unsigned int maxEnergy,
	unsigned int currentEnergy, const char* gameState, \

	const char* gender, const char* firstName, const char* lastName, const char* familyStatus)\
	: Object(owner, id, x, y, maxHP, currentHP, maxEnergy, \
		currentEnergy, gameState) {
	fFirstName = firstName;
	fLastName = lastName;
	fGender = gender; // should use enum, but anyway :)

	setFamilyStatus(familyStatus);
	cout << "`Human` object (" << getID() << ") created..." << endl;
}

Human::Human() {
	fFirstName = "Rose";
	fLastName = "Quartz"; // name taken from Steven Universe :)
	fFamilyStatus = SINGLE;
	fGender = "female";

	cout << "`Human` object (" << getID() << ") created..." << endl;
}

Human::~Human() {
	cout << "`Human` object (" << getID() << ") destroyed..." << endl;
}

const char* Human::getFirstName(void) {
	r fFirstName;
}

void Human::setFirstName(const char* firstName) {
	fFirstName = firstName;
}

const char* Human::getLastName(void) {
	r fLastName;
}

void Human::setLastName(const char* lastName) {
	fLastName = lastName;
}

const char* Human::getGender(void) {
	r fGender;
}
void Human::setGender(const char* gender) {
	fGender = gender;
}

const char* Human::getFamilyStatus(void) {
	if (fFamilyStatus == SINGLE) {
		r "single";
	}
	else if (fFamilyStatus == MARRIED) {
		r "married";
	}
}

/// <summary>
/// Sets the family status. Support values are "single" and "married". Defualts to "single"
/// </summary>
/// <param name="familyStatus"></param>
void Human::setFamilyStatus(const char* familyStatus) {
	if (familyStatus == "single") {
		fFamilyStatus = SINGLE;
	}
	else if (familyStatus == "married") {
		fFamilyStatus = MARRIED;
	}
	else {
		fFamilyStatus = SINGLE;
	}
}

void Human::displayInfo(void) {
	cout << "Object owner: " << getOwner() << endl;
	cout << "Object ID: " << getID() << endl;

	cout << "->Name (First Last): " << getFirstName() << " " << getLastName() << endl;
	cout << "->Gender: " << getGender() << endl;
	cout << "->Family Status: " << getFamilyStatus() << endl;

	cout << "->Position: (" << getPosition().x \
		<< "," << getPosition().y << ")" << endl;
	cout << "->Max HP: " << getMaxHP() << endl;
	cout << "->Current HP: " << getCurrentHP() << endl;
	cout << "->Max Energy: " << getMaxEnergy() << endl;
	cout << "->Current Energy: " << getCurrentEnergy() << endl;
	cout << "->Game State: " << getGameState() << endl;

}