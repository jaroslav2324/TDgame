#include "SystemEventsHandler.h"

SystemEventsHandler::SystemEventsHandler(){

}

SystemEventsHandler::~SystemEventsHandler(){

}

void SystemEventsHandler::handleSystemEvents(){

    SDL_Event event;
    while(SDL_PollEvent(&event)){

        switch(event.type){

            case SDL_QUIT:
            pushGameEvent(GameEventType::QUIT_GAME);
            break;

            case SDL_KEYDOWN:

                switch (event.key.keysym.sym){

                case SDLK_w:
                pushGameEvent(GameEventType::w_PRESSED);
                break;

                case SDLK_s:
                pushGameEvent(GameEventType::s_PRESSED);
                break;

                default:
                if (DEBUG_ENGINE_OUTPUT)
                    cout << CoutTextColors::YELLOW << "No case for pressed key " << event.key.keysym.sym << endl << CoutTextColors::RESET;
                pushGameEvent(GameEventType::UNDEFINED_GAME_EVENT);
                }
            break;

            case SDL_KEYUP:

                switch (event.key.keysym.sym){

                case SDLK_w:
                pushGameEvent(GameEventType::w_RELEASED);
                break;

                case SDLK_s:
                pushGameEvent(GameEventType::s_RELEASED);
                break;

                default:
                if (DEBUG_ENGINE_OUTPUT)
                    cout << CoutTextColors::YELLOW << "No case for released key " << event.key.keysym.sym << endl << CoutTextColors::RESET;
                pushGameEvent(GameEventType::UNDEFINED_GAME_EVENT);
                }
            break;

            case SDL_MOUSEBUTTONDOWN:

                switch (event.button.button){

                case SDL_BUTTON_LEFT:
                    pushGameEvent(GameEventType::MOUSE_LEFT_BTN_PRESSED);
                    break;
                
                default:
                if (DEBUG_ENGINE_OUTPUT)
                    cout << CoutTextColors::YELLOW << "No case for pressed mouse button " << event.button.button << endl << CoutTextColors::RESET;
                pushGameEvent(GameEventType::UNDEFINED_GAME_EVENT);
                    break;
                }
            break;

            case SDL_MOUSEBUTTONUP:
            
                switch (event.button.button){

                case SDL_BUTTON_LEFT:
                pushGameEvent(GameEventType::MOUSE_LEFT_BTN_RELEASED);
                break;
            
                default:
                if (DEBUG_ENGINE_OUTPUT)
                    cout << CoutTextColors::YELLOW << "No case for released mouse button " << event.button.button << endl << CoutTextColors::RESET;
                pushGameEvent(GameEventType::UNDEFINED_GAME_EVENT);
                break;
            }
            break;


        }
    }
}

void SystemEventsHandler::pushGameEvent(GameEvent event){
    queueOfGameEvents.push(event);
}

void SystemEventsHandler::pushGameEvent(GameEventType eventType){
    queueOfGameEvents.push(GameEvent(eventType));
}

bool SystemEventsHandler::popGameEvent(GameEvent* dstEvent){

    if (queueOfGameEvents.empty())
        return false;
    
    *dstEvent = queueOfGameEvents.front();
    queueOfGameEvents.pop();
    return true;
}
