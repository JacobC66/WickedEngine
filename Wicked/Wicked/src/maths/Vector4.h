#ifndef VECTOR4_H
#define VECTOR4_H

namespace wicked
{
	namespace maths
	{
		struct Vector4
		{
			union
			{
				struct { float x, y, z, w; };
				struct { float r, g, b, a; };
			};

			float magnitud;

			Vector4();
			Vector4(float _x, float _y, float _z, float _w);
			Vector4(const Vector4& u);

			float& operator[](size_t index);
			const float& operator[](size_t index) const;
			Vector4& operator=(const Vector4& u);
			friend Vector4 operator+(const Vector4& u, const Vector4& v);
			friend Vector4 operator-(const Vector4& u, const Vector4& v);
			friend Vector4 operator*(const Vector4& u, const Vector4& v);
			friend Vector4 operator/(const Vector4& u, const Vector4& v);
			friend bool operator==(const Vector4& u, const Vector4& v);
			friend bool operator!=(const Vector4& u, const Vector4& v);

			static float dot(const Vector4& u, const Vector4& v);
			static Vector4 normalize(const Vector4& u);
			static Vector4 cross(const Vector4& u, const Vector4& v);
			static float distance(const Vector4& u, const Vector4& v);

		private:
			const size_t m_length = 4;
		};
	}
}

#endif