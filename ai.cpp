#include"function.h"
#include"player.h"
#include"ai.h"
using namespace std;
int ai::getLL() { return ifLandlord; }

int* ai::getHand() { return handCard; }
void ai::setLL(int a) { ifLandlord = a; }






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
void ai::setCard(int* a)
{
	int j = 0;
	for (int i = 0; i < 17; i++) {
		handCard[i] = a[i];
	}

}


void ai::setLLcard(int* a) {
	for (int i = 0; i < 3; i++) {
		handCard[i] = a[i];
	}
}

void ai::chuCard() {


}
