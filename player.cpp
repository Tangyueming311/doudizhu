#include"function.h"
#include"player.h"
using namespace std;

//return地主值
int player::getLL() { return ifLandlord; }
//return手牌数组
int* player::getHand() { return handCard; }
//形参a为int类型，设置玩家地主值
void player::setLL(int a) { ifLandlord = a; }

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
	int x[20] = { 0 };   
	//储存要打出的牌的牌值的数组，以0结尾
	int y[20] = { 0 };

	int j = 0;
	int i = 0;
	int Temp = 0;


	//该循环是为了实现输入想打出的牌的序号后，判断能否打出，能打出则跳出循环，不能则重复循环
	do {
		j = 0;
		for (int i = 0; i < 20; i++) {
			x[i] = 0;
		}
		for (int i = 0; i < 20; i++) {
			y[i] = 0;
		}

		do {
			cin >> x[j];
			if (x[j] == 0) {
				break;
			}
			j++;
		} while (1);
 
		//handCard数组里下标为Temp的元素开始不为0
		i = 0;
		Temp = 0;
		while (handCard[Temp] == 0) {			 			  
			Temp++;
		}
		while (x[i] != 0) {
			y[i] = handCard[Temp + x[i] - 1];
			i++;
		}

	} while (rightFirst(y) == 0);

//将打出的牌进行暂存
	for (int i = 0; i < 20; i++) {
		temp[i] = y[i];
	}

	//将打出了牌后的手牌赋值为0
	i = 0;
	while (x[i] != 0) {
		handCard[Temp + x[i] - 1] = 0; 
		i++;
	}
	order();

	cout << "打出了 ";
	
	
//测试
	i = 0;
	
	while (y[i] != 0) {
		cout << y[i] << " ";
		i++;
	}
	cout << endl;


}
//跟随出牌的函数
void player::chuCard() {
	//储存要打出的牌的序号的数组，以0结尾
	int x[20] = { 0 };
	//储存要打出的牌的牌值的数组，以0结尾
	int y[20] = { 0 };

	int j = 0;
	int i = 0;
	int Temp = 0;

	//该循环是为了实现输入想打出的牌的序号后，判断能否打出，能打出则跳出循环，不能则重复循环
	do {
		j = 0;
		for (int i = 0; i < 20; i++) {
			x[i] = 0;
		}
		do {
			cin >> x[j];
			if (x[j] == 0) {
				break;
			}
			j++;
		} while (1);

		//handCard数组里下标为Temp的元素开始不为0
		i = 0;
		Temp = 0;
		while (handCard[Temp] == 0) {			 			 
			Temp++;
		}
		while (x[i] != 0) {
			y[i] = handCard[Temp + x[i] - 1];
			i++;
		}


	} while (right(y, temp, tempFunction) == 0);


	for (int i = 0; i < 20; i++) {
		temp[i] = y[i];                                        //改变暂存值
	}
	while (x[i] != 0) {
		handCard[Temp + x[i] - 1] = 0;                            //将打出了牌后的手牌赋值为0
		i++;
	}
	order();                                                   //重新排序

	//测试
	while (y[i] != 0) {
		cout << "打出了" << y[i] << " ";
	}
	cout << endl;
}
