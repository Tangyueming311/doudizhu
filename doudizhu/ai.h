#ifndef AI_H
#define AI_H
class ai
{
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

};




#endif
