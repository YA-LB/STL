#include<iostream>
#include <vector>
#include <string>
#include <map>
#include <ctime>//时间

//员工分组
using namespace std;
enum
{
	CAIWU,RENLI,MEISHU
};

class Worker
{
public:
	string m_Name;//姓名
	int m_Money; //工资
};

void createWorker(vector<Worker>&v)
{
	string nameSeed = "ABCDE";
	for (int i = 0; i < 5;i++)
	{
		Worker worker;
		worker.m_Name = "员工";
		worker.m_Name += nameSeed[i];
		worker.m_Money = rand() % 10000 + 10000; // 10000 ~ 19999
		v.push_back(worker);
	}

}

void setGroup(vector<Worker>&v, multimap<int, Worker>&m)
{
	for (vector<Worker>::iterator it = v.begin(); it != v.end();it++)
	{
		//随机产生部门编号  0 1 2 
		int id = rand() % 3;

		//将员工插入到分组的容器中
		m.insert(make_pair(id, *it));
	}

}

void showWorker(multimap<int,Worker>&m)
{
	// 0 A   0  B   1  C   2  D  2 E
	cout << "财务部门人员如下： " << endl;
	multimap<int,Worker>::iterator pos = m.find(CAIWU);
	int count = m.count(CAIWU);
	int index = 0;

	for (; pos != m.end(), index < count; pos++, index++)
	{
		cout << "姓名： " << pos->second.m_Name << " 工资： " << pos->second.m_Money << endl;
	}

	cout << "人力资源部门人员如下： " << endl;
	pos = m.find(RENLI);
	count = m.count(RENLI);
	index = 0;

	for (; pos != m.end(), index < count; pos++, index++)
	{
		cout << "姓名： " << pos->second.m_Name << " 工资： " << pos->second.m_Money << endl;
	}



	cout << "美术部门人员如下： " << endl;
	pos = m.find(MEISHU);
	count = m.count(MEISHU);
	index = 0;

	for (; pos != m.end(), index < count; pos++, index++)
	{
		cout << "姓名： " << pos->second.m_Name << " 工资： " << pos->second.m_Money << endl;
	}

}

int main(){
	//随机数种子
	srand((unsigned int)time(NULL));
	vector<Worker>v; //存放员工的容器
	//员工的创建
	createWorker(v);
	//员工分组
	multimap<int, Worker>m;
	setGroup(v,m);
	//分部门显示员工
	showWorker(m);
}
