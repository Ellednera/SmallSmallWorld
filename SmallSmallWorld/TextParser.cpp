#include "TextParser.h"

#define MAX_INPUT_TEXT_LENGTH 100
#define MAX_SUB_TEXT_LENGTH 15

char text[MAX_INPUT_TEXT_LENGTH] = "";
char** split_texts = (char**)malloc(sizeof(char*));
const char* prompt = NULL;
bool verbosity = false;

void runEngine(const char* prompt, bool verbose) {
	verbosity = verbose;
	readText(prompt);
}

void readText(const char* prompt) {

	printf("%s", prompt);
	gets_s(text);

	parseText(text);
}

char** getFinalizedCommands(void) {
	return split_texts; // a copy only
}

char** parseText(const char* text) {
	if (verbosity)
		cout << "Text to parse: " << text << endl;

	int next_space_index = 0;
	int total_words = getTotalWords(text);
	int total_sub_text_to_register = 0; // used as index for regiterSubCommands()

	if (verbosity)
		printf("total words=%d\n", total_words);

	for (int i = 0; i <= MAX_INPUT_TEXT_LENGTH; i++) {
		//printf("%c", text[i]); // output for debugging

		if (text[i] == '\0') {

			char* sub_text = processSubText(i, &next_space_index);
			registerSubCommands(sub_text, split_texts, total_sub_text_to_register++);

			// add a dummy value at the end of array
			finalizeSubCommands(split_texts, total_sub_text_to_register++);

			if (verbosity) {
				if (split_texts[total_sub_text_to_register - 1] == NULL) {
					printf("Last item of finalized commands is NULL\n");
				}

				printf("Only used %d/%d chars\n", i, MAX_INPUT_TEXT_LENGTH);
				printf("Highest index of last char: %d\n", i - 1);
			}

			// input consists '\0', stop the remaining (MAX_TEXT_LENGTH - next_space_index) being parsed
			//break; 
			return split_texts;

		}
		else if (text[i] == ' ') {
			char* sub_text = processSubText(i, &next_space_index);
			registerSubCommands(sub_text, split_texts, total_sub_text_to_register++);
		}

	}
}

char* processSubText(int end_of_subtext, int* next_space_index) {

	char* sub_text = (char*)malloc(end_of_subtext - *next_space_index + 1);
	for (int letter = 0; letter < end_of_subtext - *next_space_index; letter++) {
		*(sub_text + letter) = text[*next_space_index + letter];
	}
	*(sub_text + (end_of_subtext - *next_space_index)) = '\0';

	if (verbosity)
		printf("Subtext: %s\n", sub_text);

	*next_space_index = end_of_subtext + 1; // +1 will get rid of the space

	return sub_text;
}

int getTotalWords(const char* text) {
	int totalSpaces = 0;

	for (int i = 0; i < MAX_INPUT_TEXT_LENGTH; i++) {
		if (text[i] != '\0') {
			if (text[i] == ' ') {
				totalSpaces++;
			}
		}
		else {
			return (totalSpaces + 1);
		}
	}

	return (totalSpaces + 1);
}

void registerSubCommands(const char* sub_text, char** split_texts, int index) {
	if (verbosity)
		printf("registering command #%d...", index);

	split_texts[index] = (char*)malloc(MAX_SUB_TEXT_LENGTH * sizeof(char*) + 1);
	strcpy_s(split_texts[index], MAX_SUB_TEXT_LENGTH + 1, sub_text);

	if (verbosity)
		printf("Done!\n\n");
}

void finalizeSubCommands(char** split_texts, int index) {
	if (verbosity)
		printf("finalizing...adding NULL at #%d...", index);

	split_texts[index] = NULL;

	if (verbosity)
		printf("Done!\n\n");
}