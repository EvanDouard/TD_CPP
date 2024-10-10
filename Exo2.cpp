#include "complex.h"

Complex2D::Complex2D():
re(0), im(0)
{
}

Complex2D::Complex2D(double _re, double _im):
re(_re), im(_im)
{
}
Complex2D::Complex2D(double _both):
re(_both), im(_both)
{
}

Complex2D::Complex2D(const Complex2D &_complex):
re(_complex.re), im(_complex.im)
{
}

void Complex2D::setIm(double _im) {
    im = _im;
}

void Complex2D::setRe(double _re) {
    re = _re;
}

double Complex2D::getIm() const {
    return im;
}

double Complex2D::getRe() const {
    return re;
}

Complex2D Complex2D::operator +(const Complex2D& c) const {
    return Complex2D(re + c.re, im + c.im);
}

Complex2D Complex2D::operator -(const Complex2D& c) const {
    return Complex2D(re - c.re, im - c.im);
}

Complex2D Complex2D::operator *(const Complex2D& c) const {
    return Complex2D(re * c.re - im * c.im, im * c.re + re * c.im);
}
Complex2D Complex2D::operator /(const Complex2D& c) const {
    double denominator = c.module() * c.module();
    return Complex2D((re * c.re + im * c.im) / denominator, (im * c.re - re * c.im) / denominator);
}

//les comparaisons sont sur les modules
bool Complex2D::operator <(const Complex2D& c) const {
    return this->module() < c.module();
}

bool Complex2D::operator >(const Complex2D& c) const {
    return this->module() > c.module();
}

double Complex2D::module() const {
    return sqrt(re * re + im * im);
}

int main(int argc, char *argv[]) {
    Complex2D c1(1.0);          
    Complex2D c2(1.0, 2.0);     
    Complex2D c3;               

    std::cout << c1.getRe() << "+i" << c1.getIm() << "\n";
    std::cout << c2.getRe() << "+i" << c2.getIm() << "\n";
    std::cout << c3.getRe() << "+i" << c3.getIm() << "\n";
    Complex2D sum = c1 + c2;
    Complex2D diff = c1 - c2;
    Complex2D prod = c1 * c2;
    Complex2D quot = c1 / c2;
    std::cout << "Somme: " << sum.getRe() << "+i" << sum.getIm() << "\n";
    std::cout << "Différence: " << diff.getRe() << "+i" << diff.getIm() << "\n";
    std::cout << "Produit: " << prod.getRe() << "+i" << prod.getIm() << "\n";
    std::cout << "Quotient: " << quot.getRe() << "+i" << quot.getIm() << "\n";
    std::cout << "c1 < c2 : " << (c1 < c2) << "\n";
    std::cout << "c1 > c2 : " << (c1 > c2) << "\n";

    return 0;
}
