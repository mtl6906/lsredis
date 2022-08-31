#ifndef LS_REDIS_CONTEXT_H
#define LS_REDIS_CONTEXT_H

#include "ls/Pool.h"
#include "ls/redis/Connection.h"

namespace ls
{
    namespace redis
    {
        class Context
        {
            Pool<Connection> &pool;
            Connection *connection;
            std::unique_ptr<redisReply, std::function<void(redisReply *)>> rp;
            public:
                Context(Pool<Connection> &pool, const std::string &cmd);
                ~Context();
		std::string getString(int &ec);
                int getInt(int &ec);
        };
    }
}

#endif
