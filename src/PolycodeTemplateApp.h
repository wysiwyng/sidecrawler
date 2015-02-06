#include "PolycodeView.h"
#include "Polycode.h"
#include "Polycode3DPhysics.h"

using namespace Polycode;

class PolycodeTemplateApp {
public:
    PolycodeTemplateApp(PolycodeView *view);
    ~PolycodeTemplateApp();
    
    bool Update();
    
private:
    Core *core;
};