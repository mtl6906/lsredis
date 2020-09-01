#include "ls/json/Json.h"
#include "ls/util.h"
#include "ls/redis/Tool.h"

using std::string;
using std::unique_ptr;
using ls::json::String;
using ls::json::Int;
using ls::json::Object;
using sw::redis::ConnectionOptions;
using sw::redis::ConnectionPoolOptions;
using sw::redis::Redis;

namespace ls
{
	namespace redis
	{
		Tool *Tool::instance = new Tool();

		Tool::Tool()
		{
			char *configPath = getenv("REDIS_CONFIG_PATH");
			if(configPath == NULL)
				configPath = (char *)"RedisConfig.json";
			string content;
			if(ReadFullFile(configPath, content) < 0)
				exit(1);
			Object root;
			root.ParseFrom(content);
			string host, password;
			int poolSize, port;
			GET_STRING(root, "host", host);
			GET_STRING(root, "password", password);
			GET_INT(root, "port", port);
			GET_INT(root, "poolSize", poolSize);
	
			ConnectionOptions co;
			ConnectionPoolOptions cpo;

			co.host = host;
			co.port = 6379;
			co.password = password;
			co.db = 0;
			co.keep_alive = true;

			cpo.size = poolSize;
			redis = new Redis(co, cpo);
		}

		Tool::~Tool()
		{
			 delete redis;
		}

		Redis *Tool::GetRedis()
		{
			return redis;
		}

		Tool *Tool::GetInstance()
		{
			return instance;
		}
	}
}

