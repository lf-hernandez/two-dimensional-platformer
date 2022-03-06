#include "Vector.hpp"

Vector::Vector() {
  x = 0.0f;
  y = 0.0f;
}

Vector::Vector(float x, float y) {
  this->x = x;
  this->y = y;
}

Vector& Vector::add(const Vector& vector) {
  this->x += vector.x;
  this->y += vector.y;

  return *this;
}
Vector& Vector::subtract(const Vector& vector) {
  this->x -= vector.x;
  this->y -= vector.y;

  return *this;
}
Vector& Vector::multiply(const Vector& vector) {
  this->x *= vector.x;
  this->y *= vector.y;

  return *this;
}
Vector& Vector::divide(const Vector& vector) {
  this->x /= vector.x;
  this->y /= vector.y;

  return *this;
}

Vector& operator+(Vector& vector1, const Vector& vector2) {
  return vector1.add(vector2);
}
Vector& operator-(Vector& vector1, const Vector& vector2) {
  return vector1.subtract(vector2);
}
Vector& operator*(Vector& vector1, const Vector& vector2) {
  return vector1.multiply(vector2);
}
Vector& operator/(Vector& vector1, const Vector& vector2) {
  return vector1.divide(vector2);
}

Vector& Vector::operator+=(const Vector& vector) { return this->add(vector); }
Vector& Vector::operator-=(const Vector& vector) {
  return this->subtract(vector);
}
Vector& Vector::operator*=(const Vector& vector) {
  return this->multiply(vector);
}
Vector& Vector::operator/=(const Vector& vector) {
  return this->divide(vector);
}

std::ostream& operator<<(std::ostream& stream, const Vector& vector) {
  stream << "Vector: (" << vector.x << ", " << vector.y << ")";
  return stream;
}
