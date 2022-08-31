#ifndef LS_REDIS_CONNECTION_H
#define LS_REDIS_CONNECTION_H

#include "hiredis/hiredis.h"
#include "string"
#include "memory"
#include "functional"

namespace ls
{
    namespace redis
    {
        class Connection
        {
            redisContext *rc;
            public:
                Connection() = default;
                Connection(const std::string &ip, int port);
                ~Connection();
                redisReply* command(const std::string &cmd);
        };
    }
}

#endif
