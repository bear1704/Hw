#ifndef KMUCS_GRAPHICS_TRANSFORM_HPP
#define KMUCS_GRAPHICS_TRANSFORM_HPP

#define PI 3.14159265358979323846
#define RadToDeg 57.29577951
#define DegToRad 0.017453293
#include<iostream>
#include<cstdarg>
#include<cstring>
#include<cmath>
#include "mat.hpp"


namespace kmuvcl {
	namespace math {


		template <typename T>
		T degToRad(T angle) {

			return angle * DegToRad;

		}
		template<typename T>
		kmuvcl::math::vec<3, T> getUnitVector(T x, T y, T z) {

			kmuvcl::math::vec<3, T> sample;
			T divide = 1 / sqrt(x*x + y*y + z*z);

			sample(0) = x * divide;
			sample(1) = y * divide;
			sample(2) = z * divide;

			return sample;
		}
		template <typename T>
		kmuvcl::math::vec<3, T> getUnitVector(vec<3, T> vector)
		{


			kmuvcl::math::vec<3, T> sample;
			T divide = 1 / sqrt(vector(0)*vector(0) + vector(1)*vector(1) + vector(2)*vector(2));

			sample(0) = vector(0) * divide;
			sample(1) = vector(1) * divide;
			sample(2) = vector(2) * divide;


			//std::cout << "vector(0) = "<< sample << std::endl;

			return sample;
		}
/* ---------------------   -------------------------------------------*/


