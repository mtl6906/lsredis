#ifndef LS_REDISAPI_TOOL_H
#define LS_REDISAPI_TOOL_H

#include "ls/redis/Context.h"
#include "ls/redis/RedisConfig.h"
#include "ls/redis/ConnectionPool.h"
#include "ls/LockedCache.h"

namespace ls
{
	namespace redis
	{
		class Tool
		{
			static Tool *instance;
			RedisConfig config;
			ConnectionPool pool;
			public:
				Tool();
				~Tool();
				static Tool *GetInstance();
				std::unique_ptr<Context> GetContext(const std::string &cmd);
				std::unique_ptr<Context> GetContext(std::initializer_list<std::string> il);
		};
	}
}

#endif
