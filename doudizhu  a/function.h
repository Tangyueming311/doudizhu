#ifndef FUNCTION_H
#define FUNCTION_H
#include<iostream>
#include<string>
#include<Windows.h>
#include <conio.h>
#include<iomanip>
#include<stdio.h>
#include<cstdlib>
#include<stdlib.h>
void HideCursor();
void gotoxy(unsigned char x, unsigned char y);



int right(int* a, int* b, int c);
int rightFirst(int* a);
int singleCard(int* a, int* b);
int doubleCard(int* a, int* b);
int threeCard(int* a, int* b);
int BoomCard(int* a, int* b);
int plane1Card(int* a, int* b);
int plane2Card(int* a,int*b);
int ifShunzi1Card(int* a,int*b);
int ifShunzi2Card(int* a,int*b);
int ifShunzi3Card(int* a,int*b);

void endgame(int * a,int * b1 ,int * c1,int a1, int a2, int a3);
int ifShunzi1(int* a);
int ifShunzi2(int* a);
int ifShunzi3(int* a);
int plane1(int* a);
int plane2(int* a);

void SetFont(int size);
//������Ƶ�����0�ں���
extern int temp[20];            //ȫ�ֱ�����temp����Ϊ�����ƺ��ݴ��Ƶ�����


extern int tempFunction;        //ȫ�ֱ�����tempFunctionΪ�ݴ���Ƶ�����
extern int tempchu ;            //ȫ�ֱ�����tempchuΪ�ж��Ƿ��Ǹ��ƽ׶Σ�0,1,�Ǹ��ƣ�2���³���
extern int boom ;               //ȫ�ֱ�����boomΪ�ж��Ƿ���ը����0���ǣ�1��

//������һ����0��ǰ��
extern int Card[21];            //ȫ�ֱ�����������ΪҪ��������Ƶ����

//0�ں���
extern int cardchu[20];         //ȫ�ֱ�����������ΪҪ���������

extern int K_if_player_is_landlord;





#endif