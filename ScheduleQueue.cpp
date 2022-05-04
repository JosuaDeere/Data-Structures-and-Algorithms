// ScheduleQueue.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <queue>
#include <string>
using namespace std;
void prinTasks(queue<string> in_qTasks)
{
    queue<string> qTemp = in_qTasks;
    while (!qTemp.empty())
    {
        cout <<"Task is: "+ qTemp.front()<<endl;
        qTemp.pop();
    }
}
int main()
{
    queue<string> qTasks;
    string szIsFinished="";
    string szTaskToAdd = "";
    cout << "Please give me the tasks in order to be executed..." << endl;
    cout << "type end to finish typing your tasks..." << endl;

    while (szIsFinished != "end")
    {
        getline(cin, szTaskToAdd);
        
        if(szIsFinished != "end")
            qTasks.push(szTaskToAdd);
        szIsFinished = szTaskToAdd;
    }
    prinTasks(qTasks);

    cin.get();
}

