#include "InheritancePolymorphism.h"

void simulate_inheritance_polymorphism(void) {
	cout << "___CREATING GENERIC OBJECT___" << endl;
	create_generic_object();
	LINE;

	cout << "___CREATING HUMAN___" << endl;
	create_human();
	LINE;

	cout << "___CREATING HOUSE (WITH HOUSE OWNER)___" << endl;
	create_house();
}

void create_generic_object(void) {
	Object* obj_1 = new Object();

	//obj_1->displayInfo();
	obj_1->PingStatus();

	delete obj_1;
	obj_1 = NULL;
}

void create_human(void) {
	Human* human = new Human();

	//human->displayInfo();
	human->PingStatus();

	delete human;
	human = NULL;
}

void create_house(void) {
	Human* wanEr = new Human("Player", "human_001", 12, 12, 100, 100, 100, 100, "active", "girl", "Wan Er", "Shang Guan", "single");
	House* palace = new House("Player", "house_001", 12, 12, 100, 100, 100, 100, "active", wanEr, true, false, 1, false);

	//palace->displayInfo();
	palace->PingStatus();

	delete wanEr;
	delete palace;

	wanEr = NULL;
	palace = NULL;
}