#pragma once
#include "def.hpp"
#include <cstdio>

struct EvalPaser{
	int8_t eval_factor[13];
	int eval_table[8][8];
	EvalPaser(std::string fname){
		std::ifstream fin(fname);
		if(fin.fail()){
			throw (fname + " does not exist");
		}
		for(int i = 0; i < 12; i++){
			std::string s;
			fin >> s;
			eval_factor[i] = std::stoi(s);
		}
		int f[4][4] = {
			{0,1,2,3},
			{1,4,5,6},
			{2,5,7,8},
			{3,6,8,9},
		};

		for(int i = 0; i < 8; i++){
			for(int j = 0; j < 8; j++){
				int ii = i>3?7-i:i;
				int jj = j>3?7-j:j;
				using namespace std;
				eval_table[i][j] = eval_factor[(f[ii][jj])];
			}
		}
		for(int i = 0; i < 8; i++){
			for(int j = 0; j < 8; j++){
				std::cout << eval_table[i][j]<< '\t';
			}
			std::cout << std::endl;
		}
	}
	int32_t evalate(BitBoard_p& b){
		int s = 0; 
		int c = b->placeable_count(BLACK) - b->placeable_count(WHITE);
		for(int i = 0; i < 64; i++){
			s += ((b->black >> i) &1 ) * eval_table[i/8][i%8];
			s -= ((b->white >> i) &1 ) * eval_table[i/8][i%8];
		}
		int p = popcount(b->black) -  popcount(b->white);
		return s*eval_factor[10] + c*eval_factor[11] +p*eval_factor[12];
	}
	inline int64_t popcount( int64_t bit){
		bit = (( bit&0xAAAAAAAAAAAAAAAA) >> 1) + (bit&0x5555555555555555); //2
		bit = (( bit&0xCCCCCCCCCCCCCCCC) >> 2) + (bit&0x3333333333333333); //4
		bit = (( bit&0xF0F0F0F0F0F0F0F0) >> 4) + (bit&0x0F0F0F0F0F0F0F0F); //8
		bit = (( bit&0xFF00FF00FF00FF00) >> 8) + (bit&0x00FF00FF00FF00FF); //16
		bit = (( bit&0xFFFF0000FFFF0000) >>16) + (bit&0x0000FFFF0000FFFF); //32
		bit = (( bit&0xFFFFFFFF00000000) >>32) + (bit&0x00000000FFFFFFFF); //64
		return bit;
	}
	int32_t evalate_end(BitBoard_p& b){
		int bc = popcount(b->black);
		int wc = popcount(b->white);
		return INT32_MAX/64*(bc-wc);
	}

};
