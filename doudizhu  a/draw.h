#ifndef DRAW_H
#define DRAW_H
//int MapLength ;
// int MapLeight ;
// char Map[190][55];


void menu();



void Map_Creat();

void getNum(int a,int * b,int c);
void Draw(int left_x,int high_y,int length,int height);
void Player_Card_Creat(int* a, int c,int temp,  int if_player_is_landlord);
void put();
void move();
void buchu(int* a, int if_player_is_landlord);
int chooseCard(int a);
void dachu(int* a);
int chu(int* a,int b, int if_player_is_landlord);

void Ai_Card_Creat(int left_card_num, int right_card_num,  int if_player_is_landlord);

void Ai_Left_Chu(int* ai_card_chu,int ai_card_num);
void Ai_Left_Buchu();

void Ai_Right_Chu(int*ai_card_chu, int ai_card_num);
void Ai_Right_Buchu();

void Landlord_Card_Creat(int* card);

int Choose_Landlord(int* handcard);
#endif