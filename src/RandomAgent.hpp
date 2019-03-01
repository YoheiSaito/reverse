#include "def.hpp"
struct RandomAgent: public Agent{
	std::random_device rnd;
	RandomAgent(int turn): 
		Agent(turn)
	{
	}
	BitBoard_p think(BitBoard_p& b){
		b->print(_turn);
		auto v = placeable_pos(b);
		return agent_put(b, v[rnd()%v.size()]);
	}
};

