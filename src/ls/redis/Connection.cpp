#include "ls/redis/Connection.h"
#include "iostream"

using namespace std;

namespace ls
{
    namespace redis
    {
        Connection::Connection(const string &ip, int port) : rc(redisConnect(ip.c_str(), port))
        {
        }
        redisReply* Connection::Command(const string &cmd)
        {  
            return (redisReply *)redisCommand(rc, cmd.c_str());
        }
        Connection::~Connection()
        {
            redisFree(rc);
        }
    }
}