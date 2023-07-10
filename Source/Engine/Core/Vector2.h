#pragma once
#include <cmath>

namespace umbra
{
	class Vector2
	{
	public: //hey!! you can access x and y here
		float x, y;

	public: 
		Vector2() : x{ 0 }, y{0} {} 
		Vector2(float v): x {v}, y{v} {} //sets the x AND y to v
		Vector2(float x, float y) : x{ x }, y{y} {} //points to THIS class's x and y's || this->x = x; this->y = y;
		Vector2(int x, int y) : x{ (float)x }, y{ (float)y } {}

		//Vector2 Add(Vector2& const v) const { return Vector2(x + v.x, y + v.y); } //we're making a copy of a vector, v doesnt change
		Vector2 operator + (const Vector2& v) const { return Vector2(x + v.x, y + v.y); };
		Vector2 operator - (const Vector2& v) const { return Vector2(x - v.x, y - v.y); }; //what i did worked and this is what came from it >;3
		Vector2 operator * (const Vector2& v) const { return Vector2(x * v.x, y * v.y); };
		Vector2 operator / (const Vector2& v) const { return Vector2(x / v.x, y / v.y); };

		Vector2 operator + (float s) const { return Vector2(x + s, y + s); }; //s for scaler
		Vector2 operator - (float s) const { return Vector2(x - s, y - s); };
		Vector2 operator * (float s) const { return Vector2(x * s, y * s); };
		Vector2 operator / (float s) const { return Vector2(x / s, y / s); };

		Vector2& operator += (const Vector2& v) { x += v.x, y += v.y; return *this; };
		Vector2& operator -= (const Vector2& v) { x -= v.x, y -= v.y; return *this; };
		Vector2& operator *= (const Vector2& v) { x *= v.x, y *= v.y; return *this; };
		Vector2& operator /= (const Vector2& v) { x /= v.x, y /= v.y; return *this; };

		float LengthSqr() { return (x * x) + (y * y); };
		float Length() { return sqrt(LengthSqr()); };

		Vector2 Normalized() { return *this / Length(); } //returns normalized value of our vector
		void Normalize() { *this /= Length(); }
	};

	using vec2 = Vector2;
}