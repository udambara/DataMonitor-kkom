#pragma once

#include "DataPersistence/SampleRepository.h"
#include "DataPersistence/OrderRepository.h"

namespace mon {

// Prints order counts grouped by status (RESERVED/CONFIRMED/PRODUCING/RELEASE).
// REJECTED orders are intentionally excluded, since they are not valid orders.
void PrintOrderStatusTable(const dp::OrderRepository& orderRepo);

// Prints current stock per sample along with a derived status:
//   0 stock       -> 고갈
//   below 100     -> 부족
//   otherwise     -> 여유
void PrintInventoryTable(const dp::SampleRepository& sampleRepo);

}
