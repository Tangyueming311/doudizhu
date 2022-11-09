#ifndef PLAYER_H
#define PLAYER_H
class player {
private:
	int handCard[20] = { 0 };
	int ifLandlord = 0;                       //是否为地主，是为1，否为0

public:
	void order();
	int getLL();
	int* getHand();
	void setLL(int a);
	void setCard(int* a);
	void setLLcard(int* a);
	void chuCard();
	void chuCardFirst();

};

#endif