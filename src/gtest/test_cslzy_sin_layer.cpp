#include <algorithm>
#include <vector>

#include "gtest/gtest.h"

#include "caffe/blob.hpp"
#include "caffe/common.hpp"
#include "caffe/filler.hpp"

#include "caffe/test/test_caffe_main.hpp"
#include "caffe/test/test_gradient_check_util.hpp"

#include "caffe/layers/cslzy_sin_layer.hpp"

namespace caffe {
    template CslzySinLayerTest : public MultiDeviceTest<TypeParam> {
        typedef typename TypeParam::Dtype Dtype;
    protected:
        CslzySinLayer()
            : blob_bottom_(new Blob<Dtype>(2, 3, 4, 5)),
              blob_top_(new Blob<Dtype>())
        {
            Caffe::set_random_seed(2018);
            FilterParameter filler_param;
            blob_bottom_vec_.push_back(blob_bottom_);
            blob_top_vec_.push_back(blob_top_);
        }
        virtual ~CslzySinLayerTest() { delete blob_bottom_; delete blob_top_; }
    }
} // namespace caffe
