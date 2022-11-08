#ifndef FUNCTION_H
#define FUNCTION_H
#include<iostream>
#include<string>
#include<Windows.h>
#include <conio.h>
#include<iomanip>
#include<stdio.h>
#include<cstdlib>
void HideCursor();
void gotoxy(unsigned char x, unsigned char y);
void menu();
int right(int* a, int* b, int c);
int rightFirst(int* a);
int singleCard(int* a, int* b);
int doubleCard(int* a, int* b);
int threeCard(int* a, int* b);
extern int temp[20];
extern int tempFunction;



#endif