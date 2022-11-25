#include"function.h"
#include"card.h"
using namespace std;

//���������Ƶĵ�n��
//�β�Ϊ��n����
int card::getCard_a(int n) { return p[n]; }

//���ش��������Ƶ�����
int* card::getCard() { return p; }

//���ش����һ���Ƶ�����
int* card::getP() { return player; }

//���ش���ڶ����Ƶ�����
int* card::getP1() { return player1; }

//���ش���������Ƶ�����
int* card::getP2() { return player2; }

//���ش�������Ƶ�����
int* card::getL() { return landlord; }

//��ʼ��������
card::card() {
	int p1[54] = { 3,3,3,3,4,4,4,4,5,5,5,5,6,6,6,6,7,7,7,7,8,8,8,8,9,9,9,9,10,10,10,10,11,11,11,11,12,12,12,12,13,13,13,13,14,14,14,14,15,15,15,15,16,17 };
	for (int i = 0; i < 54; i++) {
		p[i] = p1[i];
	}
}

//�������ƽ���ϴ��
void card::washCard() {
	int temp1_x;
	int temp1_y;
	int temp2_x;
	int temp2_y;
	srand((unsigned)time(NULL));

	for (int i = 0; i < 5000; i++) {
		temp1_x = p[temp1_y = rand() % 54];
		temp2_x = p[temp2_y = rand() % 54];
		p[temp1_y] = temp2_x;
		p[temp2_y] = temp1_x;
	}

}

//�������Ʒ�Ϊ��������ƺ�һ�������
void card::dealcard() {

	
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
