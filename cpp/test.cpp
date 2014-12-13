#include <iostream>
#include "Accelerate.h"

using std::cout;
using std::endl;

void fill(float* buf, int size, float val)
{
    for (int i = 0; i < size; ++i) {
        buf[i] = val;
    }
}

bool test_vDSP_vclr1(const int size) {
    float in[size];
    fill(in, size, 1.0);

    vDSP_vclr1(in, 1, size);

    return false;
}

bool test_vDSP_vadd() {  return false; };
bool test_vDSP_vsma() { return false; };
bool test_vDSP_meanv() { return false; };
bool test_vDSP_vsmul() { return false; };
bool test_vDSP_vclip() { return false; };
bool test_vDSP_vramp() { return false; };
bool test_vDSP_vmul() { return false; };
bool test_vDSP_vfill() { return false; };


int main(int argc, char const *argv[])
{
    test_vDSP_vclr1(64);
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