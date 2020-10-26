#include "ls/redis/ConnectionPool.h"
#include "ls/redis/Context.h"

using namespace std;

namespace ls
{
    namespace redis
    {
        ConnectionPool::ConnectionPool(RedisConfig &config) : config(config)
        {
            int size = config.size;
            for(int i=0;i<size;++i)
            {
                auto conn = new Connection(config.ip.c_str(), config.port);
                auto reply = conn -> Command(string("auth ") + config.password);
                freeReplyObject(reply);
                pool.push(conn);
            }
        }
        ConnectionPool::~ConnectionPool()
        {
            while(!pool.empty())
            {
                delete pool.front();
                pool.pop();
            }
        }
        Connection *ConnectionPool::Get()
        {
            lock_guard<mutex> poolLock(poolMutex);
            if(pool.empty())
                return nullptr;
            auto conn = pool.front();
            pool.pop();
            return conn;
        }
        int ConnectionPool::Put(Connection *conn)
        {
            lock_guard<mutex> poolLock(poolMutex);
            if(nullptr == conn)
                return -1;
            pool.push(conn);
            return 0;
        }
    }
}