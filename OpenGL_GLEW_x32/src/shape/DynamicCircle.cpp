#include "DynamicCircle.h"

void DynamicCircle::update(const Scene& scene){
	for each (const IDrawable *drawable in scene.getDrawables())
		drawable->Intersect(this);
}

void DynamicCircle::Intersect(DynamicCircle * dynamicCircle)const{

}
