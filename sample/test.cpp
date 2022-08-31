#include "ls/redis/API.h"
#include "ls/DefaultLogger.h"
#include "iostream"

using namespace std;
using namespace ls;

int main()
{
	bool isMonthExist = redis::api.exists("month");
	LOGGER(ls::INFO) << "month is " << (isMonthExist ? "" : "not ") << "exist" << ls::endl;
	bool isMonth1Exist = redis::api.exists("month1");
	LOGGER(ls::INFO) << "month1 is " << (isMonth1Exist ? "" : "not ") << "exist" << endl;

	redis::api.set("month", "7");

	int ec;
	LOGGER(ls::INFO) << "month: " << redis::api.getString(ec, "month") << ls::endl;

	auto month1 = redis::api.getString(ec, "month1");
	if(ec < 0)
		LOGGER(ls::INFO) << Exception(ec).what() << ls::endl;
	else
	{
		LOGGER(ls::INFO) << "month1: " << month1 << ls::endl;
	}
	return 0;
}
