#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void scene1(double emergencyScore)
{
    string emergencyLevel;

    if (emergencyScore >= 80)
    {
        emergencyLevel = "CRITICAL";
    }
    else if (emergencyScore >= 60)
    {
        emergencyLevel = "HIGH";
    }
    else if (emergencyScore >= 40)
    {
        emergencyLevel = "MEDIUM";
    }
    else
    {
        emergencyLevel = "LOW";
    }

    cout << "[Scene 1] Emergency: " << emergencyLevel
         << " (score = " << fixed << setprecision(1)
         << emergencyScore << ")\n";
}

void support(int dinoCount, int rexAvailable,
             int lavaNearby, int marshallReady,
             const string & mainPup)
{
    string result = "";

    if (lavaNearby == 1 && marshallReady == 1
        && mainPup != "Marshall")
    {
        result = "Marshall";
    }

    if (dinoCount >= 10 && rexAvailable == 1
        && mainPup != "Rex")
    {
        if (!result.empty())
        {
            result += ", ";
        }

        result += "Rex";
    }

    if (!result.empty())
    {
        cout << "Support: " << result << '\n';
    }
}

void scene2(char terrainType, int dinoCount,
            int rexAvailable, int lavaNearby,
            int marshallReady)
{
    string mainPup;

    if (terrainType == 'F')
    {
        mainPup = "Chase";
    }
    else if (terrainType == 'M')
    {
        mainPup = "Rubble";
    }
    else if (terrainType == 'W')
    {
        mainPup = "Zuma";
    }
    else if (terrainType == 'V')
    {
        if (marshallReady == 1)
        {
            mainPup = "Marshall";
        }
        else
        {
            mainPup = "Skye";
        }
    }
    else
    {
        cout << "Invalid terrain\n";
        return;
    }

    cout << "[Scene 2] Main Pup: " << mainPup << '\n';

    support(dinoCount, rexAvailable,
            lavaNearby, marshallReady, mainPup);
}
void scene3(int rexAvailable, int marshallReady, 
    int lavaNearby, int roadBlocked, char terrainType, 
    double rescuePower, int vehicleEnergy, int rescueEquipment, int dinoCount)

{
    rescuePower = vehicleEnergy * 0.4 + rescueEquipment * 0.4;
    if (rexAvailable==1 && dinoCount >= 10)
        {
            rescuePower += 10;
        }
    if (marshallReady==1 && lavaNearby==1)
        {
            rescuePower += 10;
        }
    if (roadBlocked==1)
    {
        rescuePower -=15;
    }
    if (terrainType == 'M')
    {
        rescuePower -= 5;
    }
    if (terrainType == 'V')
    {
        rescuePower -= 10;
    }
    string status;
    if (rescuePower >= 70)
    {
        status = "STRONG";
    }
    else if (rescuePower >= 50 && rescuePower < 70)
    {
        status = "READY";
    }
    else if (rescuePower >= 30 && rescuePower < 50)
    {
        status = "RISKY";
    }
    else
    {
        status = " NOT READY";
    }
    cout << "[Scene 3] Rescue Power: " << fixed << setprecision(1) << rescuePower << " - " << status << '\n';
}
int main()
{
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

    // Scene 1
    scene1(emergencyScore);

    // Scene 2
    scene2(terrainType, dinoCount, rexAvailable,
           lavaNearby, marshallReady);
    // Scene 3
    scene3(rexAvailable, marshallReady, lavaNearby, roadBlocked, terrainType, 0.0, vehicleEnergy, rescueEquipment, dinoCount);
    return 0;
}