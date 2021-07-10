#include <iostream>
#include <string>
#include <vector>

const std::string line = "\n  -----";
const std::string num_row = "  A|B|C";
int turn = 1;

//Define the initial rows
std::vector<std::string> row1 = {"1 "," ", "|", " ", "|", " "};
std::vector<std::string> row2 = {"2 ", " ", "|", " ", "|", " "};
std::vector<std::string> row3 = {"3 ", " ", "|", " ", "|", " "};

std::vector<std::vector<std::string>> rows = {row1, row2, row3};

//Game start messgaes

void start_game() {
	std::cout << "\n---Tic Tac Toe---\n" << std::endl;
	std::cout << "Enter in a location starting with a letter, then the number\nE.g: A1 or a1\n" << std::endl; 
}

//See if it's player1's turn

bool player1_turn() {
	if(turn % 2 != 0) {
		return true;
	} else {
		return false;
	}
}

//Converts a row to a string

std::string line_to_string(std::vector<std::string> row, int last=0) {
	std::string str = "";
	for(int i = 0; i < row.size(); i++) {
		str += row[i];
	}
	if(!last) {
	str += line;		
	}
	return str;
}

//Displays the board

int display_board() {
	std::cout << num_row << std::endl;
	std::cout << line_to_string(rows[0]) << std::endl;
	std::cout << line_to_string(rows[1]) << std::endl;
	std::cout << line_to_string(rows[2],1) << std::endl;
	return 1;
}

//Validate User Input

std::vector<int> validate_input(std::string spot) {
	if((spot == "") || (spot.size() != 2)) {
		return {0};
	}
	int x;
	int y = spot[1] - '0';
	std::vector<int> return_value;
  char raw_x_value = tolower(spot[0]);
	if(raw_x_value == 'a') {
		x = 1;
	} else if(raw_x_value == 'b') {
		x = 3;
	} else if(raw_x_value == 'c') {
		x = 5;
	} else {
		return_value = {0};
	}
	
	if((y > 3 || y < 1) || (x > 5 || x < 1)) {
		return_value = {0};
	} else {
		return_value = {1, x, y};
	}
	return return_value;
}

//Checks if place is free on board

bool is_free(std::vector<int> v_input) {
	std::vector<std::string> row;
	int x = v_input[1];
	int y = v_input[2];
	if(y == 1) {
		row = rows[0];
	} else if(y == 2) {
		row = rows[1];
	} else if(y == 3) {
		row = rows[2];
	}
	std::string place = row[x];
	if(place != " ") {
		return false;
	} else {
		return true;
	}
}

//Mark an X on the chosen spot

int mark_spot(std::vector<int> v_input, bool p1) {
	std::vector<std::string> row;
	int x = v_input[1];
	int y = v_input[2];
	if(p1) {
		if(y == 1) {
			rows[0][x] = "O";
		} else if(y == 2) {
			rows[1][x] = "O";
		} else if(y == 3) {
			rows[2][x] = "O";
		}
	} else {
		if(y == 1) {
			rows[0][x] = "X";
		} else if(y == 2) {
			rows[1][x] = "X";
		} else if(y == 3) {
			rows[2][x] = "X";
		}
	}
	turn++;
	return 1;
}

//Checks if someone has won the game
std::vector<int> horizontal_win() {
	std::vector<int> info = {0,0};
	
  for(int i = 0; i <= 2; i++) {
		if((rows[i][1] == rows[i][3] && rows[i][3] == rows[i][5]) && rows[i][1] != " ") {
			if(rows[i][1] == "X") {
				info = {1,1};
			} else {
				info = {1,0};
			}
			return info;
		}
	}
	return info;
}

std::vector<int> vertical_win() {
	std::vector<int> info = {0,0};
	for(int i = 1; i <= 5; i += 2) {
		if((rows[0][i] == rows[1][i] && rows[1][i] == rows[2][i]) && rows[0][i] != " ") {
			if(rows[0][i] == "X") {
				info = {1,1};
			} else {
				info = {1,0};
			}
			return info;
		}
	}
	return info;
}

std::vector<int> diag_win() {
	std::vector<int> info = {0,0};
	bool diag1 = (rows[0][1] == rows[1][3] && rows[1][3] == rows[2][5]) && rows[0][1] != " ";
	bool diag2 = (rows[0][5] == rows[1][3] && rows[1][3] == rows[2][1]) && rows[0][5] != " ";
	if(diag1) {
		if(rows[0][1] == "X") {
			info = {1,1};
		} else {
			info = {1,0};
		}
	} else if(diag2) {
		if(rows[0][5] == "X") {
			info = {1,1};
		} else {
			info = {1,0};
		}
	}
	return info;
}

//Get the right input to check_game_status()

std::vector<int> filter_win() {
	std::vector<int> h_win = horizontal_win();
	std::vector<int> v_win = vertical_win();
	std::vector<int> d_win = diag_win();
	if(h_win[0] == 1) {
		return h_win;
	} else if(v_win[0] == 1) {
		return v_win;
	} else if(d_win[0] == 1) {
		return d_win;
	} else {
		return h_win;
	}
}
 
std::vector<int> check_game_status() {
	std::vector<int> info = filter_win();
	//tie
	if(turn >= 10 && info[0] != 1) {
		info = {0,1};
	}
	
	//std::cout << info[0] << ", " << info[1] << std::endl;
	return info;
} 
