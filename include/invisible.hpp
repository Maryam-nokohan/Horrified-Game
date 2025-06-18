#ifndef INVISIBLE_HPP
#define INVISIBLE_HPP
#include "../include/Monster.hpp"
#include <vector>
class InvisibleMan : public Monster{
    private :
    std :: vector <bool> Evidences;
    
    public :
    InvisibleMan();
    void Move(std :: shared_ptr<Location>) override;
    void Attack() override;
    // void StalkUnseen();
    bool IsEvidenceCollected(const int &index)const;
    void DestroyEvidence(const int &index);
    bool AllEvidenceCollected()const;



};
#endif