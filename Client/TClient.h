#pragma once
#include <iostream>
#include <winsock2.h>
#include "../Struct.h" 
using namespace std;

#pragma comment(lib,"ws2_32.lib") 
#pragma warning(disable:4996) 

class TClient{
private:
	string SERVER = "localhost";	//ip address of UDP server
	int PORT = 23446;				//the port on which to listen for incoming data
	WSADATA ws;
	sockaddr_in server;
	int client_socket;
public:
	void set_port(int port) {
		this->PORT = port;
	}
	void set_ipaddres(string ip) {
		this->SERVER = ip;
	}
	void Creat_Socket();
	void Send(TMessage mes);
	void Clean_n_Close();
};

