#pragma once

struct HumanAgent : public Agent{
	HumanAgent(int turn):
		Agent(turn)
	{
	}
	BitBoard_p think(BitBoard_p& b){
		b->print(_turn);
		std::string s;
		do{
			std::cout << ((_turn==BLACK)?"first(X)":"second(O)")
				<< " player>> " << std::flush;
			std::cin >> s;
			boost::trim(s);

			if('1' > s[1] || s[1] > '8'){
				std::cout << "illegal input" << std::endl;
				continue;
			}
			if ('a' > s[0] || s[0] > 'h'){
				std::cout << "illegal input" << std::endl;
				continue;
			}
			int64_t pos = BBpos[s[1]-'1'][s[0]-'a'];
			BitBoard_p tmp = agent_put(b,pos);
			if(tmp != nullptr)
				return tmp;
			std::cout << "That point is not able to place\n";
		}while(1);
	}
};
