#ifndef SCENE_FACTORY_H_
#define SCENE_FACTORY_H_
#include "Scene.h"

class SceneFactory {
public:
	static Scene& CreateScene(const std::string & filename, WorldWindow* worldwindow);
};

#endif /* WORLDWINDOW_H_ */
