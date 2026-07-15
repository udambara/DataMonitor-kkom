#include "DataMonitor/DataMonitor.h"

#include <iomanip>
#include <iostream>
#include <map>
#include <string>

namespace mon {

namespace {

std::string InventoryStatus(int stock) {
    if (stock == 0) return "고갈";
    if (stock < 100) return "부족";
    return "여유";
}

std::string RemarkFor(dp::OrderStatus status) {
    return status == dp::OrderStatus::PRODUCING ? "생산라인 대기" : "";
}

}

void PrintOrderStatusTable(const dp::OrderRepository& orderRepo) {
    std::map<dp::OrderStatus, int> counts = orderRepo.CountByStatus();

    static const dp::OrderStatus kDisplayOrder[] = {
        dp::OrderStatus::RESERVED,
        dp::OrderStatus::CONFIRMED,
        dp::OrderStatus::PRODUCING,
        dp::OrderStatus::RELEASE
    };

    std::cout << "\n[주문 현황]\n";
    std::cout << std::left << std::setw(12) << "상태"
               << std::right << std::setw(6) << "건수" << "  " << "비고" << "\n";
    std::cout << std::string(32, '-') << "\n";

    for (dp::OrderStatus status : kDisplayOrder) {
        std::cout << std::left << std::setw(12) << dp::ToString(status)
                   << std::right << std::setw(6) << counts[status] << "  "
                   << RemarkFor(status) << "\n";
    }
}

void PrintInventoryTable(const dp::SampleRepository& sampleRepo) {
    std::vector<dp::Sample> samples = sampleRepo.GetAll();

    std::cout << "\n[재고 현황]\n";
    std::cout << std::left << std::setw(22) << "시료명" << std::right << std::setw(10) << "재고" << "  " << "상태" << "\n";
    std::cout << std::string(42, '-') << "\n";

    for (const dp::Sample& sample : samples) {
        std::cout << std::left << std::setw(22) << sample.name
                   << std::right << std::setw(7) << sample.stock << " ea" << "  "
                   << InventoryStatus(sample.stock) << "\n";
    }
}

}
