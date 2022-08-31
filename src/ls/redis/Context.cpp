#include "ls/redis/Context.h"
#include "ls/Exception.h"
#include "memory"
#include "functional"
#include "iostream"

using namespace std;

namespace ls
{
	namespace redis
	{
		Context::Context(Pool<Connection> &pool, const string &cmd) : pool(pool), connection(pool.get()), rp(connection -> command(cmd), freeReplyObject)
		{
		}
		
		Context::~Context()
		{
			pool.put(connection);
		}

		string Context::getString(int &ec)
		{
			ec = Exception::LS_OK;
			if(rp -> type == REDIS_REPLY_ERROR)
			{
				ec = Exception::LS_EFORMAT;
				return "";
			}
			if(rp -> type == REDIS_REPLY_NIL)
			{
				ec = Exception::LS_EEXIST;
				return "";
			}
			if(rp -> type != REDIS_REPLY_STRING)
			{
				ec = Exception::LS_ETYPE;
				return "";
			}
			return string(rp -> str, rp ->len);
		}
		
		int Context::getInt(int &ec)
		{
			ec = Exception::LS_OK;
			if(rp -> type == REDIS_REPLY_ERROR)
			{
				ec = Exception::LS_EFORMAT;
				return -1;
			}
			if(rp -> type == REDIS_REPLY_NIL)
			{
				ec = Exception::LS_EEXIST;
				return -1;
			}
			if(rp -> type != REDIS_REPLY_INTEGER)
			{
				ec = Exception::LS_ETYPE;
				return -1;
			}
			return rp -> integer;
		}
	}
}
