#ifndef GAME_RULESENEMY_H
#define GAME_RULESENEMY_H

template <int T>
class RulesEnemy{
private:
    int value = T;
public:
    int GetValue(){
        if(value < 0){
            value = -value;
        }
        return value;
    }
    void SetValue(int value){
        this->value = value;
    }
    Enemy** GetEnemy(){
        Enemy** enemies = new Enemy *[GetValue()];
        int direction;
        srand(time(NULL));
        for(int i = 0; i < value; i++){
            direction = rand()%9;
            if(direction < 3){
                enemies[i] = new Warrior();
            }
            else if(direction < 6){
                enemies[i] = new Ghost();
            }
            else if(direction < 9){
                enemies[i] = new Tank();
            }
        }
        return enemies;
    }
};

#endif //GAME_RULESENEMY_H
