#include <iostream>
#include <stdlib.h>

#include "TextParser.h"
#include "InheritancePolymorphism.h"

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
		}
		else if (count == 1) {
			if (strcmp(parsedCommands[0], "q") == 0) {
				//exitCode = 10; // very problematic
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
				}
				else {
					printf("This command is only useful when you're in the farm, factory or delivery center\n");
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