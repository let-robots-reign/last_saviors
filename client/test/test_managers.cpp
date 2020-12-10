#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "event.h"
#include "functor_event_handler.h"

TEST(TestEventSystem, testFunctorHandlers) {
    class TestPrint {
    public:
        TEvent<const std::string &> onPrint;
    };

//    struct Functor {
//        void operator()(const std::string &str) {
//            std::cout << str << std::endl;
//        }
//    };

    auto lambdaHandler = [](const std::string &str) {
        std::cout << str << std::endl;
    };

    TestPrint tprint;
//    Functor functor;
//    tprint.onPrint += FUNCTOR_HANDLER(functor);
    tprint.onPrint += LAMBDA_HANDLER(lambdaHandler);

    tprint.onPrint("Hello");

}