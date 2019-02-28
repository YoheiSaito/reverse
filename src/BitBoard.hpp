#pragma once
#include "def.hpp"

struct BitBoard;
bool putable(uint64_t,uint64_t,uint64_t);
std::unique_ptr<BitBoard> put(uint64_t,uint64_t,uint64_t);

struct BitBoard{
	uint64_t one;
	uint64_t opp;
	BitBoard(void){
		this->one = 0x0000001008000000;
		this->opp = 0x0000000810000000;
	}
	uint64_t stone(void){
		return one | opp;
	}
	bool is_occupied(uint8_t pos){
		return _pext_u64(this->stone(), pos);
	}
	std::string to_string(int turn = NONE){
		std::string bstr(64, ' ');
		for(int i = 0; i < 64; i++){
			if( ((this->one>>  i) &1) == 1 ){
				bstr[i] = 'X';
			}else if( ((this->opp>>i)&1) == 1){
				bstr[i] = 'O';
			}else{
				switch(turn){
					bool p;
				case BLACK:
					p = putable(one, opp, 1ll<<i);
					if(p)
						bstr[i] = '*';
					break;
				case WHITE:
					p = putable(opp, one, 1ll<<i);
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
		int i =0;
		std::cout << "     A   B   C   D   E   F   G   H" << std::endl;
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

