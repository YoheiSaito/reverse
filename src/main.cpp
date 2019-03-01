#include "def.hpp"
#include <stdlib.h>

int main(void){
	BitBoard_p b(new BitBoard);

	/* b->black = 0x0000000034000000; */
	/* b->white = 0x0000001c08100000; */

	/* b->black = 0x0000001038102000; */
	/* b->white = 0x000000080021C080; */

	bool f_put = false, s_put = false;
	Agent_p  first_player = agent_select(BLACK);
	Agent_p second_player = agent_select(WHITE);
	while(1){
		system("clear");
		f_put = ( first_player->placeable_count(b) > 0);
		if(f_put){
			b = first_player->think(b);
		}else if( !s_put){
			b->print();
			break;
		}

		system("clear");
		s_put = (second_player->placeable_count(b) > 0);
		if(s_put){
			b = second_player->think(b);
		} else if(!f_put){
			b->print();
			break;
		}
	}
	int32_t c = evalate_end(b);
	if(c > 0){
		std::cout << "    Won first player ( "<< popcount(b->black) 
			<< " : " << popcount(b->white) <<" )" << std::endl;
	}else if( c < 0){
		std::cout << "    Won second player ( "<< popcount(b->black) 
			<< " : " << popcount(b->white) <<" )" << std::endl;
	}else{
		std::cout << "draw" << std::endl;
	}

}

