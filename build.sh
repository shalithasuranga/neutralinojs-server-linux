echo "Neutralino is being built.."
if [ -e bin/neutranino.out ]; then 
    rm bin/neutralino.out
fi

g++ -std=c++11  src/Buffer.cpp src/EventLoop.cpp src/EventLoopThreadPool.cpp src/Parser.cpp src/Socket.cpp src/Epoll.cpp src/EventLoopThread.cpp src/Handler.cpp src/main.cpp src/Thread.cpp -pthread -o bin/neutralino -w