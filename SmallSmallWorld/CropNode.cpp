#include "CropNode.h"

CropNode::CropNode(Crop* crop) {
	this->crop_ptr = crop;
}

CropNode::~CropNode() {
	delete this->crop_ptr;
}

Crop* CropNode::getCrop(void) {
	return this->crop_ptr;
}

void CropNode::setCrop(Crop* crop) {
	this->crop_ptr = crop;
}

CropNode* CropNode::getNextCropNode(void) {
	return this->next_crop_node_ptr;
}

void CropNode::setNextCropNode(CropNode* crop) {
	this->next_crop_node_ptr = crop;
}