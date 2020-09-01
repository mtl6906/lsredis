#include "ls/redis/Tool.h"

int main()
{
	ls::redis::Tool::GetInstance() -> GetRedis() -> command("set", "month", "19");
	return 0;
}
