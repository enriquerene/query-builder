#include "./base.h"

std::string QueryBuilder::Utils::joinStringArray(size_t arrSize, std::string const *strArr, std::string strJoinner) {
    std::string str = "";
    for (size_t i = 0; i < arrSize; i++) {
        str += strArr[i];
        if (i < arrSize - 1) {
            str += strJoinner;
        }
    }
    return str;
}
