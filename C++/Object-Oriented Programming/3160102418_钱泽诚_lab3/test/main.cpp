//Name:main
//Author:qzc
//Date:2018.4.12

#include "room.h"
#include <ctime>		//�������������
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
	int mon_num, prin_num;		//��ʾ����һ�����������ɹ��޺͹������������������������Χ��1-6�Ҳ�����ͬ
	srand((unsigned)time(NULL));
	mon_num = rand() % 6 + 1;		//����������ķ�Χ��1-6
	while (1) {
		prin_num = rand() % 6 + 1;
		if (prin_num != mon_num)		//��֤�����͹����ڲ�ͬ�ķ���
			break;
	}

	Room R0("lobby", true, false, true, true, false, false);	//���������ţ�û�й����͹���
	Room R1("001", true, true, true, false, false, false);		//���������ţ�û�й����͹���
	Room R2("002", false, true, true, false, false, false);		//�������ţ�û�й����͹���
	Room R3("003", true, true, false, true, false, false);		//���������ţ�û�й����͹���
	Room R4("004", true, false, false, true, false, false);		//�������ţ�û�й����͹���
	Room R5("005", false, false, true, false, false, false);	//�����ţ�û�й����͹���
	Room R6("006", false, true, false, true, false, false);		//�������ţ�û�й����͹���

	Rooms.push_back(R0);
	Rooms.push_back(R1);
	Rooms.push_back(R2);
	Rooms.push_back(R3);
	Rooms.push_back(R4);
	Rooms.push_back(R5);
	Rooms.push_back(R6);
	Rooms[0].upRoom = &Rooms[1];			//��ʾ������ͨ���ĸ�����
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
	Rooms[prin_num].set_princess();		//���ô˷���Ϊ������
	Rooms[mon_num].set_monster();		//���ô˷���Ϊ���޷�

	Castle(Rooms);



	return 0;
}