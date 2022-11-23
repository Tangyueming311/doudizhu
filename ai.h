//#ifndef AI_H
//#define AI_H
//class ai
//{
//private:
//	int ai_handcard_[20] = { 0 };
//	int ifLandlord = 0;                       //是否为地主，是为1，否为0
//	int ai_handcard_chu_[20] = { 0 };
//	int ai_handcard_num;
//
//	int boom_num_;
//
//	int handcard_shunzi1_[20] = { 0 };
//	int handcard_shunzi2_[20] = { 0 };
//	int handcard_shunzi3_[20] = { 0 };
//	int handcard_plane1_[20] = { 0 };
//	int handcard_plane2_[20] = { 0 };
//	int ai_handcard_boom_[20] = { 0 };
//	int handcard_single_[20] = { 0 };
//	int handcard_double_[20] = { 0 };
//
//public:
//	
//	void Order();
//	int get_LL();
//
//	
//	int* get_Hand();
//	int* get_Hand_Boom();
//	void set_Hand_Num();
//	int get_Hand_Num();
//
//	void set_LL(int a);
//	void set_Card(int* a);
//	void set_LLcard(int* a);
//	void ChuCard();
//	void ChuCardFirst();
//	//void DividCard();
//
//	int SearchShunzi1(int num);
//	int SearchShunzi2(int num);
//	int SearchShunzi3(int num);
//	int SearchPlane1(int num);
//	int SearchPlane2(int num);
//	int SearchSingle();
//	int SearchDouble();
//	void set_Boom();
//
//	//int* set_Single();
//	//int* set_Double();
//
//
//};
//
//
//
//
//#endif

#ifndef AI_H
#define AI_H
class ai
{
private:
	int handCard[20] = { 0 };
	int ifLandlord = 0;                       //是否为地主，是为1，否为0
	int left_right_ ;
	int handCard_num ;
public:
	void set_Left_Right(int a);
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
};




#endif
