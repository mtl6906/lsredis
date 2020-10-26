#ifndef LS_REDIS_REDISCONFIG_H
#define LS_REDIS_REDISCONFIG_H

#include "ls/Config.h"

namespace ls
{
    namespace redis
    {
        class RedisConfig : public Config
        {
            public:
                std::string password;
                std::string ip;
                int port;
                int size;
                RedisConfig();
        };
    }
}

#endif