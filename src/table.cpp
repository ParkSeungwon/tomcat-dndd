#include<iostream>
#include"mysqldata.h"
#include"cgi.h"
using namespace std;

int main()
{
	string tb = CGI::param(getenv("QUERY_STRING"), "table");
	string db = CGI::param(getenv("QUERY_STRING"), "group");
	SqlQuery sq;
	sq.connect("localhost", "dndd", "dndddndd", db);
	sq.select(tb, "where page=0 order by num, date, email, edit desc");
	sq.group_by("num");
	cout << "Content-type:text/html\r\n\r\n";
	for(auto it = sq.begin(); it != sq.end(); it++) {
//		cout << "<a href='book.cgi?table=" + tb;
//		cout << "&book=" << (*it)[0] << "'>";
		cout << (*it)[0] << '\n' << (*it)[3] << '\n';
	}
}
