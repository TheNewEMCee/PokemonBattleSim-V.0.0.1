#include <iostream>
#ifndef NAME_MOVE_H
#define NAME_MOVE_H


class Move {
private:
    std::string path;
    int lineToReference;
    std::string name;
    std::string type;
    std::string description;
    int power;
    bool doesRepeat;
    int minRepetitions;
    int maxRepetitions;
    int movePriority;
    double accuracy;
    bool hitsMultipleTimes;
    int minHitsPerTurn;
    int maxHitsPerTurn;
    std::string stat1AffectedSelf;
    std::string stat2AffectedSelf;
    std::string stat3AffectedSelf;
    std::string stat4AffectedSelf;
    std::string stat1AffectedOther;
    std::string stat2AffectedOther;
    std::string stat3AffectedOther;
    std::string stat4AffectedOther;
public:
    Move();
    Move(std::string name, std::string path, int lineToReference);
    ~Move();
    void setPath(std::string p);
    void setLineToReference(int lineTR);
    void setName(std::string n);
    void setType(std::string t);
    void setDescription(std::string desc);
    void setPower(int pow);
    void setDoesRepeat(bool doesRep);
    void setMinRepetitions(int minReps);
    void setMaxRepetitions(int maxReps);
    void setMovePriority(int priority);
    void setAccuracy(double acc);
    void setHitsMultipleTimes(bool hitsMultipleTimes);
    void setMinHitsPerTurn(int minHitsPT);
    void setMaxHitsPerTurn(int maxHitsPT);
    void setStat1AffectedSelf(std::string stat1);
    void setStat2AffectedSelf(std::string stat2);
    void setStat3AffectedSelf(std::string stat3);
    void setStat4AffectedSelf(std::string stat4);
    void setStat1AffectedOther(std::string stat1);
    void setStat2AffectedOther(std::string stat2);
    void setStat3AffectedOther(std::string stat3);
    void setStat4AffectedOther(std::string stat4);
    std::string getPath();
    int getLineToReference();
    std::string getName();
    std::string getType();
    std::string getDescription();
    int getPower();
    bool getDoesRepeat();
    int getMinRepetitions();
    int getMaxRepetitions();
    int getMovePriority();
    double getAccuracy();
    bool getHitsMultipleTimes();
    int getMinHitsPerTurn();
    int getMaxHitsPerTurn();
    std::string getStat1AffectedSelf();
    std::string getStat2AffectedSelf();
    std::string getStat3AffectedSelf();
    std::string getStat4AffectedSelf();
    std::string getStat1AffectedOther();
    std::string getStat2AffectedOther();
    std::string getStat3AffectedOther();
    std::string getStat4AffectedOther();

};


#endif //NAME_MOVE_H
