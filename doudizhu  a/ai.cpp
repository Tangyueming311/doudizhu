
#include"function.h"
#include"player.h"
#include"ai.h"
#include"draw.h"
using namespace std;


//int counter = 0;
void ai::set_Handcard_Num() {
	if (ifLandlord == 0) {
		handCard_num = 17;
	}
	else {
		handCard_num = 20;
	}
}
int ai::get_Handcard_Num() {
	return handCard_num;
}
int ai::getLL() { return ifLandlord; }
int* ai::get_Hand() { return handCard; }
void ai::set_LL(int a) { ifLandlord = a; }





//设置手牌
void ai::set_Card(int* a)
{
	int j = 0;
	for (int i = 0; i < 17; i++) {
		handCard[i] = a[i];
	}

}
//设置地主牌
void ai::set_LLcard(int* a)
{
	for (int i = 0; i < 3; i++) {
		handCard[i] = a[i];
	}
}


void ai::Order() {
	int min;
	int tem;
	for (int j = 0; j < 20; j++) {
		min = 100;
		tem = 0;
		for (int i = j; i < 20; i++) {
			if (handCard[i] < min) {
				min = handCard[i];
				tem = i;
			}
		}
		swap(handCard[j], handCard[tem]);
	}
}



void ai::Order_temp() {

	for (int i = 0; i < 20 - 1; i++)
	{
		for (int j = 0; j < 20 - 1 - i; j++)
			if (temp[j] > temp[j + 1])
			{
				int t = temp[j];
				temp[j] = temp[j + 1];
				temp[j + 1] = t;
			}
	}

	int temp_zero = 0;

	for (int i = 0; i < 20; i++)
	{
		if (temp[i] == 0)
			temp_zero++;
	}

	int temp_temp[20] = { 0 };
	for (int i = 0; i < 20; i++)
	{
		temp_temp[i] = temp[i];
	}
	for (int i = 0; i < 20; i++)
	{
		temp[i]=0;
	}
	for (int i = 0; i+temp_zero < 20; i++)
	{
		temp[i] = temp_temp[i + temp_zero];
	}

}




void ai::countt()
{
	int countte = 0;
	for (int i = 0; i < 20; i++)
	{
		if (temp[i] != 0)
			countte++;
	}
	counter = countte;
};
void ai::count_handcard()
{
	int countte = 0;
	for (int i = 0; i < 20; i++)
	{
		if (handCard[i] != 0)
			countte++;
	}
	handCard_num = countte;
}



//void ai::pass()
//{
//
//};



void ai::searchsingle2()
{
	int flag = 0;
	for (int i = 0; i < 20; i++)
	{
		if (handCard[i] > temp[0])
		{
			temp[0] = handCard[i];
			counter = 1;
			handCard[i] = 0;
			
			
			tempchu = 0; Order(); Order_temp(); count_handcard();
			if (left_right_ == -1) {
				Ai_Left_Chu(temp, handCard_num);
			}
			else  if (left_right_ == 1) {
				Ai_Right_Chu(temp, handCard_num);
			}
			flag = 1;
			break;
		}
	}

	if (flag == 0) {
		if (left_right_ == -1) {
			Ai_Left_Buchu();
		}
		else  if (left_right_ == 1) {
			Ai_Right_Buchu();
		}
		 Order(); Order_temp(); count_handcard();
	}
}
void ai::searchboom()
{
	bool a = 0;
	for (int i = 0; i < 17; i++)
	{
		if (0 != handCard[i] && handCard[i] == handCard[i + 1] && handCard[i + 1] == handCard[i + 2] && handCard[i + 2] == handCard[i + 3])
		{

			if (temp[0] + temp[1] > 30 || (handCard[i] < temp[0] && (temp[0] == temp[1] && temp[1] == temp[2] && temp[2] == temp[3])))
			{
				endbuchu(); break;
			}
			else
			{
				for (int i = 0; i < 20; i++)
				{
					temp[i] = 0;
				}
				temp[0] = temp[1] = temp[2] = temp[3] = handCard[i];
				handCard[i] = handCard[i + 1] = handCard[i + 2] = handCard[i + 3] = 0;
				tempFunction = 1;
				Order(); Order_temp(); count_handcard(); endchu();
				break;
			}
		}
		if (i == 16)
			a = 1;
		if (a == 1)
		{
			endbuchu();
			Order(); Order_temp(); count_handcard();
		}

	}
}


