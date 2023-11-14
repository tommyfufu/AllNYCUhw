# LCD 符號
皆為''char字符
* b : 水球
* e : 水球炸開符號
* 6 : 道具
* 7 : 道具
*   : 空白
* B : 磚塊
* Y : 箱子
* T : 樹
* X : 房子
* 0 : 0號玩家
* ; : 0號玩家與水球重疊
* / : 0號玩家與炸紋重疊
* ) : 0號玩家被炸到
* 1 : 1號玩家
* a : 1號玩家與水球重疊
* z : 1號玩家與炸紋重疊
* ! : 1號玩家被炸到
* I : 未知

# 結構
struct sock_data{
	char map_p[13][15];
	char buf[64];
};