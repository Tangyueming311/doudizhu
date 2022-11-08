//first of all ,you should know this is a dou di zhu.
#include"function.h"
#include"player.h"
#include"ai.h"
#include"card.h"
using namespace std;
extern int temp[20] = { 0 };
extern int tempFunction = 0;

int main() {
	menu();

	card a;
	a.washCard();

	a.dealcard();


	player b;
	b.setCard(a.getP());


	player b1;
	b1.setCard(a.getP1());


	player b2;
	b2.setCard(a.getP2());



	b.order();
	b1.order();
	b2.order();



	cout << "您的手牌为：";
	for (int i = 0; i < 20; i++)
	{
		cout << b.getHand()[i] << " ";
	}	 //cout << endl;
	//for(int i=0;i<20;i++){
	   //cout<< b1.getHand()[i]<<" ";
	   //
	//}
	//cout << endl;
 //   for(int i=0;i<20;i++){
	   //cout<< b2.getHand()[i]<<" ";
	   //
	//}


	cout << endl;

	cout << "你要叫地主吗？" << endl;
	cout << "输入1叫地主，不然则输入0." << endl;
	int y;
	cin >> y;
	if (y == 1) {
		b.setLL(1);
		b.setLLcard(a.getL());
		cout << "现在你是地主." << endl;
	}
	else {
		b1.setLL(1);
		b1.setLLcard(a.getL());
		srand((unsigned)time(NULL));
		int x = rand() % 2 + 1;
		cout << "地主是AI" << x << "号" << endl;
	}








	cout << endl;
	b.order();
	b1.order();
	cout << "底牌为：";
	cout << a.getL()[0] << " " << a.getL()[1] << " " << a.getL()[2] << " " << endl;

	cout << "您的手牌为：";
	for (int i = 0; i < 20; i++)
	{
		cout << b.getHand()[i] << " ";
	}




	cout << "请输入你要打出的手牌." << endl;





	//此为第一个回合
	if (b.getLL() == 1) {
		b.chuCardFirst();
		//b1.chuCard();
		//b2.chuCard();
	}


	cout << endl;
	cout << "您的手牌为：";
	for (int i = 0; i < 20; i++)
	{
		cout << b.getHand()[i] << " ";
	}
	cout << endl<<"temp为： ";
	for (int i = 0; i < 20; i++)
	{
		cout << temp[i] << " ";
	}





	//以下是第2个以及以后的回合
	//while (1) {
	//	if (b.getLL() == 1) {
	//		b.chuCard();   //仅指出牌  judge()和right()    //判断是否符合规则,以及能否打出  //以及是否打完
	//		//b1.chuCard();
	//		//b2.chuCard();
	//	}
	//	else if (b1.getLL() == 1) {
	//		//b1.chuCard();
	//		b.chuCard();   //仅指出牌  judge()和right()    //判断是否符合规则,以及能否打出
	//		//b2.chuCard();
	//	}


	//}


}


