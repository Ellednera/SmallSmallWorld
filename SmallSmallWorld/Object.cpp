#include "Object.h"

Object::Object(const char* owner, const char* id, int x, int y, \
	unsigned int maxHP, unsigned int currentHP, unsigned int maxEnergy,
	unsigned int currentEnergy, const char* gameState) {

	fOwner = owner;
	fID = id;
	fPosition = { x, y };
	fMaxHP = maxHP;
	fCurrentHP = currentHP;
	fMaxEnergy = maxEnergy;
	fCurrentEnergy = currentEnergy;

	setGameState(gameState); // this function is very nice :)

	fMessage = "Hello";

	cout << "Generic(Base) object `Object` (" << fID << ") created..." << endl;

}

Object::Object() {
	fOwner = "Computer?";
	fID = "001?";
	fPosition = { 0, 0 };

	fMaxHP = 100;
	fCurrentHP = 100;

	fMaxEnergy = 500;
	fCurrentEnergy = 500;

	fGameState = ACTIVE;

	fMessage = "Hello";

	cout << "Generic(Base) object `Object` (" << fID << ") created..." << endl;
}

Object::~Object() {
	cout << "Generic(Base) object `Object` (" << fID << ") destroyed..." << endl;
}

const char* Object::getOwner(void) {
	r fOwner;
}

void Object::setOwner(const char* newOwner) {
	fOwner = newOwner;
}

const char* Object::getID(void) {
	r fID;
}
// not setter for fID

Position Object::getPosition(void) {
	r fPosition;
}

void Object::setPosition(int x, int y) {
	fPosition.x = x;
	fPosition.y = y;
}

unsigned int Object::getMaxHP(void) {
	r fMaxHP;
}

void Object::setMaxHP(unsigned int newMaxHP) {
	fMaxHP = newMaxHP;
}

unsigned int Object::getCurrentHP(void) {
	r fCurrentHP;
}

void Object::setCurrentHP(unsigned int newCurrentHP) {
	fCurrentHP = newCurrentHP;
}

unsigned int Object::getMaxEnergy(void) {
	r fMaxEnergy;
}

void Object::setMaxEnergy(unsigned int newMaxEnergy) {
	fMaxEnergy = newMaxEnergy;
}

unsigned int Object::getCurrentEnergy(void) {
	r fCurrentEnergy;
}

void Object::setCurrentEnergy(unsigned int newCurrentEnergy) {
	fCurrentEnergy = newCurrentEnergy;
}

const char* Object::getGameState(void)
{
	if (fGameState == ACTIVE) {
		r "active";
	}
	else if (fGameState == PASSIVE) {
		r "passive";
	}
	else {
		r "destroyed";
	}
}

/// <summary>
/// Sets the game state of the object.
/// Supported strings are "active", "passive" and "destroyed" only!
/// If `state` is not recognised, defaults to 'destroyed'
/// </summary>
/// <param name="state"></param>
void Object::setGameState(const char* state)
{
	if (state == "active") {
		fGameState = ACTIVE;
	}
	else if (state == "passive") {
		fGameState = PASSIVE;
	}
	else if (state == "destroyed") {
		fGameState = DESTORYED;
	}
	else {
		fGameState = DESTORYED;
	}
}

void Object::displayInfo(void) {
	cout << "Object owner: " << getOwner() << endl;
	cout << "Object ID: " << getID() << endl;
	cout << "->Position: (" << getPosition().x \
		<< "," << getPosition().y << ")" << endl;
	cout << "->Max HP: " << getMaxHP() << endl;
	cout << "->Current HP: " << getCurrentHP() << endl;
	cout << "->Max Energy: " << getMaxEnergy() << endl;
	cout << "->Current Energy: " << getCurrentEnergy() << endl;
	cout << "->Game State: " << getGameState() << endl;
}

void Object::PingStatus(void) {
	displayInfo();
}

void Object::Listen(const char* message) {
	fMessage = message;
}

void Object::Tell(void) {
	cout << fMessage << endl;
}

istream& operator>>(istream& in, Object* object) {
	in >> object->fMessage;

	return in;
}

ostream& operator<<(ostream& out, Object* object) {
	out << object->fMessage;

	return out;
}
