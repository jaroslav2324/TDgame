#include <string>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "../Coords.h"
#include "../Timers.h"

using std::string;

class Button
{
public:

    Button(SDL_Renderer* renderer, string& btnImgPath, string& btnPressedImgPath, string& btnHoveredImgPath, Coords coords);
    Button(SDL_Renderer* renderer, const char* btnImgPath, const char* btnPressedImgPath, const char* btnHoveredImgPath, Coords coords);
    ~Button();

    void render(SDL_Renderer* renderer);

    void setModeBasic();
    void setModePressed();
    void setModeHovered();
    void setRecentlyPressedFlag();
    void unsetRecentlyPressedFlag();

    bool isPointInRect(Coords point);

private:

    const int BTN_WIDTH = 100;
    const int BTN_HEIGHT = 50;

    void loadTextures(SDL_Renderer* renderer, string& btnImgPath, string& btnPressedImgPath, string& btnHoveredImgPath);
    void loadTextures(SDL_Renderer* renderer, const char* btnImgPath, const char* btnPressedImgPath, const char* btnHoveredImgPath);

    SDL_Texture* btnTexture = nullptr;
    SDL_Texture* pressedBtnTexture = nullptr;
    SDL_Texture* hoveredBtnTexture = nullptr;

    enum BtnModes{
        BASIC,
        PRESSED,
        HOVERED
    };

    // how long show texture of pressed button after mouse clicking
    CountdownTimer* showPressedButtonTimer = nullptr;
    
    int currentBtnMode = 0;

    // in milliseconds
    const double showPressedButtonTime = 250;

    // center coords
    Coords coords;
};
