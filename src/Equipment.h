#ifndef GAMEBOOK_EQUIPMENT_H
#define GAMEBOOK_EQUIPMENT_H

/*
 * Represents hero equipment ( eg: hero equipped sword with attack 5, this class holds this value )
 */
class CEquipment
{
public:
    CEquipment()
            : attack(0), armour(0)
    {}

    void setAttack(int a)
    { attack = a; }

    int getAttack() const
    { return attack; }

    int getArmour() const
    { return armour; }

    void setArmour(int a)
    { armour = a; }

protected:
    int attack;
    int armour;
};


#endif //GAMEBOOK_EQUIPMENT_H
