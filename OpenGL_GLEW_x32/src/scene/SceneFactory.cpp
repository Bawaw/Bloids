#ifndef SCENE_FACTORY
#define SCENE_FACTORY
#include <fstream>
#include <string>
#include <iostream>
#include "SceneFactory.h"
#include <sstream>
#include "../shape/DynamicCircle.h"
#include "../shape/Boid.h"
#include "../shape/Flock.h"
 
Scene& SceneFactory::CreateScene(const std::string &filename, WorldWindow* worldwindow){
	std::ifstream inf(filename);
	if (!inf)
		std::cout << "file not found";
	std::string line;
	Scene* scene = new Scene(worldwindow);
	Colour col;
	while (inf)
	{
		std::getline(inf, line);
		std::istringstream iss(line);
		std::string word;
		std::vector<std::string> words;
		while (iss >> word) {
			words.push_back(word);
		}
		if (words[0] == "colour"){
			col.r = std::atof(words[1].c_str());
			col.g = std::atof(words[2].c_str());
			col.b = std::atof(words[3].c_str());
		}
		if (words[0] == "circle"){
			Circle *c = new Circle(Point(std::atof(words[1].c_str()), std::atof(words[2].c_str())), std::atof(words[3].c_str()),col);
			scene->addDrawables(c);
		}
		if (words[0] == "dynamicCircle"){
			DynamicCircle *c = new DynamicCircle(Point(std::atof(words[1].c_str()), std::atof(words[2].c_str())), std::atof(words[3].c_str()), col, Vector(std::atof(words[4].c_str()), std::atof(words[5].c_str())));
			scene->addDrawables(c);
			scene->addAnimatables(c);
		}
		if (words[0] == "boid"){
			Boid *b = new Boid(Point(std::atof(words[1].c_str()), std::atof(words[2].c_str())), std::atof(words[3].c_str()), Vector(std::atof(words[4].c_str()), std::atof(words[5].c_str())),col);
			scene->addDrawables(b);
			scene->addAnimatables(b);
		}

		if (words[0] == "flock"){
			int size = std::atof(words[1].c_str());
			Flock *flock = new Flock(col);
			for (int i = 0; i < size; i++)
			{
				std::getline(inf, line);
				std::istringstream iss(line);
				std::string word;
				std::vector<std::string> words;
				while (iss >> word) words.push_back(word);
				Boid *b = new Boid(Point(std::atof(words[0].c_str()), std::atof(words[1].c_str())), std::atof(words[2].c_str()), Vector(std::atof(words[3].c_str()), std::atof(words[4].c_str())), col);
				flock->addBoid(b);
			}
			scene->addDrawables(flock);
			scene->addAnimatables(flock);
		}
	}
	return *scene;
};
#endif
