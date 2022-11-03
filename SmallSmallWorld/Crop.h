#pragma once
#include "Object.h"

class Crop : public Object {
private:
	const char* crop_name;
	bool is_ripe;

public:
	Crop(const char* owner, const char* crop_name, unsigned int id, int x, int y, \
		unsigned int maxHP, unsigned int currentHP, unsigned int maxEnergy,
		unsigned int currentEnergy, const char* gameState, bool is_ripe);
	Crop();
	~Crop();

	const char* getCropName(void);
	void setCropName(const char* new_name);

	bool getIsRipe(void);
	void setIsRipe(bool is_ripe);

	void displayInfo(void) override;
};