#pragma once
#include <string>
#include <vector>


enum class Sex {
   Female,
   Male = 1,
   Unknown
};


class PersonInfo {
public:
   PersonInfo(
      const char* name,
      const char* sername,
      Sex sex
   )
      : _name(name)
      , _sername(sername)
      , _sex(sex)
   {}

private:
   std::string _name;
   std::string _sername;
   Sex _sex;
};


class AddPersonInfo {
   void addPhone(const char* phone) { _phones.push_back(phone); }
   void addEmail(const char* email) { _emails.push_back(email); }
private:
   std::vector<std::string> _phones;
   std::vector<std::string> _emails;
};


class Person {
public:
   Person(
      const char* name,
      const char* sername,
      Sex sex = Sex::Unknown
   )
      : _info(name, sername, sex)
   {}

private:
   PersonInfo    _info;
   AddPersonInfo _add_info;
};
