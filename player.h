#ifndef PLAYER_H
#define PLAYER_H
class player {
private:
	//��������
	int handCard[20] = { 0 };
	//�Ƿ�Ϊ��������Ϊ1����Ϊ0
	int ifLandlord = 0;                       

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