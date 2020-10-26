/**
 * @ Author: tekky
 * @ Create Time: 2020-10-26 10:50:14
 * @ Modified by: tekky
 * @ Modified time: 2020-10-26 10:59:16
 */

#include <map>
#include <string>
#include <iostream>

int main(int argc, char const *argv[])
{
    std::map<std::string, std::string> dict;
    std::string temp;
    while (std::getline(std::cin, temp)) {
        if (temp.size() == 0) {
            break;
        }
        int pos = temp.find(' ');
        dict[temp.substr(pos + 1)] = temp.substr(0, pos);
    }

    while (std::cin >> temp) {
        if (dict.find(temp) == dict.end()) {
            std::cout << "eh\n";
        } else {
            std::cout << dict[temp] << "\n";
        }
    }
    return 0;
}


