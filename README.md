# Interactive Light System Design Based On Simple Gesture Recognition 

![LOGO](https://github.com/actbee/Interactive-Light-System-Design-Based-On-Simple-Gesture-Recognition-/blob/master/images/pixel.jpg?raw=true)

## Introduction

This is a project I made based on Openframeworks, an amazing creative coding frameworks. 
The project is an interative light system with an arcade outlook. With Kinect V2 it can recognise simple gesture and give output images with
a style of pixel culture or a classic SNAKE game interactively.

![PIXEL](https://github.com/actbee/Interactive-Light-System-Design-Based-On-Simple-Gesture-Recognition-/blob/master/images/chosen/1.png?raw=true)

## System

In this system, there is a Kinect placed on the Arcade. So it can collect the person's real-time skeleton data (with its depth information) and tell the laptop.
The laptop computes the image output result through the codes and give the feedback to the microprocessor, which controls on and off of every single LED.
Finally the person notice the interactive result and do the next step, the process iterates again.


![system](https://github.com/actbee/Interactive-Light-System-Design-Based-On-Simple-Gesture-Recognition-/blob/master/images/system.png?raw=true)


According to the distance between the person and the Arcade, I devide two areas, A and B. In area A people can play games and in area B there are some randomed 
animes which can be interacted with people. The depth data of the real-time skeleton data can tell the system whether the person is in area A or area B.

Here in order to low down the complexity of the circut design, I choose a red and a blue LED light, both in single color. When the blue and red LED light turn on
together we can see the purple color, which is an obvious result thourgh the principle of Color Mixing(also this is how the main idea of LOGO comes from). So by this
means I can control in total 4 status of each LED light(red, blue, purple and off) and use them to get some meaningful images.

![test](https://github.com/actbee/Interactive-Light-System-Design-Based-On-Simple-Gesture-Recognition-/blob/master/images/test.png?raw=true）

## Meaning

Since the total size of pixels is quite small(only 15x10), it is a great challenge to give a meaningful output. Inspired by the Pixel Culture, I decide to present 
something in the past. 

Using a whole new way to interactive with the past things, please try to consider the relationship between the past and the future. If it is possible to bring the 
old things reborn by the new technologies? And feel the consistant humanism thoughts under the fast growing technologies.

## How to run

Please make sure you have installed the basic Kinect V2, OpenCV and Openframeworks environments on WIN before running this. The IDE I used in this project is VS2017. 
You can find all of the core codes under the 2/2/sec/file. In the KINECT file there are some codes I wrote to test the function of Kinect V2. You can find the design
report (in Chinese) in the PPT file.

## Others

You can find the video of this project from this: [BiliBili](https://www.bilibili.com/video/BV1x54y1Q7mP ) 
and this [Youtube](https://www.youtube.com/watch?v=vJQ7U_tFxb0 ) 

This project was exhibited on the [Aisan New Generation Design Exhibition(2020)](http://www.iden.cn/home/active.NewYouzhan/workinfo?id=6761).

![2]((https://github.com/actbee/Interactive-Light-System-Design-Based-On-Simple-Gesture-Recognition-/blob/master/images/chosen/2.png?raw=true))

![3]((https://github.com/actbee/Interactive-Light-System-Design-Based-On-Simple-Gesture-Recognition-/blob/master/images/chosen/3.jpg?raw=true))
