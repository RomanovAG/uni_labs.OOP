#include "conchoidnicomed.h"
#include <cmath>
#include <iostream>
#include <math.h>

using namespace std;

ConchoidNicomed::ConchoidNicomed(): l(0), a(0) {}
ConchoidNicomed::ConchoidNicomed(double l, double a)
{
    if (l < 0)
        throw std::invalid_argument("l must be >= 0");
    this->l = l;
    this->a = a;
}
//ConchoidNicomed::ConchoidNicomed(long double l, long double a) {this->l = (double) l; this->a = (double) a;}
//ConchoidNicomed::ConchoidNicomed(float l, float a) {this->l = (double) l; this->a = (double) a;}
//ConchoidNicomed::ConchoidNicomed(int l, int a) {this->l = (double) l; this->a = (double) a;}
//ConchoidNicomed::ConchoidNicomed(long l, long a) {this->l = (double) l; this->a = (double) a;}
//ConchoidNicomed::ConchoidNicomed(long long l, long long a) {this->l = (double) l; this->a = (double) a;}
//ConchoidNicomed::ConchoidNicomed(unsigned long long l, unsigned long long a) {this->l = (double) l; this->a = (double) a;}

ConchoidNicomed &ConchoidNicomed::returnY(double x, double *y1, double *y2)
{
    if (a >= 0 && l >= 0)
        if(x > this->a + this->l || x < this->a - this->l)
            return *this;
    if (a <= 0 && l <= 0)
        if(x < this->a + this->l || x > this->a - this->l)
            return *this;
    if (a >= 0 && l <= 0)
        if(x < this->a + this->l || x > this->a - this->l)
            return *this;
    if (a <= 0 && l >= 0)
        if(x > this->a + this->l || x < this->a - this->l)
            return *this;
    if(x > this->a + this->l || x < this->a - this->l)
        return *this;
    if (y1 != nullptr)
    {
        *y1 = x * sqrt(fabs(a * a - 2 * a * x - l * l + x * x)) / sqrt(fabs((a - x) * (a - x)));
        if (y2 != nullptr)
            *y2 = -*y1;
        return *this;
    }
    if (y2 != nullptr)
        *y2 = -x * sqrt(fabs(a * a - 2 * a * x - l * l + x * x)) / sqrt(fabs((a - x) * (a - x)));
    return *this;
}

void ConchoidNicomed::returnY(double x, double &y1, double &y2) const
{
    if (a >= 0 && l >= 0)
        if(x > this->a + this->l || x < this->a - this->l)
            return;
    if (a <= 0 && l <= 0)
        if(x < this->a + this->l || x > this->a - this->l)
            return;
    if (a >= 0 && l <= 0)
        if(x < this->a + this->l || x > this->a - this->l)
            return;
    if (a <= 0 && l >= 0)
        if(x > this->a + this->l || x < this->a - this->l)
            return;
    if(x > this->a + this->l || x < this->a - this->l)
        return;
    if(fabs(x) >  fabs(this->a) + fabs(this->l))
        return;
    y1 = x * sqrt(fabs(a * a - 2 * a * x - l * l + x * x)) / sqrt(fabs((a - x) * (a - x)));
    y2 = -y1;
    return;
}

double ConchoidNicomed::degToRad(double deg) const
{
    return deg * M_PI / 180;
}

void ConchoidNicomed::returnR(double fi, double *r1, double *r2) const
{
    if (fi == M_PI_2)
        return;
    long double cos_fi = cos(fi);
    if (r1 != nullptr)
        *r1 = this->a / cos_fi - this->l;
    if (r2 != nullptr)
        *r2 = this->a / cos_fi + this->l;
    return;
}

void ConchoidNicomed::returnR(double fi, double &r1, double &r2) const
{
    if (fi == M_PI_2)
        return;
    long double cos_fi = cos(fi);
    r1 = this->a / cos_fi - this->l;
    r2 = this->a / cos_fi + this->l;
    return;
}

void ConchoidNicomed::returnCurvRads(double *r_A, double *r_C, double *r_O) const
{
    if (r_A != nullptr)
        *r_A = (l + a) * (l + a) / l;
    if (r_C != nullptr)
        *r_C = (l - a) * (l - a) / l;
    if (r_O != nullptr)
        *r_O = l * sqrt(l * l - a * a) / 2 * a;
    return;
}

