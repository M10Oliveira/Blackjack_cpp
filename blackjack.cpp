#include<stdio.h>
#include<iostream>
#include<locale.h>
#include<cstdlib>
#include<time.h>
#include<string.h>

using namespace std;
//criados oos vetores das cartas e naipes
string vetCartas[12] = {"A", "2", "3","4", "5", "6", "7","8", "9", "10", "10", "10"};
string vetNaipes[4] = {" de Espadas", " de Paus", " de Ouros", " de Copas"};
//matrizes simulado a mão do jogador e do crupier
string cartasCrupier[5][2];
string cartasJogador[5][2];
int i, j, pontosJog, pontosCrupier;


int main(){
    setlocale(LC_ALL, "Portuguese");
    srand(time(0));
	//Sorteando as cartas do JOGADOR 
	for(i=0;i<=1;i++){
		cartasJogador[i][0] = vetCartas[rand() % 12];
		cartasJogador[i][1] = vetNaipes[rand() % 4];
		pontosJog = pontosJog + stoi(cartasJogador[i][0]);
	}
    cout << "*-- Cartas do Jogador --* \n" << endl;
	for(i=0;i<=1;i++){
		for(j=0;j<=1;j++){
			cout << cartasJogador[i][j];
		}
		cout << endl;		
	}
	cout<<"Total de pontos: " <<pontosJog<< endl;
	//Sorteando as cartas do CRUPIER
	for(i=0;i<=1;i++){
		cartasCrupier[i][0] = vetCartas[rand() % 12];
		cartasCrupier[i][1] = vetNaipes[rand() % 4];
	}
    cout << "\n*-- Cartas do Crupier --*\n" << endl;
	cout << cartasCrupier[0][0];
	cout << cartasCrupier[0][1]<<endl;
	cout << "****"<<endl;


}
