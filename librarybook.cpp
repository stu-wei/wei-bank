#include"librarybook.h"
LibraryBook::LibraryBook() {
	bookid = "A1";
	title = "C++";
	writer = "lisa";
	publisher = "高等教育出版社";
	price = 50;
	total = 4;
	still = 4;
}
LibraryBook::LibraryBook(string bookid, string t,string w, string pub, double p, int total) {
	set(bookid, t, w, pub, p, total);
}
void LibraryBook::set(string bookid, string t, string w, string pub, double p, int total) {
	this->bookid = bookid;
	title = t;
	writer = w;
	publisher = pub;
	price = p;
	this->total = total;
	still = total;
}
string LibraryBook::getBook() const {
	return bookid;
}
string LibraryBook::getTitle() const {
	return title;
}
bool LibraryBook::doBorrow() {
	if (still > 0) {
		still--;
		return true;
	}
	return false;
}
void LibraryBook::doReturn() {
	if (still < total) {
		still++;
	}
}
void LibraryBook::printInfo() const {
	cout << "编号：" << bookid << endl;
	cout << "书名：" <<title<< endl;
	cout << "作者：" <<writer<< endl;
	cout << "出版社：" << publisher << endl;
	cout << "价格：" << price <<"元"<< endl;
	cout << "总数量：" << total << "可借：" << still << endl;
	if (still > 0) {
		cout << "状态：可借阅" << endl;
	}
	else {
		cout << "状态：不可借阅" << endl;
	}
}