#include "PolycodeView.h"
#include "Polycode.h"
#include "Polycode2DPhysics.h"

using namespace Polycode;

class PolycodeTemplateApp : EventHandler{
public:
    PolycodeTemplateApp(PolycodeView *view);
    ~PolycodeTemplateApp();
    
    bool Update();
    void handleEvent(Event *e);
    
private:
    Core *core;
    PhysicsScene2D *scene;
    ScenePrimitive *checkShape;
};
