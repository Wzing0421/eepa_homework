#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
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
	//ע�⻪�϶�ת���϶ȵĹ�ʽ
	for (auto info : vecinfo){
		outfile << info.hour << " " << fixed << setprecision(2) << (info.temperature - 32) / 1.8 << endl;
	}
	outfile.close();
	return 0;
}