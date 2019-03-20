#include "def.hpp"
#include <stdlib.h>

int main(void){
	BitBoard_p b(new BitBoard);

	/* b->black = 0x0000000034000000; */
	/* b->white = 0x0000001c08100000; */

	/* b->black = 0x0000001038102000; */
	/* b->white = 0x000000080021C080; */

	//right test
	/* b->black = 0x7f7f7f7f7f7f7f7f; */
	/* b->black= 0x0400004080000000; */
	/* b->white= 0x0800008100000000; */

	bool f_put = false, s_put = false;
	Agent_p  first_player = agent_select(BLACK);
	Agent_p second_player = agent_select(WHITE);
	while(1){
		// agent1 の行動
		system("clear");
		if( (b->white| b->black) == 0xffffffffffffffff)
			break;
		f_put = ( first_player->placeable_count(b) > 0);
		if(f_put){
			b = first_player->think(b);
		}else if( !s_put){
			b->print();
			break;
		}else{
			std::cout << "p1 no moves" << std::endl;
			b->print(BLACK);
			sleep(1);

		}
		// agent2の行動
		system("clear");
		if( (b->black| b->white) == 0xffffffffffffffff)
			break;
		s_put = (second_player->placeable_count(b) > 0);
		if(s_put){
			b = second_player->think(b);
		} else if(!f_put){
			b->print();
			break;
		}else{
			std::cout << "p2 no moves" << std::endl;
			b->print(WHITE);
			sleep(1);
		}
	}
	// 勝敗判定
	b->print();
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