void ai::endchu()
{
	if (left_right_ == -1) {
		Ai_Left_Chu(temp, handCard_num);
	}
	else  if (left_right_ == 1) {
		Ai_Right_Chu(temp, handCard_num);
	}
	//tempchu = 0;

}
void ai::endbuchu()
{
	if (left_right_ == -1) {
		Ai_Left_Buchu();
	}
	else  if (left_right_ == 1) {
		Ai_Right_Buchu();
	}
	//tempchu++;
}

void ai::chuCard()
{
	countt();

	if (counter >= 6)
	{
		searchboom();
		Order();
	}
	if (counter == 1)
	{
		searchsingle2();
		Order();
	}
	if (counter == 2)
	{
		if (temp[0] + temp[1] == 33)
		{
			endbuchu();
		}
		else
			for (int i = 0; i < 20; i++)
			{
				if (handCard[i] == handCard[i + 1] && handCard[i] > temp[0])
				{
					temp[0] = temp[1] = handCard[i]; handCard[i] = handCard[i + 1] = 0;
					Order(); Order_temp(); countt(); count_handcard(); endchu(); break;
				}
				if (i == 19)
				{
					searchboom(); break;
				}
			}
	}
	if (counter == 3)
	{
		for (int i = 0; i < 20; i++)
		{
			if (handCard[i] != 0 && handCard[i] == handCard[i + 1] && handCard[i] == handCard[i + 2] && handCard[i] > temp[0])
			{
				temp[0] = temp[1] = temp[3] = handCard[i];
				handCard[i] = handCard[i + 1] = handCard[i + 2] = 0;
				Order(); Order_temp(); countt(); count_handcard(); endchu(); break;
			}
			if (i == 17)
			{
				searchboom(); break;
			}
		}
	}
	if (counter == 4)
	{
		if (temp[0] == temp[1] && temp[1] == temp[2] && temp[2] == temp[3])
		{
			searchboom();
		}
		else if ((temp[0] == temp[1] && temp[1] == temp[2])|| (temp[1] == temp[2] && temp[3] == temp[2]))
		{
			int max1 = temp[1]; int z = 0;
			for (int i = 0; i < 18; i++)
			{
				if (handCard[i] != 0 && handCard[i] == handCard[i + 1] && handCard[i + 1] == handCard[i + 2] && handCard[i] > max1)
				{
					z = 1;
					temp[0] = handCard[i]; temp[1] = handCard[i + 1]; temp[2] = handCard[i + 2];
					handCard[i] = 0; handCard[i + 1] = 0; handCard[i + 2] = 0;
					Order();
					for (int j = 0; j < 20; j++)
					{
						if (handCard[j] != 0 && handCard[j] != handCard[j - 1] && handCard[j] != handCard[j + 1])
						{
							temp[3] = handCard[j]; handCard[j] = 0; Order(); Order_temp(); countt(); count_handcard(); endchu(); break;
						}
						else if (j == 19)
						{
							for (int i = 0; i < 20; i++)
							{
								if (handCard[i] != 0) {
									temp[3] = handCard[i];
									handCard[i] = 0; break;
								}
							}
							Order(); Order_temp(); countt(); count_handcard(); endchu(); break;
						}
					}

				}if (z == 1)break;
				

			}
			if (z == 0) { searchboom(); }
		}

	}
	if (counter == 5)
	{
		if ((temp[0] == temp[1] && temp[1] == temp[2]) || (temp[2] == temp[3] && temp[3] == temp[4]))
		{
			searchboom();//未完善
		}
		else if (temp[0] + 1 == temp[1] && temp[1] + 1 == temp[2])
		{
			searchboom();//未完善
		}
	}
}



