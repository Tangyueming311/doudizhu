#ifndef PLAYER_H
#define PLAYER_H
class player {
private:
	//��������
	int handCard[20] = { 0 };
	

public:
	//�Ƿ�Ϊ��������Ϊ1����Ϊ0
	//static int ifLandlord;
	void order();
	//static int getLL();
	int* getHand();
	//void setLL(int a);
	void setCard(int* a);
	void setLLcard(int* a);
	void chuCard();
	void chuCardFirst();

};

#endif