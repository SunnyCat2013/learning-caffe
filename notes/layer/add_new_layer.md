# 自己动手添加一个 layer
# 计划
- 先把 cnn layer 研究一下再回来写自己的 layer
- 写一个测试，把输入数据放大再输出。

# 添加新 layer 的过程
添加一个简单的 layer 可以参考 https://github.com/BVLC/caffe/wiki/Simple-Example:-Sin-Layer。
几个主要的过程如下：
1. 添加 `include/caffe/layers/your_layer.hpp`
2. 添加 `src/caffe/layers/your_layer.cpp`
3. 添加 `test/test_your_layer.cpp`
4. 回到 build 文件夹 `cmake -DCPU_ONLY=1 .. && make -j 4 && make test && make runtest && test/test.testbin --gtest_filter='*YourClassName*'`

# 参考
https://github.com/BVLC/caffe/wiki/Simple-Example:-Sin-Layer
https://blog.csdn.net/chenriwei2/article/details/46432727
