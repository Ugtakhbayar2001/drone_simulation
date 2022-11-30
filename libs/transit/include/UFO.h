#ifndef CSCI_3081W_F22_TEAM_001_14_LAB10_LIBS_TRANSIT_INCLUDE_UFO_H_
#define CSCI_3081W_F22_TEAM_001_14_LAB10_LIBS_TRANSIT_INCLUDE_UFO_H_

#include <vector>

#include "IEntity.h"
#include "IStrategy.h"
#include "math/vector3.h"

/**
 * @brief UFO interface which uses the Interface IEntity
 *
 **/
class UFO : public IEntity {
 public:
  /**
   * @brief UFO are created with a name.
   *
   * @param obj UFO object
   **/
  UFO(JsonObject& obj);

  /**
   * @brief UFO objects are destroyed.
   *
   **/
  ~UFO();

  /**
   * @brief Updates the (position) UFO.
   *
   * @param dt Change in time
   * @param scheduler Nearest UFO.
   **/
  void Update(double dt, std::vector<IEntity*> scheduler);

  /**
   * @brief Gets the position of the UFO.
   *
   * @return Coordinates of the UFO.
   **/
  Vector3 GetPosition() const { return position; }

  /**
   * @brief Gets the destination of the UFO.
   *
   * @return Final destinatin of UFO.
   **/
  Vector3 GetDestination() const { return destination; }

  /**
   * @brief Gets the details of the UFO.
   *
   * @return Current details of the UFO.
   **/
  JsonObject GetDetails() const { return details; }

  /**
   * @brief Sets the position of the UFO.
   *
   * @param pos_ New position of the UFO.
   **/
  void SetPosition(Vector3 pos_) { position = pos_; }

  /**
   * @brief Sets the direction of the UFO.
   *
   * @param dir_ New direction of the UFO.
   **/
  void SetDirection(Vector3 dir_) { direction = dir_; }

  /**
   * @brief Sets the destination of the UFO.
   *
   * @param des_ New destination of the UFO.
   **/
  void SetDestination(Vector3 des_) { destination = des_; }

  /**
   * @brief Gets the speed of the UFO.
   *
   * @return Final speed of the UFO.
   **/
  float GetSpeed() const { return speed; }

  /**
   * @brief Sets the random destination of the UFO.
   *
   **/
  void setRandomDestination();

  /**
   * @brief Gets the direction of the UFO.
   *
   * @return Current direction of the UFO.
   **/
  Vector3 GetDirection() const { return direction; }

  /**
   * @brief Deletes the copy constructor of UFO.
   *
   * @param ufo UFO that we don't want to be copied.
   **/
  UFO(const UFO& ufo) = delete;

  /**
   * @brief Deletes the assignment operator of UFO.
   *
   * @param ufo UFO that we don't want to be copied.
   **/
  UFO& operator=(const UFO& ufo) = delete;

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

#endif  // CSCI_3081W_F22_TEAM_001_14_LAB10_LIBS_TRANSIT_INCLUDE_UFO_H_
