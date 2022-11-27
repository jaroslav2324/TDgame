#include <string>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

using std::string;

class Button
{
public:
    Button(SDL_Renderer* renderer, string& btnImgPath, string& btnPressedImgPath, string& btnHoveredImgPath, std::pair<float, float> coords);
    Button(SDL_Renderer* renderer, const char* btnImgPath, const char* btnPressedImgPath, const char* btnHoveredImgPath, std::pair<float, float> coords);
    ~Button();

    void render(SDL_Renderer* renderer);

    void setModeBasic();
    void setModePressed();
    void setModeHovered();

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

    //TODO add mode changing(create cursor position seeker)
    int currentBtnMode = 0;

    std::pair<float, float> coords;
};
