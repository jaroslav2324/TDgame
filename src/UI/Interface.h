#include <vector>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Button.h"

class Interface{
    public:
    Interface(SDL_Renderer* renderer);
    ~Interface();
    void render(SDL_Renderer* renderer);
    private:   
    
    //TODO add buttons
};
