#include "OptionsMenu.h"

OptionsMenu::OptionsMenu(Renderer* renderer, SoundPlayer* soundPlayer, SystemEventsHandler* sysEventsHandler):
Interface(renderer, soundPlayer, sysEventsHandler){
    
    //TODO change button textures
    // TODO change button centers(height)

    toMainMenuBtn = new Button(Coords(SCREEN_WIDTH / 2, 250), renderer, soundPlayer);
    toMainMenuBtn->setWidthHeight(500, 200);

    musicVolumeSlider = new Slider(renderer, {SCREEN_WIDTH / 2 - 250, 500, 500, 50});
    musicVolumeSlider->setTitle("Music volume");
    musicVolumeSlider->setTitleWidth(100);

    createButtonsVec();
    createButtonsReturnCodesVec();    
}

OptionsMenu::~OptionsMenu(){

    if (toMainMenuBtn != nullptr){
        delete toMainMenuBtn;
        toMainMenuBtn = nullptr;
    }

    if (musicVolumeSlider != nullptr){
        delete musicVolumeSlider;
        musicVolumeSlider = nullptr;
    }
}

MenuOptionsCode OptionsMenu::makeFrameTurn(){

    handleHoveringOverButtons();

    //TODO rewrite, 
    queue<Coords> queuePressedMouseCoords = savedMouseClicks;
    while (!queuePressedMouseCoords.empty()){
        Coords mouseCoords = queuePressedMouseCoords.front();
        queuePressedMouseCoords.pop();

        if (musicVolumeSlider->isPointInRect(mouseCoords) && !musicVolumeSlider->isMovingAfterMouse()){
            musicVolumeSlider->setMovingAfterMouse();
            musicVolumeSlider->setPosition(mouseCoords);
        }
        else if (!musicVolumeSlider->isPointInRect(mouseCoords) && musicVolumeSlider->isMovingAfterMouse())
            musicVolumeSlider->unsetMovingAfterMouse();
  
    }

    //TODO move getting coords to HID
    if (musicVolumeSlider->isMovingAfterMouse()){
        int x, y;
        SDL_GetMouseState(&x, &y);
        musicVolumeSlider->setPosition(Coords(x, y));
    }

    return handlePressingOnButtons();
}

void OptionsMenu::render(){

    SDL_Color color = {150, 150, 150, 255};
    SDL_Rect rect = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};
    renderer->renderFilledRect(&rect, color);

    renderButtons(renderer);
    musicVolumeSlider->render();
}

void OptionsMenu::createButtonsVec(){
    buttonsVec.push_back(toMainMenuBtn);
}

void OptionsMenu::createButtonsReturnCodesVec(){
    buttonsReturnCodesVec.push_back(MenuOptionsCode::QUIT_TO_MAIN_MENU);
}

