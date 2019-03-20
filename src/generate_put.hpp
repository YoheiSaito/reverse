#pragma once
#include "def.hpp"

bool placeable( uint64_t self, uint64_t enemy, uint64_t bb_pos){
	if((self | enemy) & bb_pos){
		return false;
	}
	uint64_t len = 0;
	bool placeable = false;
	if( (len = continuous_left(enemy, bb_pos)+1) > 1){
		uint64_t tmp_idx = bb_pos << (len);
		if(self & tmp_idx){
			placeable = true;
		}
	}
	if( (len = continuous_right(enemy, bb_pos)+1) > 1){
		uint64_t tmp_idx = bb_pos >> (len);
		if(self & tmp_idx){
			placeable = true;
		}
	}
	if( (len = continuous_up(enemy, bb_pos)+1) > 1){
		uint64_t tmp_idx = bb_pos << (len<<3);
		if(self & tmp_idx){
			placeable = true;
		}
	}
	if( (len = continuous_down(enemy, bb_pos)+1) > 1){
		uint64_t tmp_idx = bb_pos >> (len<<3);
		if(self & tmp_idx){
			placeable = true;
		}
	}
	if( (len = continuous_lowerleft(enemy, bb_pos)+1) > 1){
		uint64_t tmp_idx = bb_pos >> ((len<<3) - len);
		if(self & tmp_idx){
			placeable = true;
		}
	}
	if( (len = continuous_lowerright(enemy, bb_pos)+1) > 1){
		uint64_t tmp_idx = bb_pos >> ((len<<3) + len);
		if(self & tmp_idx){
			placeable = true;
		}
	}
	if( (len = continuous_upperleft(enemy, bb_pos)+1) > 1){
		uint64_t tmp_idx = bb_pos << ((len<<3) + len);
		if(self & tmp_idx){
			placeable = true;
		}
	}
	if( (len = continuous_upperright(enemy, bb_pos)+1) > 1){
		uint64_t tmp_idx = bb_pos << ((len<<3) - len);
		if(self & tmp_idx){
			placeable = true;
		}
	}
	return placeable;
}
std::unique_ptr<BitBoard> put( uint64_t self, uint64_t enemy, uint64_t bb_pos){

	if((self | enemy) & bb_pos){
		return nullptr;
	}

	std::unique_ptr<BitBoard> after(new BitBoard);
	after->black = self;
	after->white = enemy;
	uint64_t len = 0;
	bool placeable = false;
	if( (len = continuous_left(enemy, bb_pos)+1) > 1){
		uint64_t tmp_idx = bb_pos << (len);
		if(self & tmp_idx){
			placeable = true;
			uint64_t mask = bb_pos;
			for(uint64_t i = 0; i < len-1; i++){
				mask |= (mask <<1);
			}
			after->black |= mask;
			after->white &= ~mask;

		}
	}
	if( (len = continuous_right(enemy, bb_pos)+1) > 1){
		uint64_t tmp_idx = bb_pos >> (len);
		if(self & tmp_idx){
			placeable = true;
			uint64_t mask = bb_pos;
			for(uint64_t i = 0; i < len-1; i++){
				mask |= (mask >>1);
			}
			after->black |= mask;
			after->white &= ~mask;

		}
	}
	if( (len = continuous_up(enemy, bb_pos)+1) > 1){
		uint64_t tmp_idx = bb_pos << (len<<3);
		if(self & tmp_idx){
			placeable = true;
			uint64_t mask = bb_pos;
			for(uint64_t i = 0; i < len-1; i++){
				mask |= (mask <<8);
			}
			after->black |= mask;
			after->white &= ~mask;
	
		}
	}
	if( (len = continuous_down(enemy, bb_pos)+1) > 1){
		uint64_t tmp_idx = bb_pos >> (len<<3);
		if(self & tmp_idx){
			placeable = true;
			uint64_t mask = bb_pos;
			for(uint64_t i = 0; i < len-1; i++){
				mask |= (mask >>8);
			}
			after->black |= mask;
			after->white &= ~mask;

		}
	}
	if( (len = continuous_lowerleft(enemy, bb_pos)+1) > 1){
		uint64_t tmp_idx = bb_pos >> ((len<<3) - len);
		if(self & tmp_idx){
			placeable = true;
			uint64_t mask = bb_pos;
			for(uint64_t i = 0; i < len-1; i++){
				mask |= (mask >>7);
			}
			after->black |= mask;
			after->white &= ~mask;

		}
	}
	if( (len = continuous_lowerright(enemy, bb_pos)+1) > 1){
		uint64_t tmp_idx = bb_pos >> ((len<<3) + len);
		if(self & tmp_idx){
			placeable = true;
			uint64_t mask = bb_pos;
			for(uint64_t i = 0; i < len-1; i++){
				mask |= (mask >>9);
			}
			after->black |= mask;
			after->white &= ~mask;

		}
	}
	if( (len = continuous_upperleft(enemy, bb_pos)+1) > 1){
		uint64_t tmp_idx = bb_pos << ((len<<3) + len);
		if(self & tmp_idx){
			placeable = true;
			uint64_t mask = bb_pos;
			for(uint64_t i = 0; i < len-1; i++){
				mask |= (mask <<9);
			}
			after->black |= mask;
			after->white &= ~mask;

		}
	}
	if( (len = continuous_upperright(enemy, bb_pos)+1) > 1){
		uint64_t tmp_idx = bb_pos << ((len<<3) - len);
		if(self & tmp_idx){
			placeable = true;
			uint64_t mask = bb_pos;
			for(uint64_t i = 0; i < len-1; i++){
				mask |= (mask <<7);
			}
			after->black |= mask;
			after->white &= ~mask;

		}
	}
	if(placeable){
		return after;
	}
	return nullptr;
}
inline BitBoard_p put_black(BitBoard_p& b, uint64_t pos){
	return (put(b->black, b->white, pos));
}
inline BitBoard_p put_white(BitBoard_p& b, uint64_t pos){
	auto r = (put(b->white, b->black, pos));
	int64_t tmp = r->white;
	r->white = r->black;
	r->black =  tmp;
	return r;
}
