#pragma once

#include "Crop.h"

#define MAX_CROPS 12

// ignore classes to make life easier :)
// assume only one row of crop

typedef struct {
	Crop* crop_ptr;
	Crop* next_crop = NULL;
} CropNode;

typedef struct {
	CropNode* head;
	CropNode* tail;
	int total_crops;
	int middle = MAX_CROPS / 2; // for optimization

} CropsListSingle;

// helper functions
bool is_empty(CropsListSingle list);
bool is_full(CropsListSingle list);
Crop* get_head_crop(CropsListSingle list); // returning an actual Crop object
Crop* get_tail_crop(CropsListSingle list); // returning an actual Crop object

// no modification of crop data, makes no sense :)
void plant_crop_as_head(unsigned int crop_id);
void plant_crop_as_tail(unsigned int crop_id);
void plant_crop_at(unsigned int crop_id, int location);

// for list manipulation, to make life easier
CropNode* find_crop_node(unsigned int crop_id);
void plant_crop_node_at(unsigned int crop_id, int location);

// for reading data only
Crop* find_crop(unsigned int crop_id);
Crop* find_crop_increased_chance(unsigned int crop_id); // last to do

// plants at the right side of the located crop
void replant_crop(unsigned int crop_id, int new_location); // find_crop_node() + plant_crop_node_at()

void purge_crop(unsigned int crop_id);
void purge_farm(void);
