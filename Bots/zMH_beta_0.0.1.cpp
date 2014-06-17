#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <cstdlib>
#include <thread>

using namespace std;

int n=0;
int HP = 0,HPMAX = 0,MP = 0,MPMAX = 0;

int atk()
{
    n++;
    cout << "Ataque numero: " << n;
	keybd_event(VK_F1,0,0,0);
	Sleep(5000);
	keybd_event(VK_F1,0,0,0);
	Sleep(5000);
	keybd_event(VK_TAB,0,0,0);
	keybd_event(VK_F1,0,0,0);
	Sleep(5000);
    	keybd_event(VK_F1,0,0,0);
    	keybd_event(VK_F1,0,0,0);
    	keybd_event(VK_F1,0,0,0);
	Sleep(5000);
}
int pot()
{
    cout << n <<"\nNovo teste de pot\n";
    HWND hWnd = FindWindow(0, "12345");
    DWORD pId;
    GetWindowThreadProcessId(hWnd, &pId);
    HANDLE hProc = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pId);
    ReadProcessMemory(hProc,(void*)0x168C26B8,&HP,sizeof(HP),0);
    ReadProcessMemory(hProc,(void*)0x168C26B8,&HPMAX,sizeof(HPMAX),0);
    ReadProcessMemory(hProc,(void*)0x19B46A8C,&MP,sizeof(MP),0);
    ReadProcessMemory(hProc,(void*)0x19B46AD4,&MPMAX,sizeof(MPMAX),0);
    if (HP == HPMAX )
    {
        cerr<< "HP alto: " << HP << endl;
        Sleep(2000);
    }
    if (HP <= (70*HPMAX)/100 )
    {
        cerr << "HP baixo: " << HP << endl;
        keybd_event(0x71,0,0,0);
        Sleep(2000);
    }
    if (MP == MPMAX )
    {
        cerr<< "MP alto: " << MPMAX << endl;
        Sleep(2000);
    }
    if (MP <= (70*MPMAX)/100 )
    {
        cerr << "MP baixo: " << MP << endl;
        keybd_event(VK_F3,0,0,0);
        Sleep(2000);
    }
}

int main()
{
    int wat = 0;
	cout << "Bem vindo ao bot para PWBR zMH, version 0.0.1B\n";
	do{
		cout << "\nPara iniciar o Bot aperte 1 ou aperte 2 para ajuda e 3 para finalizar\n>>> ";
		cin >> wat;
	}while (wat != 1 && wat != 2 && wat != 3);

    if (wat == 1)
    {
        Sleep(10000);
        for(;;)
        {
            system("CLS");
            //thread thread_1 = thread(atk);
            thread thread_2 = thread(pot);
            //thread_1.join();
            thread_2.join();
        }
        return 0;
    }
    else if (wat == 2)
    {
        cout << "Obs: E necessario deixar a janela aberta esse problema será resolvido em breve\n";
        cout << "A fazer\n";
        cout << "A fazer\n";
        cout << "A fazer\n";
        cout << "Para versão 0.0.2B\n";
        cout << "O bot será fechado, assim que precionado enter\n\n\n";
    }
    else if (wat == 3)
    {
        return 0;
    }
}

