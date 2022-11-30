#ifndef CSCI_3081W_F22_TEAM_001_14_LAB10_LIBS_TRANSIT_INCLUDE_HELICOPTER_H_
#define CSCI_3081W_F22_TEAM_001_14_LAB10_LIBS_TRANSIT_INCLUDE_HELICOPTER_H_

#include <vector>

#include "IEntity.h"
#include "IStrategy.h"
#include "math/vector3.h"

/**
 * @brief Helicopter interface which uses the Interface IEntity
 *
 **/
class Helicopter : public IEntity {
 public:
  /**
   * @brief Helicopters are created with a name.
   *
   * @param obj Helicopter object
   **/
  Helicopter(JsonObject& obj);

  /**
   * @brief Helicopter objects are destroyed.
   *
   **/
  ~Helicopter();

  /**
   * @brief Updates the (position) helicopter.
   *
   * @param dt Change in time
   * @param scheduler Nearest helicopter.
   **/
  void Update(double dt, std::vector<IEntity*> scheduler);

  /**
   * @brief Gets the position of the helicopter.
   *
   * @return Coordinates of the helicopter.
   **/
  Vector3 GetPosition() const { return position; }

  /**
   * @brief Gets the destination of the helicopter.
   *
   * @return Final destinatin of helicopter.
   **/
  Vector3 GetDestination() const { return destination; }

  /**
   * @brief Gets the details of the helicopter.
   *
   * @return Current details of the helicopter.
   **/
  JsonObject GetDetails() const { return details; }

  /**
   * @brief Gets the speed of the helicopter.
   *
   * @return Final speed of the helicopter.
   **/
  float GetSpeed() const { return speed; }

  /**
   * @brief Sets the position of the helicopter.
   *
   * @param pos_ New position of the helicopter.
   **/
  void SetPosition(Vector3 pos_) { position = pos_; }

  /**
   * @brief Sets the direction of the helicopter.
   *
   * @param dir_ New direction of the helicopter.
   **/
  void SetDirection(Vector3 dir_) { direction = dir_; }

  /**
   * @brief Sets the destination of the helicopter.
   *
   * @param des_ New destination of the helicopter.
   **/
  void SetDestination(Vector3 des_) { destination = des_; }

  /**
   * @brief Sets the random destination of the helicopter.
   *
   **/
  void setRandomDestination();

  /**
   * @brief Gets the direction of the helicopter.
   *
   * @return Current direction of the helicopter.
   **/
  Vector3 GetDirection() const { return direction; }

  /**
   * @brief Deletes the copy constructor of helicopter.
   *
   * @param helicopter helicopter that we don't want to be copied.
   **/
  Helicopter(const Helicopter& helicopter) = delete;

  /**
   * @brief Deletes the assignment operator of helicopter.
   *
   * @param helicopter helicopter that we don't want to be copied.
   **/
  Helicopter& operator=(const Helicopter& helicopter) = delete;

 private:
  JsonObject details;
  Vector3 position;
  Vector3 direction;
  Vector3 destination;
  float speed;
  bool available;
  bool pickedUp;
  std::string strategyName;
  IEntity* nearestEntity = NULL;
  IStrategy* strategy = NULL;
  float x;
  float y;
  float z;
};

#endif  // CSCI_3081W_F22_TEAM_001_14_LAB10_LIBS_TRANSIT_INCLUDE_HELICOPTER_H_
