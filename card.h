#ifndef CARD_H
#define CARD_H
class card {
private:
	int player[17];                           //�ֳ��ĵ�һ������Ƶ�����
	int player1[17];                          //�ֳ��ĵڶ�������Ƶ�����
	int player2[17];                          //�ֳ��ĵ���������Ƶ�����
	int landlord[3];                          //�ֳ��ĵ����Ƶ�����
	int p[54];                                //�����Ƶ�����

public:
	card();                                     //���ƽ��и�ֵ
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