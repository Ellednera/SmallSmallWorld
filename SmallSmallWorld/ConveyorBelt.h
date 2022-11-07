#pragma once
#include "SinglyLinkedList.h"

typedef crops_singly_link_list ConveyorBelt;

ConveyorBelt* create_conveyor_belt(void);

void observe_conveyor_belt(ConveyorBelt* belt);

void send_crop_for_washing(ConveyorBelt** belt, CropNode* crop_node); // enqueue
void wash_dry_and_sell_crop(ConveyorBelt** belt); // dequeue

void purge_conveyor_belt(ConveyorBelt** belt);