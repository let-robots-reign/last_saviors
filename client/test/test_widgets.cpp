#include "gtest/gtest.h"

#include "widgets/label.h"
#include "widgets/button.h"

TEST(TestWidgets, testLabelText) {
    const Coordinate leftCorner(100, 100);
    const std::string text = "Text on the label";
    Label label(100, 50, leftCorner, text);
    EXPECT_EQ(label.getText(), text);

    const std::string newText = "New text on the label";
    label.updateText(newText);
    EXPECT_EQ(label.getText(), newText);
}

TEST(TestWidgets, testButton) {
    const Coordinate leftCorner(100, 100);
    const std::string buttonText = "Text on the button";
    Button button(100, 50, leftCorner, buttonText);
    EXPECT_EQ(button.getState(), false);
    button.press();
    EXPECT_EQ(button.getState(), true);
    button.press();
    EXPECT_EQ(button.getState(), false);
}
