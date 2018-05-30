//Name:room
//Author:qzc
//Date:2018.4.12
#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <map> 
using namespace std;

class Room {		//����ÿ��������˵���з��������������ڵ���Ϣ���Լ��Ƿ��й��ޣ��Ƿ��й���
public:
	Room(string name, bool up, bool south, bool west, bool east, bool monster, bool princess) {		//���ٴ�������ֱ���ڹ����ʱ������úø���bool����
		this->name = name;
		this->up = up;
		this->south = south;
		this->west = west;
		this->east = east;
		this->monster = monster;
		this->princess = princess;
		this->upRoom = NULL;			//�ڹ��캯���г�ʼ��Ϊ��ָ�룬��ֹ�쳣����
		this->southRoom = NULL;
		this->westRoom = NULL;
		this->eastRoom = NULL;
	}
private:
	string name;					//����������lobby��001��006����7�����䣨����߾�����
	bool up, south, west, east;		//�ĸ�bool������ʾ��ǰ��������Ƿ񿪷�
	bool monster;			//��ǰ�����Ƿ���monster
	bool princess;			//��ǰ�����Ƿ���princess
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
	Room* upRoom;			//���ø��������ָ�룬��������ת�Ƶ���Ӧ�ķ���ȥ
	Room* southRoom;
	Room* westRoom;
	Room* eastRoom;
};

