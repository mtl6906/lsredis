#ifndef LS_REDIS_CONNECTIONPOOL_H
#define LS_REDIS_CONNECTIONPOOL_H

#include "ls/redis/RedisConfig.h"
#include "ls/redis/Connection.h"
#include "queue"
#include "mutex"

namespace ls
{
    namespace redis
    {
        class ConnectionPool
        {
            RedisConfig &config;
            std::queue<Connection *> pool;
            std::mutex poolMutex;
            public:
                ConnectionPool(RedisConfig &config);
                ~ConnectionPool();
                int Put(Connection *conn);
                Connection *Get();
        };
    }
}

#endif