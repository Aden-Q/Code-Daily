//Name:room
//Author:qzc
//Date:2018.4.12
#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <map> 
using namespace std;

class Room {		//对于每个房间来说，有房间名，各个出口的信息，以及是否有怪兽，是否有公主
public:
	Room(string name, bool up, bool south, bool west, bool east, bool monster, bool princess) {		//减少代码量，直接在构造的时候就设置好各个bool变量
		this->name = name;
		this->up = up;
		this->south = south;
		this->west = west;
		this->east = east;
		this->monster = monster;
		this->princess = princess;
		this->upRoom = NULL;			//在构造函数中初始化为空指针，防止异常访问
		this->southRoom = NULL;
		this->westRoom = NULL;
		this->eastRoom = NULL;
	}
private:
	string name;					//房间名，由lobby，001到006，共7个房间（设计者决定）
	bool up, south, west, east;		//四个bool变量表示当前房间的门是否开放
	bool monster;			//当前房间是否含有monster
	bool princess;			//当前房间是否含有princess
public:
	bool get_up();
	bool get_south();
	bool get_west();
	bool get_east();
	bool get_monster();
	void set_monster();
	bool get_princess();
	void set_princess();
	string get_name();
	Room* upRoom;			//设置各个房间的指针，用来快速转移到对应的房间去
	Room* southRoom;
	Room* westRoom;
	Room* eastRoom;
};

