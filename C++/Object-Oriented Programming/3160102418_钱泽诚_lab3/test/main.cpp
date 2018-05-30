//Name:main
//Author:qzc
//Date:2018.4.12

#include "room.h"
#include <ctime>		//用于生成随机数
#include <iostream>

vector <Room> Rooms;

bool Room::get_up() {
	return up;
}
bool Room::get_south() {
	return south;
}
bool Room::get_west() {
	return west;
}
bool Room::get_east() {
	return east;
}
bool Room::get_monster() {
	return monster;
}
bool Room::get_princess() {
	return princess;
}
void Room::set_princess() {
	princess = true;
}
void Room::set_monster() {
	monster = true;
}
string Room::get_name() {
	return name;
}

void Castle(vector <Room> Rooms);

int main() {
	int mon_num, prin_num;		//表示在哪一个房间里生成怪兽和公主，生成两个随机整数，范围是1-6且不能相同
	srand((unsigned)time(NULL));
	mon_num = rand() % 6 + 1;		//生成随机数的范围是1-6
	while (1) {
		prin_num = rand() % 6 + 1;
		if (prin_num != mon_num)		//保证公主和怪兽在不同的房间
			break;
	}

	Room R0("lobby", true, false, true, true, false, false);	//有上左右门，没有公主和怪兽
	Room R1("001", true, true, true, false, false, false);		//有上左下门，没有公主和怪兽
	Room R2("002", false, true, true, false, false, false);		//有下左门，没有公主和怪兽
	Room R3("003", true, true, false, true, false, false);		//有上下右门，没有公主和怪兽
	Room R4("004", true, false, false, true, false, false);		//有上右门，没有公主和怪兽
	Room R5("005", false, false, true, false, false, false);	//有左门，没有公主和怪兽
	Room R6("006", false, true, false, true, false, false);		//有下右门，没有公主和怪兽

	Rooms.push_back(R0);
	Rooms.push_back(R1);
	Rooms.push_back(R2);
	Rooms.push_back(R3);
	Rooms.push_back(R4);
	Rooms.push_back(R5);
	Rooms.push_back(R6);
	Rooms[0].upRoom = &Rooms[1];			//表示各个门通向哪个房间
	Rooms[0].eastRoom = &Rooms[5];
	Rooms[0].westRoom = &Rooms[4];
	Rooms[1].southRoom = &Rooms[0];
	Rooms[1].westRoom = &Rooms[3];
	Rooms[1].upRoom = &Rooms[2];
	Rooms[2].westRoom = &Rooms[6];
	Rooms[2].southRoom = &Rooms[1];
	Rooms[3].upRoom = &Rooms[6];
	Rooms[3].southRoom = &Rooms[4];
	Rooms[3].eastRoom = &Rooms[1];
	Rooms[4].upRoom = &Rooms[3];
	Rooms[4].eastRoom = &Rooms[0];
	Rooms[5].westRoom = &Rooms[0];
	Rooms[6].eastRoom = &Rooms[2];
	Rooms[6].southRoom = &Rooms[3];
	Rooms[prin_num].set_princess();		//设置此房间为公主房
	Rooms[mon_num].set_monster();		//设置此房间为怪兽房

	Castle(Rooms);



	return 0;
}