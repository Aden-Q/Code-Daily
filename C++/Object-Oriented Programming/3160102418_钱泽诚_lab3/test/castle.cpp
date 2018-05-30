//Name:castle
//Author:qzc
//Date:2018.4.12

#include "room.h"
#include <iostream>

void Castle(vector <Room> Rooms) {		//��Ϸ������
	Room *curroom;				//�û���ǰ�����ķ���
	curroom = &Rooms[0];		//��ʼ����ʼ����Ϊlobby��Ҳ���������еĵ�һ������
	bool game_flag = false;		//��ʶ�����Ƿ������falseΪ��������trueΪ����
	int exit_num;
	string user_input="";			//�����ӱ�׼�����ȡ�û�������
	bool princess_flag = false;		//��ʾ�Ƿ���������

	while (!game_flag) {
		if ((*curroom).get_princess() == true) {		//ÿ��ѭ����ʼ��鵱ǰ����������û�й���������й������flag����Ϊ��
			cout << "You get the princess, please take her to your home!!!" << endl;
			princess_flag = true;
		}
		if ((*curroom).get_monster() == true) {
			cout << "You are eaten by the monster!!!" << endl;		//����Ƿ������˹��ޣ���������ˣ��������ʾ��������Ϸ
			break;
		}
		if (princess_flag == true && (*curroom).get_name() == "lobby") {		//����õ��˹������һص���lobby����ʤ��
			cout << "You win!!!" << endl;
			break;
		}

		exit_num = (*curroom).get_east() + (*curroom).get_up() + (*curroom).get_west() + (*curroom).get_south();		//ͳ�Ƶ�ǰ�����ж��ٸ�����
		cout << "Welcome to the " << (*curroom).get_name() << ". There are " << exit_num << " exits as:";
		if ((*curroom).get_up())		//������еĳ�����
			cout << " up";
		if ((*curroom).get_south())
			cout << " south";
		if ((*curroom).get_east())
			cout << " east";
		if ((*curroom).get_west())
			cout << " west";
		cout << endl;		//�������
		cout << "Please enter your command: ";
		while (1) {
			getline(cin, user_input);		//��ȡһ���е�����			
			if (user_input == "go up" && (*curroom).get_up()) {		//�����ȡ���������Ҵ��������
				curroom = (*curroom).upRoom;				//�޸ĵ�ǰ����
				break;
			}
			else if (user_input == "go south" && (*curroom).get_south()) {		//�����ȡ���������Ҵ��������
				curroom = (*curroom).southRoom;				//�޸ĵ�ǰ����
				break;
			}
			if (user_input == "go east" && (*curroom).get_east()) {		//�����ȡ���������Ҵ��������
				curroom = (*curroom).eastRoom;				//�޸ĵ�ǰ����
				break;
			}
			if (user_input == "go west" && (*curroom).get_west()) {		//�����ȡ���������Ҵ��������
				curroom = (*curroom).westRoom;				//�޸ĵ�ǰ����
				break;
			}
			else {
				cout << "Wrong input! Please input again: ";
				continue;	//����������Ҫ�û���������
			}
		}
	
	}


}