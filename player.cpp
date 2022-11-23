#include"function.h"
#include"player.h"
#include"draw.h"

using namespace std;

//return地主值
// int player::getLL() { return ifLandlord; }
//return手牌数组
int* player::getHand() { return handCard; }
//形参a为int类型，设置玩家地主值
//void player::setLL(int a) { ifLandlord = a; }

//将玩家手牌数组排序
void player::order() {
	int min;
	int temp;
	for (int j = 0; j < 20; j++) {
		min = 100;
		temp = 0;
		for (int i = j; i < 20; i++) {
			if (handCard[i] < min) {
				min = handCard[i];
				temp = i;
			}
		}
		swap(handCard[j], handCard[temp]);
	}
}

//形参a是数组类型，给手牌赋值
void player::setCard(int* a)
{
	int j = 0;
	for (int i = 0; i < 17; i++) {
		handCard[i] = a[i];
	}

}

//形参a是数组类型，给手牌加上地主牌
void player::setLLcard(int* a) {
	for (int i = 0; i < 3; i++) {
		handCard[i] = a[i];
	}
}



//首次出牌的函数
void player::chuCardFirst() {
	//储存要打出的牌的序号的数组，以0结尾
    //Card[]  
	//储存要打出的牌的牌值的数组，以0结尾
    //cardchu[]
	for (int i = 0; i < 20; i++) {
		temp[i] = 0;
	}

	int j = 0;
	int i = 0;

	//记录手牌有多少张
	int Temp = 0;
	
	//记录手牌前有多少个0
	int temp2 = 0;
	for (int k = 0; k < 20; k++) {
		if (handCard[k] != 0) {
			Temp++;
		}
		else {
			temp2++;
		}
	}
	
	//cout << endl<<"轮到你先出了"<<endl;
	
	getNum(Temp, handCard,temp2);

//该函数时创造画布函数，初始画布以及初始手牌，为每一次最开始调用的函数
//形参a是数字牌面数组，形参cardNum是牌数
	Player_Card_Creat(handCard, Temp,temp2, K_if_player_is_landlord);

	while (1) {

		int a = chooseCard(1);

		if (a == 0) {
			move();
		}
		else if (a == 1) {			
			break;
		}
		
	}



	
	



		//将打出的牌进行暂存
		for (int i = 0; i < 20; i++) {
			temp[i] = cardchu[i];
		}

		//将打出了牌后的手牌赋值为0
		i = 0;
		while (Card[i] != 0) {
			handCard[temp2 + Card[i] - 1] = 0;
			i++;
		}
		order();



		tempchu = 0;



}


//跟随出牌的函数
void player::chuCard() {
	//储存要打出的牌的序号的数组，以0结尾
	//Card[]  
	//储存要打出的牌的牌值的数组，以0结尾
	//cardchu[]

	int j = 0;
	int i = 0;
	int Temp = 0;

	//flag为是否不出，为1是出牌，为0是不出
	int flag = 1;

	
	
	//记录手牌前有多少个0
	int temp2 = 0;
	for (int k = 0; k < 20; k++) {
		if (handCard[k] != 0) {
			Temp++;
		}
		else {
			temp2++;
		}
	}



	getNum(Temp, handCard,temp2);
	//该函数时创造画布函数，初始画布以及初始手牌，为每一次最开始调用的函数
	//形参a是数字牌面数组，形参cardNum是牌数
	Player_Card_Creat(handCard, Temp, temp2, K_if_player_is_landlord);

	
		while (1) {
			int a = chooseCard(0);
			if (a == 0) {
				move();
			}
			else if (a == 1) {
				flag = 1;
				dachu(cardchu);
				break;
			}
			else if (a == 2) {
				flag = 0;
				Sleep(100);
				break;
			}
		}
	
	


	if (flag == 1) {
        //改变暂存值
		for (int i = 0; i < 20; i++) {
			temp[i] = cardchu[i];                                        
		}

        //将打出了牌后的手牌赋值为0
		i = 0;
		while (Card[i] != 0) {
			handCard[temp2 + Card[i] - 1] = 0;                            
			i++;
		}
		
		//重新排序
		order();                                                   


		tempchu = 0;

	}


	//这里的tempchu这么理解，初始值为2，调用chuFirst（）函数，tempchu=0；tempchu=0，调用chucard（）函数，如果打出，仍tempchu=0；
	//tempchu=0，调用chucard（），若不出，则tempchu+1，值为1；因为tempchu=1，下一步仍调用chucard（）；如果这一次调用chucard（）后仍不出，tempchu+1，
	//tempchu=2，则调用chufirst（）函数。
	else {
		tempchu ++;
		
	}
}
