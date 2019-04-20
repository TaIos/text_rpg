#ifndef GAMEBOOK_SWORD_H
#define GAMEBOOK_SWORD_H

#include "Item.h"

class CSword : public CItem
{
public:
    explicit CSword(int id, int price, int damage, std::string name)
            : CItem(id, price, name), attack(damage)
    {}

    void useItem(HeroStats &stats, CEquipment &equipment) const override
    { equipment.setAttack(attack); }

    void print(const CDisplay &display) const override;

    void printForShop(const CDisplay &display) const override;

protected:
    int attack;
};


#endif //GAMEBOOK_SWORD_H
