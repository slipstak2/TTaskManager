#pragma once

#include <memory>
#include <vector>
#include "person.h"
#include "common.h"
#include "project.h"
#include "label.h"


class BaseTask
{
public:
   virtual ~BaseTask();

private:
   std::string    _name;

   BaseTask *     _subTasks[16];
   BaseTask *     _parentTask;

   TaskLabel*     _labels[16];

};


class TimeTask : public BaseTask
{
public:
   TimeTask() {}
   TimeTask(const TimeTask& otherTimeTask){}
   ~TimeTask(){}

private:
   time_t _timeBegin;
   time_t _timeEnd;
};


class Meeting : public TimeTask
{
public:
   Person* _participants[16];
};

