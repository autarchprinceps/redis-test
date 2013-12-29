/*
 * =====================================================================================
 *
 *       Filename:  test.c
 *
 *    Description:  
 *
 *        Created:  29.12.2013 17:35:24
 *
 *         Author:  autarch princeps (), autarch@outlook.com
 *
 * =====================================================================================
 */
#include <hiredis/hiredis.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char** argv) {
	redisContext* c = redisConnect(argv[1], atoi(argv[2]));
	if (c == NULL || c->err) {
		if (c) {
		    printf("Connection error: %s\n", c->errstr);
		    redisFree(c);
		} else {
			printf("Connection error: can't allocate redis context\n");
		}
		exit(1);
	}
	redisReply* reply;
	reply = redisCommand(c, "HGETALL %s", "test");
	printf("test: %s\n", reply->str);
	freeReplyObject(reply);
	reply = redisCommand(c, "GET hello");
	printf("hello %s\n", reply->str);
	freeReplyObject(reply);
	reply = redisCommand(c, "GET hallo");
	printf("hallo %s\n", reply->str);
	freeReplyObject(reply);
	redisFree(c);
	printf("Unix Socket:\n");
	c = redisConnectUnix("/var/run/redis/redis.sock");
	if (c == NULL || c->err) {
		if (c) {
		    printf("Connection error: %s\n", c->errstr);
		    redisFree(c);
		} else {
			printf("Connection error: can't allocate redis context\n");
		}
		exit(1);
	}
	reply = redisCommand(c, "HGETALL %s", "test");
	printf("test: %s\n", reply->str);
	freeReplyObject(reply);
	reply = redisCommand(c, "GET hello");
	printf("hello %s\n", reply->str);
	freeReplyObject(reply);
	reply = redisCommand(c, "GET hallo");
	printf("hallo %s\n", reply->str);
	freeReplyObject(reply);
	redisFree(c);
	return 0;
}
