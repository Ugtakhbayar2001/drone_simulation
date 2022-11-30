#ifndef CSCI_3081W_F22_TEAM_001_14_LAB10_LIBS_TRANSIT_INCLUDE_CAR_H_
#define CSCI_3081W_F22_TEAM_001_14_LAB10_LIBS_TRANSIT_INCLUDE_CAR_H_

#include <vector>

#include "IEntity.h"
#include "IStrategy.h"
#include "math/vector3.h"

/**
 * @brief Car interface which uses the Interface IEntity
 *
 **/
class Car : public IEntity {
 public:
  /**
   * @brief Cars are created with a name.
   *
   * @param obj Drone object
   **/
  Car(JsonObject& obj);

  /**
   * @brief Car objects are destroyed.
   *
   **/
  ~Car();

  /**
   * @brief Updates the (position) car.
   *
   * @param dt Change in time
   * @param scheduler Nearest car.
   **/
  void Update(double dt, std::vector<IEntity*> scheduler);

  /**
   * @brief Gets the position of the car.
   *
   * @return Coordinates of the car.
   **/
  Vector3 GetPosition() const { return position; }

  /**
   * @brief Gets the destination of the car.
   *
   * @return Final destinatin of car.
   **/
  Vector3 GetDestination() const { return destination; }

  /**
   * @brief Gets the details of the car.
   *
   * @return Current details of the car.
   **/
  JsonObject GetDetails() const { return details; }

  /**
   * @brief Sets the position of the car.
   *
   * @param pos_ New position of the car.
   **/
  void SetPosition(Vector3 pos_) { position = pos_; }

  /**
   * @brief Sets the direction of the car.
   *
   * @param dir_ New direction of the car.
   **/
  void SetDirection(Vector3 dir_) { direction = dir_; }

  /**
   * @brief Sets the destination of the car.
   *
   * @param des_ New destination of the car.
   **/
  void SetDestination(Vector3 des_) { destination = des_; }

  /**
   * @brief Gets the speed of the car.
   *
   * @return Final speed of the car.
   **/
  float GetSpeed() const { return speed; }

  /**
   * @brief Sets the random destination of the car.
   *
   **/
  void setRandomDestination();

  /**
   * @brief Gets the direction of the car.
   *
   * @return Current direction of the car.
   **/
  Vector3 GetDirection() const { return direction; }

  /**
   * @brief Deletes the copy constructor of Car.
   *
   * @param car Car that we don't want to be copied.
   **/
  Car(const Car& car) = delete;

  /**
   * @brief Deletes the assignment operator of car.
   *
   * @param car Car that we don't want to be copied.
   **/
  Car& operator=(const Car& car) = delete;

 private:
  JsonObject details;
  Vector3 position;
  Vector3 direction;
  float jumpHeight = 0;
  bool goUp = true;  // jump helper
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

#endif  // CSCI_3081W_F22_TEAM_001_14_LAB10_LIBS_TRANSIT_INCLUDE_CAR_H_
