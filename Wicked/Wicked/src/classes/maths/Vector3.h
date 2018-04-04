#ifndef VECTOR3_H
#define VECTOR3_H

namespace wicked
{
	namespace maths
	{
		struct Vector3
		{
			union
			{
				struct { float x, y, z; };
				struct { float r, g, b; };
			};

			Vector3();
			Vector3(float _x, float _y, float _z);
			Vector3(const Vector3& u);

			float& operator[](size_t index);
			const float& operator[](size_t index) const;
			Vector3& operator=(const Vector3& u);
			friend Vector3 operator+(const Vector3& u, float a);
			friend Vector3 operator+(float a, const Vector3& v);
			friend Vector3 operator+(const Vector3& u, const Vector3& v);
			friend Vector3 operator-(const Vector3& u, float a);
			friend Vector3 operator-(float a, const Vector3& v);
			friend Vector3 operator-(const Vector3& u, const Vector3& v);
			friend Vector3 operator*(const Vector3& u, float a);
			friend Vector3 operator*(float a, const Vector3& v);
			friend Vector3 operator*(const Vector3& u, const Vector3& v);
			friend Vector3 operator/(const Vector3& u, float a);
			friend Vector3 operator/(float a, const Vector3& v);
			friend Vector3 operator/(const Vector3& u, const Vector3& v);
			friend bool operator==(const Vector3& u, const Vector3& v);
			friend bool operator!=(const Vector3& u, const Vector3& v);

			static float dot(const Vector3& u, const Vector3& v);
			static float magnitud(const Vector3& u);
			static Vector3 normalize(const Vector3& u);
			static Vector3 cross(const Vector3& u, const Vector3& v);
			static float distance(const Vector3& u, const Vector3& v);

		private:
			static const size_t m_length = 3;
		};
	}
}

#endif