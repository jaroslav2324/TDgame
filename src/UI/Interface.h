#include <vector>
#include <queue>
#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "../settings.h"
#include "Button.h"

using std::queue;

class Interface{
    public:
    Interface(SDL_Renderer* renderer);
    ~Interface();
    void render(SDL_Renderer* renderer);
    void saveMouseClickCoords(Coords coords);
    private:   
    
    Button* buildTowerBtn = nullptr;
    Button* spawnEnemyBtn = nullptr;

    queue<Coords> savedMouseClicks;
};
