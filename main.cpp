﻿//first of all ,you should know this is a dou di zhu.
// 这是主函数，游戏进程在这里

#include"function.h"
#include"player.h"
#include"ai.h"
#include"card.h"
#include"draw.h"
using namespace std;
extern int temp[20] = { 0 };       //全局变量，temp数组为出了牌后，暂存牌的数组
extern int tempFunction = 0;       //全局变量，tempFunction为暂存的牌的类型
extern int tempchu = 2;            //全局变量，tempchu为判断是否是跟牌阶段，0,1,是跟牌，2是新出牌
extern int boom = 0;               //全局变量，boom为判断是否是炸弹，0不是，1是
extern int  K_if_player_is_landlord = 0;



int main() {
	//16为原字体
	SetFont( 16);
    HideCursor();



	menu();        


	//定义一组牌对象，进行洗牌并分为三组基本牌和一组地主牌
	card a;         
	a.washCard();

	a.dealcard();

	//定义玩家对象b，并将b的手牌设置为a中的第一组基本牌
	player b;
	b.setCard(a.getP());

	//定义ai对象b1，并将b1的手牌设置为a中的第二组基本牌
	ai b1;
	b1.set_Card(a.getP1());

	//定义ai对象b2，并将b2的手牌设置为a中的第三组基本牌
	ai b2;
	b2.set_Card(a.getP2());


	//三组手牌都进行排序
	b.order();
	b1.Order();
	b2.Order();



	//cout << "您的手牌为：";
	//for (int i = 0; i < 20; i++)
	//{
	//	cout << b.getHand()[i] << " ";
	//}	
	//cout << endl;
	//cout << "你要叫地主吗？" << endl;
	//cout << "输入1叫地主，不然则输入0." << endl;
	//int y;
	//cin >> y;
	//if (y == 1) {
	//	b.setLL(1);                                //将b设置为地主
	//	b.setLLcard(a.getL());                     //将b的手牌加上a中的地主牌
	//	cout << "现在你是地主." << endl;
	//}
	//else {
	//	b1.set_LL(1);                               //将ai b1设置为地主
	//	b1.set_LLcard(a.getL());                    //将b1的手牌加上a中的地主牌


	//	//随机说一个ai是地主
	//	//但是后台里ai就是b1
	//	srand((unsigned)time(NULL));               
	//	int x = rand() % 2 + 1;
	//	cout << "地主是AI" << x << "号" << endl;
	//}
	//cout << endl;


	int x = Choose_Landlord(b.getHand());

	if (x == 1) {
		K_if_player_is_landlord=1;                                //将b设置为地主
	    b.setLLcard(a.getL());                     //将b的手牌加上a中的地主牌
	
	}
	else {
		b1.set_LL(1);                               //将ai b1设置为地主
	    b1.set_LLcard(a.getL());                    //将b1的手牌加上a中的地主牌

    }
	






	b.order();  
	b1.Order();

	//b1.set_Boom();
	b1.Order();
	//b1.set_Hand_Num();

	//b2.set_Boom();
	b2.Order();
	//b2.set_Hand_Num();




	//
	////打印出地主牌
	//cout << "底牌为：";
	//cout << a.getL()[0] << " " << a.getL()[1] << " " << a.getL()[2] << " " << endl;

	//cout << "您的手牌为：";
	//for (int i = 0; i < 20; i++)
	//{
	//	cout << b.getHand()[i] << " ";
	//}



	Map_Creat();
	Landlord_Card_Creat(a.getL());
	//Ai_Card_Creat(b1.get_Hand_Num(), b2.get_Hand_Num(), K_if_player_is_landlord);

	b1.set_Left_Right(-1);
	b2.set_Left_Right(1);

	b1.set_Handcard_Num();
	b2.set_Handcard_Num();

	Ai_Card_Creat(b1.get_Handcard_Num(), b2.get_Handcard_Num(), K_if_player_is_landlord);



	//这里的tempchu这么理解，初始值为2，调用chuFirst（）函数，调用后赋tempchu=0；如果tempchu=0，调用chucard（）函数，如果打出，仍tempchu=0；
	//tempchu=0，调用chucard（），若不出，则tempchu+1，值为1,若出牌，赋0；因为tempchu=1，下一步仍调用chucard（）；如果这一次调用chucard（）后仍不出，tempchu+1，
	//tempchu=2，则调用chufirst（）函数。

	//这里是测试的游戏进程


	//while (1) {
	//	if (K_if_player_is_landlord == 1) {
	//		if (tempchu == 0||tempchu==1) {
	//			b.chuCard();
	//			
	//		}
	//		else {
	//			
	//			b.chuCardFirst();
	//			
	//		}
	//		
	//		
	//		endgame(b.getHand(), b1.get_Hand(),b1.get_Hand_Boom(),b2.get_Hand(),b2.get_Hand_Boom(), K_if_player_is_landlord, b1.get_LL(), b2.get_LL());


	//		if (tempchu == 0 || tempchu == 1) {
	//			b.chuCard();
	//		}
	//		else {
	//			
	//			b.chuCardFirst();
	//		}

	//		
	//		endgame(b.getHand(), b1.get_Hand(), b1.get_Hand_Boom(), b2.get_Hand(), b2.get_Hand_Boom(), K_if_player_is_landlord, b1.get_LL(), b2.get_LL());


	//		if (tempchu == 0 || tempchu == 1) {
	//			b.chuCard();
	//		}
	//		else {				
	//			b.chuCardFirst();
	//		}

	//		
	//		endgame(b.getHand(), b1.get_Hand(), b1.get_Hand_Boom(), b2.get_Hand(), b2.get_Hand_Boom(), K_if_player_is_landlord, b1.get_LL(), b2.get_LL());
	//	}

	//}





	//这里是加上ai的游戏正式进程，建议采用跟提供的player类的chuCard（），chuCardFirst()结构类似的函数
	//自己完成吧！，开始的时候记得把上面的测试进程注释掉

	while (1) {
		if (K_if_player_is_landlord == 1) {
			if (tempchu == 0 || tempchu == 1) {
				b.chuCard();

			}
			else {

				b.chuCardFirst();
			}


		//	endgame(b.getHand(), b1.get_Hand(), b2.get_Hand(), b.getLL(), b1.getLL(), b2.getLL());
			Sleep(2000);

			if (tempchu == 0 || tempchu == 1) {
				b1.chuCard();
			}
			else {

				b1.chuCardFirst();
			}


		//	endgame(b.getHand(), b1.get_Hand(), b2.get_Hand(), b.getLL(), b1.getLL(), b2.getLL());

			Sleep(2000);

			if (tempchu == 0 || tempchu == 1) {
				b2.chuCard();
			}
			else {
				b2.chuCardFirst();
			}
			Sleep(2000);


		//	endgame(b.getHand(), b1.get_Hand(), b2.get_Hand(), b.getLL(), b1.getLL(), b2.getLL());
		}

	}












}


