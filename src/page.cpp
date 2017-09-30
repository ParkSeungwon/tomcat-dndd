#include"mysqldata.h"
#include"cgi.h"
using namespace std;

int main(int argc, char** argv)
{
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
	auto it = d.begin();
	string sep = "<?separator?>";
	for(int i=2; i<6; i++) cout << (*it)[i] << sep; //id, title, text, date
	for(it++; it!= d.end(); it++) 
		cout << (*it)[4] << sep << (*it)[5] << sep << (*it)[2] << sep;//comment
}
