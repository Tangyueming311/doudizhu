
#ifndef AI_H
#define AI_H
class ai
{
private:
	int handCard[20] = { 0 };
	int ifLandlord = 0;                       //�Ƿ�Ϊ��������Ϊ1����Ϊ0
	int left_right_=-1;
	int handCard_num;
public:

	void set_Handcard_Num();
	int get_Handcard_Num();
	void Order();
	int getLL();
	void searchplane();
	void searchsingle();
	int counter;//temp�����������ai���˶�����
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