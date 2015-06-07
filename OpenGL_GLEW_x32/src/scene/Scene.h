#ifndef SCENE_H_
#define SCENE_H_
#include <vector>
#include "../shape/IDrawable.h"
#include "../shape/IAnimatable.h"
#include "WorldWindow.h"

class WorldWindow;
class Scene {

private:
	std::vector<const IDrawable*> drawables;
	std::vector<IAnimatable*> animatables;	
public:
	Scene(const WorldWindow* worldindow){ drawables.push_back(worldindow); }
	virtual ~Scene(){ 
		//for (std::vector<const IDrawable*>::iterator it = drawables.begin(); it != drawables.end(); ++it) delete (*it);
		//for (std::vector<IAnimatable*>::iterator it = animatables.begin(); it != animatables.end(); ++it) delete (*it);
	}
	const std::vector<const IDrawable*>& getDrawables() const { return drawables; }
	const std::vector<IAnimatable*>& getAnimatables() const { return animatables; }
	void addDrawables(IDrawable *drawable) { drawables.push_back(drawable); }
	void addAnimatables(IAnimatable *animatable) { animatables.push_back(animatable); }
};

#endif /* WORLDWINDOW_H_ */
