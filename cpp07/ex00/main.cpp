#include "Whatever.hpp"

class Awesome
{
  public:
    Awesome(void) : _n(0) {}
    Awesome( int n ) : _n( n ) {}
    Awesome & operator= (Awesome & a) { _n = a._n; return *this; }
    bool operator==( Awesome const & rhs ) const { return (this->_n == rhs._n); }
    bool operator!=( Awesome const & rhs ) const{ return (this->_n != rhs._n); }
    bool operator>( Awesome const & rhs ) const { return (this->_n > rhs._n); }
    bool operator<( Awesome const & rhs ) const { return (this->_n < rhs._n); }
    bool operator>=( Awesome const & rhs ) const { return (this->_n >= rhs._n); }
    bool operator<=( Awesome const & rhs ) const { return (this->_n <= rhs._n); }
    int get_n() const { return _n; }
  private:
    int _n;
};
std::ostream & operator<<(std::ostream & o, const Awesome &a) { o << a.get_n(); return o; }

int main(void)
{
	Awesome a(2), b(4);

        swap(a, b);
        std::cout << a << " " << b << std::endl;
        std::cout << max(a, b) << std::endl;
        std::cout << min(a, b) << std::endl;
        return (0);
}

// int main(void)
// {
// 	int a = 2;
// 	int b = 3;
// 	swap(a, b);
// 	std::cout << "a = " << a << ", b = " << b << std::endl;
// 	std::cout << "min( a, b ) = " << min(a, b) << std::endl;
// 	std::cout << "max( a, b ) = " << max(a, b) << std::endl;
// 	std::cout << std::endl;

// 	std::string c = "chaine1";
// 	std::string d = "chaine2";
// 	::swap(c, d);
// 	std::cout << "c = " << c << ", d = " << d << std::endl;
// 	std::cout << "min( c, d ) = " << min(c, d) << std::endl;
// 	std::cout << "max( c, d ) = " << max(c, d) << std::endl;
// 	std::cout << std::endl;

// 	char y = 'y';
// 	char z = 'z';
// 	swap(y, z);
// 	std::cout << "y = " << y << ", z = " << z << std::endl;
// 	std::cout << "min( y, z ) = " << min(y, z) << std::endl;
// 	std::cout << "max( y, z ) = " << max(y, z) << std::endl;
// 	std::cout << std::endl;

// 	float e = 0.42f;
// 	float f = 42.42f;
// 	swap(e, f);
// 	std::cout << "e = " << e << ", f = " << f << std::endl;
// 	std::cout << "min( e, f ) = " << min(e, f) << std::endl;
// 	std::cout << "max( e, f ) = " << max(e, f) << std::endl;
// 	std::cout << std::endl;
	
// 	double g = 0.42;
// 	double h = 42.42;
// 	swap(g, h);
// 	std::cout << "g = " << g << ", h = " << h << std::endl;
// 	std::cout << "min( g, h ) = " << min(g, h) << std::endl;
// 	std::cout << "max( g, h ) = " << max(g, h) << std::endl;
// 	return 0;
// }
