#pragma once
#include <string>
#include <vector>

class BaseTask;


class Project {

public:
   std::string _name;
   std::vector<BaseTask*> rootTasks;
};