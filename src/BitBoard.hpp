#pragma once
#include "def.hpp"


bool placeable(uint64_t,uint64_t,uint64_t);
BitBoard_p put(uint64_t,uint64_t,uint64_t);
struct BitBoard{
	uint64_t black;
	uint64_t white;
	BitBoard(void){
		this->black = 0x0000001008000000;
		this->white = 0x0000000810000000;
	}
	uint64_t stblack(void){
		return black | white;
	}
	bool is_occupied(uint8_t pos){
		return _pext_u64(this->stblack(), pos);
	}
	std::string to_string(int turn = NONE){
		std::string bstr(64, ' ');
		for(int i = 0; i < 64; i++){
			if( ((this->black>>  i) &1) == 1 ){
				bstr[i] = 'X';
			}else if( ((this->white>>i)&1) == 1){
				bstr[i] = 'O';
			}else{
				switch(turn){
					bool p;
				case BLACK:
					p = placeable(black, white, 1ll<<i);
					if(p)
						bstr[i] = '*';
					break;
				case WHITE:
					p = placeable(white, black, 1ll<<i);
					if(p)
						bstr[i] = '*';
					break;
				case NONE:
				default:
					break;
				}
			}

		}
		return bstr;

	}
	void print(int turn = NONE){
		std::string bstr = this->to_string(turn);
		int i = 0;
		std::cout << "     a   b   c   d   e   f   g   h" << std::endl;
		std::cout << "   "  << std::string(33, '-') << std::endl;
		for(auto&&c : bstr){
			if( i%8 == 0 ){
				std::cout << i/8 + 1 << " " ;
			}
			std::cout << " | " << c;
			if( i%8 == 7 ){
				std::cout << " |" << std::endl;
				std::cout <<"   " << std::string(33, '-') << std::endl;
			}
			i++;
		}
	}
};

