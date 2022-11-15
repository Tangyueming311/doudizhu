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
void menu();


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

void endgame(int * a,int * b ,int * c,int a1, int a2, int a3);
int ifShunzi1(int* a);
int ifShunzi2(int* a);
int ifShunzi3(int* a);
int plane1(int* a);
int plane2(int* a);

extern int temp[20];
extern int tempFunction;
extern int tempchu;
extern int boom;

#endif