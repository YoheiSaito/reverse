#pragma once
#include "def.hpp"
#include <unistd.h>

using Evalate = std::pair<int64_t, int32_t>; 

struct ComputerAgent: public Agent{
	int maxdepth;
	ComputerAgent(int turn, int depth = 8):
		Agent(turn)
	{
		maxdepth = depth;
	}
	BitBoard_p think(BitBoard_p& b){
		b->print(_turn);
		auto t = negaScout(b, maxdepth, _turn);
		std::cout << t.second << std::endl;
		/* sleep(1); */
		return agent_put(b, t.first);

	}
	Evalate negaScout(BitBoard_p& bd, int depth, int turn,
			int32_t a = -INT32_MAX, int32_t b = INT32_MAX){

		if( (bd->black | bd->white) == 0xffffffffffffffff){
			return std::make_pair(0, (_turn==BLACK)?evalate_end(bd):-evalate_end(bd));
			/* return std::make_pair(0, evalate_end(bd)); */
		}

		PosVect ps = this->placeable_pos(bd, turn);
		if(ps.size()==0){
			return std::make_pair(0, 
					(_turn==BLACK)?
						-INT32_MAX:
						INT32_MAX);
		}
		if(depth == 0){
			return std::make_pair(0, (_turn==BLACK)?evalate(bd):-evalate(bd));
			/* return std::make_pair(0, evalate(bd)); */
		}
		// next board states is ps
		std::vector<BitBoard_p> next_node(ps.size());
		if( turn == BLACK)
			for(size_t i = 0; i < ps.size(); i++)
				next_node[i] = put_black(bd, ps[i]);
		else if( turn ==  WHITE)
			for(size_t i = 0; i < ps.size(); i++)
				next_node[i] = put_white(bd, ps[i]);
		
		int nturn = (turn==BLACK)?WHITE:BLACK;
		uint64_t best_pos = ps[0];
		for(size_t i = 0; i < next_node.size(); i++){
			auto ev = negaScout(next_node[i], depth-1, nturn, -b, -a);
			if(a < ev.second){
				best_pos = ps[i];
				a = ev.second;
			}
			if(a >= b)
				break;
		}
		return std::make_pair(best_pos, a);
	}
};
