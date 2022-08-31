#include "ls/redis/Config.h"
#include "ls/json/API.h"
#include "ls/DefaultLogger.h"

using namespace std;

namespace ls
{
    namespace redis
    {
		Config::Config()
		{
			load();
		}

		void Config::init()
		{
			json::api.get(root, "password", password);
			json::api.get(root, "ip", ip);
			json::api.get(root, "port", port);
			json::api.get(root, "size", size);
            		LOGGER(ls::INFO) << "password: " <<  password << ls::endl;
			LOGGER(ls::INFO) << "ip: " << ip << ls::endl;
			LOGGER(ls::INFO) << "port: " <<  port << ls::endl;
            		LOGGER(ls::INFO) << "size: " << size << ls::endl;
		}

		string Config::getConfigPath()
		{
			char *configPath = getenv("LS_REDIS_CONFIG");
			if(configPath == NULL)
				configPath = (char *)"redis.json";
			return configPath;
		}
    }
}
