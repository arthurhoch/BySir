//+_+_+_+_+_+_+__+__+__+__+__+_+_
//_+__+_By: "Sir" Arthur_+__+__+_
//+_+_+_+_+_+_+__+__+__+__+__+_+_

#include <stdio.h>
#include <ctime>
#include <cstdlib>

int main()
{
	int Tabuleiro[6][6];
	char Tabuleiro_Esconde[6][6];
	int Numero_minas = 0;
	int Conta_minas = 0;
	int Funcao_secreta = 0;
	int Sorteio;
	int local = 0;
	int Numero_Coluna = 1;
	int Local_Linha = 0;
	int Local_Coluna = 0;
	int termina = 0;
	int soma = 0;
	int resultado = 0;
	//Zera as variaveis
	for(int i = 0; i < 6; i++) for(int j = 0; j< 6; j++){
		Tabuleiro[i][j] = 0;
		Tabuleiro_Esconde[i][j] = 0;
	}
	//Inicia o contador para o rand
	srand((unsigned)time(0));
	//Sortear minas
	for(int i = 1; i < 6; i++){
		for(int j = 1; j < 6; j++){
			Tabuleiro_Esconde[i][j] = ' ';
			if(Numero_minas >= 10){
				continue;
			}else{
				Sorteio = (rand()%4);
				if(Sorteio == 1){
					Tabuleiro[i][j] = 9;
					Numero_minas++;
				}else{
					Tabuleiro[i][j] = 0;
				}

			}
			Sorteio = 0;
		}
	}
	//Coloca os numero conforme o numero de minas
	for (int i = 1; i < 6; i++){
		for (int j = 1; j < 6; j++){
			if(Tabuleiro[i][j] == 9){

				if(Tabuleiro[i+1][j] != 9)
					Tabuleiro[i+1][j]++;
				if(Tabuleiro[i][j+1] != 9)
					Tabuleiro[i][j+1]++;
				if(Tabuleiro[i+1][j+1] != 9)
					Tabuleiro[i+1][j+1]++;
				if(Tabuleiro[i-1][j] != 9)
					Tabuleiro[i-1][j]++;
				if(Tabuleiro[i][j-1] != 9)
					Tabuleiro[i][j-1]++;
				if(Tabuleiro[i-1][j-1] != 9)
					Tabuleiro[i-1][j-1]++;
				if(Tabuleiro[i+1][j-1] != 9)
					Tabuleiro[i+1][j-1]++;
				if(Tabuleiro[i-1][j+1] != 9)
					Tabuleiro[i-1][j+1]++;
			}
		}
	}
	//Calcula a soma para finalizar o programa caso o usuario seja vitorioso no game
	for (int i = 1; i < 6; i++){
		for (int j = 1; j < 6; j++){
			if(Tabuleiro[i][j] != 9)
				soma = soma + Tabuleiro[i][j];
		}
	}
	printf("\n\n*********************************************************\n");
	printf("***Missão do dia preencha isso sem achar nenhuma bomba***\n");
	printf("*********************************************************\n\n");
	printf("Codigo disponivel em ***github.com/arthurhoch/BySir***\n\n\n");
	do{
		//Desenha a tabela de respostas
		if (Funcao_secreta == 1){
			printf("\t\t ---------------------");
			for (int i = 1; i < 6; i++){
				printf("\n\t\t | ");
				for (int j = 1; j < 6; j++){
					printf("%d | ",Tabuleiro[i][j]);
				}
			}
			printf("\n\t\t ---------------------\n\n");
			Funcao_secreta = 0;
		}
		//Desenha a tabela a ser preenchida
		if (Funcao_secreta == 0){
			printf("\t\t    1   2   3   4   5\n");
			printf("\t\t  ---------------------");
			for (int i = 1; i < 6; i++){
				printf("\n\t\t%d | ",Numero_Coluna);
				Numero_Coluna++;
				for (int j = 1; j < 6; j++){
					printf("%c | ",Tabuleiro_Esconde[i][j]);
				}
			}
			printf("\n\t\t  ---------------------\n\n\n\n");
		}
		if (termina == 1)
			return 0;
		Numero_Coluna = 1;
		//Estrada de dados
		printf("\nDigite a localização que voce quer abrir: Ex linha 2 (enter), coluna 3 (enter) p/ 2,3 \n");
		scanf("%d",&Local_Coluna);
		scanf("%d",&Local_Linha);
		printf("\n");
		//Ativa a função SECRETA quando os numeros digitados forrem 99 e 99
		if (Local_Linha == 99 && Local_Coluna == 99)
			Funcao_secreta = 1;
		//Informaoes do jogo localizacaso digitada e bombas a redor da localizacao digitada
		printf("\n\tLocalização digitada [%d][%d]\n",Local_Linha,Local_Coluna);
		if(Tabuleiro[Local_Linha][Local_Coluna] !=9)
			printf("\tTendo %d bombas ao redor\n\n\n",Tabuleiro[Local_Linha][Local_Coluna]);
		//Tabuleiro_esconde recebe o numero de bombas que existem ao seu redor
		switch (Tabuleiro[Local_Linha][Local_Coluna]){
			case 0:
				Tabuleiro_Esconde[Local_Linha][Local_Coluna] = '0';
				//Se não tiver nenhum bomba no local selecionado
				//esse codigo busca na tabela locais ao redor
				//por pontos aonde n tenham bombas
				if(Tabuleiro[Local_Linha+1][Local_Coluna] == 0)
					Tabuleiro_Esconde[Local_Linha+1][Local_Coluna] = '0';
				if(Tabuleiro[Local_Linha][Local_Coluna+1] == 0)
					Tabuleiro_Esconde[Local_Linha][Local_Coluna+1] = '0';
				if(Tabuleiro[Local_Linha+1][Local_Coluna+1] == 0)
					Tabuleiro_Esconde[Local_Linha+1][Local_Coluna+1] = '0';
				if(Tabuleiro[Local_Linha-1][Local_Coluna] == 0)
					Tabuleiro_Esconde[Local_Linha-1][Local_Coluna] = '0';
				if(Tabuleiro[Local_Linha][Local_Coluna-1] == 0)
					Tabuleiro_Esconde[Local_Linha][Local_Coluna-1] = '0';
				if(Tabuleiro[Local_Linha-1][Local_Coluna-1] == 0)
					Tabuleiro_Esconde[Local_Linha-1][Local_Coluna-1] = '0';
				if(Tabuleiro[Local_Linha+1][Local_Coluna-1] == 0)
					Tabuleiro_Esconde[Local_Linha+1][Local_Coluna-1] = '0';
				if(Tabuleiro[Local_Linha-1][Local_Coluna+1] == 0)
					Tabuleiro_Esconde[Local_Linha-1][Local_Coluna+1] = '0';
				break;
			case 1:
				Tabuleiro_Esconde[Local_Linha][Local_Coluna] = '1';
				break;
			case 2:
				Tabuleiro_Esconde[Local_Linha][Local_Coluna] = '2';
				break;
			case 3:
				Tabuleiro_Esconde[Local_Linha][Local_Coluna] = '3';
				break;
			case 4:
				Tabuleiro_Esconde[Local_Linha][Local_Coluna] = '4';
				break;
			case 5:
				Tabuleiro_Esconde[Local_Linha][Local_Coluna] = '5';
				break;
			case 6:
				Tabuleiro_Esconde[Local_Linha][Local_Coluna] = '6';
				break;
			case 7:
				Tabuleiro_Esconde[Local_Linha][Local_Coluna] = '7';
				break;
			case 8:
				Tabuleiro_Esconde[Local_Linha][Local_Coluna] = '8';
				break;
			default:
				break;
		}
		resultado = resultado + Tabuleiro[Local_Linha][Local_Coluna];
		//Mensagem final de vitoria ou derota no jogo
		if (Tabuleiro[Local_Linha][Local_Coluna] == 9){
			Tabuleiro_Esconde[Local_Linha][Local_Coluna] = 'B';
			printf("\n\t\t\t Você perdeu HAHAHA!!!");
			printf("\n\t\t\t Da-le bomba nele!!!\n\n\n\n");
			termina++;
		}else if(soma == resultado){
			printf("\n\n ** Parabens voce venceu na vida, ops no jogo! ** \n\n");
			printf("\t\t    1   2   3   4   5\n");
			printf("\t\t  ---------------------");
			for (int i = 1; i < 6; i++){
				printf("\n\t\t%d | ",Numero_Coluna);
				Numero_Coluna++;
				for (int j = 1; j < 6; j++){
					printf("%c | ",Tabuleiro_Esconde[i][j]);
				}
			}
		return 0;
		}
	}while(Local_Coluna > -1);	
	return 0;
}
