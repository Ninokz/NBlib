#pragma once
#include "BaseServer.h"
#include "BaseClient.h"

#include "stealThreadPool.h"
#include "parrallenThreadPool.h"
#include "simplethreadpool.h"

void TestServer()
{
	Nano::Communication::BaseServer server(12345);
	server.start();
}

void TestClient()
{
	Nano::Communication::BaseClient client;
	client.connect("127.0.0.1", 12345);
	client.send("Hello", 5);
	client.disconnect();
}

void TestStealThreadPool()
{
}