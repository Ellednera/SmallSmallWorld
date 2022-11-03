#pragma once
#include "Object.h"
#include "Human.h"


class House : public Object {
private:
	Human* fHouseOwner_ptr;
	bool fOwnerIn;
	bool fDoorOpened;
	unsigned int fTotalResidents;
	bool fLightsOn;

public:
	House(const char* owner, unsigned int id, int x, int y, \
		unsigned int maxHP, unsigned int currentHP, unsigned int maxEnergy,
		unsigned int currentEnergy, const char* gameState, \
		Human* houseOwner, bool ownerIn, bool doorOpened, int totalResidents, bool lightsOn);
	House();
	~House();

	Human* getHouseOwner(void);
	void setHouseOwner(Human* newOwner); // this should be illegal :)

	bool get_isOwnerIn(void);
	void set_isOwnerIn(bool ownerIn);

	bool get_isDoorOpened(void);
	void set_isDoorOpened(bool doorOpened);

	int getTotalResidents(void);
	void setTotalResidents(int total); // not to be called by the user!

	bool get_isLightsOn(void);
	void set_isLightsOn(bool lightsOn);

	void displayInfo(void) override;
};