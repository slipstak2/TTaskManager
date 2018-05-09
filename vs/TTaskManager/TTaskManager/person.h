#pragma once
#include <string>
#include <vector>


class PersonInfo {
   std::string name;
   std::string sername;
   bool sex;
};

class AddPersonInfo {
   std::vector<std::string> phones;
   std::vector<std::string> emails;
};


class Person {
   PersonInfo    _info;
   AddPersonInfo _add_info;
};
