#include <iostream>
#include <string>
#include <vector>
#include "tic-tac-funcs.hpp"


int main() {
	bool game_running = true;
	start_game();
	while(game_running) {
		//Define the choice variable
		std::string choice;
	
		//Display the initial board
		display_board();
	  
		std::vector<int> game_status = check_game_status();
		//std::cout << game_status[0] << ", " << game_status[1] << std::endl;
		if((game_status[0] == 0) && (game_status[1] == 1)) {
			std::cout << "\n\nY'all tied...oof" << std::endl;
			break;
		} else if(game_status[0] == 1) {
			if(game_status[1] == 1) {
				std::cout << "\n\nPlayer 1 wins!" << std::endl;
				break;
			} else {
				std::cout << "\n\nPlayer 2 wins!\n" << std::endl;
				break;
			}
		}
		if(player1_turn()) {
		  std::cout << "Player 1, choose an unmarked spot: ";
		} else {
		  std::cout << "Player 2, choose an unmarked spot: ";
		}	
		std::cin >> choice;
		std::vector<int> validated_input = validate_input(choice);
		
		if(validated_input[0] == 0) {
			std::cout << "\nPlease enter a valid input\n" << std::endl;
			continue;
		}
		if(!is_free(validated_input)) {
			std::cout << "\nPlease enter another spot\n" << std::endl;
			continue;
		}
		
		if(player1_turn()) {
			mark_spot(validated_input, false);
		} else {
			mark_spot(validated_input, true);
		}
		
		//game_running = false;
  }
}