//
// Created by shahar on 23/03/2021.
//

#include "AutoUpdated.h"

AutoUpdated::AutoUpdated(unsigned int updateInterval) : UpdateInterval(updateInterval), ShouldUpdate(true) {

}

void AutoUpdated::StartUpdating() {
    this->UpdateThread = thread(&AutoUpdated::Run, this);
}

void AutoUpdated::Run() {
    while(this->ShouldUpdate){
        m_sleep(this->UpdateInterval);
        this->Update();
    }
}

void AutoUpdated::StopUpdating() {
    this->ShouldUpdate = false;
    this->UpdateThread.join();
}
