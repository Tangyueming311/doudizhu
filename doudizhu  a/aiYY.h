#ifndef AIYY_H
#define AIYY_H
class AI_YY
{
private:
	//�����߸���ΪΪʵ�ֲ��Ƶ��м����������
	int one[20] = { 0 };
	int two[20] = { 0 };
	int three[20] = { 0 };
	int four[20] = { 0 };
	int a = 0;
	int b = 0;
	int c = 0;
	//�������ʱ�����һ���˳����Ƶ�����
	//int temp[20] = { 0 };
	//����
	int handcard[20] = { 0 };
	//�������ʾ����ʣ��ĵ�������
	int temphandcard[20] = { 0 };
	//chucardfirst��������������������chucard����û���õ��������֪���Ƿ����ã�
	int number = 0;
	//�����ǲ��������
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

	//��������
	void set_Card(int* a);

	//���õ�����
	void set_LLcard(int* a);
	


	//void set_Left_Right(int a);

	int get_handCard_num_();

	int* get_Hand();
};















#endif