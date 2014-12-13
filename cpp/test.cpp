#include <iostream>
#include <iomanip>
#include <cmath>
#include "Accelerate.h"

using std::cout;
using std::endl;
using std::setprecision;

#define PREC 2

// =============================================================================
void fill(float* buf, int size, float val)
{
    for (int i = 0; i < size; ++i) {
        buf[i] = val;
    }
}

void print(float*buf, int size)
{
    cout << setprecision(PREC) << std::showpoint;
    for (int i = 0; i < size; ++i) {
        cout << buf[i] << endl;
    }
    cout << endl;
}

// =============================================================================
void test_vDSP_vclr1(const int size)
{
    cout << "clr" << endl;
    float in[size];
    float val = 1.f;
    vDSP_vfill(&val, in, 1, size);
    print(in, size);
    vDSP_vclr(in, 1, size);
    print(in, size);
    cout << endl;
}
// -----------------------------------------------------------------------------
void test_copy(const int size)
{
    cout << "copy" << endl;
    float in[size];
    float val = 1.f;
    vDSP_vfill(&val, in, 1, size);
    print(in, size);
}
// -----------------------------------------------------------------------------
void test_vDSP_vadd(const int size, int stride=1)
{
    cout << "add" << endl;
    float in1[size];
    float val1 = 1.f;
    vDSP_vfill(&val1, in1, 1, size);
    print(in1, size);

    float in2[size];
    float val2 = -1.f;
    vDSP_vfill(&val2, in2, 1, size);
    print(in2, size);

    float out[size];
    vDSP_vadd(in1, stride, in2, stride, out, stride, size);
    print(out, size);

};
// -----------------------------------------------------------------------------
void test_vDSP_vsma(const int size, int stride=1)
{
    cout << "madd" << endl;
    float in1[size];
    float val1 = 2.f;
    vDSP_vfill(&val1, in1, 1, size);
    print(in1, size);

    float in2[size];
    float val2 = -1.f;
    vDSP_vfill(&val2, in2, 1, size);
    print(in2, size);

    float mul = 0.5;

    float out[size];
    vDSP_vsma(in1, stride, &mul, in2, stride, out, stride, size);
    print(out, size);

};
// -----------------------------------------------------------------------------
void test_vDSP_vsmul(const int size, int stride=2)
{
    cout << "smul";
    float in[size];
    float val = 1.f;
    vDSP_vfill(&val, in, 1, size);
    print(in, size);

    float mul = 0.f;

    float out[size];
    vDSP_vsmul(in, stride, &mul, out, stride, size);
    print(out, size);
    cout << "BAD RESULT?" << endl;
};
// -----------------------------------------------------------------------------
void test_vDSP_vfill(const int size, int stride=1)
{
    float out[size];
    float val = 1.f;

    vDSP_vfill(&val, out, stride, size);
    print(out, size);
};
// -----------------------------------------------------------------------------
// void test_vDSP_vmul(const int size, int stride=1)
// {
//     cout << "mul" << endl;
//     float in1[size];
//     fill(in1, size, 1);
//     print(in1, size);

//     float in2[size];
//     ramp(in2, size, 0.f, 1.f);
//     print(in2, size);

//     float out[size];

//     vDSP_vmul(in1, stride, in2, stride, out, stride, size);
// };


void test_vDSP_vclip(const int size, int stride=1)
{
    cout << "clip" << endl;
    float in[size];
    for (int i = 0; i < size; ++i) {
        in[i] = 2 * sin(M_PI * 2 * 440 * i / 44100);
    }
    print(in, size);

    float min = -1.f;
    float max =  1.f;
    float out[size];
    vDSP_vclip(in, stride, &min, &max, out, stride, size);
    print(out, size);
};

void test_vDSP_vramp(const int size, int stride=1) {
    cout << "ramp" << endl;

    float start = 0.f;
    float end = 1.f;
    float step = (end - start) / size;
    float out[size];

    vDSP_vramp(&start, &step, out, stride, size);
    print(out, size);
};


void test_vDSP_meanv(const int size) { };

int main(int argc, char const *argv[])
{
    // test_vDSP_vfill(10);
    // test_vDSP_vclr1(64);
    // test_copy(10);
    // test_vDSP_vadd(10);
    // test_vDSP_vsma(10);
    // test_vDSP_vsmul(10);
    // test_vDSP_vclip(128);
    test_vDSP_vramp(10);

    // vDSP_meanv(ampScaleBuffer, 1, &smoothedAmpScale, ampScaleBufferCount);
    // vDSP_vsmul(audio, 1, &smoothedAmpScale, audio, 1, bufferSize * channelMode);
    // vDSP_vclip(audio, 1, &lowclip, &highclip, audio, 1, bufferSize * channelMode);
    // vDSP_vramp(&foStart, &foStep, scratch, 1, channelMode * bufferSize);
    // vDSP_vmul(scratch, 1, audio, 1, audio, 1, channelMode * bufferSize);
    // vDSP_vfill(&ampScale, ampScaleBuffer, 1, ampScaleBufferCount);

    return 0;
}