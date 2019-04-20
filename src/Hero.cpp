#include "Hero.h"

CHero::CHero(std::string newName, std::string newRace)
{
    name = newName;
    stats = HeroStats {newRace, 1, 0, 100, 100, 50, 10, 5, 0};
    gold = 10;
}

/**
 * @param data is string which contains all hero data
 * @param decoder is used to decode data in specific format
 */
void CHero::update(const std::string &data, const CStreamDecoder &decoder)
{
    std::istringstream stream(data);

    name = decoder.getString(stream);
    gold = decoder.getStringAsInt(stream);

    stats.race = decoder.getString(stream);

    stats.level = decoder.getStringAsInt(stream);
    stats.xp = decoder.getStringAsInt(stream);
    stats.health = decoder.getStringAsInt(stream);
    stats.maxHealth = decoder.getStringAsInt(stream);
    stats.mana = decoder.getStringAsInt(stream);
    stats.attack = decoder.getStringAsInt(stream);
    stats.strength = decoder.getStringAsInt(stream);
    stats.armour = decoder.getStringAsInt(stream);

    decoder.getString(stream); // load word 'hero_equipment'
    equipment.setAttack(decoder.getStringAsInt(stream));
    equipment.setArmour(decoder.getStringAsInt(stream));

    decoder.getString(stream); // load word 'inventory'
    inventory.update(decoder.getNumbers(stream));
}

/**
 * Exports hero data using specific format
 * @param data is a string in which hero data with specific format are exported
 */
void CHero::exportData(std::string &data) const
{
    std::string heroStatsData, inventoryData;

    data = "hero_basic ";
    data += (name + " " + std::to_string(gold) + "\n");

    stats.exportData(heroStatsData);
    data += (heroStatsData + "\n");

    data += "hero_equipment ";
    data += std::to_string(equipment.getAttack()) + " " + std::to_string(equipment.getArmour()) + "\n";

    inventory.exportData(inventoryData);
    data += (inventoryData + "\n");
}

void CHero::fight(const CCreature &creature)
{
    int creatureDamage = creature.getAttack() - getArmour();
    int creatureHP = creature.getAttack() * 2;
    int heroDMG = getAttack();

    if (creatureDamage > 0)
    {
        while ((creatureHP > 0) && (stats.health > 0))
        {
            creatureHP -= heroDMG;
            stats.health -= creatureDamage;
        }
    }
}

void CHero::printStats(const CDisplay &display) const
{
    display.printWithDelimiter(
            "Name:" + name + ", " +
            "Race:" + stats.race + ", " +
            "Level:" + std::to_string(stats.level) + ", " +
            "XP:" + std::to_string(stats.xp) + "/5" + "\n" +
            "Attack:" + std::to_string(getAttack()) + ", " +
            "Armour:" + std::to_string(getArmour()) + ", " +
            "Gold:" + std::to_string(gold) + "\n"
            "HP:" + std::to_string(stats.health) + "/" + std::to_string(stats.maxHealth) + "\n");
}

void CHero::addXP(int num, const CDisplay &display)
{
    stats.xp += num;
    if (stats.xp >= 5)
    {
        stats.level += (stats.xp / 5);
        stats.xp = stats.xp % 5;
        stats.levelUp();

        display.print("You have levelled up! You are level " + std::to_string(stats.level) + ".\n");
        display.printDelimiter();
    }
}


