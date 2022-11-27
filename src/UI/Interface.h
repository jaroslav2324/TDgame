#include <vector>
#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "../settings.h"
#include "Button.h"

class Interface{
    public:
    Interface(SDL_Renderer* renderer);
    ~Interface();
    void render(SDL_Renderer* renderer);
    private:   
    
    Button* buildTowerBtn = nullptr;
    Button* spawnEnemyBtn = nullptr;
};
