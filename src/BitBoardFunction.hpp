#pragma once 
#include "def.hpp"
uint64_t inverse_last_8bit(uint64_t bits){
	bits = ((bits&0x0F) << 4) | ((bits&0xF0) >> 4);
	bits = ((bits&0x33) << 2) | ((bits&0xcc) >> 2);
	bits = ((bits&0x55) << 1) | ((bits&0xaa) >> 1);
	return bits;
}
BitBoard rotate_right(BitBoard base){
	BitBoard tmp;
	tmp.white = 0;
	tmp.black = 0;
	uint64_t wcols[8] = {
		_bextr_u64(base.white,  0, 8),
		_bextr_u64(base.white,  8, 8),
		_bextr_u64(base.white, 16, 8),
		_bextr_u64(base.white, 24, 8),
		_bextr_u64(base.white, 32, 8),
		_bextr_u64(base.white, 40, 8),
		_bextr_u64(base.white, 48, 8),
		_bextr_u64(base.white, 56, 8),
	};
	uint64_t bcols[8] = {
		_bextr_u64(base.black,  0, 8),
		_bextr_u64(base.black,  8, 8),
		_bextr_u64(base.black, 16, 8),
		_bextr_u64(base.black, 24, 8),
		_bextr_u64(base.black, 32, 8),
		_bextr_u64(base.black, 40, 8),
		_bextr_u64(base.black, 48, 8),
		_bextr_u64(base.black, 56, 8),
	};
	uint64_t dst_pdeps[8] = {
		(BB_07 | BB_17 | BB_27 | BB_37 | BB_47 | BB_57 | BB_67 | BB_77),
		(BB_06 | BB_16 | BB_26 | BB_36 | BB_46 | BB_56 | BB_66 | BB_76),
		(BB_05 | BB_15 | BB_25 | BB_35 | BB_45 | BB_55 | BB_65 | BB_75),
		(BB_04 | BB_14 | BB_24 | BB_34 | BB_44 | BB_54 | BB_64 | BB_74),
		(BB_03 | BB_13 | BB_23 | BB_33 | BB_43 | BB_53 | BB_63 | BB_73),
		(BB_02 | BB_12 | BB_22 | BB_32 | BB_42 | BB_52 | BB_62 | BB_72),
		(BB_01 | BB_11 | BB_21 | BB_31 | BB_41 | BB_51 | BB_61 | BB_71),
		(BB_00 | BB_10 | BB_20 | BB_30 | BB_40 | BB_50 | BB_60 | BB_70),
	};

	for(int i =0; i < 8; i++){
		tmp.black |= _pdep_u64(bcols[i], dst_pdeps[i]);
		tmp.white |= _pdep_u64(wcols[i], dst_pdeps[i]);
	}

	return tmp;
}
BitBoard rotate_left(BitBoard base){
	BitBoard tmp;
	tmp.white = 0;
	tmp.black = 0;
	uint64_t wcols[8] = {
		inverse_last_8bit(_bextr_u64(base.white,  0, 8)),
		inverse_last_8bit(_bextr_u64(base.white,  8, 8)),
		inverse_last_8bit(_bextr_u64(base.white, 16, 8)),
		inverse_last_8bit(_bextr_u64(base.white, 24, 8)),
		inverse_last_8bit(_bextr_u64(base.white, 32, 8)),
		inverse_last_8bit(_bextr_u64(base.white, 40, 8)),
		inverse_last_8bit(_bextr_u64(base.white, 48, 8)),
		inverse_last_8bit(_bextr_u64(base.white, 56, 8)),
	
	};
	uint64_t bcols[8] = {
		inverse_last_8bit(_bextr_u64(base.black,  0, 8)),
		inverse_last_8bit(_bextr_u64(base.black,  8, 8)),
		inverse_last_8bit(_bextr_u64(base.black, 16, 8)),
		inverse_last_8bit(_bextr_u64(base.black, 24, 8)),
		inverse_last_8bit(_bextr_u64(base.black, 32, 8)),
		inverse_last_8bit(_bextr_u64(base.black, 40, 8)),
		inverse_last_8bit(_bextr_u64(base.black, 48, 8)),
		inverse_last_8bit(_bextr_u64(base.black, 56, 8)),
	};
	uint64_t dst_pdeps[8] = {
		(BB_00 | BB_10 | BB_20 | BB_30 | BB_40 | BB_50 | BB_60 | BB_70),
		(BB_01 | BB_11 | BB_21 | BB_31 | BB_41 | BB_51 | BB_61 | BB_71),
		(BB_02 | BB_12 | BB_22 | BB_32 | BB_42 | BB_52 | BB_62 | BB_72),
		(BB_03 | BB_13 | BB_23 | BB_33 | BB_43 | BB_53 | BB_63 | BB_73),
		(BB_04 | BB_14 | BB_24 | BB_34 | BB_44 | BB_54 | BB_64 | BB_74),
		(BB_05 | BB_15 | BB_25 | BB_35 | BB_45 | BB_55 | BB_65 | BB_75),
		(BB_06 | BB_16 | BB_26 | BB_36 | BB_46 | BB_56 | BB_66 | BB_76),
		(BB_07 | BB_17 | BB_27 | BB_37 | BB_47 | BB_57 | BB_67 | BB_77),
	};

	for(int i =0; i < 8; i++){
		tmp.black |= _pdep_u64(bcols[i], dst_pdeps[i]);
		tmp.white |= _pdep_u64(wcols[i], dst_pdeps[i]);
	}

	return tmp;
}
inline uint8_t continuous_left(uint64_t board, uint64_t bb_pos){
	uint64_t mask = 0x7f7f7f7f7f7f7f7f;
	uint8_t i = 0;
	board = (board& mask) << 1;
	while( bb_pos & board ){
		board = (board & mask) << 1;
		i++;
	}
	return i;
}
inline uint8_t continuous_right(uint64_t board, uint64_t bb_pos){
	uint64_t mask = 0xfefefefefefefefe;
	uint8_t i = 0;
	board = (board & mask) >> 1;
	while( bb_pos & board ){
		board = (board & mask) >> 1;
		i++;
	}
	return i;
}
inline uint8_t continuous_down(uint64_t board, uint64_t bb_pos){
	uint64_t mask = 0xffffffffffffff00;
	uint8_t i = 0;
	board = (board & mask) >> 8;
	while( bb_pos & board ){
		board = (board & mask) >> 8;
		i++;
	}
	return i;
}
inline uint8_t continuous_up(uint64_t board, uint64_t bb_pos){
	uint64_t mask = 0x00ffffffffffffff;
	uint8_t i = 0;
	board = (board & mask) << 8;
	while( bb_pos & board ){
		board = (board & mask) << 8;
		i++;
	}
	return i;
}
inline uint8_t continuous_upperleft(uint64_t board, uint64_t bb_pos){
	uint64_t mask = 0x007f7f7f7f7f7f7f;
	uint8_t i = 0;
	board = (board & mask) << 9;
	while( bb_pos & board ){
		board = (board & mask) << 9;
		i++;
	}
	return i;

}
inline uint8_t continuous_upperright(uint64_t board, uint64_t bb_pos){
	uint64_t mask = 0x00fefefefefefefe;
	uint8_t i = 0;
	board = (board & mask) << 7;
	while( bb_pos & board ){
		board = (board & mask) << 7;
		i++;
	}
	return i;

}
inline uint8_t continuous_lowerleft(uint64_t board, uint64_t bb_pos){
	uint64_t mask = 0xfefefefefefefe00;
	uint8_t i = 0;
	board = (board & mask) >> 7;
	while( bb_pos & board ){
		board = (board & mask) >> 7;
		i++;
	}
	return i;
}
inline uint8_t continuous_lowerright(uint64_t board, uint64_t bb_pos){
	uint64_t mask = 0x7f7f7f7f7f7f7f00;
	uint8_t i = 0;
	board = (board & mask) >> 9;
	while( bb_pos & board ){
		board = (board & mask) >> 9;
		i++;
	}
	return i;
}
