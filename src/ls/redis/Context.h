#ifndef LS_REDIS_CONTEXT_H
#define LS_REDIS_CONTEXT_H

#include "ls/redis/ConnectionPool.h"

namespace ls
{
    namespace redis
    {
        class Context
        {
            ConnectionPool &pool;
            Connection *connection;
            std::unique_ptr<redisReply, std::function<void(redisReply *)>> rp;
            public:
                Context(ConnectionPool &pool, const std::string &cmd);
                ~Context();
                std::pair<int, std::string> GetStringReply();
                std::pair<int, int> GetIntReply();
        };
    }
}

#endif