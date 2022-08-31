#ifndef LS_REDISAPI_API_H
#define LS_REDISAPI_API_H

#include "ls/redis/Context.h"
#include "ls/redis/Config.h"
#include "ls/Pool.h"
#include "memory"

namespace ls
{
	namespace redis
	{
		class API
		{
			Config config;
			Pool<Connection> pool;
			public:
				API();
				std::unique_ptr<Context> getContext(const std::string &cmd);
				std::unique_ptr<Context> getContext(std::initializer_list<std::string> il);
				bool exists(const std::string &key);
				std::string getString(int &ec, const std::string &key);
				int getInt(int &ec, const std::string &key);
				void set(const std::string &key, const std::string &value);
		};
		extern API api;
	}
}

#endif
