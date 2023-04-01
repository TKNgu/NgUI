#include "Transform.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

using namespace il012e::utility;

#define UPDATE_MODEL \
    this->model = glm::mat4(1.0f); \
    this->model = glm::translate(this->model, this->translateVector); \
    this->model = glm::scale(this->model, this->scaleSize); \
    this->model = glm::rotate(this->model, this->angle, this->rotateVector); \

void Transform::translate(glm::vec3 translateVector) {
    this->translateVector = translateVector;
    UPDATE_MODEL
}

void Transform::scale(glm::vec3 scaleSize) {
    this->scaleSize = scaleSize;
    UPDATE_MODEL
}

void Transform::rotate(float angle, glm::vec3 rotateVector) {
    this->angle = angle;
    this->rotateVector = rotateVector;
    UPDATE_MODEL
}

