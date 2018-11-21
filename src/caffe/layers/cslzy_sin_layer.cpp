// Sin neuron activation function layer.
// Adapted from TanH layer which was adapted from the ReLU layer code written by Yangqing Jia

#include <vector>

#include "caffe/layers/sin_layer.hpp"

namespace caffe {
    template <typename Dtype>
    void CslzySinLayer<Dtype>::Forward_cpu(const vector<Blob<Dtype>*>& bottom,
                                           const vector<Blob<Dtype>*>& top)
    {
        const Dtype* bottom_data = bottom[0]->cpu_data(); // 把输入数据变成一维数组。
        Dtype* top_data = top[0]->mutable_cpu_data();
        const int count = bottom[0]->count();
        for(int i = 0; i < count; ++i) {
            top_data[i] = sin(bottom_data[i]);
        }
    }

    template CslzySinLayer::Backward_cpu(const vector<Blob<Dtype>*>& top,
                                         const vector<bool>& propagate_down,
                                         const vector<Blob<Dtype>*>& bottom)
    {
        
    }
} // namespace caffe
