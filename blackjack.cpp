#include<stdio.h>
#include<iostream>
#include<locale.h>
#include<cstdlib>
#include<time.h>
#include<Windows.h>
#include<string.h>

using namespace std;
//criados os vetores das cartas e naipes
string vetCartas[12] = {"1", "2", "3","4", "5", "6", "7","8", "9", "10", "10", "10"};
string vetNaipes[4] = {" de Espadas", " de Paus", " de Ouros", " de Copas"};
//matrizes simulado a mão do jogador e do crupier
const int TAM_MAX = 10;
string vet, cartasCrupier[TAM_MAX][2], cartasJogador[TAM_MAX][2], replay="sim";
int i, j,ptj, ptc, pontosJog, pontosCrupier, opcao, pts; 
float aposta,  dinheiroTotal=1000;

void resetarJogo(){
	system("CLS");
	cout << "\tINICIANDO NOVA RODADA!!!";
	Sleep(3000);
	system("CLS");
	pontosJog=0;
	pontosCrupier=0;
	aposta=0;
	for(i=0;i<TAM_MAX;i++){
		for(j=0;j<=1;j++){
			cartasJogador[i][j]="";
			cartasCrupier[i][j]="";
		}
	}
	replay="sim";
	opcao=0;
}
int somarCartas(string vet[][2]){
	pts = 0;
	for(i=0;i<=TAM_MAX;i++){
		if(vet[i][0] ==""){
			break;
		}
		else{
			pts += stoi(vet[i][0]);
		}
	}
	return pts; 	
}
void iniciarJogo(){
	
	for(i=0;i<=1;i++){
		cartasJogador[i][0] = vetCartas[rand() % 1];
		cartasJogador[i][1] = vetNaipes[rand() % 4];
		pontosJog += stoi(cartasJogador[i][0]);
	}
    cout << "*-- Cartas do Jogador --* \n" << endl;
	for(i=0;i<=1;i++){
		for(j=0;j<=1;j++){
			cout << cartasJogador[i][j];
		}
		cout << endl;		
	}
	cout<<"\n"<<"Total de pontos: " <<pontosJog<< endl;
	//Sorteando as cartas do CRUPIER
	for(i=0;i<=1;i++){
		cartasCrupier[i][0] = vetCartas[rand() % 1];
		cartasCrupier[i][1] = vetNaipes[rand() % 4];
	}
    cout << "\n*-- Cartas do Crupier --*\n" << endl;
	cout << cartasCrupier[0][0] << cartasCrupier[0][1]<<endl << "****"<<endl;
}
void resultadoFinal(int opc, int ptj, int ptc){
	if(opc !=3){
		
		if(ptj>21){
			cout << "\nESTOUROU!! O CRUPIER GANHOU!!!!"<<endl;
				printf("Você perdeu R$%0.2f", aposta);
		}
		else if(ptj == ptc){
			cout << "\nEMPATE!!!"<<endl;
			dinheiroTotal += aposta;
			printf("Valor ganho R$%0.2f\n", aposta);
		}
		else if(ptc>ptj && ptc<=21){
			cout << "\nO CRUPIER GANHOU!!!!"<<endl;
			printf("Você perdeu R$%0.2f\n", aposta);
		}
		else{
			cout << "\nVOCÊ GANHOU!!!!!"<<endl;
			dinheiroTotal += aposta*2;
			printf("Valor ganho R$%0.2f\n", aposta*2);
		}
	}
}
void darCarta(string vet[][2]){
	for(i=0;i<=TAM_MAX;i++){
		if(vet[i][0] == ""){
			vet[i][0] = vetCartas[rand() % 12];
			vet[i][1] = vetNaipes[rand() % 4];
			Sleep(1000);
			cout <<vet[i][0];
			cout <<vet[i][1]<<endl;
			break;	
		}
		Sleep(1000);	
		cout << vet[i][0] << vet[i][1]<<endl;
	}
}
int main(){
    setlocale(LC_ALL, "Portuguese");
    srand(time(0));
	while(replay=="sim" || replay == "SIM"){		
		printf("Você tem R$%0.2f \nDeseja apostar quanto?\n", dinheiroTotal);
		
		cin >> aposta;
		while(aposta>dinheiroTotal){
		  	printf("Saldo insuficiente! Deseja apostar quanto?");
		   	cin >> aposta;
		}
		dinheiroTotal -= aposta;
		iniciarJogo();
		while(pontosJog < 21 && pontosCrupier < 17 && opcao!=3 && opcao!=4){
			opcao = 0;
			printf("\n\n	*-- OPÇÕES -**\n1=PEDIR CARTA\n2=DOBRAR APOSTA\n3=DESISTIR\n4=FICAR COM ESSAS\n");
			if(cartasJogador[0][0]==cartasJogador[1][0]){
				printf("5=DIVIDIR\n");
			}
			cin >> opcao;
			while(opcao != 1 && opcao != 2 && opcao != 3 && opcao != 4){
				printf("Opçao Iválida!!! Use entre 1 e 4\n");
				cin >> opcao;
			}
			switch(opcao){
				case 1:	
					printf("\n*-- Cartas do Jogador --*\n");
					darCarta(cartasJogador);
					pontosJog = somarCartas(cartasJogador);
					printf("\ntotal de pontos: %d",pontosJog);
					break;
				case 2:
					printf("Você dobrou a aposta de R$%0.2f para R$%0.2f\n", aposta, aposta*2);
					aposta += aposta*2;
					printf("*-- Cartas do Jogador --*");
					darCarta(cartasJogador);
					pontosJog = somarCartas(cartasJogador);
					printf("\ntotal de pontos: %d\n*-- Cartas do Crupier --*",pontosJog);		
					while(pontosCrupier <17 && pontosCrupier<pontosJog){
						Sleep(1000);	
						darCarta(cartasCrupier);
						pontosCrupier = somarCartas(cartasCrupier);
						Sleep(1000);
						
						printf("\ntotal de pontos crupier: %d\n", pontosCrupier);
					}
					break;				
				case 3:
					printf("Você desistiu e perdeu somente metade da aposta! Valor obtido: R$%0.2f", aposta/2);
					dinheiroTotal += aposta/2;
					break;						
				case 4:

					printf("\n*-- Cartas do Crupier --*\n");			
					while(pontosCrupier <17 && pontosCrupier<pontosJog){
						Sleep(1000);	
						darCarta(cartasCrupier);
						pontosCrupier = somarCartas(cartasCrupier);
						Sleep(1000);
						printf("\nSeus Pontos: %d\nPontos do Crupier: %d\n", pontosJog, pontosCrupier);
					}
					break;									
			}		
		}
		resultadoFinal(opcao, pontosJog, pontosCrupier);
		printf("\nDeseja Jogar Novamente?\n");
		cin>>replay;
		while(replay != "sim" && replay != "nao" && replay != "não" && replay !="SIM"){
			printf("Opção inválida!! Digite sim ou não");
			cin >> replay; 
		}
		resetarJogo();
	}

}
