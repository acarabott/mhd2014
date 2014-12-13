var dsp_scalar = {
    clr: function(out, step, size) {
      for (var i = 0; i < size; i += step) {
        out[i] = 0;
      }
    },

    copy: function(buf, out, size) {
      for (var i = 0; i < size; i++) {
        out[i] = buf[i];
      };
    },

    // div: function(buf, bufStep, div, out, outStep, size) {
    //     for (var i = 0; i < size; i++) {
    //         out[i * outStep] = buf[i * buf1Step] / div;
    //     }
    // },

    ramp: function(start, rampStep, out, step, size) {
        var val = start;

        for (var i = 0; i < size; i++) {
            out[i * step] = val;
            val += rampStep;
        }
    },

    // rampmul: function(buf, bufStep, rampStart, rampStep, out, outStep, size) {
    //   for (var i = 0; i < size; i++) {
    //     out[i * outStep] = rampStart * buf[i * bufStep];
    //     rampStart += rampStep;
    //   }
    // },

    mul: function(buf1, buf1Step, buf2, buf2step, out, outStep, size) {
        for (var i = 0; i < size; i++) {
            out[i * outStep] = buf1[i * buf1Step] * buf2[i * buf2step];
        }
    },

    add: function(buf1, buf1Step, buf2, buf2step, out, outStep, size) {
        for (var i = 0; i < length; i++) {
            out[i * outStep] = buf1[i * buf1Step] + buf2[i * buf2step];
        }
    },

    mulAdd: function(buf1, buf1Step, mul, buf2, buf2step, out, outStep, size) {
        for (var i = 0; i < size; i++) {
            out[i * outStep] = buf1[i * buf1Step] * mul + buf2[i * buf2step];
        }
    },

    mean: function(buf, bufStep, out, size) {
        var sum = 0;

        for (var i = 0; i < size; i++) {
            sum += buf[i * bufStep];
        }

        out[0] = sum / size;
    },

    fill: function(val, out, outStep, size) {
        for (var i = 0; i < size; i++) {
            out[i * outStep] = val;
        }
    },

    // smul: function(buf, bufStep, mul, out, outStep, size) {
    //     for (var i = 0; i < size; i++) {
    //         out[i * outStep] = buf[i * bufStep] * mul;
    //     }
    // },

    clip: function(buf, bufStep, min, max, out, outStep, size) {
        for (var i = 0; i < size; i++) {
            if (buf[i * bufStep] < min) {
                out[i * outStep] = min;
            } else if (buf[i * bufStep] > max) {
                out[i * outStep] = max;
            } else {
                out[i * outStep] = buf[i * bufStep];
            }
        }
    }
};

var dsp_simd = {
    clr: function(out, step, size) {
      if (step != 1) throw "not implemented";
      for (var i = 0; i < size; i += step * 4) {
        var vf = SIMD.float32x4(0,0,0,0);
        out[i]   = vf.x;
        out[i+1] = vf.y;
        out[i+2] = vf.z;
        out[i+3] = vf.w;
      }
    },

    copy: function(buf, out, size) {
      for (var i = 0; i < size; i+=4) {
        var vf = SIMD.float32x4( buf[i+0], buf[i+1], buf[i+2], buf[i+3])
        out[i]   = vf.x;
        out[i+1] = vf.y;
        out[i+2] = vf.z;
        out[i+3] = vf.w;
      };
    },

    // div: function(buf, bufStep, div, out, outStep, size) {
    //     for (var i = 0; i < size; i++) {
    //         out[i * outStep] = buf[i * buf1Step] / div;
    //     }
    // },

    ramp: function(start, rampStep, out, step, size) {
        var val = start;

        for (var i = 0; i < size; i++) {
            out[i * step] = val;
            val += rampStep;
        }
    },

    // rampmul: function(buf, bufStep, rampStart, rampStep, out, outStep, size) {
    //   for (var i = 0; i < size; i++) {
    //     out[i * outStep] = rampStart * buf[i * bufStep];
    //     rampStart += rampStep;
    //   }
    // },

    mul: function(buf1, buf1Step, buf2, buf2step, out, outStep, size) {
        for (var i = 0; i < size; i++) {
            out[i * outStep] = buf1[i * buf1Step] * buf2[i * buf2step];
        }
    },

    add: function(buf1, buf1Step, buf2, buf2step, out, outStep, size) {
        for (var i = 0; i < length; i++) {
            out[i * outStep] = buf1[i * buf1Step] + buf2[i * buf2step];
        }
    },

    mulAdd: function(buf1, buf1Step, mul, buf2, buf2step, out, outStep, size) {
        for (var i = 0; i < size; i++) {
            out[i * outStep] = buf1[i * buf1Step] * mul + buf2[i * buf2step];
        }
    },

    mean: function(buf, bufStep, out, size) {
        var sum = 0;

        for (var i = 0; i < size; i++) {
            sum += buf[i * bufStep];
        }

        out[0] = sum / size;
    },

    fill: function(val, out, outStep, size) {
        for (var i = 0; i < size; i++) {
            out[i * outStep] = val;
        }
    },

    // smul: function(buf, bufStep, mul, out, outStep, size) {
    //     for (var i = 0; i < size; i++) {
    //         out[i * outStep] = buf[i * bufStep] * mul;
    //     }
    // },

    clip: function(buf, bufStep, min, max, out, outStep, size) {
        for (var i = 0; i < size; i++) {
            if (buf[i * bufStep] < min) {
                out[i * outStep] = min;
            } else if (buf[i * bufStep] > max) {
                out[i * outStep] = max;
            } else {
                out[i * outStep] = buf[i * bufStep];
            }
        }
    }
};

var dsp = window.SIMD && !window.DISABLE_SIMD ? dsp_simd : dsp_scalar;
