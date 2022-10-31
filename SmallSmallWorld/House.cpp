#include "House.h"

House::House(const char* owner, const char* id, int x, int y, \
	unsigned int maxHP, unsigned int currentHP, unsigned int maxEnergy,
	unsigned int currentEnergy, const char* gameState, \
	Human* houseOwner, bool ownerIn, bool doorOpened, int totalResidents, bool lightsOn) : \
	Object(owner, id, x, y, maxHP, currentHP, maxEnergy, currentEnergy, gameState) {

	fHouseOwner_ptr = houseOwner;
	fOwnerIn = ownerIn;
	fDoorOpened = doorOpened;
	fTotalResidents = totalResidents;
	fLightsOn = lightsOn;

	cout << "`House` object (" << getID() << ") created..." << endl;
}

House::House() {
	fHouseOwner_ptr = NULL; // very problematic :)
	fOwnerIn = false;
	fDoorOpened = false;
	fTotalResidents = 0; // no one owns this house, also assume no wild animals
	fLightsOn = false;

	cout << "`House` object (" << getID() << ") created..." << endl;
}

House::~House() {
	cout << "`House` object (" << getID() << ") destroyed..." << endl;
}

Human* House::getHouseOwner(void) {
	r fHouseOwner_ptr;
}

void House::setHouseOwner(Human* newOwner) {
	// this should be illegal :)
	fHouseOwner_ptr = newOwner;
}

bool House::get_isOwnerIn(void) {
	r fOwnerIn;
}

void House::set_isOwnerIn(bool ownerIn) {
	fOwnerIn = ownerIn;
}

bool House::get_isDoorOpened(void) {
	r fDoorOpened;
}

void House::set_isDoorOpened(bool doorOpened) {
	fDoorOpened = doorOpened;
}


int House::getTotalResidents(void) {
	r fTotalResidents;
}

void House::setTotalResidents(int total) {
	// not to be called by the user!
	fTotalResidents = total;
}

bool House::get_isLightsOn(void) {
	r fLightsOn;
}

void House::set_isLightsOn(bool lightsOn) {
	fLightsOn = lightsOn;
}

void House::displayInfo(void) {
	cout << "Object owner: " << getOwner() << endl;
	cout << "Object ID: " << getID() << endl;
	cout << "->Position: (" << getPosition().x \
		<< "," << getPosition().y << ")" << endl;
	cout << "->Max HP: " << getMaxHP() << endl;
	cout << "->Current HP: " << getCurrentHP() << endl;
	cout << "->Max Energy: " << getMaxEnergy() << endl;
	cout << "->Current Energy: " << getCurrentEnergy() << endl;
	cout << "->Game State: " << getGameState() << endl;

	cout << "->House Owner: " << fHouseOwner_ptr->getFirstName() << "(" << fHouseOwner_ptr << ")" << endl;
	cout << "->Owner in? " << get_isOwnerIn() << endl;
	cout << "->Total residents: " << getTotalResidents() << endl;
	cout << "->Door opened? " << get_isDoorOpened() << endl;
	cout << "->Lights on? " << get_isDoorOpened() << endl;
}