#ifndef DEFINES_H_
#define DEFINES_H_

#include "ap_fixed.h"
#include "ap_int.h"
#include "nnet_utils/nnet_types.h"
#include <cstddef>
#include <cstdio>

// hls-fpga-machine-learning insert numbers
#define N_INPUT_1_1 4
#define N_INPUT_2_1 3
#define N_OUTPUTS_4 4
#define N_FILT_4 10

// hls-fpga-machine-learning insert layer-precision
typedef ap_fixed<8,3> input_t;
typedef ap_fixed<8,3> model_default_t;
typedef ap_fixed<8,3> result_t;
typedef ap_fixed<8,3> conv1d_weight_t;
typedef ap_fixed<8,3> conv1d_bias_t;

#endif
