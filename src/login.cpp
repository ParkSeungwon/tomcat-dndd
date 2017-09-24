#include<iostream>
#include<string>
#include"mysqldata.h"
#include"cgi.h"
using namespace std;

int main()
{
	string s;
	auto param = CGI::parse_post(cin);
	string id = param["id"];
	string pass = param["password"];
	string db = param["group"];
	SqlQuery sq;
	sq.connect("localhost", "dndd", "dndddndd", db);
	sq.select("Users", "where email='" + id + "' order by date desc limit 1");
	auto it = sq.begin();
	bool login =false;//id=zezeon%40msn.com&password=cockcodk0
	if((*it)[1] == sq.password(pass)) login=true;
	cout << "Content-type:text/html\r\n\r\n";                                     
	if(login) {
		cout << (*it)[3] <<'\n'<< (*it)[2] << '\n';
		for(auto& a : sq.show_tables()) if(a!="Users" && a!="Vote" && a!="Follow") 
			cout << a << '\n';//print all tables
	} else cout << "Login failed";
}