void ConchoidNicomed::returnCurvRads(double &r_A, double &r_C, double &r_O) const
{
    r_A = (l + a) * (l + a) / l;
    r_C = (l - a) * (l - a) / l;
    r_O = l * sqrt(l * l - a * a) / 2 * a;
    return;
}

double ConchoidNicomed::returnArea(double *area) const
{
    if (fabs(this->l) <= fabs(this->a))
    {
        if (area != nullptr)
            *area = 0;
        return 0;
    }
    double s = a * sqrt(l*l - a*a) - 2 * a * l * log((l + sqrt(l*l - a*a)) / a) + l*l * acos(a / l);
    if (area != nullptr)
        *area = s;
    return s;
}

double ConchoidNicomed::returnArea(double &area) const
{
    if (fabs(this->l) <= fabs(this->a))
    {
        area = 0;
        return 0;
    }
    double s = a * sqrt(l*l - a*a) - 2 * a * l * log((l + sqrt(l*l - a*a)) / a) + l*l * acos(a / l);
    area = s;
    return s;
}

void ConchoidNicomed::returnIP(double *x1, double *x2, double *x3, double *x4) const
{
    if (x1 == nullptr || x2 == nullptr || x3 == nullptr || x4 == nullptr)
        return;
    if (l == a)
    {
        *x1 = a * sqrt(3);
        *x2 = *x1;
        *x3 = *x4 = sqrt(-1);
    }
    if (l > a)
    {
        *x1 = a*a / pow(fabs(-a*a*a + sqrt(fabs(a*a*l*l*l*l - 2*a*a*a*a*l*l)) + a*l*l), 1 / 3.) +
            pow(fabs(-a*a*a + sqrt(fabs(a*a*l*l*l*l - 2*a*a*a*a*l*l)) + a*l*l), 1 / 3.);
        *x2 = *x1;
    }
    if (l < a)
    {
        *x1 = *x2 = 1.38 * a;
        *x3 = *x4 = 0.57 * a;
    }
    return;
}

void ConchoidNicomed::returnIP(double &x1, double &x2, double &x3, double &x4) const
{
    if (l == a)
    {
        x1 = a * sqrt(3);
        x2 = x1;
        x3 = x4 = sqrt(-1);
    }
    if (l > a)
    {
        x1 = a*a / pow(fabs(-a*a*a + sqrt(fabs(a*a*l*l*l*l - 2*a*a*a*a*l*l)) + a*l*l), 1 / 3.) +
            pow(fabs(-a*a*a + sqrt(fabs(a*a*l*l*l*l - 2*a*a*a*a*l*l)) + a*l*l), 1 / 3.);
        x2 = x1;
    }
    if (l < a)
    {
        x1 = x2 = 1.38 * a;
        x3 = x4 = 0.57 * a;
    }
    return;
}

//.
//????????????????????????
//????????????????????????
//????????????????????????
//????????????????????????
//????????????????????????
//????????????????????????
//????????????????????????
//????????????????????????
//????????????????????????
//????????????????????????
//????????????????????????
//????????????????????????
//????????????????????????
//????????????????????????
//????????????????????????
//????????????????????????

void returnIP_old(double *x1, double *x2)
{
    double a = 0, l = 0;
    double x = a;
    while (true)
    {
        if (fabs(-l*l * (2*a*a*a - 3 * a*a * x - 2 * a*l*l + x*x*x) /
                pow((a - x) * (a - x), 3 / 2.) * pow(a*a - 2*a*x - l*l + x*x, 3 / 2.)) <= 0.0001)
        {
            //cout << "y: " << x * sqrt(fabs(a * a - 2 * a * x - l * l + x * x)) / sqrt((a - x) * (a - x));
            //cout << "\nx: " << x;
            *x1 = x;
            break;
        }
        x += 0.0001;
    }
    if (fabs(l) > fabs(a))
    {
        x = 0;
        while (true)
        {
            if (fabs(-l*l * (2*a*a*a - 3 * a*a * x - 2 * a*l*l + x*x*x) /
                    pow((a - x) * (a - x), 3 / 2.) * pow(a*a - 2*a*x - l*l + x*x, 3 / 2.)) <= 0.0001)
            {
                //cout << "y: " << x * sqrt(fabs(a * a - 2 * a * x - l * l + x * x)) / sqrt((a - x) * (a - x));
                //cout << "\nx: " << x;
                *x2 = x;
                break;
            }
            x -= 0.0001;
        }
    }
    else
    {
        x = 0;
        while (true)
        {
            if (fabs(-l*l * (2*a*a*a - 3 * a*a * x - 2 * a*l*l + x*x*x) /
                    pow((a - x) * (a - x), 3 / 2.) * pow(a*a - 2*a*x - l*l + x*x, 3 / 2.)) <= 0.0001)
            {
                //cout << "y: " << x * sqrt(fabs(a * a - 2 * a * x - l * l + x * x)) / sqrt((a - x) * (a - x));
                //cout << "\nx: " << x;
                *x2 = x;
                break;
            }
            x += 0.0001;
        }
    }
}

