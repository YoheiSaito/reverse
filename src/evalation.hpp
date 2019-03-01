#include "def.hpp"
const int evalation_table[8][8] = {
	{30, 3,15,15,15,15, 3,30},
	{ 3, 1, 4, 4, 4, 4, 1, 3},
	{15, 4, 8, 8, 8, 8, 4,15},
	{15, 4, 8, 6, 6, 8, 4,15},
	{15, 4, 8, 6, 6, 8, 4,15},
	{15, 4, 8, 8, 8, 8, 4,15},
	{ 3, 1, 4, 4, 4, 4, 1, 3},
	{30, 3,15,15,15,15, 3,30},
};
int32_t evalate(BitBoard_p& b){
	int s = 0; 
	for(int i = 0; i < 64; i++){
		s += ((b->black >> i) &1 ) * evalation_table[i/8][i%8];
		s -= ((b->white >> i) &1 ) * evalation_table[i/8][i%8];
	}
	return s;
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
	if(bc > wc){
		return INT32_MAX;
	}else if (bc < wc){
		return -INT32_MAX;
	}
	return 0;
}