void ai::chuCardFirst()
{
	//清空temp数组
	for (int i = 0; i < 20; i++)
	{
		temp[i] = 0;
	}
	//改变暂存数组则出牌，不改变则继续扫描
	//查看有没有飞机牌并打出；
	searchplane();
	//连对
	if (temp[0] == 0)
		searchliandui();
	//顺子
	if (temp[0] == 0)
		searchshunzi();
	//三带一，二
	if (temp[0] == 0)
		searchsandaiyi();
	////对子
	 if (temp[0] == 0)
		searchduizi();
	////单牌
	if (temp[0] == 0)
		searchsingle();

	//出牌函数，改变tempchu
	endchu();



}

void ai::searchplane()
{
	bool flag = 0;
	int y[20] = { 0 };//用来暂存飞机牌
	int newcard[20] = { 0 };
	for (int i = 0; i < 20; i++)
	{
		newcard[i] = handCard[i];
	}
	for (int i = 0; i < 20; i++)
	{
		
		if (0 != newcard[i] && newcard[i] == newcard[i + 1] && newcard[i + 1] == newcard[i + 2] /*&& newcard[i] != newcard[i + 3]*/)
		{
			/*cout << "有三张一样的" << i;*/
			if (newcard[i] + 1 == newcard[i + 3] && newcard[i + 3] == newcard[i + 4] && newcard[i + 4] == newcard[i + 5]) { cout << "可以出飞机"; flag = 1; }

		}
		if (flag == 1)
		{
			int n = 0;
			for (int j = i; j < i + 6; j++)
			{
				
				y[n] = newcard[j];
				handCard[j] = 0; newcard[j] = 0; n++;
			}
			Order();
			/*选择飞机并出牌（这里没有考虑到有三个的飞机）*/
			//此时要寻找两张单牌(不考虑带两个对子）
			for (int j = 1; j < 20; j++)
			{
				if (flag == 1)
				{
					for (int i = 0; i < 20; i++)//排序暂存牌组；
					{
						temp[i] = y[i];
					}

					for (int i = 0; i < 20 - 1; i++)
					{
						for (int j = 0; j < 20 - 1 - i; j++)
							if (temp[j] > temp[j + 1])
							{
								int t = temp[j];
								temp[j] = temp[j + 1];
								temp[j + 1] = t;
							}
					}

					Order_temp();



					for (int i = 0; i < 20; i++)
					{
						if (temp[i] != 0)
							counter++;
					}
					tempFunction = 2108;
					break;
				}

			}

			break;
		}
	}

	;
}
void ai::searchliandui()
{
	int newcard[20] = { 0 };
	for (int i = 0; i < 20; i++)
	{
		newcard[i] = handCard[i];
	}
	for (int i = 0; i < 15; i++)
	{
		if (newcard[i] != 0 && newcard[i] == newcard[i + 1] && newcard[i] + 1 == newcard[i + 2] && newcard[i + 2] == newcard[i + 3] && newcard[i + 2] + 1 == newcard[i + 4] && newcard[i + 4] == newcard[i + 5])
		{
			int n = 0;
			for (int j = i; j < i + 6; j++)
			{
				 temp[n] = newcard[j]; handCard[j] = 0;
				n++;
			}
			tempFunction = 1206;
			Order();
			Order_temp();
			countt();
			count_handcard(); break;
		}

	}

};
void ai::searchshunzi()
{
	
	int store[40] = { 0 };
	int newcard[20] = { 0 };
	for (int i = 0; i < 20; i++)
	{
		newcard[i] = handCard[i];
	}
	int c = 0;

	for (int i = 0; i < 20; i++)
	{
		if (newcard[i] == newcard[i + 1] || newcard[i] >= 15)
		{
			store[c] = newcard[i];
			newcard[i] = 0; c++;

		}
	}
	for (int i = 0; i < 20 - 1; i++)
	{
		for (int j = 0; j < 20 - 1 - i; j++)
			if (newcard[j] > newcard[j + 1])
			{
				int t = newcard[j];
				newcard[j] = newcard[j + 1];
				newcard[j + 1] = t;
			}
	}
	for (int i = 0; i < 20; i++)
	{
		int n = 0;
		if (newcard[i] != 0)
		{
			if (newcard[i] + 1 == newcard[i + 1]
				&& newcard[i + 1] + 1 == newcard[i + 2]
				&& newcard[i + 2] + 1 == newcard[i + 3]
				&& newcard[i + 3] + 1 == newcard[i + 4])
			{
				if (newcard[i + 4] + 1 == newcard[i + 5])
				{
					if (newcard[i + 5] + 1 == newcard[i + 6])
					{
						if (newcard[i + 6] + 1 == newcard[i + 7])
						{
							for (int j = i; j < i + 8; j++) {
								temp[n] = newcard[j]; n++;
								newcard[j] = 0;
							}
							tempFunction = 1108;
							break;
						}
						else
						{
							for (int j = i; j < i + 7; j++) {
								temp[n] = newcard[j]; newcard[j] = 0; n++;
							}
							tempFunction = 1107;
							break;
						}
					}
					else
					{
						for (int j = i; j < i + 6; j++) {
							temp[n] = newcard[j]; newcard[j] = 0; n++;
						}
						tempFunction = 1106;
						break;
					}
				}
				else
				{
					for (int j = i; j < i + 5; j++) {
						temp[n] = newcard[j]; newcard[j] = 0; n++;
					}
					tempFunction = 1105;
					break;
				}

			}

		}
	}int a = 0;
	for (int t = 39; t > 19; t--)
	{

		store[t] = newcard[a]; a++;

	}
	int min;
	int tem;
	for (int j = 0; j < 40; j++) {
		min = 100;
		tem = 0;
		for (int i = j; i < 40; i++) {
			if (store[i] < min) {
				min = store[i];
				tem = i;
			}
		}
		swap(store[j], store[tem]);
	}/*
	for (int i = 0; i < 40 - 1; i++)
	{
		for (int j = i; j < 40 - 1 - i; j++)
			if (store[j] > store[j + 1])
			{
				int t = store[j];
				store[j] = store[j + 1];
				store[j + 1] = t;
			}
	}*/
	int temp_zero = 0;
	for (int i = 0; i < 40; i++)
	{
		if (store[i] == 0)
			temp_zero++;
	}

	int temp_temp[40] = { 0 };
	for (int i = 0; i < 40; i++)
	{
		temp_temp[i] = store[i];
	}

	for (int i = 0; i + temp_zero < 40; i++)
	{
		store[i] = temp_temp[i + temp_zero];
	}
	for (int j = 0; j < 20; j++)
	{
		handCard[j] = store[j];
	}
	Order(); Order_temp(); countt(); count_handcard();

}
void ai::searchsandaiyi()
{
	for (int i = 0; i < 18; i++)
	{
		if (handCard[i] != 0 && handCard[i] == handCard[i + 1] && handCard[i + 1] == handCard[i + 2])
		{
			temp[0] = handCard[i]; temp[1] = handCard[i + 1]; temp[2] = handCard[i + 2];
			handCard[i] = 0; handCard[i + 1] = 0; handCard[i + 2] = 0;
			Order();
			for (int j = 0; j < 19; j++)
			{
				if (handCard[j] != 0 && handCard[j] != handCard[j - 1] && handCard[j] != handCard[j + 1])
				{
					temp[3] = handCard[j]; handCard[j] = 0; Order(); Order_temp(); countt(); count_handcard();
					
					break;
				}
				if(j==18)
				{
					for (int j = 0; j < 19; j++)
					{
						if(handCard!=0){ temp[3] = handCard[j]; handCard[j] = 0; Order(); Order_temp(); countt(); count_handcard(); break; }
					}
				}
				tempFunction = 2104;

			}
			break;
		}

	}
}
void ai::searchduizi()
{
	for (int i = 0; i < 19; i++)
	{
		if (handCard[i] != 0 && handCard[i] == handCard[i + 1])
		{
			temp[i] = handCard[i]; temp[i + 1] = handCard[i + 1];
			handCard[i] = 0; handCard[i + 1] = 0;
			Order(); Order_temp(); countt(); count_handcard(); 
			tempFunction = 202;
			break;
		}
	}
};
void ai::searchsingle()
{
	for (int i = 0; i < 20; i++)
	{
		if (handCard[i] != 0)
		{
			temp[0] = handCard[i];
			handCard[i] = 0;
			Order(); Order_temp(); countt(); count_handcard();
			tempFunction = 101;
			break;
		}
	}
};


