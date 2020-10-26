#include "ls/redis/RedisConfig.h"
#include "ls/util.h"

#define REDISCONFIG_LOG "REDISCONFIG_LOG"

namespace ls
{
    using namespace json;
    namespace redis
    {
		RedisConfig::RedisConfig()
		{
			char *configPath = getenv("LS_REDIS_REDISCONFIG");
			if(configPath == NULL)
				configPath = (char *)"redis.json";
			Load(configPath);
            GET_STRING(root, "password", password);
			GET_STRING(root, "ip", ip);
			GET_INT(root, "port", port);
            GET_INT(root, "size", size);
            ls_log_tag(REDISCONFIG_LOG, "password: %s", password.c_str());
			ls_log_tag(REDISCONFIG_LOG, "ip: %s", ip.c_str());
			ls_log_tag(REDISCONFIG_LOG, "port: %d", port);
            ls_log_tag(REDISCONFIG_LOG, "size: %d", size);
		}
    }
}