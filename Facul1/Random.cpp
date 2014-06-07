//+_+_+_+_+_+_+__+__+__+__+__+_+_
//_+__+_By: "Sir" Arthur_+__+__+_
//+_+_+_+_+_+_+__+__+__+__+__+_+_

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
int main()
{
    srand((unsigned)time(0));
    int m[4][4];

    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4;j++)
            {
                m[i][j] = (rand()%99);
            }
    for(int i = 0; i < 4; i++)
    {
        cout << "\n";
            for(int j = 0; j < 4;j++)
            {
                cout << " ";
                cout << m[i][j];
            }
    }
}
