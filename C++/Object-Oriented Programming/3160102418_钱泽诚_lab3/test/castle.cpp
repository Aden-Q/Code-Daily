//Name:castle
//Author:qzc
//Date:2018.4.12

#include "room.h"
#include <iostream>

void Castle(vector <Room> Rooms) {		//游戏主程序
	Room *curroom;				//用户当前所处的房间
	curroom = &Rooms[0];		//初始化起始房间为lobby，也就是容器中的第一个房间
	bool game_flag = false;		//标识程序是否结束，false为不结束，true为结束
	int exit_num;
	string user_input="";			//用来从标准输入读取用户的命令
	bool princess_flag = false;		//表示是否遇到公主

	while (!game_flag) {
		if ((*curroom).get_princess() == true) {		//每次循环开始检查当前房间里面有没有公主，如果有公主则把flag设置为真
			cout << "You get the princess, please take her to your home!!!" << endl;
			princess_flag = true;
		}
		if ((*curroom).get_monster() == true) {
			cout << "You are eaten by the monster!!!" << endl;		//检查是否遇到了怪兽，如果遇到了，则输出提示并结束游戏
			break;
		}
		if (princess_flag == true && (*curroom).get_name() == "lobby") {		//如果拿到了公主并且回到了lobby，则胜利
			cout << "You win!!!" << endl;
			break;
		}

		exit_num = (*curroom).get_east() + (*curroom).get_up() + (*curroom).get_west() + (*curroom).get_south();		//统计当前房间有多少个出口
		cout << "Welcome to the " << (*curroom).get_name() << ". There are " << exit_num << " exits as:";
		if ((*curroom).get_up())		//输出所有的出口名
			cout << " up";
		if ((*curroom).get_south())
			cout << " south";
		if ((*curroom).get_east())
			cout << " east";
		if ((*curroom).get_west())
			cout << " west";
		cout << endl;		//输出换行
		cout << "Please enter your command: ";
		while (1) {
			getline(cin, user_input);		//读取一整行的输入			
			if (user_input == "go up" && (*curroom).get_up()) {		//如果读取到了向上且存在这个门
				curroom = (*curroom).upRoom;				//修改当前房间
				break;
			}
			else if (user_input == "go south" && (*curroom).get_south()) {		//如果读取到了向下且存在这个门
				curroom = (*curroom).southRoom;				//修改当前房间
				break;
			}
			if (user_input == "go east" && (*curroom).get_east()) {		//如果读取到了向左且存在这个门
				curroom = (*curroom).eastRoom;				//修改当前房间
				break;
			}
			if (user_input == "go west" && (*curroom).get_west()) {		//如果读取到了向右且存在这个门
				curroom = (*curroom).westRoom;				//修改当前房间
				break;
			}
			else {
				cout << "Wrong input! Please input again: ";
				continue;	//错误输入需要用户重新输入
			}
		}
	
	}


}