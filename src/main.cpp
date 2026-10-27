#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

string scene1(double emergencyScore) {
    if (emergencyScore >= 80) {
        return "CRITICAL";
    }
    else if (emergencyScore >= 60) {
        return "HIGH";
    }
    else if (emergencyScore >= 40) {
        return "MEDIUM";
    }
    else {
        return "LOW";
    }
}

int main() {
    int dinoCount, dangerLevel, vehicleEnergy;
    int roadBlocked, lavaNearby, rexAvailable;
    int marshallReady, rescueEquipment, specialRescueReady;
    double temperature, rescueDistance;
    char terrainType;

    cin >> dinoCount >> dangerLevel >> temperature
        >> terrainType >> rescueDistance >> vehicleEnergy
        >> roadBlocked >> lavaNearby >> rexAvailable
        >> marshallReady >> rescueEquipment >> specialRescueReady;

    double emergencyScore = dinoCount * 3
                          + dangerLevel * 5
                          + temperature * 0.2
                          + rescueDistance * 2;

    cout << "[Scene 1] Emergency: " << scene1(emergencyScore)
         << " (score = " << fixed << setprecision(1)
         << emergencyScore << ")" << endl;

    return 0;
}