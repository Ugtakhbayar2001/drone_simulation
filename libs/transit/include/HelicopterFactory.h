#ifndef CSCI_3081W_F22_TEAM_001_14_LAB10_LIBS_TRANSIT_INCLUDE_HELICOPTERFACTORY_H_
#define CSCI_3081W_F22_TEAM_001_14_LAB10_LIBS_TRANSIT_INCLUDE_HELICOPTERFACTORY_H_

#include <vector>

#include "Helicopter.h"
#include "IEntity.h"
#include "IEntityFactory.h"

/**
 * @brief HelicopterFactory interface which uses the Interface IEntityFactory
 *
 **/
class HelicopterFactory : public IEntityFactory {
 public:
  /**
   * @brief HelicopterFactory objects are destroyed.
   *
   **/
  virtual ~HelicopterFactory() {}

  /**
   * @brief Helicopter are created with a name.
   *
   * @param entity HelicopterFactory object
   **/
  IEntity* CreateEntity(JsonObject& entity);
};

#endif  // CSCI_3081W_F22_TEAM_001_14_LAB10_LIBS_TRANSIT_INCLUDE_HELICOPTERFACTORY_H_
