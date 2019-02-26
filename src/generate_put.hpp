#pragma once
#include "def.hpp"

bool putable( uint64_t self, uint64_t enemy, uint64_t bb_pos){
	if((self | enemy) & bb_pos){
		return false;
	}
	uint64_t len = 0;
	bool putable = false;
	if( (len = continuous_left(enemy, bb_pos)+1) > 1){
		uint64_t tmp_idx = bb_pos >> (len);
		if(self & tmp_idx){
			putable = true;
		}
	}
	if( (len = continuous_right(enemy, bb_pos)+1) > 1){
		uint64_t tmp_idx = bb_pos << (len);
		if(self & tmp_idx){
			putable = true;
		}
	}
	if( (len = continuous_up(enemy, bb_pos)+1) > 1){
		uint64_t tmp_idx = bb_pos >> (len<<3);
		if(self & tmp_idx){
			putable = true;
		}
	}
	if( (len = continuous_down(enemy, bb_pos)+1) > 1){
		uint64_t tmp_idx = bb_pos << (len<<3);
		if(self & tmp_idx){
			putable = true;
		}
	}
	if( (len = continuous_lowerleft(enemy, bb_pos)+1) > 1){
		uint64_t tmp_idx = bb_pos << ((len<<3) - len);
		if(self & tmp_idx){
			putable = true;
		}
	}
	if( (len = continuous_lowerright(enemy, bb_pos)+1) > 1){
		uint64_t tmp_idx = bb_pos << ((len<<3) + len);
		if(self & tmp_idx){
			putable = true;
		}
	}
	if( (len = continuous_upperleft(enemy, bb_pos)+1) > 1){
		uint64_t tmp_idx = bb_pos >> ((len<<3) + len);
		if(self & tmp_idx){
			putable = true;
		}
	}
	if( (len = continuous_upperright(enemy, bb_pos)+1) > 1){
		uint64_t tmp_idx = bb_pos >> ((len<<3) - len);
		if(self & tmp_idx){
			putable = true;
		}
	}
	return putable;
}
std::unique_ptr<BitBoard> put( uint64_t self, uint64_t enemy, uint64_t bb_pos){

	if((self | enemy) & bb_pos){
		return nullptr;
	}

	std::unique_ptr<BitBoard> after(new BitBoard);
	after->one = self;
	after->opp = enemy;
	uint64_t len = 0;
	bool putable = false;
	if( (len = continuous_left(enemy, bb_pos)+1) > 1){
		uint64_t tmp_idx = bb_pos >> (len);
		if(self & tmp_idx){
			putable = true;
			uint64_t mask = bb_pos;
			for(uint64_t i = 0; i < len-1; i++){
				mask |= (mask >>1);
			}
			after->one |= mask;
			after->opp &= ~mask;

		}
	}
	if( (len = continuous_right(enemy, bb_pos)+1) > 1){
		uint64_t tmp_idx = bb_pos << (len);
		if(self & tmp_idx){
			putable = true;
			uint64_t mask = bb_pos;
			for(uint64_t i = 0; i < len-1; i++){
				mask |= (mask <<1);
			}
			after->one |= mask;
			after->opp &= ~mask;

		}
	}
	if( (len = continuous_up(enemy, bb_pos)+1) > 1){
		uint64_t tmp_idx = bb_pos >> (len<<3);
		if(self & tmp_idx){
			putable = true;
			uint64_t mask = bb_pos;
			for(uint64_t i = 0; i < len-1; i++){
				mask |= (mask >>8);
			}
			after->one |= mask;
			after->opp &= ~mask;
	
		}
	}
	if( (len = continuous_down(enemy, bb_pos)+1) > 1){
		uint64_t tmp_idx = bb_pos << (len<<3);
		if(self & tmp_idx){
			putable = true;
			uint64_t mask = bb_pos;
			for(uint64_t i = 0; i < len-1; i++){
				mask |= (mask <<8);
			}
			after->one |= mask;
			after->opp &= ~mask;

		}
	}
	if( (len = continuous_lowerleft(enemy, bb_pos)+1) > 1){
		uint64_t tmp_idx = bb_pos << ((len<<3) - len);
		if(self & tmp_idx){
			putable = true;
			uint64_t mask = bb_pos;
			for(uint64_t i = 0; i < len-1; i++){
				mask |= (mask <<7);
			}
			after->one |= mask;
			after->opp &= ~mask;

		}
	}
	if( (len = continuous_lowerright(enemy, bb_pos)+1) > 1){
		uint64_t tmp_idx = bb_pos << ((len<<3) + len);
		if(self & tmp_idx){
			putable = true;
			uint64_t mask = bb_pos;
			for(uint64_t i = 0; i < len-1; i++){
				mask |= (mask <<9);
			}
			after->one |= mask;
			after->opp &= ~mask;

		}
	}
	if( (len = continuous_upperleft(enemy, bb_pos)+1) > 1){
		uint64_t tmp_idx = bb_pos >> ((len<<3) + len);
		if(self & tmp_idx){
			putable = true;
			uint64_t mask = bb_pos;
			for(uint64_t i = 0; i < len-1; i++){
				mask |= (mask >>9);
			}
			after->one |= mask;
			after->opp &= ~mask;

		}
	}
	if( (len = continuous_upperright(enemy, bb_pos)+1) > 1){
		uint64_t tmp_idx = bb_pos >> ((len<<3) - len);
		if(self & tmp_idx){
			putable = true;
			uint64_t mask = bb_pos;
			for(uint64_t i = 0; i < len-1; i++){
				mask |= (mask >>7);
			}
			after->one |= mask;
			after->opp &= ~mask;

		}
	}
	if(putable){
		return after;
	}
	return nullptr;
}
