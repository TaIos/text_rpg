#ifndef GAMEBOOK_ERRORSLIST_H
#define GAMEBOOK_ERRORSLIST_H

enum class error
{
    no_error, unknown, first_menu, load, save, exit, invalid_input,
    no_such_filename, no_write_permission, error_reading_event,
    error_reading_creature, error_reading_shop_item, error_reading_world,
    cant_open_file, cant_write_to_file, error_while_writing_to_file,
    error_while_decoding_player_data, invalid_id
};

#endif //GAMEBOOK_ERRORSLIST_H
