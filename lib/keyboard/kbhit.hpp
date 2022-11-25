#ifndef _KBHIT_HPP
#define _KBHIT_HPP
    
#include <termios.h>
    
class keyboard{
    public:
        keyboard();
        ~keyboard();
        int kbhit();
        int getch();

    private:
        struct termios initial_settings, new_settings;
        int peek_character;
};
    
#endif

/*  Example

#include "kbhit.h"

int main(){
    int key_nr;
    char key;
    keyboard keyb;
    do{
        if( keyb.kbhit() ){
            key_nr = keyb.getch(); //return int
            key = key_nr; // get ascii char
            // do some stuff
        }
    }while(key != 'q');
    return 0;
}

*/
