#include <iostream>
#include <iomanip>
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
    fill(in, size, 1.f);
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
    fill(in, size, 1.f);
    print(in, size);
    print(in, size);
}

void test_vDSP_vadd(const int size, int stride=1)
{
    cout << "add" << endl;
    float in1[size];
    fill(in1, size, 1.f);
    print(in1, size);

    float in2[size];
    fill(in2, size, -1.f);
    print(in2, size);

    float out[size];
    vDSP_vadd(in1, stride, in2, stride, out, stride, size);
    print(out, size);

};
void test_vDSP_vsma() { };
void test_vDSP_meanv() { };
void test_vDSP_vsmul() { };
void test_vDSP_vclip() { };
void test_vDSP_vramp() { };
void test_vDSP_vmul() { };
void test_vDSP_vfill() { };


int main(int argc, char const *argv[])
{
    // test_vDSP_vclr1(64);
    // test_copy(10);

    test_vDSP_vadd(10);
    // vDSP_vadd(audio + audioOffset, 1, scratch, 1, audio + audioOffset, 1, fadeInTime);
    // vDSP_vsma(scratch, 1, &((*i)->multL), audio + audioOffset, 2, audio + audioOffset, 2, fadeInTime);
    // vDSP_meanv(ampScaleBuffer, 1, &smoothedAmpScale, ampScaleBufferCount);
    // vDSP_vsmul(audio, 1, &smoothedAmpScale, audio, 1, bufferSize * channelMode);
    // vDSP_vclip(audio, 1, &lowclip, &highclip, audio, 1, bufferSize * channelMode);
    // vDSP_vramp(&foStart, &foStep, scratch, 1, channelMode * bufferSize);
    // vDSP_vmul(scratch, 1, audio, 1, audio, 1, channelMode * bufferSize);
    // vDSP_vfill(&ampScale, ampScaleBuffer, 1, ampScaleBufferCount);

    return 0;
}