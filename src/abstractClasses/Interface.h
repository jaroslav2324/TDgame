#include <queue>

#include "../Coords.h"
#include "../Renderer.h"
#include "../UI/MenuOptionsCodes.h"

using std::queue;

class Interface{
    public:
    Interface();
    ~Interface();

    virtual void render(Renderer* renderer) = 0;
    void saveMouseClickCoords(Coords coords);

    // file must be opened in binary mode. Using with other streams is not recommended(unknown result).
    virtual void saveToBinaryFile(ostream& outpustStream) = 0;
    // file must be opened in binary mode. Using with other streams is not recommended(unknown result).
    virtual void loadFromBinaryFile(istream& inputStream) = 0;

    protected:   

    queue<Coords> savedMouseClicks;

    virtual void handleHoveringOverButtons() = 0;
    virtual MenuOptionsCode handlePressingOnButtons() = 0;
};
