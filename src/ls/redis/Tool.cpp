#include "ls/util.h"
#include "ls/redis/Tool.h"

#define REDIS_LOG "REDIS_LOG"

using namespace std;

namespace ls
{
	namespace redis
	{
		Tool *Tool::instance = new Tool();
		Tool::Tool() : pool(config)
		{
			ls_log_tag(REDIS_LOG, "tool create");
		}
		Tool::~Tool()
		{
			
		}
		unique_ptr<Context> Tool::GetContext(const string &cmd)
		{
			return unique_ptr<Context>(new Context(pool, cmd));
		}
		unique_ptr<Context> Tool::GetContext(initializer_list<string> il)
		{
			int len = il.size() + 1;
			for(auto it : il)
				len += it.size();
			string cmd;
			cmd.reserve(len);
			for(auto it : il)
			{
				cmd.append(it);
				cmd.append(" ");
			}
			cmd.pop_back();
			return GetContext(cmd);
		}
		Tool *Tool::GetInstance()
		{
			return instance;
		}
	}
}

