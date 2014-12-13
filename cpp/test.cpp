#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include "Accelerate.h"


using std::cout;
using std::endl;
using std::setprecision;
using std::ofstream;
using std::stringstream;

#define PREC 2

// =============================================================================
void fill(float* buf, int size, float val)
{
    for (int i = 0; i < size; ++i) {
        buf[i] = val;
    }
}
// -----------------------------------------------------------------------------
void print(float*buf, int size, std::ostream& stream)
{
    stream << setprecision(PREC) << std::showpoint;
    for (int i = 0; i < size; ++i) {
        stream << buf[i] << endl;
    }
    stream << endl;
}

// =============================================================================
void test_vDSP_vclr1(const int size)
{
    ofstream output("results/clr");
    // output << "clr" << endl;
    float in[size];
    float val = 1.f;
    vDSP_vfill(&val, in, 1, size);
    print(in, size, output);
    vDSP_vclr(in, 1, size);
    print(in, size, output);
    output << endl;
}
// -----------------------------------------------------------------------------
void test_copy(const int size)
{
    ofstream output("results/copy");
    // output << "copy" << endl;
    float in[size];
    float val = 1.f;
    vDSP_vfill(&val, in, 1, size);
    print(in, size, output);
    output << endl;
    print(in, size, output);
    output << endl;
}
// -----------------------------------------------------------------------------
void test_vDSP_vadd(const int size, int stride=1)
{
    ofstream output("results/add");
    // output << "add" << endl;
    float in1[size];
    float val1 = 1.f;
    vDSP_vfill(&val1, in1, 1, size);
    print(in1, size, output);

    float in2[size];
    float val2 = -1.f;
    vDSP_vfill(&val2, in2, 1, size);
    print(in2, size, output);

    float out[size];
    vDSP_vadd(in1, stride, in2, stride, out, stride, size);
    print(out, size, output);

};
// -----------------------------------------------------------------------------
void test_vDSP_vsma(const int size, int stride=1)
{
    ofstream output("results/madd");
    // output << "madd" << endl;
    float in1[size];
    float val1 = 2.f;
    vDSP_vfill(&val1, in1, 1, size);
    print(in1, size, output);

    float in2[size];
    float val2 = -1.f;
    vDSP_vfill(&val2, in2, 1, size);
    print(in2, size, output);

    float mul = 0.5;

    float out[size];
    vDSP_vsma(in1, stride, &mul, in2, stride, out, stride, size);
    print(out, size, output);

};
// -----------------------------------------------------------------------------
void test_vDSP_vsmul(const int size, int stride=2)
{
    ofstream output("results/smu");
    // output << "smul";

    float in[size];
    float val = 1.f;
    vDSP_vfill(&val, in, 1, size);
    print(in, size, output);

    float mul = 0.f;

    float out[size];
    vDSP_vsmul(in, stride, &mul, out, stride, size);
    print(out, size, output);
    // output << "BAD RESULT?" << endl;
};
// -----------------------------------------------------------------------------
void test_vDSP_vfill(const int size, int stride=1)
{
    ofstream output("results/fill");
    // output << "fill";
    float out[size];
    float val = 1.f;

    vDSP_vfill(&val, out, stride, size);
    print(out, size, output);
};
// -----------------------------------------------------------------------------
void test_vDSP_vmul(const int size, int stride=1)
{
    ofstream output("results/mul");
    // output << "mul" << endl;
    float in1[size];
    fill(in1, size, 1.f);
    print(in1, size, output);

    float in2[size];
    float start = 0.f;
    float end = 1.f;
    float step = (end - start) / size;
    vDSP_vramp(&start, &step, in2, 1, size);
    print(in2, size, output);

    float out[size];

    vDSP_vmul(in1, stride, in2, stride, out, stride, size);
};
// -----------------------------------------------------------------------------
void test_vDSP_vclip(const int size, int stride=1)
{
    ofstream output("results/clip");
    // output << "clip" << endl;
    float in[size];
    for (int i = 0; i < size; ++i) {
        in[i] = 2 * sin(M_PI * 2 * 440 * i / 44100);
    }
    print(in, size, output);

    float min = -1.f;
    float max =  1.f;
    float out[size];
    vDSP_vclip(in, stride, &min, &max, out, stride, size);
    print(out, size, output);
};
// -----------------------------------------------------------------------------
void test_vDSP_vramp(const int size, int stride=1) {
    ofstream output("results/ramp");
    // output << "ramp" << endl;

    float start = 0.f;
    float end = 1.f;
    float step = (end - start) / size;
    float out[size];

    vDSP_vramp(&start, &step, out, stride, size);
    print(out, size, output);
};
// -----------------------------------------------------------------------------
void test_vDSP_meanv(const int size, int stride=1)
{
    ofstream output("results/mean");
    // output << "mean" << endl;

    float in[size];
    float start = 0.f;
    float end = 1.f;
    float step = (end - start) / size;
    vDSP_vramp(&start, &step, in, 1, size);
    print(in, size, output);

    float out;
    vDSP_meanv(in, stride, &out, size);
    output << out << endl;
};
// =============================================================================
int main(int argc, char const *argv[])
{
    test_vDSP_vfill(128);
    test_vDSP_vclr1(128);
    test_copy(128);
    test_vDSP_vadd(128);
    test_vDSP_vsma(128);
    test_vDSP_vsmul(128);
    test_vDSP_vclip(128);
    test_vDSP_vramp(128);
    test_vDSP_meanv(128);
    test_vDSP_vmul(128);

    return 0;
}