#pragma once

#include "CropNode.h"

#define MAX_CROPS 12

// ignore classes to make life easier :)
// assume only one row of crop

typedef struct crops_singly_link_list {
	CropNode* head;
	CropNode* tail;
	int total_crops;
	int middle; // for optimization

} CropsListSingle;

CropsListSingle* initialise_partial_list(void);

// helper functions
bool is_empty(CropsListSingle* list);
bool is_full(CropsListSingle* list);
Crop* get_head_crop(CropsListSingle* list); // returning an actual Crop object
Crop* get_tail_crop(CropsListSingle* list); // returning an actual Crop object

void inspect_crops(CropsListSingle* list);

// no modification of crop data, makes no sense :)
void plant_crop_as_head(CropsListSingle* list, unsigned int crop_id);
void plant_crop_as_tail(CropsListSingle* list, unsigned int crop_id);
void plant_crop_at(CropsListSingle* list, unsigned int crop_id, int location);

// for list manipulation, to make life easier
CropNode* find_crop_node(CropsListSingle* list, unsigned int crop_id);
void plant_crop_node_as_head(CropsListSingle* list, CropNode* crop_node);
void plant_crop_node_as_tail(CropsListSingle** list, CropNode* crop_node);
void plant_crop_node_at(CropsListSingle* list, CropNode* crop_node, int location);

// for reading data only
Crop* find_crop(CropsListSingle* list, unsigned int crop_id);
Crop* find_crop_increased_chance(CropsListSingle* list, unsigned int crop_id); // last to do

// plants at the right side of the located crop
void replant_crop(CropsListSingle* list, unsigned int crop_id, int new_location); // find_crop_node() + plant_crop_node_at()

void purge_crop(CropsListSingle* list, unsigned int crop_id);
void purge_farm(CropsListSingle** list);