int bin_search(int *a, int n, int x)
{
    int l = 0;
    int r = n - 1;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (a[m] == x)
            return m;
        if (a[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
}

void returnY_old(double x, double eps, double *y1, double *y2)
{
    double a = 0; //temp
    double l = 0;
    if (y1 == nullptr || y2 == nullptr)
        return;
    if (a == 0)
    {
        *y1 = 0;
        *y2 = 0;
        return;
    }
    double s = 0;
    x = fabs(x);
    while (true)
    {
        if (fabs(x - (1 - l / sqrt(a * a + s * s)) * s) <= eps)
        {
            //cout << s << "\n";
            *y1 = -(1 - l / sqrt(a * a + s * s)) * a;
            //cout << "y1: " << y1 << "\n";
            break;
        }
        s += eps;
    }
    s = *y1;
    *y2 = -(1 + l / sqrt(a * a + s * s)) * a;
    //cout << "y2: " << *y2 << "\n";
    return;
    /*//    while (true)
    //    {
    //        while (true)
    //        {
    //            if (fabs(fake_x - (1 - this->l / sqrt(this->a * this->a + s * s)) * s) < 0.001)
    //            {
    //                cout << s << "\n";
    //                cout << "y1: " << y1;
    //                break;
    //            }
    //            s += 0.0001;
    //        }
    //        if ()
    //        {
    //            y2 = (1 + this->l / sqrt(this->a * this->a + s * s)) * this->a;
    //            cout << "y2: " << y2 << "\n";
    //            break;
    //        }
    //    }
    //    while (l <= r)
    //    {
    //        s = (l + r) / 2;
    //        if (fabs(x - (1 + l / sqrt(this->a * this->a + s * s)) * s) < 0.01)
    //        {
    //            double y1 = (1 + l / sqrt(this->a * this->a + s * s)) * this->a;
    //            double y2 = (1 - l / sqrt(this->a * this->a + s * s)) * this->a;
    //            cout << "y1: " << y1 << "\ny2: " << y2;
    //            return y1;
    //        }

    //    }*/
}



//    double t = 0;
//    double sq_a = this->a * this->a;
//    double x_dot = sq_a * this->l / pow(sq_a + t * t, 3 / 2.) + 1;
//    double x_dot_dot = -3 * sq_a * this->l * t / pow(sq_a + t * t, 5 / 2.);
//    double y_dot = -this->a * this->l * t / pow(sq_a + t * t, 3 / 2.);
//    double y_dot_dot = -this->a * this->l * (sq_a - 2 * t * t) / pow(sq_a + t * t, 5 / 2.);
//    if (r1 != nullptr)
//        *r1 = fabs(pow(pow(x_dot, 2) + pow(y_dot, 2), 3 / 2.) / x_dot * y_dot_dot - y_dot * x_dot_dot);
//    if (r2 != nullptr)
//        *r2 = fabs(x_dot * y_dot_dot - y_dot * x_dot_dot / pow(pow(x_dot, 2) + pow(y_dot, 2), 3 / 2.));
//    cout << *r1 << "\n" << *r2;
//    return;

//return -a/2 - 1/2 * sqrt(l*l - x*x + 1/3 * (a*a - l*l + x*x) +
//                    pow((108 * x*x * a*a*a*a + 108 * x*x*x*x * a*a - 108 * x*x * (a*a - l*l + x*x) * a*a + 2 * pow((a*a - l*l + x*x), 3) + sqrt(pow((108 * x*x * a*a*a*a + 108 * x*x*x*x * a*a - 108 * x*x * (a*a - l*l + x*x) * a*a + 2 * pow((a*a - l*l + x*x), 3)), 2) - 4 * pow((a*a - l*l + x*x), 6))), (1/3))
//                        /(3 * pow(2, 1/3)) + (pow(2, 1/3) * pow((a*a - l*l + x*x), 2))/(3 * pow((108 * x*x * a*a*a*a + 108 * x*x*x*x * a*a - 108 * x*x * (a*a - l*l + x*x) * a*a + 2 * pow((a*a - l*l + x*x), 3) + sqrt(pow((108 * x*x * a*a*a*a + 108 * x*x*x*x * a*a - 108 * x*x * (a*a - l*l + x*x) * a*a + 2 * pow((a*a - l*l + x*x), 3)), 2) - 4 * pow((a*a - l*l + x*x),6))), (1/3))))
//    + 1/2 * sqrt(a*a + l*l - x*x + 1/3 * (-a*a + l*l - x*x) - pow((108 * x*x * a*a*a*a + 108 * x*x*x*x * a*a - 108 * x*x * (a*a - l*l + x*x) * a*a + 2 * pow((a*a - l*l + x*x), 3) + sqrt(pow(108 * x*x * a*a*a*a + 108 * x*x*x*x * a*a - 108 * x*x * (a*a - l*l + x*x) * a*a + 2 * (pow((a*a - l*l + x*x), 3)), 2) - 4 * pow((a*a - l*l + x*x),6))), (1/3))
//              /(3 * pow(2, 1/3)) - (pow(2, 1/3) * pow((a*a - l*l + x*x), 2))/(3 * pow((108 * x*x * a*a*a*a + 108 * x*x*x*x * a*a - 108 * x*x * (a*a - l*l + x*x) * a*a + 2 * pow((a*a - l*l + x*x), 3) + sqrt((108 * x*x * a*a*a*a + 108 * x*x*x*x * a*a - 108 * x*x * (a*a - l*l + x*x) * a*a + 2 * pow(pow((a*a - l*l + x*x), 3), 2)) - 4 * pow((a*a - l*l + x*x),6))), (1/3)))
//          - (-8 * a*a*a - 16 * x*x * a + 8 * (a*a - l*l + x*x) * a)/(4 * sqrt(l*l - x*x + 1/3 * (a*a - l*l + x*x) + pow((108 * x*x * a*a*a*a + 108 * x*x*x*x * a*a - 108 * x*x * (a*a - l*l + x*x) * a*a + 2 * pow((a*a - l*l + x*x), 3) + sqrt(pow(108 * x*x * a*a*a*a + 108 * x*x*x*x * a*a - 108 * x*x * (a*a - l*l + x*x) * a*a + 2 * (pow((a*a - l*l + x*x), 3)), 2) - 4 * pow((a*a - l*l + x*x),6))), (1/3))
//                                                                                           /(3 * pow(2, 1/3)) + (pow(2, 1/3) * pow((a*a - l*l + x*x), 2))/(3 * pow((108 * x*x * a*a*a*a + 108 * x*x*x*x * a*a - 108 * x*x * (a*a - l*l + x*x) * a*a + 2 * pow((a*a - l*l + x*x), 3) + sqrt(pow(108 * x*x * a*a*a*a + 108 * x*x*x*x * a*a - 108 * x*x * (a*a - l*l + x*x) * a*a + 2 * (pow((a*a - l*l + x*x), 3)), 2) - 4 * pow((a*a - l*l + x*x),6))), (1/3))))));

//    double y = 0;
//    //double prev = l * l * y * y - ((x * x + y * y) * (y + a) * (y + a));
//    double curr;
//    double l = 0., r = -100.;
//    while (fabs(l) <= fabs(r))
//    {
//        cout << "\nl: " << l << "r: " << r << "\n";
//        cout << (y = (l + r) / 2.);
//        if (fabs(l * l * y * y - ((x * x + y * y) * (y + a) * (y + a))) < 0.001)
//        {
//            cout << "\n returned \n";
//            cout << l * l * y * y - ((x * x + y * y) * (y + a) * (y + a));
//            return y;
//        }
//        if (l * l * y * y - ((x * x + y * y) * (y + a) * (y + a)) > 0.001)
//            l = y + 0.001;
//        else if (l * l * y * y - ((x * x + y * y) * (y + a) * (y + a)) < -0.001)
//            r = y - 0.001;
//    }
//    return 228;
//    while (true)
//    {
//        if (fabs(l * l * y * y - ((x * x + y * y) * (y + a) * (y + a))) < 0.001)
//            return y;
//        y -= 0.0001;
//    }
