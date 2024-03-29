#ifndef _object_H
#define _object_H

#include "../include/glm/vec3.hpp"
#include "./components/component.h"
#include <vector>
#include <string>

class scene;
class transform;
class object {
public:
    std::string label;
    transform *transform;
    scene *scene;

    object() : object("object"){};
    object(std::string label);
    ~object();
    void update();

    void add_component(component *comp);
    template <class component_type> component_type* get_component();
private:
    std::vector<component*> components;
};

#endif