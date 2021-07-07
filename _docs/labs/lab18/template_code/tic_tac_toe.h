#include <iostream>

#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H

class tic_tac_toe
{
	public:
		//default constructor, sets m_ai_mode to false
		tic_tac_toe();

		//constructor, sets m_ai_mode
		tic_tac_toe(bool ai_mode);

		//default destructor
		~tic_tac_toe();

		//executes game
		void play();

	private:
		struct game_state {
			char* m_gs_board;
			int m_gs_player;
		};

		//holds current player
		int m_current_player;

		//tic tac toe gameboard to hold moves
		char* m_board;

		//true if AI mode enabled, false otherwise
		bool m_ai_mode;

		//-1 if ongoing, 0 if over with tie, 1 if over with win
		int game_status(char* board);

		//draws board and returns it as a string
		std::string draw_board(char* board);

		//makes a move for the current player, returns true on success, false on invalid move
		bool make_move(int location);

		//minimax algorithm to calculate the minimax value of state, P1 is max, P2 is min
		int minimax_algo(game_state* state, int depth);

		//returns optimal move for ai using minimax algorithm
		int minimax_move();
};

#endif