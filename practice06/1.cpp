/*
������Գ���ѧ�����ļ���ز�����
*/
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
struct Reading {    //�¶����ݶ�ȡ
	int hour;                // ��[0:23]����ȡֵ��Сʱ��
	double temperature;      // �����¶�
};
vector<Reading> vecinfo;
int main(){
	int _hour;
	double _temperature;
	//�ض����ļ�����
	while (cin >> _hour >> _temperature){
		Reading r;
		r.hour = _hour;
		r.temperature = _temperature;
		vecinfo.push_back(r);
	}

	ofstream outfile;//����ļ���
	outfile.open("store_temps.txt");//Ĭ���Ǹ���д��
	/*
	outfile.open("store_temps.txt", ios::out|ios::app);�����ô�׷��д��,���Բο���������
	https://blog.csdn.net/cfl997/article/details/103387997?depth_1-utm_source=distribute.pc_relevant.none-task&utm_source=distribute.pc_relevant.none-task
	��Ԫ��д���ļ�
	*/
	for (auto info : vecinfo){
		outfile << info.hour << " " << info.temperature << endl;
	}
	outfile.close();
	return 0;
}