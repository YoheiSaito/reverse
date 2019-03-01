#pragma once
#include "def.hpp"

using PosVect = std::vector<uint64_t>;
struct Agent{
	int _turn;
	Agent(int turn){
		_turn = turn;
	}
	int placeable_count(BitBoard_p& b){
		auto s = b->to_string(_turn);
		int i = 0;
		for(auto&& c : s){
			if(c == '*'){
				i++;
			}
		}
		return i;
	}

	PosVect placeable_pos(BitBoard_p& b){
		PosVect v;
		auto s = b->to_string(_turn);
		int i = 0;
		for(auto&& c : s){
			if(c == '*'){
				v.emplace_back(BBpos[i/8][i%8]);
			}
			i++;
		}
		return v;
	}

	PosVect placeable_pos(BitBoard_p& b, int turn){
		PosVect v;
		auto s = b->to_string(turn);
		int i = 0;
		for(auto&& c : s){
			if(c == '*'){
				v.emplace_back(BBpos[i/8][i%8]);
			}
			i++;
		}
		return v;
	}
	BitBoard_p agent_put(BitBoard_p& b, uint64_t pos){
		if(_turn == BLACK){
			if( placeable(b->black, b->white, pos))
				return put_black(b, pos);
		}else{
			if( placeable(b->white, b->black, pos))
				return put_white(b, pos);
		}
		return nullptr;
	}

	virtual BitBoard_p think(BitBoard_p& b) = 0;
	virtual ~Agent(){}

};
using Agent_p = std::unique_ptr<Agent>;

#include "HumanAgent.hpp"
#include "RandomAgent.hpp"
#include "ComputerAgent.hpp"

Agent_p agent_select(int turn){
	std::string s;
	long n;
	std::cout << "Select Player "<< (turn==BLACK?"1":"2")<<std::endl;
	std::cout << "    0) Human " << std::endl;
	std::cout << "    1) Random Selector" << std::endl;
	std::cout << "    n) Computer (Depth n)" << std::endl;
	std::cout << " >> " << std::flush;
	std::cin  >> s;
	boost::trim(s);
	n = std::stoi(s);

	if(n == 0){
		return Agent_p(new HumanAgent(turn));
	}else if( n == 1){
		return Agent_p(new RandomAgent(turn));
	}else{
		return Agent_p(new ComputerAgent(turn, n));
	}
};
