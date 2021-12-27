#ifndef GAME_RULESBUILDER_H
#define GAME_RULESBUILDER_H

#include "../../Map/MapBuilder/FirstMapBuilder.h"
#include "../../Map/MapBuilder/SecondMapBuilder.h"
#include "../../Map/MapBuilder/MapDirector.h"

template <int T>
class RulesBuilder{
private:
    int builderID = T;
public:
    Map* GetFieldFromBuilder(){
        MapBuilder* builder;
        
        //std::cout << "Builder was called\n";

        if(builderID%2){
            builder = new FirstMapBuilder();
        }
        else{
            builder = new SecondMapBuilder();
        }
        auto director = MapDirector(builder);
        director.ConstructMap();
        Map* map = builder->ReturnMap();
        delete builder;
        return map;
    }
};

#endif //GAME_RULESBUILDER_H
