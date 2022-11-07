#pragma once
#include "SinglyLinkedList.h"

typedef crops_singly_link_list MarinatingUrn;

MarinatingUrn* create_stack(void);

void observe_urn(MarinatingUrn* urn);

void add_cabbage(MarinatingUrn** urn, CropNode* cabbage_node); // push
void remove_and_eat_cabbage(MarinatingUrn** urn); // pop

void purge_urn(MarinatingUrn** urn);
