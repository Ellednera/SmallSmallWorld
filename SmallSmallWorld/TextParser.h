#pragma once
#include <iostream>

using namespace std;

void runEngine(const char* prompt, bool verbose);

void readText(const char* prompt);

char** getFinalizedCommands(void);

char** parseText(const char* text);

char* processSubText(int i, int* next_space_index);

int getTotalWords(const char* text);

void registerSubCommands(const char* sub_text, char** split_texts, int index);

void finalizeSubCommands(char** split_texts, int index);