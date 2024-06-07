//
// Created by Myles Clark on 2024-06-05.
//
#include <iostream>
#include "Move.h"

Move::Move() {}
Move::Move(std::string name, std::string path, int lineToReference) {}
Move::~Move() {}
void Move::setPath(std::string p) {}
void Move::setLineToReference(int lineTR) {}
void Move::setName(std::string n) {}
void Move::setType(std::string t) {}
void Move::setDescription(std::string desc) {}
void Move::setPower(int pow) {}
void Move::setDoesRepeat(bool doesRep) {}
void Move::setMinRepetitions(int minReps) {}
void Move::setMaxRepetitions(int maxReps) {}
void Move::setMovePriority(int priority) {}
void Move::setAccuracy(double acc) {}
void Move::setHitsMultipleTimes(bool hitsMultipleTimes) {}
void Move::setMinHitsPerTurn(int minHitsPT) {}
void Move::setMaxHitsPerTurn(int maxHitsPT) {}
void Move::setStat1AffectedSelf(std::string stat1) {}
void Move::setStat2AffectedSelf(std::string stat2) {}
void Move::setStat3AffectedSelf(std::string stat3) {}
void Move::setStat4AffectedSelf(std::string stat4) {}
void Move::setStat1AffectedOther(std::string stat1) {}
void Move::setStat2AffectedOther(std::string stat2) {}
void Move::setStat3AffectedOther(std::string stat3) {}
void Move::setStat4AffectedOther(std::string stat4) {}
std::string Move::getPath() {}
int Move::getLineToReference() {}
std::string Move::getName() {}
std::string Move::getType() {}
std::string Move::getDescription() {}
int Move::getPower() {}
bool Move::getDoesRepeat() {}
int Move::getMinRepetitions() {}
int Move::getMaxRepetitions() {}
int Move::getMovePriority() {}
double Move::getAccuracy() {}
bool Move::getHitsMultipleTimes() {}
int Move::getMinHitsPerTurn() {}
int Move::getMaxHitsPerTurn() {}
std::string Move::getStat1AffectedSelf() {}
std::string Move::getStat2AffectedSelf() {}
std::string Move::getStat3AffectedSelf() {}
std::string Move::getStat4AffectedSelf() {}
std::string Move::getStat1AffectedOther() {}
std::string Move::getStat2AffectedOther() {}
std::string Move::getStat3AffectedOther() {}
std::string Move::getStat4AffectedOther() {}