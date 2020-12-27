#include "gtest/gtest.h"
#include <idb_conn.h>
#include <iusers_mapper.h>
#include <iscore_mapper.h>
#include <iqquest_mapper.h>
#include <ipquest_mapper.h>
#include <DBBuilder.h>


TEST(TestGameDB, testSignIn) {
    auto builder = std::make_shared<DBBuilder>();
    std::shared_ptr<IDB> qwerty = builder->buildAllDB(); // Подключение к бд

    auto qst = qwerty->getQQuestM()->getRandQuizPuzzle(); // Получение вопросов
    std::cout << qst.question << std::endl;

//    User new_user;
//    new_user.login = "1337QWERTY228";
//    new_user.password = "ZXC";
//    new_user.name = "KEK";
//    new_user.age = "12";
//
//    if (user->sign_in(new_user))
//        std::cout << "Есть";
//    else
//        std::cout << "Нет";
//
//    user->sign_up(new_user);

//    auto qstM = qwerty->getQQuestM();
//
//    auto qst = qstM->getRandQuizPuzzle();
//
//    std::cout << qst.question << std::endl;
//    connector->DBExec("select * from sn_user where user_id > 4 AND user_id < 9;");
//    std::cout << "Get " << connector->getDBTuples() << "tuples, each tuple has "
//                  << connector->getDBNFields() << "fields" << std::endl;
//        // print column name
////        for (int i = 0; i < PQnfields(res); i++) {
////            std::cout << PQfname(res, i) << "              ";
////        }
//        std::cout << std::endl;
//        // print column values
//        for (int i = 0; i < connector->getDBTuples(); i++) {
//            for (int j = 0; j < connector->getDBNFields(); j++) {
//                std::cout << connector->DBGetValue(i, j) << "   ";
//            }
//            std::cout << std::endl;
//        }

}