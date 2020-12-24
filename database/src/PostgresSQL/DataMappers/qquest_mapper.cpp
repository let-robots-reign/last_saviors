#include "qquest_mapper.h"

QQuestMapper::QQuestMapper(std::shared_ptr<IDBConn> &new_dbConn) {
    this->dbConn = new_dbConn;
}

QuizPuzzle QQuestMapper::getRandQuizPuzzle() {
    dbConn->DBExec("select COUNT(*) from quiz_question;");
    int question_count = std::stoi(dbConn->DBGetValue(0, 0));

    srand(time(NULL));
    int qst_ind = question_count * (rand() / (RAND_MAX + 1.0)) + 1;

    dbConn->DBExec("select * from quiz_question where qst_id=" + std::to_string(qst_ind) + ";");
    if (dbConn->getDBTuples() != 0) {
        QuizPuzzle quiz_qst;
        quiz_qst.id = std::stoi(dbConn->DBGetValue(0, 0));
        quiz_qst.questionComplexity = std::stoi(dbConn->DBGetValue(0, 1));
        quiz_qst.question = dbConn->DBGetValue(0, 2);
        quiz_qst.answer1 = dbConn->DBGetValue(0, 3);
        quiz_qst.answer2 = dbConn->DBGetValue(0, 4);
        quiz_qst.answer3 = dbConn->DBGetValue(0, 5);
        quiz_qst.answer4 = dbConn->DBGetValue(0, 6);
        quiz_qst.correctAnswer = std::stoi(dbConn->DBGetValue(0, 7));

        return quiz_qst;
    }

    // TODO: Сделать исключения
}
