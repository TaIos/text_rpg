#ifndef GAMEBOOK_INVENTORY_H
#define GAMEBOOK_INVENTORY_H

#include <set>
#include <vector>
#include <string>

class CInventory
{
public:

    void exportData(std::string &data) const;

    void addItem(int itemID)
    { items.insert(itemID); }

    void removeItem(int itemID)
    { items.erase(itemID); }

    bool isInInventory(int itemID) const
    { return (items.find(itemID) != items.end()); }

    bool isEmpty() const
    { return items.empty(); }

    void update(const std::set<int> &itemsID)
    { items = itemsID; }

    void update(const std::vector<int> &itemsID);

    const std::set<int> &getItemsID() const
    { return items; }

protected:
    std::set<int> items;
};


#endif //GAMEBOOK_INVENTORY_H
