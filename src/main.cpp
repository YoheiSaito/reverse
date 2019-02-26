#include "def.hpp"

int main(void){
	std::unique_ptr<BitBoard> w(new BitBoard);
	w->one = 0x0000000034000000;
	w->opp = 0x0000001c08100000;
	w->print(BLACK);
}

