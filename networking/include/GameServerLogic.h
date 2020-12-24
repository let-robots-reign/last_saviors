#pragma once
#include "ServerLogic.h"
#include "PacketBase.h"
#include "idb_conn.h"
#include <iusers_mapper.h>
#include <iscore_mapper.h>
#include <iqquest_mapper.h>
#include <ipquest_mapper.h>
#include <DBBuilder.h>


// TODO: GameServerLogic is always about GameClientStruct, right?
// so we are supposed to write a template specialization
template<typename TClient>
struct GameServerLogic : public ServerLogic<TClient> {
    friend class TCPServer<GameServerLogic<TClient>, TClient>;
private:
    TCPServer<GameServerLogic<TClient>, TClient> & Server;

private:

    GameServerLogic(TCPServer<GameServerLogic<TClient>, TClient> & server);

    void OnStart();

    void OnTick();

    void OnConnect(const size_t i);

    void OnDisconnect(const size_t i);

    void OnProcess(const size_t i);


    void Send(const size_t i, const Packet & packet);
    void Send(const Packet & packet);

    void ProcessPacket(const size_t i, const Packet & packet);

private:
    std::shared_ptr<IDB> qwerty;

};
