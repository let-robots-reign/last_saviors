#ifndef CLIENT_LOADER_H
#define CLIENT_LOADER_H

#include <vector>
#include <string>

class ILoader {
public:
    ILoader() = default;

    virtual void loadTextures() = 0;

    virtual void loadMaps() = 0;

    virtual void loadWaves() = 0;

    virtual void calculatePath() = 0;

    virtual std::string loadTowerDescription() = 0;

    virtual std::vector<std::string> *getCurrentMap() = 0;

    virtual std::vector<std::string> *getWaves() = 0;

    virtual size_t getMapSize() = 0;

    virtual size_t getStart() = 0;
};

#endif //CLIENT_LOADER_H
