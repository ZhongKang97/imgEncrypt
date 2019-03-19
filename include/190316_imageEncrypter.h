#ifndef _IMAGEENCRYPTER_H
#define _IMAGEENCRYPTER_H
#include<opencv2\opencv.hpp>
#include<opencv2\imgproc.hpp>
#include<opencv2\core.hpp>
#include<opencv2\highgui.hpp>
#include<iostream>
using namespace std;
using namespace cv;
class imageEncrypter
{
public:
	imageEncrypter();
	~imageEncrypter();
	void encrypt(cv::Mat showImage, cv::Mat encryptImage,Mat & outImg,bool isColor=false);
	void decode(cv::Mat encryptedImage,Mat &outImg,bool isColor=false);
private:
	void processSingleChannelPic(cv::Mat showImage1D, cv::Mat encryptImage1D,Mat &out);
	void decodeSingleChannelPic(cv::Mat encryptImage1D,Mat &outImg);
	int getEncryptValue(int first, int encryptValue);
	int getDecodeValue(int encryptedValue);
	int showImg_width, showImg_hight;
	int encryptImg_width, encryptImg_hight;
};
#endif
