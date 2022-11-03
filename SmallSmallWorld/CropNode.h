#pragma once

#include "Crop.h"

class CropNode {
private:
	Crop* crop_ptr;
	CropNode* next_crop_node_ptr = NULL;

public:
	CropNode(Crop* crop);
	~CropNode();

	Crop* getCrop(void);
	void setCrop(Crop* crop);

	CropNode* getNextCropNode(void);
	void setNextCropNode(CropNode* crop);
};