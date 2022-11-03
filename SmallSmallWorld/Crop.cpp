#include "Crop.h"

Crop::Crop(const char* owner, const char* crop_name, unsigned int id, int x, int y, \
	unsigned int maxHP, unsigned int currentHP, unsigned int maxEnergy, \
	unsigned int currentEnergy, const char* gameState, bool is_ripe) : \
	Object(owner, id, x, y, maxHP, currentHP, maxEnergy, currentEnergy, gameState) {

	this->crop_name = crop_name;
	this->is_ripe = is_ripe;
	cout << "`Crop` object (" << getID() << ") created..." << endl;
}

Crop::Crop() {
	this->crop_name = "carrot";
	this->is_ripe = false;
}

Crop::~Crop() {
	cout << "`Crop` object (" << getID() << ") destroyed..." << endl;
}


const char* Crop::getCropName(void) {
	return this->crop_name;
}

void Crop::setCropName(const char* new_name) {
	this->crop_name = new_name;
}

bool Crop::getIsRipe(void) {
	return this->is_ripe;
}

void Crop::setIsRipe(bool is_ripe) {
	this->is_ripe = is_ripe;
}

void Crop::displayInfo(void) {
	cout << "Object owner: " << getOwner() << endl;
	cout << "Object ID: " << getID() << endl;
	cout << "->Position: (" << getPosition().x \
		<< "," << getPosition().y << ")" << endl;
	cout << "->Max HP: " << getMaxHP() << endl;
	cout << "->Current HP: " << getCurrentHP() << endl;
	cout << "->Max Energy: " << getMaxEnergy() << endl;
	cout << "->Current Energy: " << getCurrentEnergy() << endl;
	cout << "->Game State: " << getGameState() << endl;

	cout << "->Crop name: " << getCropName() << endl;
	cout << "->Is ripe? " << getIsRipe() << endl;
}