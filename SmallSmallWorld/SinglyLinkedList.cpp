#include "SinglyLinkedList.h"

CropsListSingle* initialise_partial_list(void) {
	// for fun
	const char* available_crops[10] = {\
		"carrot", "cabbage", "corn", "lettuce", "green beans", \
		"bringle", "tomato", "peanuts", "wheat", "barley"\
	};
	// default create 7 objects, id in order, in main change to universal id
	int crop_id = 300;
	int row_number = 1;
	int column_number = 1;
	int space = 3;

	Crop* crop;
	
	CropsListSingle* crops_sll = (CropsListSingle*) malloc( sizeof(CropsListSingle) );
	//crops_sll->head = NULL;
	//crops_sll->tail = NULL;
	crops_sll->total_crops = 0;
	crops_sll->middle = 0;

	for (int i = 0; i < 7; i++) {
		crop = new Crop("Computer", available_crops[rand() % 10], crop_id++, row_number, column_number, \
		50, 50, 50, 50, "active", false);

		CropNode* crop_node = new CropNode(crop);		

		//plant_crop_node_as_tail(&crops_sll, crop_node);
		plant_crop_node_as_head(&crops_sll, crop_node);
	}
	
	return crops_sll;
}

bool sll_is_empty(CropsListSingle* list) {
	return list->total_crops == 0;
}

bool sll_is_full(CropsListSingle* list) {
	return list->total_crops == MAX_CROPS;
}

void inspect_crops(CropsListSingle* list) {
	CropNode* current_node = list->head;

	while (current_node != NULL) {
		cout << "Crop #" << current_node->getCrop()->getID();
		cout << " is " << current_node->getCrop()->getCropName() << endl;
		current_node = current_node->getNextCropNode();
	}
}

Crop* find_crop(CropsListSingle** list, unsigned int crop_id) {
	if ( sll_is_empty(*list) )
		return NULL;

	CropNode* found = (*list)->head;
	while ( found && (found->getCrop()->getID() != crop_id) ) {

		found = found->getNextCropNode();
	}

	return found->getCrop();
}

void plant_crop_as_head(CropsListSingle** list, unsigned int crop_id, const char* crop_name) {
	Crop* crop = new Crop("Player", crop_name, crop_id, 5, 5, 50, 50, 50, 50, "active", false);
	CropNode* node = new CropNode(crop);

	plant_crop_node_as_head(list, node);
}

void plant_crop_as_tail(CropsListSingle** list, unsigned int crop_id, const char* crop_name) {
	//cout << "Ready to plant " << crop_name << " at tail" << endl;
	Crop* crop = new Crop("Player", crop_name, crop_id, 5, 5, 50, 50, 50, 50, "active", false);
	CropNode* node = new CropNode(crop);
	//cout << node->getCrop()->getCropName() << endl;

	plant_crop_node_as_tail(list, node);
}

void plant_crop_node_as_head(CropsListSingle** list, CropNode* crop_node) {
	if (sll_is_full(*list))
		return;

	if ( sll_is_empty(*list) ) {
		(*list)->head = (*list)->tail = crop_node;
	}
	else {
		crop_node->setNextCropNode( (*list)->head );
		(*list)->head = crop_node;
	}

	(*list)->total_crops++;
}

void plant_crop_node_as_tail(CropsListSingle** list, CropNode* crop_node) {
	//cout << crop_node->getCrop()->getCropName() << endl;
	if ( (*list)->total_crops == MAX_CROPS )
		return;
	
	if ((*list)->total_crops == 0 ) { // same thing as (*list)->head == NULL
		(*list)->head = crop_node;
		(*list)->tail = crop_node;
	}
	else {
		// append to the back
		(*list)->tail->setNextCropNode(crop_node);
	}

	//cout << (*list)->total_crops << " = " << crop_node->getCrop()->getCropName() << endl;

	// update SLL metadata
	(*list)->tail = crop_node;
	(*list)->total_crops++;
}

void plant_crop_at(CropsListSingle** list, unsigned int crop_id, const char* crop_name, int location) {
	Crop* crop = new Crop("Player", crop_name, crop_id, 5, 5, 50, 50, 50, 50, "active", false);
	CropNode* node = new CropNode(crop);

	plant_crop_node_at(list, node, location);
}

/// <summary>
/// Plants at (location + 1)th, ie inserts the node after the specified location
/// </summary>
/// <param name="list"></param>
void plant_crop_node_at(CropsListSingle** list, CropNode* crop_node, int location) {
	if ( sll_is_empty(*list) ) {
		plant_crop_node_as_head(list, crop_node);
	}
	else if ( (*list)->total_crops == 1 ) {
		plant_crop_node_as_tail(list, crop_node);
	}
	else {
		CropNode* temp = (*list)->head;
		for (int i = 0; i < (location - 1); i++) {
			temp = temp->getNextCropNode();
		}
		CropNode* nextNode = temp->getNextCropNode();
		crop_node->setNextCropNode(nextNode);
		temp->setNextCropNode(crop_node);
		(*list)->total_crops++;
	}
}

void purge_crop(CropsListSingle** list, unsigned int crop_id) {

	// get the actual node
	CropNode* to_delete= (*list)->head;
	while (to_delete && (to_delete->getCrop()->getID() != crop_id)) {
		to_delete = to_delete->getNextCropNode();
	}
	//cout << "Found the node" << endl;
	//found->getCrop()->displayInfo();

	if ( (*list)->head == to_delete ) {
		if ( (*list)->head->getNextCropNode() == NULL ) {
			(*list)->head = (*list)->tail = NULL;
		}
		else {
			(*list)->head = (*list)->head->getNextCropNode();
		}
	}
	else {
		CropNode* previous = (*list)->head;
		while ( previous != NULL && previous->getNextCropNode() != to_delete ) {
			previous = previous->getNextCropNode();
		}
		previous->setNextCropNode(to_delete->getNextCropNode());
	}

	// delete and reduce total crops
	delete to_delete;
	(*list)->total_crops--;
}

void purge_farm(CropsListSingle** list) {
	while ( (*list)->head != NULL) {
		CropNode* node = (*list)->head;
		cout << "Deleting crop #" << node->getCrop()->getID() << endl;
		(*list)->head = (*list)->head->getNextCropNode();

		delete node;
		node = NULL;
	}
	free(*list);
	(*list) = NULL;
}