mkdir /usr/include/ls
mkdir /usr/include/ls/redis

cp build/liblsredis.so /usr/lib
cp src/ls/redis/*.h /usr/include/ls/redis
