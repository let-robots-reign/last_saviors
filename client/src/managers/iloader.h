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
    static const size_t BUTTON_START_ID;
    static const size_t BUTTON_PAUSE_ID;

    virtual void loadMaps();

    virtual void loadWaves();

    virtual void loadTextures() = 0;

    virtual void loadFont() = 0;

    virtual void calculatePath() = 0;

    virtual std::string loadTowerDescription() const = 0;

    virtual std::vector<std::string> getCurrentMap() const = 0;

    virtual std::vector<std::string> getWaves() const = 0;

    virtual size_t getMapSize() const = 0;

    virtual size_t getStart() const = 0;

protected:
    std::vector<std::string> CURRENT_MAP;
    std::vector<std::string> waves;
    size_t mapSize{};
};

#endif //CLIENT_LOADER_H
