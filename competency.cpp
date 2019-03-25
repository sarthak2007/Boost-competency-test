#include <iostream> 
#include <boost/units/quantity.hpp>
#include <boost/units/systems/si/length.hpp>
#include <boost/units/systems/si/prefixes.hpp>
#include <boost/units/systems/si/io.hpp>

using namespace std; 
using namespace boost::units;
using namespace boost::units::si;

class Vector { 
private: 
    quantity<length> x, y, z; 
    // Components of the Vector with units
  
public: 
    Vector(quantity<length> x, quantity<length> y, quantity<length> z) 
    { 
        // Constructor 
        this->x = x; 
        this->y = y; 
        this->z = z; 
    } 
    Vector sum(Vector v); // Add 2 Vectors 
    Vector cross(Vector v); // Cross Product of 2 Vectors
    friend ostream& operator<<(ostream& out, const Vector& v); 
    // To output the Vector 
}; 
  
// Addition of vectors 
Vector Vector::sum(Vector v) 
{ 
    quantity<length> x1((x.value() + v.x.value())*meters);
    quantity<length> y1((y.value() + v.y.value())*meters);
    quantity<length> z1((z.value() + v.z.value())*meters); 
    return Vector(x1, y1, z1); 
} 

// Cross product of vectors 
Vector Vector::cross(Vector v) 
{  
    quantity<length> x1((y.value() * v.z.value() - z.value() * v.y.value())*meters); 
    quantity<length> y1((z.value() * v.x.value() - x.value() * v.z.value())*meters); 
    quantity<length> z1((x.value() * v.y.value() - y.value() * v.x.value())*meters); 
    return Vector(x1, y1, z1); 
} 
  
// Output the vector with units 
ostream& operator<<(ostream& out, const Vector& v) 
{ 
    out << v.x << " i "; 
    if (v.y.value() >= 0) 
        out << "+ "; 
    out << v.y << " j "; 
    if (v.z.value() >= 0) 
        out << "+ "; 
    out << v.z << " k" ; 
    return out; 
} 
  

int main() 
{ 
    // Let us Take the vector quantites : 
    // V1 = 0.005 m i + 10000 m j + 5 m k
    // V2 = 0.01 m i + 5000 m j + 10 m k

    quantity<length> x(5 *milli*meters);
    quantity<length> y(10 *kilo*meters);
    quantity<length> z(5 * meters);
    quantity<length> a(10 * milli*meters);
    quantity<length> b(5 * kilo*meters);
    quantity<length> c(10 * meters); 
    Vector V1(x,y,z), V2(a,b,c); 
  
    cout << "V1 = " << V1 << endl; 
    cout << "V2 = " << V2 << endl; 
    cout << "V1 + V2 = " << V1.sum(V2) << endl;
    cout << "Cross Product = " << V1.cross(V2) << endl; 
  
    return 0; 
} 