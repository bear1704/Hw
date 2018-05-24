#include <iostream>
//#include "vec2.hpp"
//#include "vec3.hpp"

//using kmuvcl::math::vec2f;
//using kmuvcl::math::vec3f;
#include "vec.hpp"
#include "mat.hpp"
#include "transform.hpp"
//using kmuvcl::math::vec2f;
//using kmuvcl::math::vec3f;
//using kmuvcl::math::mat3x3f;

//typedef kmuvcl::math::mat<3, 2, float> mat3x2f;
//typedef kmuvcl::math::mat<2, 3, float> mat2x3f;

int main()
{
	kmuvcl::math::mat<4, 4, float>  translateMat;
	kmuvcl::math::mat<4, 4, float>  rotateMat;
	kmuvcl::math::mat<4, 4, float>  scaleMat;
	kmuvcl::math::mat<4, 4, double>  lookAtMat;
	kmuvcl::math::mat<4, 4, double>  orthoMat;
	kmuvcl::math::mat<4, 4, double>  frustumMat;
	kmuvcl::math::mat<4, 4, double>  perspectiveMat;

	

	translateMat = kmuvcl::math::translate(2.0f, 3.0f, 4.0f);
	rotateMat = kmuvcl::math::rotate(90.0f, 0.0f, 0.0f, 1.0f);
	scaleMat = kmuvcl::math::scale(2.0f, 3.0f, 4.0f);
	lookAtMat = kmuvcl::math::lookAt(0.0, -3.0, 3.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0);
	orthoMat = kmuvcl::math::ortho(-1.0, 1.0, -1.0, 1.0, 1.0, 10.0);
	frustumMat = kmuvcl::math::frustum(-1.0, 1.0, -1.0, 1.0, 1.0, 10.0);
	perspectiveMat = kmuvcl::math::perspective(45.0, 3.0, 1.0, 100.0);


	std::cout << "Translation Matrix = " << std::endl;
	std::cout << translateMat << std::endl;
	std::cout << "Rotation Matrix = " << std::endl;
	std::cout << rotateMat << std::endl;
	std::cout << "Scale Matrix = " << std::endl;
	std::cout << scaleMat << std::endl;
	std::cout << "LookAt Matrix = " << std::endl;
	std::cout << lookAtMat << std::endl;
	std::cout << "Ortho Matrix = " << std::endl;
	std::cout << orthoMat << std::endl;
	std::cout << "Frustum Matrix = " << std::endl;
	std::cout << frustumMat << std::endl;
	std::cout << "Perspective Matrix = " << std::endl;
	std::cout << perspectiveMat << std::endl;

	return  0;
}
