#ifndef LS_REDIS_CONFIG_H
#define LS_REDIS_CONFIG_H

#include "ls/Config.h"

namespace ls
{
    namespace redis
    {
        class Config : public ls::Config
        {
            public:
                Config();
		std::string getConfigPath() override;
		void init() override;
                std::string password;
                std::string ip;
                int port;
                int size;
        };
    }
}

#endif
