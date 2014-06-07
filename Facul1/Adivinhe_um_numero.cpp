//+_+_+_+_+_+_+__+__+__+__+__+_+_
//_+__+_By: "Sir" Arthur_+__+__+_
//+_+_+_+_+_+_+__+__+__+__+__+_+_

#include <iostream>
using namespace std;
int main()
{
        String acertos = "Acertadores\n";
        int palpite[19];
        int i,a=1,certo=4,j=1,rateiro,n_acertadores=0;
        for (i=0;i < 19; i++)
        {
            cout << "Apostador número: " << "\nPense em um número entre 1 e 10\n";
            cin >> palpite[]

            if (palpite[i] == certo)
            {
                acertos = acertos + "\n" + a;
                n_acertadores++;
            }
            a++;
        }
        if(n_acertadores > 0)
        {
            System.out.print(acertos+"\n");
            System.out.print("Roteiro por acertador: "+38/n_acertadores+ "\n");
        }else
            System.out.print("Ninguém acertou\n");


    }
    return 0;

}
