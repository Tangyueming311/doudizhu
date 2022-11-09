#ifndef CARD_H
#define CARD_H
class card {
private:
	int player[17];
	int player1[17];
	int player2[17];
	int landlord[3];
	int p[54];

public:
	card();                                     //对牌进行赋值
	void washCard();
	void dealcard();
	void order();
	int getCard_a(int a);
	int* getCard();
	int* getP();
	int* getP1();
	int* getP2();
	int* getL();

};


#endif