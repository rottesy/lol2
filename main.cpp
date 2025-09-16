// #include <iostream>
// #include <string>

// using namespace std;

// class Transport 
// {
// protected:
//     double speedPerH;
//     double costPerKm;
//     double capacity;
// public:
//     Transport(double speed, double cost, double cap) : speedPerH(speed),costPerKm(cost),capacity(cap) {}
//     virtual ~Transport() = default;
//     virtual double calculateTime(double distance) 
//     {
//         return distance / speedPerH;
//     }
//     [[nodiscard]] virtual double calculateCost(double distance,double weight) const
//     {
//         if (weight > capacity)
//         {
//             cout << "Attention: the load capacity has been exceeded!" << "\n";
//             return -1;
//         }
//         return distance * costPerKm * (weight / 100);
//     }
//     [[nodiscard]] virtual double calculatePassengerCost(double distance,int passengers) const
//     {
//         return distance * costPerKm * passengers;
//     }
//     virtual void displayInfo() const
//     {
//         cout << "Speed : " << speedPerH << " km/h" << "\n";
//         cout << "Cost per km : " << costPerKm << " BYN" << "\n";
//         cout << "Load capacity : " << capacity << "kg" << "\n";
//     }
//     [[nodiscard]] virtual const char* getType() const
//     {
//         return "Transport vehicle";
//     }
// };

// class Car : public Transport
// {
// private:
//     int maxPassengers;
// public:
//     Car(double speed,double cost,double cap,int maxPass) : Transport(speed,cost,cap),maxPassengers(maxPass) {}
    
//     [[nodiscard]] double calculateCost(double distance,double weight) const override
//     {
//         if (weight > capacity)
//         {
//             cout << "A car can't carry such a load!" << "\n";
//             return -1;
//         }
//         return distance * costPerKm * (1 + weight/500);
//     }
//     [[nodiscard]] double calculatePassengerCost(double distance,int passengers) const override
//     {
//         if (passengers > maxPassengers)
//         {
//             cout << "A car can't carry that many passengers." << "\n";
//             return -1;
//         }
//         return distance * costPerKm * passengers;
//     }
//     void displayInfo() const override
//     {
//         cout << "Type - Car" << "\n";
//         Transport :: displayInfo();
//         cout << "Max number of passengers : " << maxPassengers << "\n";
//         cout << "===" << "\n";
//     }

//     [[nodiscard]] const char* getType() const override
//     {
//         return "Car";
//     }
// };

// class Bicycle : public Transport
// {
// public:
//     Bicycle(double speed,double cost,double cap) : Transport(speed,cost,cap) {}
//     [[nodiscard]] double calculateCost(double distance,double weight) const override
//     {
//         if (weight > capacity)
//         {
//             cout << "A bicycle can't carry such a load!" << "\n";
//             return -1;
//         }
//         return distance * costPerKm * (1 + weight/50);
//     }
//     [[nodiscard]] double calculatePassengerCost(double distance,int passengers) const override
//     {
//         if (passengers > 1)
//         {
//             cout << "The bicycle can only carry 1 passenger!" << "\n";
//             return -1;
//         }
//         return distance * costPerKm;
//     }
//     void displayInfo() const override
//     {
//         cout << "Type - Bicycle" << "\n";
//         Transport::displayInfo();
//         cout << "===" << "\n";
//     }
//     [[nodiscard]] const char* getType() const override
//     {
//         return "Bicycle";
//     }
// };

// class Carriage : public Transport
// {
// private:
//     int numberOfHorses;
// public:
//     Carriage(double speed,double cost,double cap,int horses) : Transport(speed,cost,cap),numberOfHorses(horses) {}
//     [[nodiscard]] double calculateCost(double distance,double weight) const override
//     {
//         if (weight > capacity)
//         {
//             cout << "A carriage can't carry such a load!" << "\n";
//             return -1;
//         }
//         return distance * costPerKm * (weight / 100) * numberOfHorses;
//     }
//     [[nodiscard]] double calculatePassengerCost(double distance,int passengers) const override
//     {
//         return distance * costPerKm * passengers * 0.8;
//     }
//     void displayInfo() const override
//     {
//         cout << "Type - Carriage" << "\n";
//         Transport::displayInfo();
//         cout << "Number of horses : " << numberOfHorses << "\n";
//         cout << "===" << "\n";
//     }
//     [[nodiscard]] const char* getType() const override {
//         return "Carriage";
//     }    
// };

