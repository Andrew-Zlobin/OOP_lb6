#ifndef GAME_RULESTHING_H
#define GAME_RULESTHING_H

template <int T>
class RulesThing{
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
    Item** GetThing(){
        Item** items = new Item *[GetValue()];
        int direction;
        int x = 0, y = 0;
        for(int i = 0; i < GetValue(); i++){
            direction = rand()%9;
            if(direction < 3){
                items[i] = new Heal();
            }
            else if(direction < 6){
                items[i] = new IncreaseDamage();
            }
            else if(direction < 9){
                items[i] = new IncreaseMaxHealth();
            }
        }
        return items;
    }
};

#endif //GAME_RULESTHING_H
