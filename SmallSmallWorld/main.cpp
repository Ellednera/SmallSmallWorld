#include <iostream>
#include <stdlib.h>

#include "TextParser.h"
#include "InheritancePolymorphism.h"
#include "SinglyLinkedList.h"

using namespace std;

//unsigned int exitCode = 0; // not working
unsigned int uid = 1;
Object* objects_collection[20] = { NULL };

enum e_spot { FLOATING, FARM, FACTORY, DELIVERY_CENTER };
bool canLeaveCurrentSpot = false; // for farm, factory and delivery center
e_spot currentSpot = FLOATING;


void printWelcomeBanner(void);
void initializeEverything(void);

int main() {
	
	printWelcomeBanner();
	CropsListSingle* crop_list = initialise_partial_list();
	
	while ("this small small world is operating...") {
		
		runEngine("Command: ", false);
		char** parsedCommands = getFinalizedCommands();

		if (parsedCommands == NULL) {
			printf("No commands\n");
		}

		int count = 0;
		for (int i = 0; parsedCommands[i] != NULL; i++) {
			count++;
		}

		printf("Total sub commands: %d\n", count);
		
		// command checking and response
		if (count == 2) {
			//printf("2 words command\n");
			if (strcmp(parsedCommands[0], "hello") == 0 && strcmp(parsedCommands[1], "world") == 0) {
				printf("Executing `hello world`...\n");
			}
			else if (strcmp(parsedCommands[0], "visit") == 0 && strcmp(parsedCommands[1], "farm") == 0) {
				// location set to (-250, -100), might be useless :)
				printf("You're at the farm\n");
				canLeaveCurrentSpot = true;
				currentSpot = FARM;
			}
			else if (strcmp(parsedCommands[0], "visit") == 0 && strcmp(parsedCommands[1], "factory") == 0) {
				// location set to (0, 0), might be useless :)
				printf("You're at the factory\n");
				canLeaveCurrentSpot = true;
				currentSpot = FACTORY;
			}
			else if (strcmp(parsedCommands[0], "visit") == 0 && strcmp(parsedCommands[1], "delivery_center") == 0) {
				// location set to (50, -25), might be useless :)
				printf("You're at the delivery center\n");
				canLeaveCurrentSpot = true;
				currentSpot = DELIVERY_CENTER;
			}
			else if (strcmp(parsedCommands[0], "test") == 0 && strcmp(parsedCommands[1], "crops") == 0) {
				// only allow in the farm
				if (currentSpot == FARM) {
					test_crop();
				}
				else {
					printf("You can only do this in the farm\n");
				}
			}
			else if (strcmp(parsedCommands[0], "inspect") == 0 && strcmp(parsedCommands[1], "crops") == 0) {
				// only allow in the farm
				if (currentSpot == FARM) {
					if ( crop_list == NULL ) {
						crop_list = initialise_partial_list();
					}
					inspect_crops(crop_list);
				}
				else {
					printf("You can only do this in the farm\n");
				}
			}
			else if (strcmp(parsedCommands[0], "purge") == 0 && strcmp(parsedCommands[1], "farm") == 0) {
				// only allow in the farm
				if (currentSpot == FARM) {
					purge_farm(&crop_list);
				}
				else {
					printf("You can only do this in the farm\n");
				}
			}
			else if (strcmp(parsedCommands[0], "simulate") == 0 && strcmp(parsedCommands[1], "farm") == 0) {
				Crop* carrot = new Crop("Computer", "carrot", uid++, 1, 1, 100, 100, 100, 100, "active", false);
				Crop* apple = new Crop("Computer", "apple", uid++, 1, 1, 100, 100, 100, 100, "active", false);
				Crop* banana = new Crop("Computer", "banana", uid++, 1, 1, 100, 100, 100, 100, "active", false);
				Crop* orange = new Crop("Computer", "orange", uid++, 1, 1, 100, 100, 100, 100, "active", false);
				Crop* peach = new Crop("Computer", "peach", uid++, 1, 1, 100, 100, 100, 100, "active", false);

				// for planting as head
				CropNode* carrot_node = new CropNode(carrot);
				CropNode* apple_node = new CropNode(apple);
				// for planting as tail
				CropNode* banana_node = new CropNode(banana);
				CropNode* orange_node = new CropNode(orange);
				// for random insertion
				CropNode* peach_node = new CropNode(peach);

				system("pause");

				cout << "Adding carrot at head..." << endl;
				plant_crop_node_as_head(&crop_list, carrot_node);
				cout << "Adding apple at head..." << endl;
				plant_crop_node_as_head(&crop_list, apple_node);

				cout << "Adding banana at tail..." << endl;
				plant_crop_node_as_tail(&crop_list, banana_node);
				cout << "Adding orange at tail..." << endl;
				plant_crop_node_as_tail(&crop_list, orange_node);

				cout << "Adding peach at location 4..." << endl;
				plant_crop_node_at(&crop_list, peach_node, 4);

				cout << "Press enter to inspect crops..." << endl;
				system("pause");

				inspect_crops(crop_list);

				cout << "Press enter to purge all the crops..." << endl;
				system("pause");
				purge_farm(&crop_list);
				crop_list = NULL;
			}
		}
		else if (count == 1) {
			if (strcmp(parsedCommands[0], "q") == 0) {
				if ( crop_list != NULL ) {
					purge_farm(&crop_list);
				}
				break;
			}
			else if (strcmp(parsedCommands[0], "cls") == 0) {
				system("cls");
			}
			else if (strcmp(parsedCommands[0], "leave") == 0) {

				if (canLeaveCurrentSpot) {
					if (currentSpot == FARM) {
						printf("You left the farm\n");
					}
					else if (currentSpot == FACTORY) {
						printf("You left the factory\n");
					}
					else if (currentSpot == DELIVERY_CENTER) {
						printf("You left the delivery center\n");
					}
					currentSpot = FLOATING;
					canLeaveCurrentSpot = false;
				}
				else {
					printf("This command is only useful in the farm, factory or delivery center\n");
				}
			}
		}
		else if (count == 4) {
			// simulate class -inheritance -polymorphism :)
			if (strcmp(parsedCommands[0], "simulate") == 0 && strcmp(parsedCommands[1], "class") == 0 \
				&& strcmp(parsedCommands[2], "-inheritance") == 0 && strcmp(parsedCommands[3], "-polymorphism") == 0) {
				simulate_inheritance_polymorphism();
			}

		}
		else if (count == 6) {
			// use human <object_id | human_id> visit <x> <y> 
			if (strcmp(parsedCommands[0], "use") == 0 && strcmp(parsedCommands[1], "human") == 0 \
				&& strcmp(parsedCommands[3], "visit") == 0) {
				// find human id parsedCommand[1] from link list
				// modify position
				// for simplicity sake, just use the input id to create a new human :)
				int human_id = atoi(parsedCommands[2]);
				
				Human* jasmine = new Human("Player", human_id, 15, 15, 100, 100, 100, 100, "active", "female", "Jasmine", "Tan", "single");

				cout << "Original position: (" << jasmine->getPosition().x << ","<< jasmine->getPosition().y << ")" << endl;

				int x = atoi(parsedCommands[4]);
				int y = atoi(parsedCommands[5]);
				jasmine->setPosition(x, y);


				cout << "New position: (" << jasmine->getPosition().x << "," << jasmine->getPosition().y << ")" << endl;

				delete jasmine;
				jasmine = NULL;
			}
		}
		else if (count == 7) {
		// buggy
		// do this: plant tail once, then head once, purge
			if (strcmp(parsedCommands[0], "plant") == 0 && strcmp(parsedCommands[1], "new") == 0 && strcmp(parsedCommands[2], "crop") == 0 \
				&& strcmp(parsedCommands[5], "at") == 0 && strcmp(parsedCommands[6], "tail") == 0) {
				
				plant_crop_as_tail(&crop_list, atoi(parsedCommands[3]), parsedCommands[4]);

			}
			else if (strcmp(parsedCommands[0], "plant") == 0 && strcmp(parsedCommands[1], "new") == 0 && strcmp(parsedCommands[2], "crop") == 0 \
				&& strcmp(parsedCommands[5], "at") == 0 && strcmp(parsedCommands[6], "head") == 0) {
				
				plant_crop_as_head(&crop_list, atoi(parsedCommands[3]), parsedCommands[3]);
				
			}
		}
		// free the text parser array
		for (int i = 0; i < count; i++) {
			free(parsedCommands[i]);
			//cout << parsedCommands[i] << endl;
		}
		// free(parsedCommands[i]); // errors, strange

		/*
		// https://www.geeksforgeeks.org/dynamically-allocate-2d-array-c/
		int maxWordLength = 15;
		// do checking for individual split word, if > maxWordLength => command not supported
		char** split_texts = (char**)malloc( sizeof(char*) );
		split_texts[0] = (char*)malloc( maxWordLength * sizeof(char*) + 1 );
		strcpy_s(split_texts[0], maxWordLength+1, "hello");

		printf( "%s\n", split_texts[0]);
		*/
	}


	return 10;
}

void printWelcomeBanner(void) {
	cout << "Welcome to Small Small World~" << endl;
}