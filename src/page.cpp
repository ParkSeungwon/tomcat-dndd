#include<json/json.h>
#include"mysqldata.h"
#include"cgi.h"
using namespace std;

int main(int argc, char** argv)
{//print json object <- query with db, table, book, page,
	string qs = getenv("QUERY_STRING");
	string db = CGI::param(qs, "group");
	string tb = CGI::param(qs, "table");
	string book = CGI::param(qs, "book");
	string page = CGI::param(qs, "page");
	SqlQuery d;
	d.connect("localhost", "dndd", "dndddndd", db);

	d.select(tb, "where num=" + book +" and page=" + page + " order by date, email, edit desc");
	d.group_by("date", "email");
	cout << "Content-type:text/html\r\n\r\n";                                     
	Json::Value jv;
	auto it = d.begin();
	const char* name[] = {"id", "title", "text", "date"};
	for(int i=0; it!= d.end(); it++, i++) //title for comment = "코멘트임."
		for(int j=0; j<4; j++) jv[i][name[j]] = static_cast<string>((*it)[j+2]);
	cout << jv;
}
