#include "ls/DefaultLogger.h"
#include "ls/redis/API.h"

using namespace std;

namespace ls
{
	namespace redis
	{
		API::API()
		{
           		int size = config.size;
         		for(int i=0;i<size;++i)
			{
				auto conn = new Connection(config.ip.c_str(), config.port);
				auto reply = conn -> command(string("auth ") + config.password);
				freeReplyObject(reply);
				pool.put(conn);
			}
			LOGGER(ls::INFO) << "tool create" << ls::endl;
		}
		
		unique_ptr<Context> API::getContext(const string &cmd)
		{
			return unique_ptr<Context>(new Context(pool, cmd));
		}
		
		unique_ptr<Context> API::getContext(initializer_list<string> il)
		{
			int len = il.size() + 1;
			for(auto it : il)
				len += it.size();
			string cmd;
			cmd.reserve(len);
			for(auto it : il)
			{
				cmd.append(it);
				cmd.append(" ");
			}
			cmd.pop_back();
			return getContext(cmd);
		}

		bool API::exists(const string &key)
		{
			int ec;
			auto context = getContext({"exists", key});
			context -> getInt(ec);
			return ec != Exception::LS_EEXIST;
		}

		int API::getInt(int &ec, const string &key)
		{
			auto context = getContext({"get", key});
			auto value = context -> getInt(ec);
			return value;
		}

		string API::getString(int &ec, const string &key)
		{
			auto context = getContext({"get", key});
			auto value = context -> getString(ec);
			return value;
		}

		void API::set(const string &key, const string &value)
		{
			auto context = getContext({"set", key, value});
		}

		API api;
	}
}
