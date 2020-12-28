#ifndef CLIENT_LOADER_H
#define CLIENT_LOADER_H

#include <vector>
#include <string>
#include <fstream>

class ILoader {
public:
    ILoader() = default;

    static const char ROAD_CHAR;
    static const size_t MOUSE_POINTER_ID;
    static const size_t MOUSE_ACTIVE_SELECT_ID;
    static const size_t MOUSE_INACTIVE_SELECT_ID;
    static const size_t MOUSE_UPGRADE_ID;
    static const size_t BUTTON_START_ID;
    static const size_t BUTTON_PAUSE_ID;
    static const size_t BUTTON_UPGRADE_ID;
    static const size_t BUTTON_QUIZ_ID;

    virtual void loadMaps();

    virtual void loadWaves();

    virtual std::string loadTowerDescription();

    virtual void loadTextures() = 0;

    virtual void loadFont() = 0;

    virtual void calculatePath() = 0;

    virtual std::vector<std::string> *getCurrentMap() = 0;

    virtual std::vector<std::string> *getWaves() = 0;

    virtual size_t getMapSize() = 0;

    virtual size_t getStart() = 0;

protected:
    std::vector<std::string> CURRENT_MAP;
    size_t mapSize;
    std::vector<std::string> waves;
};

#endif //CLIENT_LOADER_H
