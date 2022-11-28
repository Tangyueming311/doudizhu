
#ifndef AI_H
#define AI_H
class ai
{
private:
	int handCard[20] = { 0 };
	int ifLandlord = 0;                       //是否为地主，是为1，否为0
	int left_right_=-1;
	int handCard_num;
public:

	void set_Handcard_Num();
	int get_Handcard_Num();
	void Order();
	int getLL();
	void searchplane();
	void searchsingle();
	int counter;//temp数组的牌数，ai出了多少张
	void searchboom();
	void countt();
	void pass();
	void searchsingle2();//
	int* get_Hand();
	void set_LL(int a);
	void set_Card(int* a);
	void set_LLcard(int* a);
	void chuCard();
	void chuCardFirst();
	void Order_temp();
	void endchu();
	void count_handcard();
	void searchshunzi();
	void searchliandui();
	void searchsandaiyi();
	void searchduizi();
	void endbuchu();

};




#endif