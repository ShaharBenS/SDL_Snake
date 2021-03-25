//
// Created by shahar on 23/03/2021.
//

#ifndef TRYINGOUTSDL_AUTOUPDATED_H
#define TRYINGOUTSDL_AUTOUPDATED_H

#include <thread>
#include <unistd.h>

using namespace std;

class AutoUpdated{
public:
    AutoUpdated(unsigned int updateInterval);
    void StartUpdating();
    void StopUpdating();
    virtual void Update()=0;
private:
    unsigned int UpdateInterval;
    thread UpdateThread;
    bool ShouldUpdate;
    void Run();
};

#endif //TRYINGOUTSDL_AUTOUPDATED_H
