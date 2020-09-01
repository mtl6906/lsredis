#ifndef LS_REDISAPI_TOOL_H
#define LS_REDISAPI_TOOL_H

#include "sw/redis++/redis.h"

namespace ls
{
	namespace redis
	{
		class Tool
		{
			static Tool *instance;
			sw::redis::Redis *redis;
			Tool();
			public:
				~Tool();
				sw::redis::Redis *GetRedis();
				static Tool *GetInstance();
		};
	}
}

#endif
