#ifndef __STATE_PARSER_H__
#define __STATE_PARSER_H__

#include<vector>
#include<tinyxml.h>

#include "Object/GameObject.h"

class StateParser {
public:

  bool parseState(const char* stateFile, std::string stateID,
  std::vector<GameObject*> *pObjects, std::vector<std::string> *pTextureIDs);

private:

  void parseObjects(TiXmlElement* pStateRoot,
  std::vector<GameObject*> *pObjects);
  void parseTextures(TiXmlElement* pStateRoot,
  std::vector<std::string> *pTextureIDs);
};

#endif /* end of include guard: __STATE_PARSER_H__ */
