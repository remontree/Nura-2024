#include"task/carnard.h"
#include"task/updatesensor.h"
#include"task/parachute.h"
#include"task/recieve.h"
#include"task/transmit.h"

Recieve reciver;
Transmit transmitter;
UpdateSensor sensorupdater;
Parachute parachute;
Carnard carnard;

bool parachute_flag;

void setup(){
    parachute_flag = false;
}

void loop(){
    reciver.run();
    sensorupdater.run();
    carnard.run();
    if(parachute_flag==true){
        parachute.run();
    }
    transmitter.run();
    return;
}