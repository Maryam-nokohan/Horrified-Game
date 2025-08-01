#ifndef INVISIBLE_HPP
#define INVISIBLE_HPP
#include "../include/Monster.hpp"
#include <vector>
class Game;
class Location;
class InvisibleMan : public Monster
{
private:
    std ::vector<std::pair<bool, std ::string>> Evidences;
public:
    InvisibleMan();
    void Move(std ::shared_ptr<Location>) override;
    void StalkUnseen(Game &game, int moves);
    bool IsEvidenceDestroyed(std ::string LocationName);
    void AddDetroyedEvidence(std ::string LocaitonName);
    bool CanBeDefeated() override;
    bool IsTasksLocation(std ::string) override;
    std :: vector<bool> GetEvidences();
    std :: vector<std::pair<bool , std::string>> GetEvidence() const;
};
#endif