#include <iostream>
#include <string>
#include <vector>
//Game funcs
void start_game();
int display_board();
std::string line_to_string(std::vector<std::string> row, int last=0);
bool is_free(std::vector<int> v_input);
int mark_spot(std::vector<int> v_input, bool p1);
bool player1_turn();

//Human funcs
std::vector<int> validate_input(std::string spot);

//Game over funcs
std::vector<int> check_game_status();
std::vector<int> horizontal_win();
std::vector<int> vertical_win();
std::vector<int> diag_win();
std::vector<int> filter_win();
std::vector<int> play_again();
void reset_game();
