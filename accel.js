var dsp = {
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

    div: function(buf, bufStep, div, out, outStep, size) {
        for (var i = 0; i < size; i++) {
            out[i * outStep] = buf[i * buf1Step] / div;
        }
    },

    ramp: function(start, rampStep, out, step, size) {
        var val = start;

        for (var i = 0; i < size; i++) {
            out[i * step] = val;
            val += rampStep;
        }
    },

    rampmul: function(buf, bufStep, rampStart, rampStep, out, outStep, size) {
      for (var i = 0; i < size; i++) {
        out[i * outStep] = rampStart * buf[i * bufStep];
        rampStart += rampStep;
      }
    },

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

    smul: function(buf, bufStep, mul, out, outStep, size) {
        for (var i = 0; i < size; i++) {
            out[i * outStep] = buf[i * bufStep] * mul;
        }
    },

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
