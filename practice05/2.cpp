/*
��ע��==,!=,<<�ȷ������ص�ʵ��
��ע�ⳣ�������ʹ��
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class Book{
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
	string getname() const;
	string getauthor() const;
	string getISBN() const;
	string gettime() const;
	void borrowBook();
	void returnBook();

	//�Զ���ȽϺ�����ISBN��С��������
	bool operator < (const Book & b){
		return ISBN < b.ISBN;
	}
	friend bool operator == (const Book &a, const Book &b);
	friend bool operator != (const Book &a, const Book &b);
	//�����������
	friend ostream & operator << (ostream & os, Book & b);
};
string Book::getname() const{
	return name;
}
string Book::getauthor() const{
	return author;
}
string Book::getISBN() const{
	return ISBN;
}
string Book::gettime() const{
	return time;
}
void Book::borrowBook(){
	isBorrowed = true;
}
void Book::returnBook(){
	isBorrowed = false;
}

bool operator == (const Book &a, const Book &b){
	return a.getISBN() == b.getISBN();
}

bool operator != (const Book &a, const Book &b){
	return a.getISBN() != b.getISBN();
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
	//for testing operator == and !=
	//cout << (vec[0] == vec[1])<< endl;
	//cout << (vec[0] != vec[1]) << endl;
	//system("pause");
	return 0;
}