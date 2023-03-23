#include <iostream>
#include <string>
#include <ctime>
#include <fstream>

enum State {
	START,
	WIN,
	LOSE,
	DRAW
};

enum Sign {
	ROCK = 1,
	PAPER,
	SCISSORS
};

int computerChoice() {
	return rand() % 3 + 1;
}

State compareOfChoice(int input, int oposite) {
	switch (input) {
		case ROCK:
			switch (oposite) {
				case ROCK:
					return DRAW;
				case PAPER:
					return LOSE;
				case SCISSORS:
					return WIN;
			}
			break;
		case PAPER:
			switch (oposite) {
				case ROCK:
					return WIN;
				case PAPER:
					return DRAW;
				case SCISSORS:
					return LOSE;
			}
			break;
		case SCISSORS:
			switch (oposite) {
				case ROCK:
					return LOSE;
				case PAPER:
					return WIN;
				case SCISSORS:
					return DRAW;
			}
			break;
	}
}

int main() {
	std::ofstream out("out.txt");
	srand(time(nullptr));
	int input;
	Sign oposite;
	std::string startGame;
	State win;
	int humanWinCount = 0;
	int computerWinCount = 0;
	std::cout << "DO YOU WANT TO PLAY RPS, HUMAN? y/n: ";
	std::cin >> startGame;

	while (startGame == "y") { //game logic
		//human turn
		std::cout << "RULES: 0 - quit, 1 - rock, 2 - paper, 3 - scissors" << std::endl;
		std::cout << "YOUR TURN, HUMAN: ";
		std::cin >> input;
		if (input == 0) //quit
			break;
		while (input < 0 || input > 3) {
			std::cout << "WRONG CHOICE. DON'T MAKE MISTAKES HUMAN.. HUMAN: ";
			std::cin >> input;
		}
		if (input == 0) //quit
			break;

		std::cout << "HUMAN: ";
		switch (input) {
			case ROCK:
				std::cout << "ROCK" << std::endl;
				break;
			case PAPER:
				std::cout << "PAPER" << std::endl;
				break;
			case SCISSORS:
				std::cout << "SCISSORS" << std::endl;
				break;
			default:
				break;
		}

		//computer turn
		oposite = Sign(computerChoice());
		std::cout << "COMPUTER: ";
		switch (oposite) {
			case ROCK:
				std::cout << "ROCK" << std::endl;
				break;
			case PAPER:
				std::cout << "PAPER" << std::endl;
				break;
			case SCISSORS:
				std::cout << "SCISSORS" << std::endl;
				break;
			default:
				break;
		}

		//compare
		win = compareOfChoice(input, oposite);
		switch (win) {
			case START:
				break;
			case WIN:
				std::cout << "HUMAN, YOU WIN!" << std::endl;
				humanWinCount++;
				break;
			case LOSE:
				std::cout << "HUMAN, YOU LOSE, GOODBYE..." << std::endl;
				computerWinCount++;
				break;
			case DRAW:
				std::cout << "IT'S DRAW.." << std::endl;
				break;
		}
		std::cout << "Human won: " << humanWinCount << std::endl;
		std::cout << "Computer won: " << computerWinCount << std::endl;
		std::cout << "\nLET'S PLAY ANOTHER GAME? y/n: ";
		std::cin >> startGame;
	}
	std::cout << "\nGAME OVER. BYE HUMAN.." << std::endl;
	out << "Human wins:\t" << humanWinCount << std::endl;
	out << "Computer wins:\t" << computerWinCount << std::endl;
	out.close();

	return 0;
}
