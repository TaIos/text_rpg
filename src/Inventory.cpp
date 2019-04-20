#include "Inventory.h"

void CInventory::exportData(std::string &data) const
{
    data = "hero_inventory ";
    for (const auto &itemID : items)
        data += (std::to_string(itemID) + " ");
}

void CInventory::update(const std::vector<int> &itemsID)
{
    items.clear();
    for (auto id : itemsID)
        items.insert(id);
}

