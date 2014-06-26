#include <dos.h>
#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <stdlib.h>
#include <conio.h>
#include <unistd.h>
#include <windows.h>

int main()
{
	//variaveis
	//gerais
	int Valores_Sorteados[6];
	int Numero_Identificacao[20];
	int Numeros_Apostaddos[20][15];
	int Numero_Acertos[20];
	int Opcao;
	int Conta_Aposta;
	int Cadastro_Apostadores;
	//auxiliares
	int Conta_Apostadores;
	int Valor_Aposta;
	int Valor_ApostaV2;
	bool impostor;
	bool repetido;
	int x;
	//
	//zera a variavei
	for (int i=0; i < 20 ; i++){ Numero_Acertos[i] = 0; for (int j = 0; j < 15; ++j) Numeros_Apostaddos[i][j] = 0;}
	for (int i=0; i < 20 ; i++) Numero_Identificacao[i] = 0;
	for (int i=0; i < 6 ; i++) Valores_Sorteados[i] = 0;


	Conta_Apostadores = 0;
	Opcao = 1;
	Conta_Aposta = 0;
	//
	//randonizador
	srand((unsigned)time(0));
	//
	//Menu
	do{
        system("cls");
		if((Opcao < 1) || (Opcao > 6))
			printf("*** A opcao deve estar entre 1 e 5 !!!\n\n");

		printf("\n\n");
		printf("  ______*_____*__****__*****_____ **___________________________________ \n");
		printf(" / _____**___**__*____*__________*__*________________________________  |\n");
		printf("/ /     * * * *  **** *  ***    ******                               | |\n");
		printf("| |     *  *  *  *    *    **   *    *                               | |\n");
		printf("| |     *     *  ****  ******  *      *                              | |\n");
		printf("| |***********************************************************       | |\n");
		printf("| |    1 - Adicionar apostador                                       | |\n");
		printf("| |    2 - Gerar apostadores                                         | |\n");
		printf("| |    3 - Gerar numeros sorteados                                   | |\n");
		printf("| |    4 - Adicionar numeros sorteados                               | |\n");
		printf("| |    5 - Finalizar e visualizar resultados                         | |\n");
		printf("| |***********************************************************       | |\n");
		printf("| |                                *****   ****   **    *    **      | |\n");
		printf("| |                               ***      *      * *   *   *  *     | |\n");
		printf("| |                                 ****   ****   *  *  *  ******    | |\n");
		printf("| |___________________________________***__*______*_  *_*__*____*___/  |\n");
		printf("|_________________________________****** __*****__*____**_*______*____/ \n");
		printf(">>> ");
		scanf("%d",&Opcao);
        system("cls");
		switch(Opcao){
	    case 1:
	    	printf("Quantos apostadores voce deseja cadastras MAX = 20\n");
	    	printf(">>> ");
	    	scanf("%d",&Cadastro_Apostadores);

	    	for(int i=0; i < Cadastro_Apostadores; i++){
	    		if(Conta_Apostadores > 18) i = Cadastro_Apostadores;

	    		if(Conta_Apostadores < 20){
	    			printf("\tBem vindo apostador %d\n",Conta_Apostadores+1);
	    			do{
	    				x=0;
	    				printf("\tInforme o seu numero de identificacao\n");
	    				printf(">>> ");
						scanf("%d",&Numero_Identificacao[Conta_Apostadores]);
						for(int j=0; j< 20; j++){
							if((Numero_Identificacao[Conta_Apostadores] == Numero_Identificacao[j]) && (Conta_Apostadores != j) ){
								printf("Essa id já existe\n");
								x = 1;
								impostor = true;
							}else if(x == 0){
								impostor = false;
							}
						}
					}while(impostor == true);
					do{
						printf("\tQuantos numeros voce quer apostar de 6 ate 15\n");
						printf(">>> ");
						scanf("%d",&Valor_Aposta);
						if ((Valor_Aposta < 6) || (Valor_Aposta > 15))
							printf("SOMENTE NUMERO ENTRE 6 E 15 !!!\n");
					}while((Valor_Aposta < 6) || (Valor_Aposta > 15));
					Valor_ApostaV2 = Valor_Aposta *2;
					Conta_Aposta = 0;
					for (Valor_Aposta; Valor_Aposta < Valor_ApostaV2; Valor_Aposta++){
						do{
							do{
								x=0;
								printf("\n\t\tNumero %d\n",Conta_Aposta+1);
								printf(">>> ");
								scanf("%d",&Numeros_Apostaddos[Conta_Apostadores][Conta_Aposta]);
								for(int j=0; j < 15;j++)
									if((Numeros_Apostaddos[Conta_Apostadores][Conta_Aposta] == Numeros_Apostaddos[Conta_Apostadores][j]) && (Conta_Aposta != j)){
										printf("Numero repetido, digite outro !!!\n");
										repetido = true;
										x++;
									}else if(x == 0){
										repetido = false;
									}
							}while(repetido == true);
							if((Numeros_Apostaddos[Conta_Apostadores][Conta_Aposta] < 1) || (Numeros_Apostaddos[Conta_Apostadores][Conta_Aposta] > 60))
								printf("O numero deve estar entre 1 e 60 !!!\n");
						}while((Numeros_Apostaddos[Conta_Apostadores][Conta_Aposta] < 1) || (Numeros_Apostaddos[Conta_Apostadores][Conta_Aposta] > 60));
						Conta_Aposta++;
					}
					Conta_Aposta = 0;
	    			Conta_Apostadores++;
	    		}else{
	    			printf("Ja existem 20 apostadores\n");
	    			printf("Voltando ao menu em 5 segundos...\n");
	    			Sleep(5000);
	    		}
	    	}
	    	break;
        case 2:
        	printf("Quantos apostadores voce deseja randonizar MAX = 20\n");
        	printf(">>> ");
	    	scanf("%d",&Cadastro_Apostadores);

	    	for(int i=0; i < Cadastro_Apostadores; i++){
	    		if(Conta_Apostadores > 18) i = Cadastro_Apostadores;

	    		if(Conta_Apostadores < 20){
	    			do{
	    				x=0;
						Numero_Identificacao[Conta_Apostadores] = (rand()%20+1);
						for(int j=0; j< 20; j++){
							if((Numero_Identificacao[Conta_Apostadores] == Numero_Identificacao[j]) && (Conta_Apostadores != j) ){
								x = 1;
								impostor = true;
							}else if(x == 0){
								impostor = false;
							}
						}
					}while(impostor == true);
					do{
						Valor_Aposta = (rand()%15+6);
					}while((Valor_Aposta < 6) || (Valor_Aposta > 15));
					Valor_ApostaV2 = Valor_Aposta *2;
					Conta_Aposta = 0;
					for (Valor_Aposta; Valor_Aposta < Valor_ApostaV2; Valor_Aposta++){
						do{
							do{
								x=0;
								Numeros_Apostaddos[Conta_Apostadores][Conta_Aposta] = (rand()%60+1);
								for(int j=0; j < 15;j++)
									if((Numeros_Apostaddos[Conta_Apostadores][Conta_Aposta] == Numeros_Apostaddos[Conta_Apostadores][j]) && (Conta_Aposta != j)){
										repetido = true;
										x++;
									}else if(x == 0){
										repetido = false;
									}
							}while(repetido == true);
						}while((Numeros_Apostaddos[Conta_Apostadores][Conta_Aposta] < 1) || (Numeros_Apostaddos[Conta_Apostadores][Conta_Aposta] > 60));
						Conta_Aposta++;
					}
					Conta_Aposta = 0;
	    			Conta_Apostadores++;
	    		}else{
	    			printf("Ja existem 20 apostadores\n");
	    			printf("Voltando ao menu em 5 segundos...\n");
	    			Sleep(5000);
	    		}
	    	}
        	break;
        case 3:
        	for(int i=0; i < 6; i++){
				do{
					do{
						x=0;
						Valores_Sorteados[i] = (rand()%60+1);
						for(int j=0; j < 6;j++)
							if((Valores_Sorteados[i] == Valores_Sorteados[j]) && (i != j)){
									x++;
								}else if(x == 0){
									repetido = false;
								}
					}while(repetido == true);
				}while((Valores_Sorteados[i] < 1) || (Valores_Sorteados[i] > 60));
        	}

        	break;
        case 4:
        	for(int i=0; i < 6; i++){
				do{
					do{
						x=0;
						printf("\n\t\tNumero %d\n",i+1);
						printf(">>> ");
						scanf("%d",&Valores_Sorteados[i]);
						for(int j=0; j < 6;j++)
							if((Valores_Sorteados[i] == Valores_Sorteados[j]) && (i != j)){
									printf("Numero repetido, digite outro !!!\n");
									x++;
								}else if(x == 0){
									repetido = false;
								}
					}while(repetido == true);
					if((Valores_Sorteados[i] < 1) || (Valores_Sorteados[i] > 60))
						printf("O numero deve estar entre 1 e 60 !!!\n");
				}while((Valores_Sorteados[i] < 1) || (Valores_Sorteados[i] > 60));
        	}

        	break;
        case 5:
        	for(int i=0; i < 20; i++)
        		for(int j=0; j < 6; j++)
        			for(int k=0; k < 15; k++){
        				if (Numeros_Apostaddos[i][k] == Valores_Sorteados[j])
        					if(Numeros_Apostaddos[i][k] != 0)
        						Numero_Acertos[i] = Numero_Acertos[i] +1;
        			}

        	break;
        default: printf("\n\nOpcao invalida!!!\n\n"); continue;
    	}
	}while(Opcao != 5);
	for(int i=0; i < 20; i++)
		if(Numero_Acertos[i] == 6)
			printf("\t\t\tO apostador de ID %d acertou todos numeros sorteados!!!\n\n",Numero_Identificacao[i]);

	for(int i=0; i < 20; i++)
		if(Numero_Identificacao[i] != 0)
			printf("O apostador de ID %d acertou os %d numeros!!!\n",Numero_Identificacao[i], Numero_Acertos[i]);
	return 0;
}

