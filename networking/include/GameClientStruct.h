#include "ClientStruct.h"

struct GameClientStruct : public ClientStruct {
public:
    GameClientStruct(std::unique_ptr<TCPSocketConnectedClient> socket);

    // some game client specific stuff here
    // player class object, user id from db, etc
};

