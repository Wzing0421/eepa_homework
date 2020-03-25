/*
��ע���������ʱ���Լ�ֲ�����
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <vector>
using namespace std;

class Fraction{
	//���Ӻͷ�ĸ
	int numerator;
	int denominator;
public:
	Fraction(){}
	Fraction(int _numberator, int _denominator) :numerator(_numberator), denominator(_denominator){}
	//������������
	Fraction operator +(Fraction &f);
	Fraction operator -(Fraction &f);
	Fraction operator *(Fraction &f);
	Fraction operator /(Fraction &f);
	int getnumerator() const{ return numerator; }
	int getdenominator() const{ return denominator; }
	//��������
	void simplify();
	int gcd(int _numerator, int _denominator);//շת����õ����ӷ�ĸ���Լ��

};

Fraction Fraction::operator +(Fraction &f){
	int num1 = getnumerator() * f.getdenominator() + getdenominator() * f.getnumerator();
	int num2 = getdenominator() * f.getdenominator();
	Fraction ret(num1, num2);
	ret.simplify();
	return ret;
}

Fraction Fraction::operator -(Fraction &f){
	int num1 = getnumerator() * f.getdenominator() - getdenominator() * f.getnumerator();
	int num2 = getdenominator() * f.getdenominator();
	Fraction ret(num1, num2);
	ret.simplify();
	return ret;
}

Fraction Fraction::operator *(Fraction &f){
	int num1 = getnumerator() *  f.getnumerator();
	int num2 = getdenominator() * f.getdenominator();
	Fraction ret(num1, num2);
	ret.simplify();
	return ret;
}

Fraction Fraction::operator /(Fraction &f){
	int num1 = getnumerator() *  f.getdenominator();
	int num2 = getdenominator() * f.getnumerator();
	Fraction ret(num1, num2);
	ret.simplify();
	return ret;
}

//�����������ӷ�ĸԼ��
void Fraction::simplify(){
	int num = gcd(numerator, denominator);
	//��ֹ��ĸ���ָ���
	if (num < 0) num = abs(num);
	numerator = numerator / num;
	denominator = denominator / num;
}

//շת���������ӷ�ĸ���Լ��
int Fraction::gcd(int _numerator, int _denominator){
	if (_denominator == 0) return _numerator;
	else return gcd(_denominator, _numerator % _denominator);
}

int main(){

	int num1, num2, num3, num4;//�����������ӷ�ĸ
	char ch1, ch2; // ����/
	char op; //������
	cin >> num1 >> ch1 >> num2 >> op >> num3 >> ch2 >> num4;
	Fraction f1(num1, num2);
	Fraction f2(num3, num4);
	Fraction ret;
	switch (op)
	{
	case '+':
		ret = f1 + f2;
		break;
	case '-':
		ret = f1 - f2;
		break;
	case '*':
		ret = f1 * f2;
		break;
	case '/':
		ret = f1 / f2;
		break;
	default:
		break;
	}
	double ans = (double)ret.getnumerator() / ret.getdenominator();
	cout << ret.getnumerator() << '/' << ret.getdenominator() << '(' << fixed << setprecision(6) << ans << ')' << endl;
	//system("pause");
	return 0;
}