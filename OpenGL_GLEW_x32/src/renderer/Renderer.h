#ifndef RENDERER_H_
#define RENDERER_H_
#include "../scene/scene.h"

class Renderer {
private:
	const Scene& scene;
public:
	Renderer(Scene &scene): scene(scene){}
	virtual ~Renderer(){ };
	void render();
};

#endif /* RENDERER_H_ */

