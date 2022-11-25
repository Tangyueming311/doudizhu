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
//打出的牌的数组0在后面
extern int temp[20];            //全局变量，temp数组为出了牌后，暂存牌的数组


extern int tempFunction;        //全局变量，tempFunction为暂存的牌的类型
extern int tempchu ;            //全局变量，tempchu为判断是否是跟牌阶段，0,1,是跟牌，2是新出牌
extern int boom ;               //全局变量，boom为判断是否是炸弹，0不是，1是

//与手牌一样，0在前面
extern int Card[21];            //全局变量，该数组为要打出的手牌的序号

//0在后面
extern int cardchu[20];         //全局变量，该数组为要打出的手牌

extern int K_if_player_is_landlord;





#endif