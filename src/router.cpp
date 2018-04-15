#include <iostream>
#include <string>
#include <fstream>
#include <unistd.h>
#include "functions.h"

using namespace std;

namespace routes {

    string getClientJs() {
        return "class Neutralino{static createFile(){console.log('done');}}";

    }
    
    string getFile(string file) {
        ifstream t;
        t.open(file);
        string buffer = "";
        string line;
        while(t){
        getline(t, line);
            buffer += line + "\r\n";
        }
        t.close();
        return buffer;
    }

    pair<string, string> handle(string path) {
        if(path == "/"){
            char cwd[1024];
            getcwd(cwd, sizeof(cwd));
            cout << std::string(cwd)  << endl;
            return make_pair(routes::getFile(std::string(cwd) + "/bin/app/index.html"), "text/html");
        }
        else if(path == "/neutralino.js"){
            return make_pair(routes::getClientJs(), "text/javascript");
        }
        return make_pair(path, "application/json");
    }


}