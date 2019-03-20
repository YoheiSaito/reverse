#include "def.hpp"
#include "evalpaser.hpp"

const int evalation_table[8][8] = {
	{50,-3,15,10,10,15,-3,50},
	{-3,-5, 5, 1, 1, 5,-5,-3},
	{15, 5, 8, 8, 8, 8, 5,15},
	{10, 1, 8, 6, 6, 8, 1,10},
	{10, 1, 8, 6, 6, 8, 1,10},
	{15, 5, 8, 8, 8, 8, 5,15},
	{-3,-5, 5, 1, 1, 5,-5,-3},
	{50,-3,15,10,10,15,-3,50},
};
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

