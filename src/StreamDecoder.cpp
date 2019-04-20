#include "StreamDecoder.h"

std::string CStreamDecoder::getString(std::istringstream &stream) const
{
    std::string str;
    stream >> str;
    return str;
}

int CStreamDecoder::getStringAsInt(std::istringstream &stream) const
{
    return atoi(getString(stream).c_str());
}

/**
 * Get all text in '<' and '>'
 * @param stream stream to read data from
 * @return return text which is enclosed by <text>
 */
std::string CStreamDecoder::getText(std::istringstream &stream) const
{
    char c;
    std::string text;
    while (stream.get() != '<')
        continue;
    while ((c = stream.get()) != '>')
        text.push_back(c);

    return text;
}

/**
 *  Reads numbers separated by whitespace to the end of line and return them as vector
 */
std::vector<int> CStreamDecoder::getNumbers(std::istringstream &stream) const
{
    std::string line, num;
    std::vector<int> numbers;

    std::getline(stream, line);
    std::istringstream lineOfNum(line);

    while (lineOfNum >> num)
        numbers.push_back(atoi(num.c_str()));

    return numbers;
}

/**
 *  Reads numbers separated by whitespace to the end of line and return them as vector
 */
std::vector<int> CStreamDecoder::getNumbers(const std::string &data) const
{
    std::istringstream stream(data);
    return getNumbers(stream);
}

std::string CStreamDecoder::getNumbersAsString(std::istringstream &stream) const
{
    std::string str;

    for (const auto &num : getNumbers(stream))
        str += (std::to_string(num) + " ");

    return str;
}

/**
 * Decodes player data into specific form
 * @param data is place from which data with specific format are read
 * @param hero is place where are hero data will be loaded
 * @param storyline is place where event order will be loaded ( sequence of integers )
 * @return error if can't recognize data format
 */
error CStreamDecoder::decodePlayerData(const std::string &data, std::string &hero, std::string &storyline) const
{
    std::istringstream stream(data);

    if (getString(stream) != "hero_basic")
        return error::error_while_decoding_player_data;

    hero += (getString(stream) + " "); // load hero name

    hero += (getString(stream) + " "); // load gold value

    if (getString(stream) != "hero_stats")
        return error::error_while_decoding_player_data;

    hero += (getString(stream) + " "); // load hero race

    hero += (getNumbersAsString(stream) + " "); // load hero statistic

    if (getString(stream) != "hero_equipment")
        return error::error_while_decoding_player_data;

    hero += "hero_equipment ";
    hero += (getNumbersAsString(stream) + " "); // load hero equipment (attack, armour)

    if (getString(stream) != "hero_inventory")
        return error::error_while_decoding_player_data;

    hero += "inventory ";
    hero += getNumbersAsString(stream); // load hero inventory

    if (getString(stream) != "event_order")
        return error::error_while_decoding_player_data;

    storyline += "event ";
    storyline = getNumbersAsString(stream); // load storyline event order

    return error::no_error;
}
