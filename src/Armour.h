#ifndef GAMEBOOK_ARMOUR_H
#define GAMEBOOK_ARMOUR_H

#include "Item.h"

class CArmour : public CItem
{
public:
    CArmour() = default;

    explicit CArmour(int id, int price, int def, std::string name)
            : CItem(id, price, name), defense(def)
    {}

    void useItem(HeroStats &stats, CEquipment &equipment) const override
    { equipment.setArmour(defense); }

    void print(const CDisplay &display) const override;

    void printForShop(const CDisplay &display) const override;

protected:
    int defense;

};


#endif //GAMEBOOK_ARMOUR_H
