#include <fstream>
#include <iostream>
#include <string>
#include "SceneFactory.h"
#include "Scene.h"

Scene SceneFactory::CreateScene(std::string &filename){
	std::ifstream inf(filename);
	std::string line;
	Scene scene;
	while (inf)
	{
		std::getline(inf,line);
	}

}
