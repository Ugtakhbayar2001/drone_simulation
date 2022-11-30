#define _USE_MATH_DEFINES
#include "Car.h"

#include <cmath>
#include <limits>

#include "AstarStrategy.h"

Car::Car(JsonObject& obj) : details(obj) {
  JsonArray pos(obj["position"]);
  position = {pos[0], pos[1], pos[2]};

  JsonArray dir(obj["direction"]);
  direction = {dir[0], dir[1], dir[2]};

  speed = obj["speed"];
  available = true;
}

Car::~Car() {
  // Delete Dynamically allocated variables
}

void Car::setRandomDestination() {
  x = ((float(rand()) / float(RAND_MAX)) * (1500 - (-1400))) + -1400;
  y = ((float(rand()) / float(RAND_MAX)) * (100000 - 240)) + 240;
  z = ((float(rand()) / float(RAND_MAX)) * (800 - (-800))) + -800;
  destination = {x, y, z};
}

void Car::Update(double dt, std::vector<IEntity*> scheduler) {
  if (strategy != NULL && strategy->IsCompleted()) {
    setRandomDestination();
    strategy = new AstarStrategy(position, destination, graph);
  } else if (strategy != NULL && strategy->IsCompleted() == false) {
    strategy->Move(this, dt);
  } else {
    setRandomDestination();
    strategy = new AstarStrategy(position, destination, graph);
    std::cout << "set destination" << std::endl;
  }
}
