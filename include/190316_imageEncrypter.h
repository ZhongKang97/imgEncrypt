#pragma once
#ifndef _IMAGEENCRYPTER_H
#define _IMAGEENCRYPTER_H
#include<opencv2\opencv.hpp>
#include<iostream>
using namespace std;
class imageEncrypter
{
public:
	imageEncrypter();
	~imageEncrypter();
	cv::Mat encode(cv::Mat showImage, cv::Mat encryptImage,bool isColor=false);
private:

};

imageEncrypter::imageEncrypter()
{
}

imageEncrypter::~imageEncrypter()
{
}
#endif