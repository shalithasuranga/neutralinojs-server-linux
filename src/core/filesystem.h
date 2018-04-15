#include <map>
#ifndef FILESYSTEM_H
#define FILESYSTEM_H

namespace filesystem {
    string createFile(string jso);

    typedef string (*pfunc)(string);

    map <string, pfunc> funcmap = {
        {"filesystem.createFile", filesystem::createFile}
    };

    //void init() {
      //  funcmap["filesystem.createFile"] = filesystem::createFile;
    //}


}

#endif