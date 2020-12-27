#ifndef DB_IDB_H
#define DB_IDB_H


class IDB {
public:
    virtual std::shared_ptr<IUsersMapper> getUserM() = 0;

    virtual std::shared_ptr<IScoreMapper> getScoreM() = 0;

    virtual std::shared_ptr<IQQuestMapper> getQQuestM() = 0;

    virtual std::shared_ptr<IPQuestMapper> getPQuestM() = 0;
};


#endif //DB_IDB_H
