#include "ls/redis/Context.h"
#include "memory"
#include "functional"
#include "iostream"

using namespace std;

namespace ls
{
    namespace redis
    {
        Context::Context(ConnectionPool &pool, const string &cmd) : pool(pool), connection(pool.Get()), rp(connection -> Command(cmd), freeReplyObject)
        {
        }
        Context::~Context()
        {
            pool.Put(connection);
        }
        pair<int, string> Context::GetStringReply()
        {
            if(rp -> type != REDIS_REPLY_STRING)
                return pair<int, string>(-1, "");
            return pair<int, string>(0, string(rp -> str, rp ->len));
        }
        pair<int, int> Context::GetIntReply()
        {
            if(rp -> type != REDIS_REPLY_INTEGER)
                return {-1, rp -> integer};
            return {0, rp -> integer};
        }
    }
}