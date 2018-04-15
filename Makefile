neutralino: main.o Socket.o EventLoopThreadPool.o EventLoopThread.o Thread.o EventLoop.o Parser.o Handler.o Epoll.o Buffer.o
	g++ -std=c++11 -pthread -o bin/neutralino main.o Socket.o EventLoopThreadPool.o EventLoopThread.o Thread.o EventLoop.o Parser.o Handler.o Epoll.o Buffer.o

main.o: src/main.cpp src/Socket.h src/EventLoopThreadPool.h src/EventLoopThread.h src/EventLoop.h
	g++ -std=c++11 -c -pthread src/main.cpp src/EventLoopThreadPool.cpp src/EventLoopThread.cpp src/EventLoop.cpp

Socket.o: src/Socket.cpp src/Socket.h 
	g++ -std=c++11 -c -pthread src/Socket.cpp

EventLoopThreadPool.o: src/EventLoopThreadPool.cpp src/EventLoopThread.h 
	g++ -std=c++11 -c -pthread src/EventLoopThreadPool.cpp src/EventLoopThread.cpp

EventLoopThread.o: src/EventLoopThread.cpp src/EventLoopThread.h src/EventLoop.h src/Thread.h 
	g++ -std=c++11 -c -pthread src/EventLoopThread.cpp src/EventLoop.cpp src/Thread.cpp

Thread.o: src/Thread.cpp src/Thread.h 
	g++ -std=c++11 -c -pthread src/Thread.cpp

EventLoop.o: src/EventLoop.cpp src/EventLoop.h src/Epoll.h 
	g++ -std=c++11 -c src/EventLoop.cpp src/Epoll.cpp

Parser.o: src/Parser.cpp src/Parser.h 
	g++ -std=c++11 -c src/Parser.cpp

Handler.o: src/Handler.cpp src/Handler.h src/Parser.h 
	g++ -std=c++11 -c src/Handler.cpp src/Parser.cpp

Epoll.o: src/Handler.cpp src/Handler.h src/Parser.h src/Epoll.h 
	g++ -std=c++11 -c src/Epoll.cpp src/Handler.cpp src/Parser.cpp

Buffer.o: src/Buffer.cpp src/Buffer.h 
	g++ -std=c++11 -c src/Buffer.cpp

clean:
	rm *.o bin/neutralino
