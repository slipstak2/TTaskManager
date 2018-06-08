#pragma once

#include <memory>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include "person.h"

class TaskLabel {
public:
   static TaskLabel* create(const std::string& name, int color) {
      auto taskLabel = new TaskLabel(name, color);
      labels[name] = taskLabel;
      return taskLabel;
   }
   static TaskLabel* get(const std::string& name) {
      auto it = labels.find(name);
      return it == labels.end() ? nullptr : it->second;
   }
   static void free() {
      for (auto it : labels) {
         delete it.second;
      }
   }
   static std::map<std::string, TaskLabel*> labels;

public:
   const std::string& name() const { return _name; }
   ~TaskLabel() {
      printf("~TaskLabel\n");
   }

private:
   TaskLabel(const std::string &name, int color)
      : _name(name)
      , _color(color)
   {}

   std::string _name;
   int _color;
};

std::map<std::string, TaskLabel*> TaskLabel::labels;

class Task
{
public:
   Task(const char * name = "", Task* parentTask = nullptr)
      : _name(name)
      , _parentTask(parentTask)
   { }

   virtual ~Task() {
      for (auto _subTask : _subTasks) {
         delete _subTask;
      }
   }

   void addLabel(const TaskLabel* taskLabel) {
      _labels.push_back(taskLabel);
   }

   void addSubTask(Task* subTask) {
      _subTasks.push_back(subTask);
   }

   void changeParentTask(Task* parentTask) {
      _parentTask = parentTask;
   }

private:
   std::string    _name;
   std::vector<Task*> _subTasks;

   Task *         _parentTask;

   std::vector<const TaskLabel*> _labels;
};


class TimeTask : public Task
{
public:
   TimeTask(time_t begin, time_t end, const char* name = "", Task* parentTask = nullptr)
      : Task(name, parentTask)
      , _timeBegin(begin)
      , _timeEnd(end)
   {}

private:
   time_t _timeBegin;
   time_t _timeEnd;
};


class Meeting : public TimeTask
{
public:
   Meeting(time_t begin, time_t end, const char* name, Task* parentTask = nullptr)
      :TimeTask(begin, end, name, parentTask)
   {}
   void addParticipant(Person* person) {
      _participants.push_back(person);
   }
private:
   std::vector<Person *> _participants;
};
