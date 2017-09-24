#include<string>
#include<istream>
#include<map>

class CGI
{
public:
	static std::string header() {return header_;}
	static std::string param(const std::string& post_string, 
			const std::string& parameter);
	static std::map<std::string, std::string> parse_post(std::istream& post);

private:
	static std::string header_;
};
