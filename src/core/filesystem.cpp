#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "../../lib/json/json.hpp"

using namespace std;
using json = nlohmann::json;

namespace filesystem {



    string createDirectory(string jso) {
        json input;
        json output;
        try {
            input = json::parse(jso);
        }
        catch(exception e){
            output["error"] = "JSON parse error is occurred!";
            return output.dump();
        }
        string filename = input["name"];
        if(mkdir(filename.c_str(), 0700) == 0){
            output["success"] = filename + " directory was created!";
            return output.dump();
        }
        else{
            output["error"] = "Cannot create " + filename;
            return output.dump();
        }
       
        
    }
}
