#include"function.h"
#include"card.h"
using namespace std;


int card::getCard_a(int a) { return p[a]; }
int* card::getCard() { return p; }
int* card::getP() { return player; }
int* card::getP1() { return player1; }
int* card::getP2() { return player2; }
int* card::getL() { return landlord; }
card::card() {
	int p1[54] = { 3,3,3,3,4,4,4,4,5,5,5,5,6,6,6,6,7,7,7,7,8,8,8,8,9,9,9,9,10,10,10,10,11,11,11,11,12,12,12,12,13,13,13,13,14,14,14,14,15,15,15,15,16,17 };
	for (int i = 0; i < 54; i++) {
		p[i] = p1[i];
	}
}

void card::washCard() {
	int temp1_x;
	int temp1_y;
	int temp2_x;
	int temp2_y;
	srand((unsigned)time(NULL));

	for (int i = 0; i < 1000; i++) {
		temp1_x = p[temp1_y = rand() % 54];
		temp2_x = p[temp2_y = rand() % 54];
		p[temp1_y] = temp2_x;
		p[temp2_y] = temp1_x;
	}

}
void card::dealcard() {

	//int player[20];
	//int player1[20];
	//int player2[20];
	//int landlord[3];
	for (int i = 0; i <= 16; i++)
	{
		player[i] = p[i];
	}
	for (int i = 17; i <= 33; i++)
	{
		player1[i - 17] = p[i];
	}
	for (int i = 34; i <= 50; i++)
	{
		player2[i - 34] = p[i];
	}
	for (int i = 51; i <= 53; i++)
	{
		landlord[i - 51] = p[i];
	}
}
