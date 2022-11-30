#ifndef CSCI_3081W_F22_TEAM_001_14_LAB10_LIBS_TRANSIT_INCLUDE_CARFACTORY_H_
#define CSCI_3081W_F22_TEAM_001_14_LAB10_LIBS_TRANSIT_INCLUDE_CARFACTORY_H_
#include <vector>

#include "Car.h"
#include "IEntity.h"
#include "IEntityFactory.h"

/**
 * @brief CarFactory interface which uses the Interface IEntityFactory
 *
 **/
class CarFactory : public IEntityFactory {
 public:
  /**
   * @brief CarFactory objects are destroyed.
   *
   **/
  ~CarFactory() {}

  /**
   * @brief Cars are created with a name.
   *
   * @param entity CarFactory object
   **/
  IEntity* CreateEntity(JsonObject& entity);
};

#endif  // CSCI_3081W_F22_TEAM_001_14_LAB10_LIBS_TRANSIT_INCLUDE_CARFACTORY_H_
