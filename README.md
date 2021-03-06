# Learning codes and deep learning from Caffe
- [ ] 根据 http://caffe.berkeleyvision.org/tutorial/ 学习 caffe 对各种机器学习的算法的实现。
    - [x] Layers
    - [x] blobs
    - [ ] loss
    - [ ] solver

- [ ] 读论文，实现论文中新的结构
    - [x]  [添加新的 layer](https://github.com/SunnyCat2013/learning-caffe/blob/master/notes/layer/add_new_layer.md)

- [ ] 学习框架的使用
    - [ ] 训练和测试 mnist 数据集
      学习了一下怎么训练和测试模型，看了一下 lenet_train_test.prototxt 里面的参数
    - [ ] 学习 web_demo 的在线响应

# Run jupyter notebook in docker
1. 配置 docker port mapping，名称和共享文件夹
```
docker run -it -p 7000:7000 --rm --name test -v $(pwd):/caffe cslzy/learning-caffe
```
2. 启动 jupyter notebook
```
jupyter-notebook --no-browser --ip 0.0.0.0 --port=7000 --allow-root
```
3. 在本机上打开 http://localhost:7000/tree
4. 将 docker 里面运行 jupyter notebook 产生的 token 填到网页上。

# Docker image
docker image which is build by using codes from this repository.
```
docker pull cslzy/learning-caffe
```

# Docker
- [ ] screen
- [ ]

# Caffe

[![Build Status](https://travis-ci.org/BVLC/caffe.svg?branch=master)](https://travis-ci.org/BVLC/caffe)
[![License](https://img.shields.io/badge/license-BSD-blue.svg)](LICENSE)

Caffe is a deep learning framework made with expression, speed, and modularity in mind.
It is developed by Berkeley AI Research ([BAIR](http://bair.berkeley.edu))/The Berkeley Vision and Learning Center (BVLC) and community contributors.

Check out the [project site](http://caffe.berkeleyvision.org) for all the details like

- [DIY Deep Learning for Vision with Caffe](https://docs.google.com/presentation/d/1UeKXVgRvvxg9OUdh_UiC5G71UMscNPlvArsWER41PsU/edit#slide=id.p)
- [Tutorial Documentation](http://caffe.berkeleyvision.org/tutorial/)
- [BAIR reference models](http://caffe.berkeleyvision.org/model_zoo.html) and the [community model zoo](https://github.com/BVLC/caffe/wiki/Model-Zoo)
- [Installation instructions](http://caffe.berkeleyvision.org/installation.html)

and step-by-step examples.

[![Join the chat at https://gitter.im/BVLC/caffe](https://badges.gitter.im/Join%20Chat.svg)](https://gitter.im/BVLC/caffe?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge&utm_content=badge)

Please join the [caffe-users group](https://groups.google.com/forum/#!forum/caffe-users) or [gitter chat](https://gitter.im/BVLC/caffe) to ask questions and talk about methods and models.
Framework development discussions and thorough bug reports are collected on [Issues](https://github.com/BVLC/caffe/issues).

Happy brewing!

## License and Citation

Caffe is released under the [BSD 2-Clause license](https://github.com/BVLC/caffe/blob/master/LICENSE).
The BAIR/BVLC reference models are released for unrestricted use.

Please cite Caffe in your publications if it helps your research:

    @article{jia2014caffe,
      Author = {Jia, Yangqing and Shelhamer, Evan and Donahue, Jeff and Karayev, Sergey and Long, Jonathan and Girshick, Ross and Guadarrama, Sergio and Darrell, Trevor},
      Journal = {arXiv preprint arXiv:1408.5093},
      Title = {Caffe: Convolutional Architecture for Fast Feature Embedding},
      Year = {2014}
    }
