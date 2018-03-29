#ifndef VECTOR2_H
#define VECTOR2_H

namespace wicked
{
	namespace maths
	{
		struct Vector2
		{
			union
			{
				struct { float x, y; };
				struct { float r, g; };
			};

			float magnitud;

			Vector2();
			Vector2(float _x, float _y);
			Vector2(const Vector2& u);

			float& operator[](size_t index);
			const float& operator[](size_t index) const;
			Vector2& operator=(const Vector2& u);
			void operator+= (const Vector2& u);
			void operator-= (const Vector2& u);
			void operator*= (const Vector2& u);
			void operator/= (const Vector2& u);
			friend Vector2 operator+(const Vector2& u, const Vector2& v);
			friend Vector2 operator-(const Vector2& u, const Vector2& v);
			friend Vector2 operator*(const Vector2& u, const Vector2& v);
			friend Vector2 operator/(const Vector2& u, const Vector2& v);
			friend bool operator==(const Vector2& u, const Vector2& v);
			friend bool operator!=(const Vector2& u, const Vector2& v);

			static float dot(const Vector2& u, const Vector2& v);
			static Vector2 normalize(const Vector2& u);
			static Vector2 cross(const Vector2& u, const Vector2& v);
			static float distance(const Vector2& u, const Vector2& v);

		private:
			static const size_t m_length = 2;
		};
	}
}

#endif