// void demonstrateTransport(Transport* transport, double distance, double weight, int passengers)
// {
//     cout << "=== Calculation for " << transport->getType() << " ===" << "\n";
//     transport->displayInfo();
//     double time = transport->calculateTime(distance);
//     cout << "Transportation time for a distance of " << distance << "km: " << time << " hours (" << time * 60 << " minutes)" << "\n";
//     double cost = transport->calculateCost(distance,weight);
//     if (cost >= 0)
//     {
//         cout << "Transportation cost for a weight of " << weight << "kg: " << cost << " BYN" << "\n";
//     }
//     double passengerCost = transport->calculatePassengerCost(distance,passengers);
//     if (passengerCost >= 0)
//     {
//         cout << "Transportation cost for " << passengers << " passengers : " << passengerCost << " BYN" << "\n";
//     }
//     cout << "=============================" << "\n" << "\n";
// }

// int main() {
    
//     Car car(60, 10, 500, 5);
//     Bicycle bicycle(15, 5, 50);
//     Carriage carriage(8, 7, 300, 2);
    
    
//     double distance = 100;    
//     double weight = 200;      
//     int passengers = 3;       
    
    
//     demonstrateTransport(&car, distance, weight, passengers);
//     demonstrateTransport(&bicycle, distance, weight, passengers);
//     demonstrateTransport(&carriage, distance, weight, passengers);
     
//     return 0;
// }
#include <iostream>

using namespace std;


const double CAR_WEIGHT_FACTOR = 500.0;
const double BICYCLE_WEIGHT_FACTOR = 50.0;
const double CARRIAGE_HORSE_FACTOR = 1.0;
const double CARRIAGE_PASSENGER_DISCOUNT = 0.8;
const double WEIGHT_DIVISOR = 100.0;

class Transport 
{
private:
    double speedPerH;
    double costPerKm;
    double capacity;
    
public:
    Transport(double speed, double cost, double cap) 
        : speedPerH(speed), costPerKm(cost), capacity(cap) {}
    
    virtual ~Transport() = default;

    double getSpeed() const { return speedPerH; }
    double getCostPerKm() const { return costPerKm; }
    double getCapacity() const { return capacity; }
    
    virtual double calculateTime(double distance) 
    {
        return distance / speedPerH;
    }
    
    [[nodiscard]] virtual double calculateCost(double distance, double weight) const
    {
        if (weight > capacity)
        {
            cout << "Attention: the load capacity has been exceeded!" << "\n";
            return -1;
        }
        return distance * costPerKm * (weight / WEIGHT_DIVISOR);
    }
    
    [[nodiscard]] virtual double calculatePassengerCost(double distance, int passengers) const
    {
        return distance * costPerKm * passengers;
    }
    
    virtual void displayInfo() const
    {
        cout << "Speed: " << speedPerH << " km/h" << "\n";
        cout << "Cost per km: " << costPerKm << " BYN" << "\n";
        cout << "Load capacity: " << capacity << " kg" << "\n";
    }
    
    [[nodiscard]] virtual const char* getType() const
    {
        return "Transport vehicle";
    }
    
   
    virtual void inputDetails() 
    {
        cout << "Enter speed (km/h): ";
        cin >> speedPerH;
        cout << "Enter cost per km (BYN): ";
        cin >> costPerKm;
        cout << "Enter load capacity (kg): ";
        cin >> capacity;
    }
};

class Car : public Transport
{
private:
    int maxPassengers;
    
public:

    using Transport::Transport;
    Car(double speed, double cost, double cap, int maxPass) 
        : Transport(speed, cost, cap), maxPassengers(maxPass) {}
    
    [[nodiscard]] double calculateCost(double distance, double weight) const override
    {
        if (weight > getCapacity())
        {
            cout << "A car can't carry such a load!" << "\n";
            return -1;
        }
        return distance * getCostPerKm() * (1 + weight / CAR_WEIGHT_FACTOR);
    }
    
    [[nodiscard]] double calculatePassengerCost(double distance, int passengers) const override
    {
        if (passengers > maxPassengers)
        {
            cout << "A car can't carry that many passengers." << "\n";
            return -1;
        }
        return distance * getCostPerKm() * passengers;
    }
    
    void displayInfo() const override
    {
        cout << "Type: Car" << "\n";
        Transport::displayInfo();
        cout << "Max number of passengers: " << maxPassengers << "\n";
        cout << "===" << "\n";
    }

    [[nodiscard]] const char* getType() const override
    {
        return "Car";
    }
    
    void inputDetails() override
    {
        Transport::inputDetails();
        cout << "Enter max number of passengers: ";
        cin >> maxPassengers;
    }
};

class Bicycle : public Transport
{
public:
    using Transport::Transport;
    Bicycle(double speed, double cost, double cap) 
        : Transport(speed, cost, cap) {}
    
    [[nodiscard]] double calculateCost(double distance, double weight) const override
    {
        if (weight > getCapacity())
        {
            cout << "A bicycle can't carry such a load!" << "\n";
            return -1;
        }
        return distance * getCostPerKm() * (1 + weight / BICYCLE_WEIGHT_FACTOR);
    }
    
