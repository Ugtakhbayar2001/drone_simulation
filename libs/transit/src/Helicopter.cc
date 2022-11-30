#define _USE_MATH_DEFINES
#include "Helicopter.h"

#include <cmath>
#include <limits>

#include "BeelineStrategy.h"

Helicopter::Helicopter(JsonObject& obj) : details(obj) {
  JsonArray pos(obj["position"]);
  position = {pos[0], pos[1], pos[2]};

  JsonArray dir(obj["direction"]);
  direction = {dir[0], dir[1], dir[2]};

  speed = obj["speed"];
  available = true;
}

Helicopter::~Helicopter() {
  // Delete dynamically allocated variables
}

void Helicopter::setRandomDestination() {
  x = ((float(rand()) / float(RAND_MAX)) * (1500 - (-1400))) + -1400;
  y = ((float(rand()) / float(RAND_MAX)) * (1000 - 240)) + 240;
  z = ((float(rand()) / float(RAND_MAX)) * (800 - (-800))) + -800;
  destination = {x, y, z};
  std::cout << destination[0] << std::endl;
  std::cout << destination[1] << std::endl;
  std::cout << destination[2] << std::endl;
}

void Helicopter::Update(double dt, std::vector<IEntity*> scheduler) {
  if (strategy != NULL && strategy->IsCompleted()) {
    setRandomDestination();
    strategy = new BeelineStrategy(position, destination);
  } else if (strategy != NULL && strategy->IsCompleted() == false) {
    strategy->Move(this, dt);
  } else {
    setRandomDestination();
    strategy = new BeelineStrategy(position, destination);
  }
}
