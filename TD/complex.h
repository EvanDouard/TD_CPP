#include <iostream>
#include <string>
#include <cmath>

class Complex2D {
    public:
        Complex2D();
        Complex2D(double re, double im);
        Complex2D(double bot);
        Complex2D(const Complex2D &complex);  
        
        void setIm(double im);
        void setRe(double re);
        double getIm() const;
        double getRe() const;

        Complex2D operator +(const Complex2D& c) const;
        Complex2D operator -(const Complex2D& c) const;
        Complex2D operator *(const Complex2D& c) const;
        Complex2D operator /(const Complex2D& c) const;
        bool operator <(const Complex2D& c) const;
        bool operator >(const Complex2D& c) const;

        double module() const;

    private:
        double re, im;
};
