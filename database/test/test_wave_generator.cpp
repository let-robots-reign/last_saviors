#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "loader.h"
#include "IWave.h"

using ::testing::Return;

class MockLoader : public Loader {
public:
    MOCK_METHOD(LoadingResult, loadResources, ());
    MOCK_METHOD(LoadingResult, loadTextures, ());
    MOCK_METHOD(LoadingResult, loadFonts, ());
};

TEST(TestManagers, testLoader) {
    using texturesType = int; // sf::Texture
    MockLoader mLoader;
    EXPECT_CALL(mLoader, loadResources()).Times(1);
    EXPECT_CALL(mLoader, loadTextures()).Times(1);
    EXPECT_CALL(mLoader, loadFonts()).Times(1);

    EXPECT_EQ(mLoader.loadResources(), LOADING_SUCCESS);
    EXPECT_EQ(mLoader.loadTextures(), LOADING_SUCCESS);
    EXPECT_EQ(mLoader.loadFonts(), LOADING_SUCCESS);
}

// аналогично RendererManager и UserInputManager