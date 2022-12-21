#include <queue>

#include "../Coords.h"
#include "../Renderer.h"

using std::queue;

class Interface{
    public:
    Interface();
    ~Interface();

    virtual void render(Renderer* renderer) = 0;
    void saveMouseClickCoords(Coords coords);

    protected:   

    queue<Coords> savedMouseClicks;

    virtual void handleHoveringOverButtons() = 0;
    virtual void handlePressingOnButtons() = 0;
};
