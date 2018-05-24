#include "Camera.h"
#include <glm/ext.hpp>

const glm::vec3 Camera::center_position() const
{
  return  glm::vec3(position_.x + front_dir_.x,
                 position_.y + front_dir_.y, 
                 position_.z + front_dir_.z);
}

// TODO: fill up the following functions properly 
void Camera::move_forward(float delta)
{	
}

void Camera::move_backward(float delta)
{	
}

void Camera::move_left(float delta)
{	
}

void Camera::move_right(float delta)
{
}

void Camera::rotate_left(float delta)
{
}

void Camera::rotate_right(float delta)
{
}