			template <typename T>
			kmuvcl::math::mat<4, 4, T> translate(T dx, T dy, T dz) {
				kmuvcl::math::mat<4, 4, T> trans;
				int i = 0;

				while (i < 4) {
					trans(i, i) = 1;
					i++;
				}
				trans(3, 0) = dx;
				trans(3, 1) = dy;
				trans(3, 2) = dz;
				return trans;
			}
			template <typename T>
			kmuvcl::math::mat<4, 4, T> rotate(T angle, T x, T y, T z) {

				kmuvcl::math::mat<4, 4, T> rotate_matrix;

				T radAngle = degToRad(angle); // 라디안값 구하기
				kmuvcl::math::vec<3, T> vec;
				vec = getUnitVector(x, y, z); //단위벡터 구하기

				T ux = vec(0);
				T uy = vec(1);
				T uz = vec(2);


				rotate_matrix(0, 0) = cos(radAngle) + ux*ux*(1 - cos(radAngle));
				rotate_matrix(0, 1) = uy * ux * (1 - cos(radAngle)) + uz * sin(radAngle);
				rotate_matrix(0, 2) = uz * ux * (1 - cos(radAngle)) - uy * sin(radAngle);
				rotate_matrix(0, 3) = 0;
				rotate_matrix(1, 0) = ux * uy * (1 - cos(radAngle)) - uz * sin(radAngle);
				rotate_matrix(1, 1) = cos(radAngle) + uy * uy * (1 - cos(radAngle));
				rotate_matrix(1, 2) = uz * uy * (1 - cos(radAngle)) + ux * sin(radAngle);
				rotate_matrix(1, 3) = 0;
				rotate_matrix(2, 0) = ux * uz * (1 - cos(radAngle)) + uy * sin(radAngle);
				rotate_matrix(2, 1) = uy * uz * (1 - cos(radAngle)) - ux * sin(radAngle);
				rotate_matrix(2, 2) = cos(radAngle) + uz * uz * (1 - cos(radAngle));
				rotate_matrix(2, 3) = 0;
				rotate_matrix(3, 0) = 0;
				rotate_matrix(3, 1) = 0;
				rotate_matrix(3, 2) = 0;
				rotate_matrix(3, 3) = 1;

				return rotate_matrix;

			}
			template <typename T>
			kmuvcl::math::mat<4, 4, T> scale(T sx, T sy, T sz) {

				kmuvcl::math::mat<4, 4, T> scale_matrix;

				scale_matrix(0, 0) = sx;
				scale_matrix(1, 1) = sy;
				scale_matrix(2, 2) = sz;
				scale_matrix(3, 3) = 1;

				return scale_matrix;
			}
			template <typename T>
			kmuvcl::math::mat<4, 4, T> lookAt(T eyeX, T eyeY, T eyeZ, T centerX, T centerY, T centerZ,
				T upX, T upY, T upZ) {

				kmuvcl::math::mat<4, 4, T> lookAtLeft;
				kmuvcl::math::mat<4, 4, T> lookAtRight;
				kmuvcl::math::mat<4, 4, T> result;
				kmuvcl::math::vec<3, T> cam_axis;
				//cam_axis(0) = centerX - eyeX;
				//cam_axis(1) = centerY - eyeY;
				//cam_axis(2) = centerZ - eyeZ;
				cam_axis(0) = eyeX - centerX;
				cam_axis(1) = eyeY - centerY;
				cam_axis(2) = eyeZ - centerZ;



				lookAtLeft(3, 3) = 1;
				lookAtRight(0, 0) = 1;
				lookAtRight(1, 1) = 1;
				lookAtRight(2, 2) = 1;
				lookAtRight(3, 3) = 1;

				lookAtRight(3, 0) = -(eyeX); //-cam-posx
				lookAtRight(3, 1) = -(eyeY); //-cam-posy
				lookAtRight(3, 2) = -(eyeZ); //-cam-posz

				cam_axis = getUnitVector(cam_axis); //set cam-z-axis OK
				
				//lookAtLeft.set_ith_row(2, cam_axis); // cam-z-axis 행에 세팅

				lookAtLeft(0, 2) = cam_axis(0); // cam-z-axis 행에 세팅
				lookAtLeft(1, 2) = cam_axis(1);
				lookAtLeft(2, 2) = cam_axis(2);
				//OK
				

				kmuvcl::math::vec<3, T> up(upX, upY, upZ);
				cam_axis = cross(up, cam_axis); //직교벡터 구하려는 수작
				//OK
				
				cam_axis = getUnitVector(cam_axis); // cam-x-axis를 구했다
				

				//lookAtLeft.set_ith_row(0, cam_axis); //cam-x-axis 행에 세팅

				lookAtLeft(0, 0) = cam_axis(0);
				lookAtLeft(1, 0) = cam_axis(1);
				lookAtLeft(2, 0) = cam_axis(2);

				

				//OK
				
				kmuvcl::math::vec<3, T> cam_z_axis;
				//lookAtLeft.get_ith_row(2, cam_z_axis);
				cam_z_axis(0) = lookAtLeft(0, 2);
				cam_z_axis(1) = lookAtLeft(1, 2);
				cam_z_axis(2) = lookAtLeft(2, 2);


				cam_axis = cross(cam_z_axis, cam_axis);
				cam_axis = getUnitVector(cam_axis); // cam-y-axis 단위벡터화

				//lookAtLeft.set_ith_row(1, cam_axis); //cam-y-axis 행렬에 세팅
				lookAtLeft(0, 1) = cam_axis(0);
				lookAtLeft(1, 1) = cam_axis(1);
				lookAtLeft(2, 1) = cam_axis(2);

			
				return lookAtLeft*lookAtRight;
			

			}
			template <typename T>
			kmuvcl::math::mat<4, 4, T> ortho(T l, T r, T b, T t, T n, T f) {

				kmuvcl::math::mat<4, 4, T> retOrtho;

				retOrtho(0, 0) = 2 / (r - l);
				retOrtho(1, 1) = 2 / (t - b);
				retOrtho(2, 2) = -(2 / (f - n));
				retOrtho(3, 3) = 1;
				retOrtho(3, 0) = -((r + l) / (r - l));
				retOrtho(3, 1) = -((t + b) / (t - b));
				retOrtho(3, 2) = -((f + n) / (f - n));

				return retOrtho;


			}

			template <typename T>
			kmuvcl::math::mat<4, 4, T> frustum(T l, T r, T b, T t, T n, T f) {

				kmuvcl::math::mat<4, 4, T> retFrust;

				retFrust(0, 0) = (2 * n) / (r - l);
				retFrust(1, 1) = (2 * n) / (t - b);
				retFrust(2, 0) = (r + l) / (r - l);
				retFrust(2, 1) = (t + b) / (t - b);
				retFrust(2, 2) = -((f + n) / (f - n));
				retFrust(2, 3) = -1;
				retFrust(3, 2) = -((2 * f*n) / (f - n));

				return retFrust;

			}
			template <typename T>
			kmuvcl::math::mat<4, 4, T> perspective(T fovy, T aspect, T zNear, T zFar){
				
				T radAngle = degToRad(fovy);

				T bottom = (-zNear) * tan(radAngle / 2);
				T left = bottom * aspect;
				T top = zNear * tan(radAngle / 2);
				T right = top * aspect;

				return frustum(left, right, bottom, top, zNear, zFar);
							
			
			}





	}
}
#include"operator.hpp"

#endif