/*
������ע������ʽ�����Ե���ϵͳ�������е�����Ҳ�����Լ�ʵ�֡�
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class Book{
	//��ע��淶�������ó�Ա����Ϊ˽��
private:
	string name;
	string author;
	string ISBN;
	string time;
	bool isBorrowed;
public:
	//constructor
	Book(string _name, string _author, string _ISBN, string _time) :name(_name), author(_author), ISBN(_ISBN), time(_time){
		isBorrowed = false;	
	}
	//ͨ����Ա��������ó�Ա����
	string getname();
	string getauthor();
	string getISBN();
	string gettime();
	void borrowBook();
	void returnBook();
	
	//�Զ���ȽϺ�����ISBN��С��������
	bool operator < (const Book & b){
		return ISBN < b.ISBN;
	}
	//�����������
	friend ostream & operator << (ostream & os, Book & b);
};
string Book::getname(){
	return name;
}
string Book::getauthor(){
	return author;
}
string Book::getISBN(){
	return ISBN;
}
string Book::gettime(){
	return time;
}
void Book::borrowBook(){
	isBorrowed = true;
}
void Book::returnBook(){
	isBorrowed = false;
}
ostream & operator <<(ostream & os, Book & b){
	os << b.name << " " << b.author << " " << b.ISBN << " " << b.time << endl;
	return os;
}

int main(){
	vector<Book> vec;
	string _name, _author, _ISBN, _time;
	//����
	while (cin >> _name >> _author >> _ISBN >> _time){
		vec.push_back(Book(_name, _author, _ISBN, _time));
	}
	//����
	sort(vec.begin(), vec.end());
	for (auto & v : vec){
		cout << v;
	}
	//system("pause");
	return 0;
}