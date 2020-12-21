#include "ClientStruct.h"
///TODO: #include Ilya's Quiz

struct GameClientStruct : public ClientStruct {
public:
    GameClientStruct(std::unique_ptr<TCPSocketConnectedClient> socket);

    enum QuizState { NONE, ANSWERING } m_quizstate;
    Quiz m_quiz;
};
