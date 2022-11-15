//在这里写你的ai吧！
//记得把成员函数声明放进ai.h
//如果不知道怎么用多个文件的话先去百度一下捏


//提供了一个出牌种类的表，为tempFunction的值
// 
//
#include"function.h"
#include"player.h"
#include"ai.h"
using namespace std;
int ai::getLL() { return ifLandlord; }
int* ai::getHand() { return handCard; }
void ai::setLL(int a) { ifLandlord = a; }

//排序函数
void ai::order() {
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
//设置手牌
void ai::setCard(int* a)
{
	int j = 0;
	for (int i = 0; i < 17; i++) {
		handCard[i] = a[i];
	}

}
//设置地主牌
void ai::setLLcard(int* a) {
	for (int i = 0; i < 3; i++) {
		handCard[i] = a[i];
	}
}




void ai::chuCard() {


}

void ai::chuCardFirst() {

}