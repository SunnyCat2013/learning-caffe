#include <algorithm>
#include <vector>

#include "gtest/gtest.h"

#include "caffe/blob.hpp"
#include "caffe/common.hpp"
#include "caffe/filler.hpp"
#include "caffe/layers/cslzy_sin_layer.hpp"

#include "caffe/test/test_caffe_main.hpp"
#include "caffe/test/test_gradient_check_util.hpp"

// cmake -DCPU_ONLY=1 .. && make -j 4 && make test && make runtest && test/test.testbin --gtest_filter='*TanH*'

namespace caffe {
    template <typename TypeParam>
    class CslzySinLayerTest : public MultiDeviceTest<TypeParam> {
        typedef typename TypeParam::Dtype Dtype;
    protected:
        CslzySinLayerTest()
            : blob_bottom_(new Blob<Dtype>(2, 3, 4, 5)),
              blob_top_(new Blob<Dtype>())
        {
            Caffe::set_random_seed(2018);
            FillerParameter filler_param;
            blob_bottom_vec_.push_back(blob_bottom_);
            blob_top_vec_.push_back(blob_top_);
        }
        virtual ~CslzySinLayerTest() { delete blob_bottom_; delete blob_top_; }

        void TestForward(Dtype filler_std)
        {
            FillerParameter filler_param;
            filler_param.set_std(filler_std);
            GaussianFiller<Dtype> filler(filler_param);
            filler.Fill(this->blob_bottom_);

            LayerParameter layer_param;
            CslzySinLayer<Dtype> layer(layer_param);
            layer.SetUp(this->blob_bottom_vec_, this->blob_top_vec_);
            layer.Forward(this->blob_bottom_vec_, this->blob_top_vec_);
            // Now, check values
            const Dtype* bottom_data = this->blob_bottom_->cpu_data();
            const Dtype* top_data = this->blob_top_->cpu_data();
            const Dtype min_precision = 1e-5;
            for (int i = 0; i < this->blob_bottom_->count(); ++i) {
              Dtype expected_value = sin(bottom_data[i]);
              Dtype precision = std::max(
                Dtype(std::abs(expected_value * Dtype(1e-4))), min_precision);
              EXPECT_NEAR(expected_value, top_data[i], precision);
            }
          }

          void TestBackward(Dtype filler_std)
          {
              FillerParameter filler_param;
              filler_param.set_std(filler_std);
              GaussianFiller<Dtype> filler(filler_param);
              filler.Fill(this->blob_bottom_);

              LayerParameter layer_param;
              CslzySinLayer<Dtype> layer(layer_param);
              GradientChecker<Dtype> checker(1e-4, 1e-2, 1701);
              checker.CheckGradientEltwise(&layer, this->blob_bottom_vec_,
                  this->blob_top_vec_);
            }

         Blob<Dtype>* const blob_bottom_;
         Blob<Dtype>* const blob_top_;
         vector<Blob<Dtype>*> blob_bottom_vec_;
         vector<Blob<Dtype>*> blob_top_vec_;
        };
        TYPED_TEST_CASE(CslzySinLayerTest, TestDtypesAndDevices);
        // 第二个参数是用来区分不同测试的分类的。。可以不用事先定义。。
        TYPED_TEST(CslzySinLayerTest, TestCslzySin) {
          this->TestForward(1.0);
          this->TestForward(1.5);
        }
        TYPED_TEST(CslzySinLayerTest, TestCslzySinGradient) {
          this->TestBackward(1.0);
        }


} // namespace caffe
