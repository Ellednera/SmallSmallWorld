#pragma once
#include <iostream>

#define r return

using namespace std;

typedef struct Position { int x; int y; } Position;
enum e_gameState { ACTIVE, PASSIVE, DESTORYED };

class Object
{
private:
	const char* fOwner;
	unsigned int fID;
	Position fPosition;
	unsigned int fMaxHP;
	unsigned int fCurrentHP;
	unsigned int fMaxEnergy;
	unsigned int fCurrentEnergy;
	e_gameState fGameState;

	string fMessage;

public:
	Object(const char* owner, unsigned int id, int x, int y, \
		unsigned int maxHP, unsigned int currentHP, unsigned int maxEnergy,
		unsigned int currentEnergy, const char* gameState);

	Object();

	~Object();

	const char* getOwner(void);

	void setOwner(const char* newOwner);

	unsigned int getID(void);
	// no setter for fID

	Position getPosition(void);

	void setPosition(int x, int y);

	unsigned int getMaxHP(void);

	void setMaxHP(unsigned int newMaxHP);

	unsigned int getCurrentHP(void);

	void setCurrentHP(unsigned int newCurrentHP);

	unsigned int getMaxEnergy(void);

	void setMaxEnergy(unsigned int newMaxEnergy);

	unsigned int getCurrentEnergy(void);

	void setCurrentEnergy(unsigned int newCurrentEnergy);

	const char* getGameState(void);

	void setGameState(const char* state);

	void virtual displayInfo(void);

	void PingStatus(void);

	void Listen(const char* message);

	void Tell(void);

	friend istream& operator>>(istream& in, Object* object);

	friend ostream& operator<<(ostream& out, Object* object);

};

