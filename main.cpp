//first of all ,you should know this is a dou di zhu.
// 这是主函数，游戏进程在这里

#include"function.h"
#include"player.h"
#include"ai.h"
#include"card.h"
using namespace std;
extern int temp[20] = { 0 };       //全局变量，temp数组为出了牌后，暂存牌的数组
extern int tempFunction = 0;       //全局变量，tempFunction为暂存的牌的类型
int main() {

	menu();         //调用菜单        


	//定义一组牌对象，进行洗牌并分为三组基本牌和一组地主牌
	card a;         
	a.washCard();

	a.dealcard();

	//定义玩家对象b，并将b的手牌设置为a中的第一组基本牌
	player b;
	b.setCard(a.getP());

	//定义ai对象b1，并将b1的手牌设置为a中的第二组基本牌
	ai b1;
	b1.setCard(a.getP1());

	//定义ai对象b2，并将b2的手牌设置为a中的第三组基本牌
	ai b2;
	b2.setCard(a.getP2());


	//三组手牌都进行排序
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
		b.setLL(1);                                //将b设置为地主
		b.setLLcard(a.getL());                     //将b的手牌加上a中的地主牌
		cout << "现在你是地主." << endl;
	}
	else {
		b1.setLL(1);                               //将ai b1设置为地主
		b1.setLLcard(a.getL());                    //将b1的手牌加上a中的地主牌


		//随机说一个ai是地主
		//但是后台里ai就是b1
		srand((unsigned)time(NULL));               
		int x = rand() % 2 + 1;
		cout << "地主是AI" << x << "号" << endl;
	}

	cout << endl;

	b.order();  
	b1.order();
	
	//打印出地主牌
	cout << "底牌为：";
	cout << a.getL()[0] << " " << a.getL()[1] << " " << a.getL()[2] << " " << endl;

	cout << "您的手牌为：";
	for (int i = 0; i < 20; i++)
	{
		cout << b.getHand()[i] << " ";
	}




	cout << "请输入你要打出的手牌." << endl;





	//此为第一个回合，谁是地主谁先出牌
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

	//测试代码
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


