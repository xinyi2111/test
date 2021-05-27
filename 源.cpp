#include "common.h"

int main() {
	//��������õ���ģʽ
	manager* manag = manager::simpleInstance();
	vector<student*> students;
	manag->start(students);
	int input = 0;
	string name;
	int up = 0, down = 0;
	manag->menu();
	while (cin >> input && input != 0) {
		switch (input) {
		case 1:
			manag->titleMenu();
			manag->printScore<vector<student*>, student*>(students);
			break;
		case 2:
			cout << "��ƽ����������ʾ" << endl;
			cout << "����ƽ���ֳɹ�" << endl;
			if (manag->sortByAverageScore<vector<student*>, student*>(students))
				cout << "����ɹ�" << endl << endl;
			else
				cout << "����δ֪����" << endl << endl;
			manag->AveragetitleMenu();
			manag->printAverangeScore<vector<student*>, student*>(students);
			break;
		case 3:
			cout << "���Ƶİ�ƽ���ɼ�" << endl;
			manag->titleMenuOfClassAverage();
			manag->calculateAverageOfScoreAndPrint(students);
			break;
		case 4:
			cout << "������Ҫ��ѯ��ѧ����������" << endl;
			cin >> name;
			manag->searchByName(students, name);
			break;
		case 5:
			cout << "��ʾ���в������ѧ��:" << endl;
			manag->printScoreFailure(students);
			break;
		case 6:
			cout << "��ʾ��ߺ���ͳɼ�" << endl;
			manag->findMaxAndMin(students);
			break;
		case 7:
			cout << "������ɼ�������������֣������䣩" << endl;
			cin >> up >> down;
			manag->coutAndSegmentScore(students, up, down);
			break;
		default:
			cout << "����������������룺" << endl;
		}
		manag->menu();
	}	manag->ending(students);
	return 0;
}
