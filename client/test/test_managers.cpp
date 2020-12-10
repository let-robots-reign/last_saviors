#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "event.h"
#include "functor_event_handler.h"

class TestPrint {
public:
    explicit TestPrint() {}

    TEvent<const std::string &> onPrint;
};

TEST(TestEventSystem, testLambdaHandler) {
    TestPrint tprint;
    auto lambdaHandler = [](const std::string &str) {
        std::cout << str << std::endl;
    };
    tprint.onPrint += LAMBDA_HANDLER(lambdaHandler);

    tprint.onPrint("Lambda");
}

void functionHandler(const std::string &str) {
    std::cout << str << std::endl;
}

TEST(TestEventSystem, testFunction) {
    TestPrint tprint;

    tprint.onPrint += FUNCTION_HANDLER(functionHandler);
    tprint.onPrint("Function");
}
