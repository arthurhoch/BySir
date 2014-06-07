//+_+_+_+_+_+_+__+__+__+__+__+_+_
//_+__+_By: "Sir" Arthur_+__+__+_
//+_+_+_+_+_+_+__+__+__+__+__+_+_

#include <stdlib.h> //system
#include <iostream> //cin cout
int main()
{
    for (;;)
    {
        system("eject");
        system("xset -display :0.0 dpms force off");
        system("firefox -search 'You dead tomorrow'");
        system("sleep 5");
        system("xset -display :0.0 dpms force on");
        for(int i=0; i < 1000;i++)
            std::cout << "You need to dead tomorrow!!!\n";
        return 0;
    }
    return 0;
}
