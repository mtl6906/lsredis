#include "ls/redis/Tool.h"
#include "iostream"

using namespace std;

int main()
{
	auto rp = ls::redis::Tool::GetInstance() -> GetContext("exists month") -> GetIntReply();
	cout << rp.first << " " << rp.second << endl;
	ls::redis::Tool::GetInstance() -> GetContext("set month 12");
	auto ctx = ls::redis::Tool::GetInstance() -> GetContext("get month");
	auto res = ctx -> GetStringReply();
	cout << res.first << " " << res.second << endl; 
	return 0;
}
