#include "SystemEventsHandler.h"

SystemEventsHandler::SystemEventsHandler(){

}

SystemEventsHandler::~SystemEventsHandler(){

}

void SystemEventsHandler::handleSystemEvents(){

    saveCurrentMouseCoords();

    SDL_Event event;
    GameEvent gameEvent;
    while(SDL_PollEvent(&event)){
        switch(event.type){

            case SDL_QUIT:
                gameEvent = GlobalGameEvent(GlobalEventType::QUIT_GAME);
                pushGameEvent(gameEvent);
                break;

            case SDL_KEYDOWN:

                switch (event.key.keysym.sym){

                case SDLK_w:
                gameEvent = KeyboardGameEvent(KeyboardEventType::w_PRESSED);
                pushGameEvent(gameEvent);
                break;

                case SDLK_s:
                gameEvent = KeyboardGameEvent(KeyboardEventType::s_PRESSED);
                pushGameEvent(gameEvent);
                break;

                default:
                if (DEBUG_ENGINE_OUTPUT)
                    cout << CoutTextColors::YELLOW << "No case for pressed key " << event.key.keysym.sym << endl << CoutTextColors::RESET;
                gameEvent = UndefinedGameEvent();
                pushGameEvent(gameEvent);
                }
            break;

            case SDL_KEYUP:

                switch (event.key.keysym.sym){

                case SDLK_w:
                gameEvent = KeyboardGameEvent(KeyboardEventType::w_RELEASED);
                pushGameEvent(gameEvent);
                break;

                case SDLK_s:
                gameEvent = KeyboardGameEvent(KeyboardEventType::s_RELEASED);
                pushGameEvent(gameEvent);
                break;

                default:

                if (DEBUG_ENGINE_OUTPUT)
                    cout << CoutTextColors::YELLOW << "No case for released key " << event.key.keysym.sym << endl << CoutTextColors::RESET;
                gameEvent = UndefinedGameEvent();
                pushGameEvent(gameEvent);
                }
            break;

            case SDL_MOUSEBUTTONDOWN:

                switch (event.button.button){

                case SDL_BUTTON_LEFT:
                gameEvent = MouseGameEvent(MouseEventType::MOUSE_LEFT_BTN_PRESSED, Coords(event.button.x, event.button.y));
                pushGameEvent(gameEvent);
                break;
                
                default:
                if (DEBUG_ENGINE_OUTPUT)
                    cout << CoutTextColors::YELLOW << "No case for pressed mouse button " << event.button.button << endl << CoutTextColors::RESET;
                gameEvent = UndefinedGameEvent();
                pushGameEvent(gameEvent);
                break;
                }
            break;

            case SDL_MOUSEBUTTONUP:
            
                switch (event.button.button){

                case SDL_BUTTON_LEFT:

                gameEvent = MouseGameEvent(MouseEventType::MOUSE_LEFT_BTN_RELEASED, Coords(event.button.x, event.button.y));
                pushGameEvent(gameEvent);
                break;
            
                default:
                if (DEBUG_ENGINE_OUTPUT)
                    cout << CoutTextColors::YELLOW << "No case for released mouse button " << event.button.button << endl << CoutTextColors::RESET;
                gameEvent = UndefinedGameEvent();
                pushGameEvent(gameEvent);
                break;
            }
            break;


        }
    }
}

queue<GameEvent>* SystemEventsHandler::getQueueOfGameEventsPtr(){
    return &queueOfGameEvents;
}

void SystemEventsHandler::pushGameEvent(GameEvent event){
    queueOfGameEvents.push(event);
}

bool SystemEventsHandler::popGameEvent(GameEvent* dstEvent){

    if (queueOfGameEvents.empty())
        return false;
    
    *dstEvent = queueOfGameEvents.front();
    queueOfGameEvents.pop();
    return true;
}

void SystemEventsHandler::saveCurrentMouseCoords(){
    int x, y;
    SDL_GetMouseState(&x, &y);

    savedCurrentMouseCoords.x = x;
    savedCurrentMouseCoords.y = y;
}

Coords SystemEventsHandler::getCurrentMouseCoords(){
    return savedCurrentMouseCoords;
}
