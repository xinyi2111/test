#include<iostream>
#include<vector>
using namespace std;

//vector ��С���Զ�̬�ı�ײ�ռ��������Ŀռ�
/*void main()
{
	int ar[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int n = sizeof(ar) / sizeof(ar[0]);

	vector<int> iv(ar, ar + n);//ͨ�������ʼ������

	for (int i = 0; i<iv.size(); ++i)
		cout << iv[i] << " ";
	cout << endl;

	vector<int> iv1(iv.begin(), iv.end());//ͨ���������ʼ��������ĩβ������������������
	//verctor(inputlterator begin,inputlterator end)
	vector<int> iv2(iv1);
	//�������캯����ʼ��
	int iv3[] = { 1, 2, 3, 4, 5 };

	void main()
{
	vector<int> iv3{1,2,3,4,5,6,7,8,9,10};
	vector<int>::iterator it = iv3.begin();

	iv3.pop_back();
	auto pit = find(iv3.begin(), iv3.end(), 5);
	cout<<*pit<<endl;

	*pit = 20;
	iv3.erase(pit);


	while(it != iv3.end())
	{
		cout<<*it<<" ";
		++it;
	}
	cout<<endl;
}

void main()
{
	vector<int> iv3{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	vector<int>::iterator it = iv3.begin();

	iv3.pop_back();
	auto pit = find(iv3.begin(), iv3.end(), 5);//find�ӿڵ�ʵ��
    //������
	cout << *pit << endl;

	*pit = 20;//��ָ�뽫20��5�滻
	iv3.erase(pit);
	auto pos2 = find(iv3.begin(), iv3.end(), 5);//���м����λ�ò���

	while (it != iv3.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

void main()
{
	//�Ե�����ʧЧ���о���
	vector<int> iv1{ 1, 2, 3, 4, 5 };
	auto it = find(iv1.begin(), iv1.end(), 3);
	//����3��λ��
	cout << *it << endl;
	iv1.push_back(10);
	//cout << *it << endl;
	//�����µ����ݵ��µײ�ռ����ݣ���ǰ�����Ŀռ䱻�ͷţ����Ե�����ʧЧ
	//���������Խ��������ʧЧ������
	//�漰���ռ����ݻ�ɾ���������Ϳ��ܻ�ʧЧ
	//��������������¸�ֵ

	it = find(iv1.begin(), iv1.end(), 3);
	cout << *it << endl;

}

void main()
{
	//��������ɾ��
	vector<int> iv1{ 1, 2, 3, 4, 5 };
	auto it = find(iv1.begin(), iv1.end(), 3);

	cout << *it << endl;

	it = iv1.erase(it);

	cout << *it << endl;
}*/

int main()
{
	vector <int>iv4{ 1, 2, 3, 4};
	auto it = iv4.begin();
	while (it != iv4.end())
	{
		if (*it % 2 == 0)
		{
			it=iv4.erase(it);
			
			//��Ҫ���¸�ֵ����Ȼ2��Ӧ�ĵ�����ʧЧ
			//��Ȼ����ͨ�����ǽ���������
		}
		else
		{
			++it;
		}
	}
	for (auto &e : iv4)
		cout << e << " ";
	cout << endl;
	/*cout << "we"<< endl;*/


	return 0;

	

}