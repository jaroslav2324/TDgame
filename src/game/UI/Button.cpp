#include "Button.h"

Button::Button(Coords coords, Renderer* renderer, SoundPlayer* soundPlayer, TexturesEnumeration textureNoInteraction, TexturesEnumeration textureHoveredOver, TexturesEnumeration texturePressedOn,
    SoundsEnumeration soundHoverOver, SoundsEnumeration soundPressOn){

    Button::coords = coords;
    this->renderer = renderer;
    this->soundPlayer = soundPlayer;

    this->textureNoInteraction = textureNoInteraction;
    this->textureHoveredOver = textureHoveredOver;
    this->texturePressedOn = texturePressedOn;

    this->soundHoverOver = soundHoverOver;
    this->soundPressOn = soundPressOn;

    pressingCooldownTimer = new CountdownTimer(0);
}

Button::~Button(){

    if (pressingCooldownTimer != nullptr){
        delete pressingCooldownTimer;
        pressingCooldownTimer = nullptr;
    }
}

void Button::render(){

    int x = coords.x - btnWidth / 2;
    int y = coords.y - btnHeight / 2;
    SDL_Rect btnRect = {x, y, btnWidth, btnHeight};

    if (!pressingCooldownTimer->isCountdownEnd()){
        renderer->renderTexture(texturePressedOn, &btnRect);
        return;
    }

    switch (btnCursorInteractionMode)
    {
    case NO_INTERACTION:
        renderer->renderTexture(textureNoInteraction, &btnRect);
        break;
    case PRESSED_ON:
        renderer->renderTexture(texturePressedOn, &btnRect);
        break;
    case HOVERED_OVER:
    renderer->renderTexture(textureHoveredOver, &btnRect);
        break;
    default:
        break;
    }

    // render label
    if (label != ""){
        int rectX = (coords.x - btnWidth * 0.5) + btnWidth * 0.2;
        int rectY = (coords.y - btnHeight * 0.5) + btnHeight * 0.2;
        int rectWidth = btnWidth * 0.6;
        int rectHeight = btnHeight * 0.6;
        SDL_Rect textRect = {rectX, rectY, rectWidth, rectHeight};
        SDL_Color textClr = {0, 0, 0, 255};
        renderer->renderText(label, &textRect, textClr, labelTextSize);
    }
}

// void Button::setModeNoCursorInteraction(){
//     btnCursorInteractionMode = NO_INTERACTION;
// }

// void Button::setModePressedOn(){
//     btnCursorInteractionMode = PRESSED_ON;
//     pressingCooldownTimer->replaceTime(pressingCooldownTime);
// }

// void Button::setModeHoveredOver(){
//     btnCursorInteractionMode = HOVERED_OVER;
// }

void Button::setModeAndPlaySound(ObjectCursorInteractionsModes btnMode){

    switch(btnMode){

        case NO_INTERACTION:
        btnCursorInteractionMode = NO_INTERACTION;
        break;

        case PRESSED_ON:
        btnCursorInteractionMode = PRESSED_ON;
        pressingCooldownTimer->replaceTime(pressingCooldownTime);
        //TODO change channel
        soundPlayer->playSound(soundPressOn, SoundChannels::EFFECTS_CHANNEL);
        break;

        case HOVERED_OVER:
        if (btnCursorInteractionMode == ObjectCursorInteractionsModes::NO_INTERACTION){
            //TODO change channel
            soundPlayer->playSound(soundHoverOver, SoundChannels::EFFECTS_CHANNEL);
        }
        btnCursorInteractionMode = HOVERED_OVER;
        
        break;

        default:
        if (DEBUG_CONSOLE_OUTPUT_ON)
            cout << CoutTextColors::RED << "No such ObjectCursorInteractionModes" << endl << CoutTextColors::RESET;

        break;
    }
}

bool Button::isPointInRect(Coords point){
    
    int x1 = coords.x - btnWidth / 2;
    int y1 = coords.y - btnHeight / 2;

    int x2 = coords.x + btnWidth / 2;
    int y2 = coords.y + btnHeight / 2;

    if (point.x < x1 || point.y < y1 || point.x >= x2 || point.y >= y2)
        return false;
    return true;
}

void Button::setWidthHeight(int width, int height){
    btnWidth = width;
    btnHeight = height;
}

void Button::setLabel(string label){
    this->label = label;
}

void Button::setLabelTextSize(TextSizes labelTextSize){
    this->labelTextSize = labelTextSize;
}

bool Button::isPressingCooldownInactive(){
    return pressingCooldownTimer->isCountdownEnd();
}

void Button::saveToBinaryFile(ostream& outpustStream){

    if (DEBUG_CONSOLE_OUTPUT_ON && !SAVING_LEVELS_ON)
        cout << "Saving levels is turned off. Saving button stopped." << endl;

    if (!SAVING_LEVELS_ON)
        return;
    
    // save width and height
    outpustStream.write((char*)&btnWidth, sizeof(btnWidth));
    outpustStream.write((char*)&btnHeight, sizeof(btnHeight));

    // save textures nums in TexturesEnumeration
    outpustStream.write((char*)&textureNoInteraction, sizeof(textureNoInteraction));
    outpustStream.write((char*)&textureHoveredOver, sizeof(textureHoveredOver));
    outpustStream.write((char*)&texturePressedOn, sizeof(texturePressedOn));

    // save pressing cooldown time
    outpustStream.write((char*)&pressingCooldownTime, sizeof(pressingCooldownTime));
}

void Button::loadFromBinaryFile(istream& inputStream){

    if (DEBUG_CONSOLE_OUTPUT_ON && !LOADING_LEVELS_ON)
        cout << "Loading levels is turned off. Loading button stopped." << endl;

    if (!LOADING_LEVELS_ON)
        return;

    // load width and height
    inputStream.read((char*)&btnWidth, sizeof(btnWidth));
    inputStream.read((char*)&btnHeight, sizeof(btnHeight));

    // load textures nums in TexturesEnumeration
    inputStream.read((char*)&textureNoInteraction, sizeof(textureNoInteraction));
    inputStream.read((char*)&textureHoveredOver, sizeof(textureHoveredOver));
    inputStream.read((char*)&texturePressedOn, sizeof(texturePressedOn));

    // load pressing cooldown time
    inputStream.read((char*)&pressingCooldownTime, sizeof(pressingCooldownTime));
}
