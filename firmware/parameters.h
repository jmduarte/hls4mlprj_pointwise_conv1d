#ifndef PARAMETERS_H_
#define PARAMETERS_H_

#include "ap_fixed.h"
#include "ap_int.h"

#include "nnet_utils/nnet_code_gen.h"
#include "nnet_utils/nnet_helpers.h"
// hls-fpga-machine-learning insert includes
#include "nnet_utils/nnet_conv1d.h"
#include "nnet_utils/nnet_sepconv1d_stream.h"

// hls-fpga-machine-learning insert weights
#include "weights/w4.h"
#include "weights/b4.h"

// hls-fpga-machine-learning insert layer-config
// conv1d
struct config4_mult : nnet::dense_config {
    static const unsigned n_in = 3;
    static const unsigned n_out = 10;
    static const unsigned reuse_factor = 4;
    static const unsigned strategy = nnet::latency;
    typedef model_default_t accum_t;
    typedef conv1d_bias_t bias_t;
    typedef conv1d_weight_t weight_t;
    template<class x_T, class y_T>
    using product = nnet::product::mult<x_T, y_T>;
};

struct config4 : nnet::conv1d_config {
    static const unsigned pad_left = 0;
    static const unsigned pad_right = 0;
    static const unsigned in_width = 4;
    static const unsigned n_chan = 3;
    static const unsigned filt_width = 1;
    static const unsigned kernel_size = filt_width;
    static const unsigned n_filt = 10;
    static const unsigned stride_width = 1;
    static const unsigned dilation = 1;
    static const unsigned out_width = 4;
    static const unsigned reuse_factor = 4;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    static const unsigned strategy = nnet::latency;
    static const nnet::conv_implementation implementation = nnet::conv_implementation::pointwise;
    static const unsigned min_width = 4;
    static const ap_uint<filt_width> pixels[min_width];
    static const unsigned n_partitions = 4;
    static const unsigned n_pixels = out_width / n_partitions;
    template<class data_T, class CONFIG_T>
    using fill_buffer = nnet::fill_buffer_4<data_T, CONFIG_T>;
    typedef model_default_t accum_t;
    typedef conv1d_bias_t bias_t;
    typedef conv1d_weight_t weight_t;
    typedef config4_mult mult_config;
    template<unsigned K, unsigned S, unsigned W>
    using scale_index = nnet::scale_index_unscaled<K, S, W>;
};
const ap_uint<config4::filt_width> config4::pixels[] = {0};


#endif
