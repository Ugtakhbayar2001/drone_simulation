#ifndef CSCI_3081W_F22_TEAM_001_14_LAB10_LIBS_TRANSIT_INCLUDE_UFOFACTORY_H_
#define CSCI_3081W_F22_TEAM_001_14_LAB10_LIBS_TRANSIT_INCLUDE_UFOFACTORY_H_

#include <vector>

#include "IEntity.h"
#include "IEntityFactory.h"
#include "UFO.h"

/**
 * @brief UFOFactory interface which uses the Interface IEntityFactory
 *
 **/
class UFOFactory : public IEntityFactory {
 public:
  /**
   * @brief UFOFactory objects are destroyed.
   *
   **/
  virtual ~UFOFactory() {}

  /**
   * @brief UFO are created with a name.
   *
   * @param entity UFOFactory object
   **/
  IEntity* CreateEntity(JsonObject& entity);
};

#endif  // CSCI_3081W_F22_TEAM_001_14_LAB10_LIBS_TRANSIT_INCLUDE_UFOFACTORY_H_
