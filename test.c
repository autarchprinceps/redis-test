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
	redisReply* reply;
	reply = redisCommand(c, "HGETALL %s", "test");
	printf("test: %s\n", reply->str);
	freeReplyObject(reply);
	reply = redisCommand(c, "GET hello");
	printf("Hello %s\n", reply->str);
	freeReplyObject(reply);
	reply = redisCommand(c, "GET hallo");
	printf("Hallo %s\n", reply->str);
	freeReplyObject(reply);
	redisFree(c);
	return 0;
}
