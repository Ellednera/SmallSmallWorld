#include "MarinateCabbage.h"

MarinatingUrn* create_stack(void) {
	MarinatingUrn* urn = (MarinatingUrn*)malloc(sizeof(MarinatingUrn));
	//crops_sll->head = NULL;
	//crops_sll->tail = NULL;
	urn->total_crops = 0;
	urn->middle = 0;

	return urn;
}

void add_cabbage(MarinatingUrn** urn, CropNode* cabbage_node) {
	plant_crop_node_as_head(urn, cabbage_node);
}

void remove_and_eat_cabbage(MarinatingUrn** urn) {
	while ((*urn)->head != NULL) {
		CropNode* cabbage_node = (*urn)->head;
		cout << "Eating cabbage #" << cabbage_node->getCrop()->getID() << endl;
		(*urn)->head = (*urn)->head->getNextCropNode();

		delete cabbage_node;
		cabbage_node = NULL;

		(*urn)->total_crops--;
	}
}

void observe_urn(MarinatingUrn* urn) {
	if (urn == NULL || sll_is_empty(urn)) {
		cout << "No cabbages in the urn anymore!" << endl;
	}
	else {
		inspect_crops(urn);
	}
		
}

void purge_urn(MarinatingUrn** urn) {
	if ((*urn) != NULL) {
		// if urn is not null
		cout << "Purging urn...Done!" << endl;
		//purge_farm(urn);
		// list has no nodes anymore, deleted when remove_and_eat_cabbage() is called
		free(*urn);
		(*urn) = NULL;
	}

}