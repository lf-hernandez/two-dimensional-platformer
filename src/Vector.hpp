#pragma once
#include <iostream>

using namespace std;

class Vector {
 public:
  float x;
  float y;

  Vector();
  Vector(float x, float y);

  Vector& add(const Vector& vector);
  Vector& subtract(const Vector& vector);
  Vector& multiply(const Vector& vector);
  Vector& divide(const Vector& vector);

  friend Vector& operator+(Vector& vector1, const Vector& vector2);
  friend Vector& operator-(Vector& vector1, const Vector& vector2);
  friend Vector& operator*(Vector& vector1, const Vector& vector2);
  friend Vector& operator/(Vector& vector1, const Vector& vector2);

  Vector& operator+=(const Vector& vector);
  Vector& operator-=(const Vector& vector);
  Vector& operator*=(const Vector& vector);
  Vector& operator/=(const Vector& vector);

  friend ostream& operator<<(ostream& stream, const Vector& vector);
};
