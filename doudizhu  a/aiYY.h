#ifndef AIYY_H
#define AIYY_H
class AI_YY
{
private:
	//以下七个均为为实现拆牌的中间变量或数组
	int one[20] = { 0 };
	int two[20] = { 0 };
	int three[20] = { 0 };
	int four[20] = { 0 };
	int a = 0;
	int b = 0;
	int c = 0;
	//这个是临时存放上一个人出的牌的数组
	//int temp[20] = { 0 };
	//手牌
	int handcard[20] = { 0 };
	//这个最后表示的是剩余的单牌杂牌
	int temphandcard[20] = { 0 };
	//chucardfirst函数里面打出的牌数（在chucard里面没有用到这个，不知道是否有用）
	int number = 0;
	//以下是拆出来的牌
	int huojian[2] = { 0 };
	int zhadan[20] = { 0 };
	int shuangpai[20] = { 0 };
	int sanzhang[20] = { 0 };
	int danshun[20] = { 0 };
	int ifLandlord;
	int left_right_;


	int handCard_num_;
public:
	void order();
	void order1();
	void order2(int b[], int num);
	void order3(int a[]);
	void ifshuangshun();
	void qingling();
	void initlize();
	void ifshunzi(int b[], int temphandcard[], int shuangpai[]);
	void chucardfirst();
	void chaipai();
	void zhaozhadan();
	void zhaowangzha();
	void chucard();

	void set_LL(int a) { ifLandlord = a; }

	//设置手牌
	void set_Card(int* a);

	//设置地主牌
	void set_LLcard(int* a);
	


	//void set_Left_Right(int a);

	int get_handCard_num_();

	int* get_Hand();
};















#endif