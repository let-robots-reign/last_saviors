#include "ClientStruct.h"
///TODO: #include Ilya's Quiz
#include "quiz_puzzlez.h"


struct GameClientStruct : public ClientStruct {
public:
    GameClientStruct(std::unique_ptr<TCPSocketConnectedClient> socket);

    enum QuizState { NONE, ANSWERING } m_quizstate;
    QuizPuzzle m_quiz;
};
