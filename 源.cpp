#include "common.h"

int main() {
	//管理类采用单例模式
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
			cout << "按平均分排序并显示" << endl;
			cout << "计算平均分成功" << endl;
			if (manag->sortByAverageScore<vector<student*>, student*>(students))
				cout << "排序成功" << endl << endl;
			else
				cout << "发生未知错误" << endl << endl;
			manag->AveragetitleMenu();
			manag->printAverangeScore<vector<student*>, student*>(students);
			break;
		case 3:
			cout << "各科的班平均成绩" << endl;
			manag->titleMenuOfClassAverage();
			manag->calculateAverageOfScoreAndPrint(students);
			break;
		case 4:
			cout << "请输入要查询的学生的姓名：" << endl;
			cin >> name;
			manag->searchByName(students, name);
			break;
		case 5:
			cout << "显示所有不及格的学生:" << endl;
			manag->printScoreFailure(students);
			break;
		case 6:
			cout << "显示最高和最低成绩" << endl;
			manag->findMaxAndMin(students);
			break;
		case 7:
			cout << "请输入成绩区间的两个数字（闭区间）" << endl;
			cin >> up >> down;
			manag->coutAndSegmentScore(students, up, down);
			break;
		default:
			cout << "输入错误，请重新输入：" << endl;
		}
		manag->menu();
	}	manag->ending(students);
	return 0;
}
