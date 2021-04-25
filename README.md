# Interactive Light System Design Based On Simple Gesture Recognition 

![LOGO](https://github.com/actbee/Interactive-Light-System-Design-Based-On-Simple-Gesture-Recognition-/blob/master/images/pixel.jpg?raw=true)

## Introduction

This is a project I made based on openFrameswork, an amazing creative coding frameworks. 
The project is an interactive light system with an arcade outlook. With Kinect V2 it can recognise simple gesture and give output images with
a style of pixel culture or a classic SNAKE game interactively.

![PIXEL](https://github.com/actbee/Interactive-Light-System-Design-Based-On-Simple-Gesture-Recognition-/blob/master/images/chosen/1.png?raw=true)

## System

In this system, there is a Kinect placed on the Arcade. So it can collect the person's real-time skeleton data (with its depth information) and tell the laptop.
The laptop computes the image output result through the codes and give the feedback to the microprocessor, which controls on and off of every single LED.
Finally the person notice the interactive result and do the next step, the process iterates again.


![system](https://github.com/actbee/Interactive-Light-System-Design-Based-On-Simple-Gesture-Recognition-/blob/master/images/system.png?raw=true)


According to the distance between the person and the Arcade, I devide two areas, A and B. In area A people can play games and in area B there are some random 
animes which can be interacted with people. The depth data of the real-time skeleton data can tell the system whether the person is in area A or area B. Some simple
but natural human gestures are chosen to interact and the following image shows all of them.

![gesture](https://github.com/actbee/Interactive-Light-System-Design-Based-On-Simple-Gesture-Recognition-/blob/master/images/gestures.png?raw=true)

For the consideration of safety, instead of using high power strong light LED, I chose the low power LED and by paralleling some of them together and let the light
passes throug some specific meterials placed beyond to provid pixel light well. The principle of producing those beautiful pixel lights is shown in the 
following image. The visual effect is strongly connected with the pixel (hole) width, the light-passing material choosed, the sickness of this material 
and the distance between the material and the LED light. I have tested multiple possible materials in multiple distances to get the best visual result.

![principle](https://github.com/actbee/Interactive-Light-System-Design-Based-On-Simple-Gesture-Recognition-/blob/master/images/led.png?raw=true)

Here in order to low down the complexity of the circut design, I chose a red and a blue LED light, both in single color. When the blue and red LED light turn on
together we can see the purple color, which is an obvious result thourgh the principle of Color Mixing(also this is how the main idea of LOGO comes from). So by this
mean I can control in total 4 status of each LED light(red, blue, purple and off) and use them to get some meaningful images.

![testimg](https://github.com/actbee/Interactive-Light-System-Design-Based-On-Simple-Gesture-Recognition-/blob/master/images/test.png?raw=true)

Finally all of these circuts are put all together in the hardware. The following image describes the strutre of the hardware.
The control board gets the information from the laptop and controls the LED circuit board. Lights from small LED lights pass through the ABS skeleton to get together, 
forming the pixel light. Finally the pixel light passes through the transparent PC to get the final visual result.

![hardware](https://github.com/actbee/Interactive-Light-System-Design-Based-On-Simple-Gesture-Recognition-/blob/master/images/hardware.png?raw=true)

## Meaning

Since the total size of pixels is quite small(only 15x10), it is a great challenge to give a meaningful output. Inspired by the Pixel Culture, I decide to present 
something in the past. So I choose a classic SNAKE game, some pixel charachters in some games, and a modified GAME OF LIFE to present.

Using a whole new way to interactive with the past things, please try to consider the relationship between the past and the future. If it is possible to bring the 
old things reborn by the new technologies? And feel the consistant humanism thoughts under the fast growing technologies.

Besides these kinds of art-guided thinking, this project can be expanded to help the old practing their body, help the physical injured patients to get recovery or 
teach the young kids. Many potential situations need to be discussed.

## How to run

Please make sure you have installed the basic Kinect V2, OpenCV and openFrameswork environments on WIN before running this. The IDE I used in this project is VS2017. 
You can find all of the core codes under the 2/2/sec/file. In the KINECT file there are some codes I wrote to test the function of Kinect V2. You can find the design
report (in Chinese) in the PPT file.

## Others

You can find the video of this project from this: [BiliBili](https://www.bilibili.com/video/BV1x54y1Q7mP ) 
and this [Youtube](https://www.youtube.com/watch?v=vJQ7U_tFxb0 ) 

<iframe src="//player.bilibili.com/player.html?aid=840943071&bvid=BV1x54y1Q7mP&cid=199270892&page=1" scrolling="no" border="0" frameborder="no" framespacing="0" allowfullscreen="true"> </iframe>  

This project was exhibited on the [Aisan New Generation Design Exhibition(2020)](http://www.iden.cn/home/active.NewYouzhan/workinfo?id=6761).

You can find the paper of this project on [arXiv](https://arxiv.org/abs/2010.10180).

![2](https://github.com/actbee/Interactive-Light-System-Design-Based-On-Simple-Gesture-Recognition-/blob/master/images/chosen/2.png?raw=true)

![3](https://github.com/actbee/Interactive-Light-System-Design-Based-On-Simple-Gesture-Recognition-/blob/master/images/chosen/3.jpg?raw=true)
