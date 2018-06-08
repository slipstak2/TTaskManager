#include <iostream>
#include <assert.h>
#include "Task.h"

using namespace std;

void createTaskLabels() {
   auto mainLabel = TaskLabel::create("Main", 0xFFF0F8FF);
   auto smartLabel = TaskLabel::create("smart", 0xFFFAEBD7);

   auto tmpLabel = TaskLabel::get("smart");
   assert(smartLabel == tmpLabel);
}
int main() {
   createTaskLabels();


   auto pi = PersonInfo("Vasia", "Petrov", Sex::Male);
   Person p("Petr", "Mitrichev");

   Task task1("New task");
   Task task2("Yet another task", &task1);

   task1.addLabel(TaskLabel::get("smart"));

   TaskLabel::free();
   return 0;
}