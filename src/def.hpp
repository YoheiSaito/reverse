#pragma once

#include <iostream>
#include <memory>
#include <vector>
#include <cinttypes>
#include <chrono>
#include <numeric>
#include <iterator>
#include <random>
#include <algorithm>

#include <immintrin.h>
#include <stdint.h>

#include <boost/algorithm/string.hpp>


constexpr uint64_t BB_00 = (1ll<<0);
constexpr uint64_t BB_01 = (1ll<<1);
constexpr uint64_t BB_02 = (1ll<<2);
constexpr uint64_t BB_03 = (1ll<<3);
constexpr uint64_t BB_04 = (1ll<<4);
constexpr uint64_t BB_05 = (1ll<<5);
constexpr uint64_t BB_06 = (1ll<<6);
constexpr uint64_t BB_07 = (1ll<<7);

constexpr uint64_t BB_10 = (1ll<<8);
constexpr uint64_t BB_11 = (1ll<<9);
constexpr uint64_t BB_12 = (1ll<<10);
constexpr uint64_t BB_13 = (1ll<<11);
constexpr uint64_t BB_14 = (1ll<<12);
constexpr uint64_t BB_15 = (1ll<<13);
constexpr uint64_t BB_16 = (1ll<<14);
constexpr uint64_t BB_17 = (1ll<<15);

constexpr uint64_t BB_20 = (1ll<<16);
constexpr uint64_t BB_21 = (1ll<<17);
constexpr uint64_t BB_22 = (1ll<<18);
constexpr uint64_t BB_23 = (1ll<<19);
constexpr uint64_t BB_24 = (1ll<<20);
constexpr uint64_t BB_25 = (1ll<<21);
constexpr uint64_t BB_26 = (1ll<<22);
constexpr uint64_t BB_27 = (1ll<<23);

constexpr uint64_t BB_30 = (1ll<<24);
constexpr uint64_t BB_31 = (1ll<<25);
constexpr uint64_t BB_32 = (1ll<<26);
constexpr uint64_t BB_33 = (1ll<<27);
constexpr uint64_t BB_34 = (1ll<<28);
constexpr uint64_t BB_35 = (1ll<<29);
constexpr uint64_t BB_36 = (1ll<<30);
constexpr uint64_t BB_37 = (1ll<<31);

constexpr uint64_t BB_40 = (1ll<<32);
constexpr uint64_t BB_41 = (1ll<<33);
constexpr uint64_t BB_42 = (1ll<<34);
constexpr uint64_t BB_43 = (1ll<<35);
constexpr uint64_t BB_44 = (1ll<<36);
constexpr uint64_t BB_45 = (1ll<<37);
constexpr uint64_t BB_46 = (1ll<<38);
constexpr uint64_t BB_47 = (1ll<<39);

constexpr uint64_t BB_50 = (1ll<<40);
constexpr uint64_t BB_51 = (1ll<<41);
constexpr uint64_t BB_52 = (1ll<<42);
constexpr uint64_t BB_53 = (1ll<<43);
constexpr uint64_t BB_54 = (1ll<<44);
constexpr uint64_t BB_55 = (1ll<<45);
constexpr uint64_t BB_56 = (1ll<<46);
constexpr uint64_t BB_57 = (1ll<<47);

constexpr uint64_t BB_60 = (1ll<<48);
constexpr uint64_t BB_61 = (1ll<<49);
constexpr uint64_t BB_62 = (1ll<<50);
constexpr uint64_t BB_63 = (1ll<<51);
constexpr uint64_t BB_64 = (1ll<<52);
constexpr uint64_t BB_65 = (1ll<<53);
constexpr uint64_t BB_66 = (1ll<<54);
constexpr uint64_t BB_67 = (1ll<<55);

constexpr uint64_t BB_70 = (1ll<<56);
constexpr uint64_t BB_71 = (1ll<<57);
constexpr uint64_t BB_72 = (1ll<<58);
constexpr uint64_t BB_73 = (1ll<<59);
constexpr uint64_t BB_74 = (1ll<<60);
constexpr uint64_t BB_75 = (1ll<<61);
constexpr uint64_t BB_76 = (1ll<<62);
constexpr uint64_t BB_77 = (1ll<<63);

struct BitBoard;
using BitBoard_p = std::unique_ptr<BitBoard>;
const uint64_t BBpos[8][8] = {
	{BB_00, BB_01, BB_02, BB_03, BB_04, BB_05, BB_06, BB_07},
	{BB_10, BB_11, BB_12, BB_13, BB_14, BB_15, BB_16, BB_17},
	{BB_20, BB_21, BB_22, BB_23, BB_24, BB_25, BB_26, BB_27},
	{BB_30, BB_31, BB_32, BB_33, BB_34, BB_35, BB_36, BB_37},
	{BB_40, BB_41, BB_42, BB_43, BB_44, BB_45, BB_46, BB_47},
	{BB_50, BB_51, BB_52, BB_53, BB_54, BB_55, BB_56, BB_57},
	{BB_60, BB_61, BB_62, BB_63, BB_64, BB_65, BB_66, BB_67},
	{BB_70, BB_71, BB_72, BB_73, BB_74, BB_75, BB_76, BB_77},
};
static const int NONE  =  1;
static const int BLACK =  0;
static const int WHITE = -1;

#include "BitBoard.hpp"
#include "BitBoardFunction.hpp"
#include "generate_put.hpp"
#include "evalation.hpp"
#include "agent.hpp"
