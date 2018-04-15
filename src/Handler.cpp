/*
 * Author: Broglie 
 * E-mail: yibo141@outlook.com
 */

#include "Handler.h"

using namespace std;

Handler::Handler(const int connfd)
      :_connfd(connfd)
{
    _isClosed = false;
}

Handler::~Handler()
{
    if(!_isClosed)
        close(_connfd);
}

void Handler::handle()
{
    if(!receiveRequest())
    {
        close(_connfd);
        _isClosed = true;
        return;
    }
    string content =  "hey fuck";
    std::string msg = "HTTP/1.1 200 OK\r\nContent-Length: " + std::to_string(content.size()) +"\r\nConnection: close\r\n\r\n" + content;
    _outputBuffer.append(msg.c_str(), msg.size());
    _outputBuffer.sendFd(_connfd);
    close(_connfd);
    _isClosed = true;
}

bool Handler::receiveRequest()
{ 
    if(_inputBuffer.readFd(_connfd) == 0)
        return false;
    std::string request = _inputBuffer.readAllAsString();
    std::cout << "---------------------------Request---------------------------" << std::endl;
    std::cout << request << std::endl;
    std::cout << "-------------------------------------------------------------" << std::endl;
    Parser p(request);
    _request = p.getParseResult();
    return true;
}

void Handler::sendErrorMsg()
{
    std::string msg = "HTTP/1.1 200 OK\r\nContent-Length: 13\r\nConnection: close\r\n\r\nHello, world!";
    _outputBuffer.append(msg.c_str(), msg.size());
    _outputBuffer.sendFd(_connfd);
    close(_connfd);
    _isClosed = true;
}

void Handler::parseURI()
{

}

void Handler::getFileType()
{

}