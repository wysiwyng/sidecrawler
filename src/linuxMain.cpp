#include "Polycode.h"
#include "PolycodeView.h"
#include "PolycodeTemplateApp.h"

int main(int argc, char *argv[]) {
	PolycodeView *view = new PolycodeView("Hello Polycode!");
	PolycodeTemplateApp *app = new PolycodeTemplateApp(view);
	while(app->Update()) {}
	return 0;
}
