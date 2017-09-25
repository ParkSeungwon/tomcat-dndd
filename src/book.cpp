#include<iostream>
#include"mysqldata.h"
#include"cgi.h"
using namespace std;

int main()
{
	string qs = getenv("QUERY_STRING");
	string tb = CGI::param(qs, "table");
	string book = CGI::param(qs, "book");
	string db = CGI::param(qs, "group");
	SqlQuery sq;
	sq.connect("localhost", "dndd", "dndddndd", db);
	sq.select(tb, "where num=" + book + " order by page, date, edit desc");
	sq.group_by("page");
	cout << "Content-type:text/html\r\n\r\n";
	for(auto it = sq.begin(); it != sq.end(); it++)
		cout << (*it)[1] << '\n' << (*it)[3] << '\n';//page, title
}
