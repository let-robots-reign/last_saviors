#include "pgsql.h"


pgsql::pgsql(std::shared_ptr<IDBConn> &_dbConn, std::shared_ptr<IUsersMapper> &_userM,
             std::shared_ptr<IScoreMapper> &_scoreM, std::shared_ptr<IQQuestMapper> &new_QQuestM,
             std::shared_ptr<IPQuestMapper> &new_PQuestM)
             : dbConn(_dbConn), userM(_userM),
               scoreM(_scoreM), QQuestM(new_QQuestM),
               PQuestM(new_PQuestM) {

}

std::shared_ptr<IUsersMapper> pgsql::getUserM() {
    return this->userM;
}

std::shared_ptr<IScoreMapper> pgsql::getScoreM() {
    return this->scoreM;
}

std::shared_ptr<IQQuestMapper> pgsql::getQQuestM() {
    return this->QQuestM;
}

std::shared_ptr<IPQuestMapper> pgsql::getPQuestM() {
    return this->PQuestM;
}
