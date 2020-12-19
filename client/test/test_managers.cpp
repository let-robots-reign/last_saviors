#include "gtest/gtest.h"

#include "event.h"
#include "method_event_handler.h"
#include "functor_event_handler.h"
#include "label.h"
#include "button.h"

class Printer {
public:
    Printer() : label(Label("Label Text")), button(Button("Button Text")) {}

    void firstPrintHandler(const std::string &str, bool &wasCalled) {
        wasCalled = true;
        std::cout << str << std::endl;
    }

    void secondPrintHandler(const std::string &str, bool &wasCalled) {
        label.updateText(str);
    }

    void buttonClickHandler(const Coordinate &coords) {
        button.press();
        label.updateText("Button was pressed");
    }

    TEvent<const std::string &, bool &> onPrint;
    TEvent<const Coordinate &> onButtonClick;

    Label label;
    Button button;
};


TEST(TestEventSystem, testMethodHandler) {
    Printer printer;

    printer.onPrint += METHOD_HANDLER(printer, Printer::firstPrintHandler);

    bool wasCalled = false;
    printer.onPrint("Method handler", wasCalled);

    EXPECT_TRUE(wasCalled);
}

TEST(TestEventSystem, testSeveralHandlersForEvent) {
    Printer printer;

    printer.onPrint += METHOD_HANDLER(printer, Printer::firstPrintHandler);
    printer.onPrint += METHOD_HANDLER(printer, Printer::secondPrintHandler);

    bool firstWasCalled = false;
    printer.onPrint("Several handlers are called", firstWasCalled);

    EXPECT_TRUE(firstWasCalled);
    EXPECT_EQ(printer.label.getText(), "Several handlers are called");
}

TEST(TestEventSystem, testChangingFieldsAfterEvent) {
    Printer printer;

    printer.onButtonClick += METHOD_HANDLER(printer, Printer::buttonClickHandler);
    printer.onButtonClick(Coordinate(10, 10));

    EXPECT_TRUE(printer.button.isPressed());
    EXPECT_EQ(printer.label.getText(), "Button was pressed");
}


class TestPrint {
public:
    TEvent<const std::string &, bool &> onPrint;
};

TEST(TestEventSystem, testLambdaHandler) {
    TestPrint tprint;

    auto lambdaHandler = [](const std::string &str, bool &wasCalled) {
        wasCalled = true;
        std::cout << str << std::endl;
    };
    tprint.onPrint += LAMBDA_HANDLER(lambdaHandler);

    bool wasCalled = false;
    tprint.onPrint("Lambda", wasCalled);

    EXPECT_TRUE(wasCalled);
}

void functionHandler(const std::string &str, bool &wasCalled) {
    wasCalled = true;
    std::cout << str << std::endl;
}

TEST(TestEventSystem, testFunctionHandler) {
    TestPrint tprint;

    tprint.onPrint += FUNCTION_HANDLER(functionHandler);

    bool wasCalled = false;
    tprint.onPrint("Function", wasCalled);

    EXPECT_TRUE(wasCalled);
}

TEST(TestEventSystem, testFunctorHandler) {
    struct Functor {
        void operator()(const std::string &str, bool &wasCalled) {
            wasCalled = true;
            std::cout << str << std::endl;
        }
    };

    TestPrint tprint;
    Functor functor;

    tprint.onPrint += FUNCTOR_HANDLER(functor);

    bool wasCalled = false;
    tprint.onPrint("Functor", wasCalled);

    EXPECT_TRUE(wasCalled);
}

TEST(TestEventSystem, testStdFunctionHandler) {
    std::function<void(const std::string &, bool &)> stdFunc = functionHandler;

    TestPrint tprint;

    tprint.onPrint += STD_FUNCTION_HANDLER(functionHandler);

    bool wasCalled = false;
    tprint.onPrint("std::function", wasCalled);

    EXPECT_TRUE(wasCalled);
}

TEST(TestEventSystem, testUnsubbing) {
    TestPrint tprint;

    auto lambdaHandler = [](const std::string &str, bool &wasCalled) {
        wasCalled = true;
        std::cout << str << std::endl;
    };
    tprint.onPrint += LAMBDA_HANDLER(lambdaHandler);

    bool wasCalledAfterSub = false;
    bool wasCalledAfterUnsub = false;

    tprint.onPrint("Lambda", wasCalledAfterSub);

    tprint.onPrint -= LAMBDA_HANDLER(lambdaHandler);

    tprint.onPrint("Lambda", wasCalledAfterUnsub);

    EXPECT_TRUE(wasCalledAfterSub);
    EXPECT_FALSE(wasCalledAfterUnsub);
}
