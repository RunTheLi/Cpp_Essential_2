#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class FarmAnimal{
public:
  FarmAnimal(double water_consumption);
  double getWaterConsumption();
  // ...
private:
  double water_consumption;
};

FarmAnimal::FarmAnimal(double water_consumption) {
  this->water_consumption = water_consumption;
}

double FarmAnimal::getWaterConsumption() {
  return water_consumption;
}

class ConsumptionAccumulator
{
public:
  ConsumptionAccumulator();
  double getTotalConsumption();
  void addConsumption(FarmAnimal &animal);
private:
  double total_consumption;
};

ConsumptionAccumulator::ConsumptionAccumulator() :
  total_consumption(0)
{
}

double ConsumptionAccumulator::getTotalConsumption()
{
  return total_consumption;
}

void ConsumptionAccumulator::addConsumption(FarmAnimal &animal)
{
  total_consumption += animal.getWaterConsumption();
}

class Sheep : public FarmAnimal{
    public:
        Sheep(double weight) : FarmAnimal((weight / 10.0) * 1.1) {}
};

class Horse : public FarmAnimal{
    public:
        Horse(double weight) : FarmAnimal((weight / 100.0) * 6.8) {}
};

class Cow : public FarmAnimal{
    public:
        Cow(double weight) : FarmAnimal((weight / 100.0) * 8.6) {}
};


int main()
{
  ConsumptionAccumulator accumulator;
    string type;
    double weight;

    while (true) {
        string line;
        getline(cin, line);
        if(line.empty()) break;
        stringstream ss(line);
        ss >> type >> weight;

        if (type == "sheep") {
            Sheep s(weight);
            accumulator.addConsumption(s);
        } else if (type == "horse") {
            Horse h(weight);
            accumulator.addConsumption(h);
        } else if (type == "cow") {
            Cow c(weight);
            accumulator.addConsumption(c);
        }
    }
  // read user input
  // create appropriate objects and add them to the accumulator

  cout << accumulator.getTotalConsumption() << endl;

  return 0;
}