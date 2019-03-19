#include"../include/190316_imageEncrypter.h"
imageEncrypter::imageEncrypter()
{
	showImg_hight = 0;
	showImg_width = 0;
	encryptImg_hight = 0;
	encryptImg_width = 0;
}

imageEncrypter::~imageEncrypter()
{
}
/*********************************/
//�������ƣ�getEncryptValue
//�������ã��õ����ܺ����ɫֵ ͼ�����Ϊ��CV_8UC1
//���������first����������ͼ�������ֵ encryptvalue����Ҫ���ص�ͼ�������ֵ
//��������ܺ������ֵ
//���ߣ�ZhongKang97
//�༭ʱ�䣺20190318
/*********************************/
int imageEncrypter::getEncryptValue(int first, int encryptValue)
{
	
	int out = 0;
	first = first >> 3;
	first = first << 3;
	encryptValue = encryptValue >> 5;
	out = first | encryptValue;
	out = static_cast<uchar>(out);
	return out;
}
/*********************************/
//�������ƣ�getDecodeValue
//�������ã��õ����ܵ���ɫֵ ͼ�����Ϊ��CV_8UC1
//���������encryptedValue�����ܺ������ֵ
//��������ܺ������ֵ
//���ߣ�ZhongKang97
//�༭ʱ�䣺20190318
/*********************************/
int imageEncrypter::getDecodeValue(int encryptedValue)
{
	return encryptedValue << 5;
}
/*********************************/
//�������ƣ�processSingleChannelPic
//�������ã��õ����ܺ�ĵ�ͨ��ͼ��
//���������showImage1D:��������ͼ����ϲ�ͼ�� encryptImage1D�����ܵ�ͼ��
//��������ܺ�ĵ�ͨ��ͼ
//���ߣ�ZhongKang97
//�༭ʱ�䣺20190318
/*********************************/
void imageEncrypter::processSingleChannelPic(cv::Mat showImage1D, cv::Mat encryptImage1D,Mat &out)
{
	cv::Mat outImage=Mat::zeros(showImage1D.size(),showImage1D.type()) ;
	size_t row, col;
	for ( row = 0; row < showImage1D.rows; row++)
	{
		uchar* data = outImage.ptr<uchar>(row);
		uchar*data_s = showImage1D.ptr<uchar>(row);
		uchar*data_e = encryptImage1D.ptr<uchar>(row);
		for ( col = 0; col < showImage1D.cols; col++)
		{
			data[col] = getEncryptValue(data_s[col], data_e[col]);
		}
	}
	
	out = outImage.clone();
} 
/*********************************/
//�������ƣ�processSingleChannelPic
//�������ã��õ����ܺ�ĵ�ͨ��ͼ��
//��������� encryptImage1D�����ܵ�ͼ���ͼ�� ��ͨ��
//��������ܺ�ĵ�ͨ��ͼ
//���ߣ�ZhongKang97
//�༭ʱ�䣺20190318
/*********************************/
void imageEncrypter::decodeSingleChannelPic(cv::Mat encryptImage1D,Mat &outImage)
{
	cv::Mat out = Mat::zeros(encryptImage1D.size(), encryptImage1D.type());
	size_t row, col;
	for (row = 0; row < encryptImage1D.rows; row++)
	{
		uchar* data = out.ptr<uchar>(row);
		uchar*data_e = encryptImage1D.ptr<uchar>(row);
		for (col = 0; col < encryptImage1D.cols; col++)
		{
			data[col] = getDecodeValue( data_e[col]);
		}
	}

	outImage = out.clone();
}
/*********************************/
//�������ƣ�encrypt
//�������ã��õ����ܺ��ͼ�񣬿����ڼ��ܲ�ɫͼ����߻Ҷ�ͼ
//���������showImage���ϲ�ͼ�� encryptImage��������ͼ isColor��Ĭ��Ϊfalse����������ͼ����Ƿ��ǲ�ɫͼ��
//��������ܺ��ͼ��
//���ߣ�ZhongKang97
//�༭ʱ�䣺20190318
/*********************************/
void imageEncrypter::encrypt(cv::Mat showImage, cv::Mat encryptImage,Mat & outImg, bool isColor)
{
	showImg_hight = showImage.rows;
	showImg_width = showImage.cols;
	resize(encryptImage, encryptImage, Size(showImg_width, showImg_hight));
    Mat out(showImage.size(),showImage.depth());
	if (isColor == true)
	{
		vector<Mat> BGR_show, BGR_encryptImage,BGR_out;
		cv::split(showImage, BGR_show);
		cv::split(encryptImage, BGR_encryptImage);
		cv::split(showImage.clone(), BGR_out);
		for (int channel = 0; channel < 3; channel++)
			processSingleChannelPic(BGR_show[channel], BGR_encryptImage[channel], BGR_out[channel]);
		cv::merge(BGR_out, out);
	}
	else
	{
		 processSingleChannelPic(showImage, encryptImage,out);
	}
	outImg = out.clone();
}
/*********************************/
//�������ƣ�decode
//�������ã��õ����ܺ��ͼ�񣬿����ڲ�ɫͼ����߻Ҷ�ͼ
//���������encryptedImage�����ܺ��ͼ�� isColor��Ĭ��Ϊfalse����������ͼ����Ƿ��ǲ�ɫͼ��
//��������ܺ��ͼ��
//���ߣ�ZhongKang97
//�༭ʱ�䣺20190319
/*********************************/
void imageEncrypter::decode(cv::Mat encryptedImage,Mat& outImg, bool isColor)
{
	if (showImg_width == 0 || showImg_hight == 0)
	{
		encryptImg_hight = encryptedImage.rows;
		encryptImg_width = encryptedImage.cols;
		resize(encryptedImage, encryptedImage, Size(encryptImg_width, encryptImg_hight));
	}
	else resize(encryptedImage, encryptedImage, Size(showImg_width, showImg_hight));
	Mat out(encryptedImage.size(), encryptedImage.depth());
	if (isColor == true)
	{
		vector<Mat> BGR_out(3), BGR_encrypted;
		cv::split(encryptedImage, BGR_encrypted);
		for (int channel = 0; channel < 3; channel++)
			decodeSingleChannelPic(BGR_encrypted[channel], BGR_out[channel]);
		merge(BGR_out, out);
	}
	else
	{
		decodeSingleChannelPic(encryptedImage, out);
	}
	outImg = out.clone();
}

