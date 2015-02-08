#include "PolycodeTemplateApp.h"
#include "nfd.h"
#include "BMPFile.h"
#include "Level.h"

PolycodeTemplateApp::PolycodeTemplateApp(PolycodeView *view) {
	core = new POLYCODE_CORE(view, 640, 480, false, true, 0, 0, 90, 0, true);

	CoreServices::getInstance()->getResourceManager()->addArchive("res/default.pak");
	CoreServices::getInstance()->getResourceManager()->addDirResource("default", false);

	PhysicsScene* scene = new PhysicsScene();

	ScenePrimitive *ground = new ScenePrimitive(ScenePrimitive::TYPE_PLANE, 10, 10);
	ground->loadTexture("res/green_texture.png");
	scene->addPhysicsChild(ground, PhysicsSceneEntity::SHAPE_PLANE, 0.0);

	for (int i = 0; i < 100; i++) {
		ScenePrimitive *box = new ScenePrimitive(ScenePrimitive::TYPE_BOX, 0.5, 0.5, 0.5);
		box->loadTexture("res/pink_texture.png");
		box->Roll(-45 + (rand() % 90));
		box->Pitch(-45 + (rand() % 90));
		box->setPosition(-2 + (rand() % 4), i*0.5, -2 + (rand() % 4));
		scene->addPhysicsChild(box, PhysicsSceneEntity::SHAPE_BOX, 1.0);
	}

	String wd = core->getDefaultWorkingDirectory();
	nfdchar_t *outPath = NULL;
	nfdresult_t result = NFD_OpenDialog("bmp", wd.c_str(), &outPath);
    if (result != NFD_OKAY) exit(EXIT_FAILURE);
	Level * level = new Level();
	level->readLevelFromFile(outPath);

	//BMPFile * bmp = new BMPFile();

	//bmp->read(outPath);


	Logger::log("%s", wd.c_str());
	scene->getDefaultCamera()->setPosition(7, 7, 7);
	scene->getDefaultCamera()->lookAt(Vector3(0, 0, 0));
}
PolycodeTemplateApp::~PolycodeTemplateApp() {
    
}

bool PolycodeTemplateApp::Update() {
	return core->updateAndRender();
}
