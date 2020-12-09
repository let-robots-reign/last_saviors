// #include "gtest/gtest.h"
// #include "gmock/gmock.h"
// #include "TCPServer.h"
// #include "NetworkErrors.h"

// using namespace testing;

// class MockTCPServer : public TCPServer {
// protected:
//     MOCK_METHOD(void, OnConnect, (const size_t id), (override));
//     MOCK_METHOD(void, OnDisconnect, (const size_t id), (override));
//     MOCK_METHOD(void, OnProcess, (const size_t id), (override));
//     MOCK_METHOD(void, Tick, (), (override));
// };

// //work in progress
// /*TEST(TCPServer, callback_call_test) {
//     MockTCPServer Server;
//     Server.Bind(1337);
//     Server.Start();
//     EXPECT_CALL(Server, Tick(_));

// }*/

