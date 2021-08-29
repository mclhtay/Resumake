#include "skill.h"

Skill::Skill()
{

}


void Skill::setSkill(QString s){
    Skill::skill = s;
}


void Skill::reset(){
    setSkill("");
}

QString Skill::getSkill(){
    return Skill::skill;
}
