#include <iostream>
#include <string>
using namespace std;

class Transport {
protected:
    string name;
    double weight; 
    double fuel; 

public:
    Transport(string name, double weight, double fuel)
        : name(name), weight(weight), fuel(fuel) {}

    virtual ~Transport() {}

    virtual double calculCost(double distance, double fuelPrice) = 0;

    virtual void Print() {
        cout << "Название: " << name << "\n"
            << "Вес: " << weight << " кг\n"
            << "Расход топлива: " << fuel << " л/100 км\n";
    }
};

class Car : public Transport {
public:
    Car(string name, double weight, double fuel)
        : Transport(name, weight, fuel) {}

    double calculCost(double distance, double fuelPrice) override {
        return (distance / 100.0) * fuel * fuelPrice;
    }

    void Print() override {
        cout << "Тип: Автомобиль\n";
        Transport::Print();
    }
};

class Airplane : public Transport {
public:
    Airplane(string name, double weight, double fuel)
        : Transport(name, weight, fuel) {}

    double calculCost(double distance, double fuelPrice) override {
        return (distance / 100.0) * fuel * fuelPrice * 2.0;
    }

    void Print() override {
        cout << "Тип: Самолет\n";
        Transport::Print();
    }
};

class Ship : public Transport {
public:
    Ship(string name, double weight, double fuel)
        : Transport(name, weight, fuel) {}

    double calculCost(double distance, double fuelPrice) override {
        return (distance / 100.0) * fuel * fuelPrice * 0.8;
    }

    void Print() override {
        cout << "Тип: Судно\n";
        Transport::Print();
    }
};

class Truck : public Transport {
public:
    Truck(string name, double weight, double fuel)
        : Transport(name, weight, fuel) {}

    double calculCost(double distance, double fuelPrice) override {
        return (distance / 100.0) * fuel * fuelPrice * 1.5;
    }
    void Print() override {
        cout << "Тип: Грузовик\n";
        Transport::Print();
    }
};

int main() {
    setlocale(0, "ru");
    Transport* transport[] = {
        new Car("Легковая машина", 1400, 8.5),
        new Airplane("Пассажирский самолет", 40000, 250),
        new Ship("Грузовое судно", 100000, 50),
        new Truck("Грузовик", 8000, 30)
    };
    double distance = 1000; 
    double fuelPrice = 1.5; 
    for (int i = 0; i < 4; i++) {
        transport[i]->Print();
        cout << "Стоимость доставки на " << distance << " км: "
            << transport[i]->calculCost(distance, fuelPrice) << endl<<endl;
        delete transport[i]; 
    }
    return 0;
}
