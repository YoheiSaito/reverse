#include "def.hpp"

int main(void){
	BitBoard_p w(new BitBoard);
	/* w->one = 0x0000000034000000; */
	/* w->opp = 0x0000001c08100000; */
	std::string s;
	while(1){
		w->print(BLACK);
		std::cin >> s;
		boost::trim(s);
		w = put_black(w, BBpos[s[1]-'1'][s[0]-'a']);
		w->print(WHITE);
		std::cin >> s;
		boost::trim(s);
		w = put_white(w, BBpos[s[1]-'1'][s[0]-'a']);
	}
}

