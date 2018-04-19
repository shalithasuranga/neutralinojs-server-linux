#include <map>
#ifndef FILESYSTEM_H
#define FILESYSTEM_H

namespace filesystem {
    string createDirectory(string jso);

    typedef string (*pfunc)(string);

    map <string, pfunc> funcmap = {
        {"filesystem.createDirectory", filesystem::createDirectory}
    };



}

#endif