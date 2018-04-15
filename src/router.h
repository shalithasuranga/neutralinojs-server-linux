#include <string>

using namespace std;

namespace routes {

    string getFile(string file);

    string getClientJs();

    pair<string, string> handle(string path);
}