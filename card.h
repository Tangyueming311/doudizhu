#ifndef CARD_H
#define CARD_H
class card {
private:
	int player[17];                           //分出的第一组基本牌的牌面
	int player1[17];                          //分出的第二组基本牌的牌面
	int player2[17];                          //分出的第三组基本牌的牌面
	int landlord[3];                          //分出的地主牌的牌面
	int p[54];                                //所有牌的牌面

public:
	card();                                     //对牌进行赋值
	void washCard();
	void dealcard();
	int getCard_a(int a);
	int* getCard();
	int* getP();
	int* getP1();
	int* getP2();
	int* getL();

};


#endif