    [[nodiscard]] double calculatePassengerCost(double distance, int passengers) const override
    {
        if (passengers > 1)
        {
            cout << "The bicycle can only carry 1 passenger!" << "\n";
            return -1;
        }
        return distance * getCostPerKm();
    }
    
    void displayInfo() const override
    {
        cout << "Type: Bicycle" << "\n";
        Transport::displayInfo();
        cout << "===" << "\n";
    }
    
    [[nodiscard]] const char* getType() const override
    {
        return "Bicycle";
    }
};

class Carriage : public Transport
{
private:
    int numberOfHorses;
    
public:
    using Transport::Transport;
    Carriage(double speed, double cost, double cap, int horses) 
        : Transport(speed, cost, cap), numberOfHorses(horses) {}
    
    [[nodiscard]] double calculateCost(double distance, double weight) const override
    {
        if (weight > getCapacity())
        {
            cout << "A carriage can't carry such a load!" << "\n";
            return -1;
        }
        return distance * getCostPerKm() * (weight / WEIGHT_DIVISOR) * numberOfHorses * CARRIAGE_HORSE_FACTOR;
    }
    
    [[nodiscard]] double calculatePassengerCost(double distance, int passengers) const override
    {
        return distance * getCostPerKm() * passengers * CARRIAGE_PASSENGER_DISCOUNT;
    }
    
    void displayInfo() const override
    {
        cout << "Type: Carriage" << "\n";
        Transport::displayInfo();
        cout << "Number of horses: " << numberOfHorses << "\n";
        cout << "===" << "\n";
    }
    
    [[nodiscard]] const char* getType() const override {
        return "Carriage";
    }
    
    void inputDetails() override
    {
        Transport::inputDetails();
        cout << "Enter number of horses: ";
        cin >> numberOfHorses;
    }
};


void inputTransportationDetails(double& distance, double& weight, int& passengers)
{
    cout << "=== Enter Transportation Details ===" << "\n";
    cout << "Enter distance (km): ";
    cin >> distance;
    cout << "Enter cargo weight (kg): ";
    cin >> weight;
    cout << "Enter number of passengers: ";
    cin >> passengers;
    cout << "\n";
}


Transport* createTransport()
{
    int choice;
    cout << "=== Select Transport Type ===" << "\n";
    cout << "1. Car" << "\n";
    cout << "2. Bicycle" << "\n";
    cout << "3. Carriage" << "\n";
    cout << "Enter your choice (1-3): ";
    cin >> choice;
    
    Transport* transport = nullptr;
    
    switch (choice)
    {
        case 1:
            transport = new Car(0, 0, 0, 0);
            break;
        case 2:
            transport = new Bicycle(0, 0, 0);
            break;
        case 3:
            transport = new Carriage(0, 0, 0, 0);
            break;
        default:
            cout << "Invalid choice! Using default transport." << "\n";
            transport = new Transport(0, 0, 0);
    }
    
    cout << "\nEnter details for " << transport->getType() << ":\n";
    transport->inputDetails();
    cout << "\n";
    
    return transport;
}

void demonstrateTransport(Transport* transport, double distance, double weight, int passengers)
{
    cout << "=== Calculation for " << transport->getType() << " ===" << "\n";
    transport->displayInfo();
    
    double time = transport->calculateTime(distance);
    cout << "Transportation time for " << distance << " km: " 
         << time << " hours (" << time * 60 << " minutes)" << "\n";
    
    if(double cost = transport->calculateCost(distance, weight);cost >= 0)
    {
        cout << "Transportation cost for " << weight << " kg: " << cost << " BYN" << "\n";
    }
    
    if(double passengerCost = transport->calculatePassengerCost(distance, passengers);passengerCost >= 0)
    {
        cout << "Transportation cost for " << passengers << " passengers: " << passengerCost << " BYN" << "\n";
    }
    
    cout << "=============================" << "\n\n";
}

int main() 
{
   
    double distance = 0;
    double weight = 0;
    int passengers = 0;
    inputTransportationDetails(distance, weight, passengers);
    
    
    Transport* transport = createTransport();
    
    
    demonstrateTransport(transport, distance, weight, passengers);
    
    
    delete transport;
    
    
    // cout << "=== Example with predefined vehicles ===" << "\n\n";
    
    // Car car(60, 10, 500, 5);
    // Bicycle bicycle(15, 5, 50);
    // Carriage carriage(8, 7, 300, 2);
    
    // demonstrateTransport(&car, distance, weight, passengers);
    // demonstrateTransport(&bicycle, distance, weight, passengers);
    // demonstrateTransport(&carriage, distance, weight, passengers);
    
    return 0;
}