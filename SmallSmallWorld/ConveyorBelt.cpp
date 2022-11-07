#include "ConveyorBelt.h"
#include "MarinateCabbage.h"

ConveyorBelt* create_conveyor_belt(void) {
	//return create_stack(); // sounds strange
	ConveyorBelt* belt = (ConveyorBelt*)malloc(sizeof(ConveyorBelt));
	//crops_sll->head = NULL;
	//crops_sll->tail = NULL;
	belt->total_crops = 0;
	belt->middle = 0;

	return belt;
}

void observe_conveyor_belt(ConveyorBelt* belt) {
	if (belt == NULL || sll_is_empty(belt)) {
		cout << "No crops on the conveyor belt anymore!" << endl;
	}
	else {
		inspect_crops(belt);
	}
}

void send_crop_for_washing(ConveyorBelt** belt, CropNode* crop_node) {
	// singly-linked list involved, easier to remove head than to remove tail
	plant_crop_node_as_tail(belt, crop_node);
}

void wash_dry_and_sell_crop(ConveyorBelt** belt) {
	while ((*belt)->head != NULL) {
		CropNode* crop_node = (*belt)->head;

		cout << "" << endl;
		cout << "Washing crop (id=" << crop_node->getCrop()->getID() << ", name=" \
			<< crop_node->getCrop()->getCropName() << ") and selling it..." << endl;
		(*belt)->head = (*belt)->head->getNextCropNode();

		delete crop_node;
		crop_node = NULL;

		(*belt)->total_crops--;
	}
}

void purge_conveyor_belt(ConveyorBelt** belt) {
	if ((*belt) != NULL) {
		
		cout << "Purging conveyor belt...Done!" << endl;
		
		free(*belt);
		(*belt) = NULL;
	}
}