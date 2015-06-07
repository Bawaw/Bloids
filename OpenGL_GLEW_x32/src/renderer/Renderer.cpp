#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <windows.h>
#include <glew.h>
#include <glut.h>
#endif

#include "Renderer.h"

void Renderer::render(){
	for each (const IDrawable* dr in scene.getDrawables()){
		dr->Draw();
	}
	for each (IAnimatable* an in scene.getAnimatables())
	{
		an->update(scene);
	}
}


