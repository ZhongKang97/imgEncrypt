#include"../include/190316_imageEncrypter.h"
/********************demo****************************/
//作用：展示类的使用方法和效果
//
//作者：zhongkang97
//编辑时间：20190319
/***************************************************/
int main(int argc, char** argv)
{
	if (argc != 3) cout << "Useage: showImage hide_img" << endl;
	else
	{
		//Mat img_show = cv::imread(agrv[1]);
		//Mat img_encrypt = cv::imread(argv[2]);
		Mat img_show = cv::imread("D:\\CODEing\\DataSets\\OpenCV_data\\MyData\\Clannad_2.jpg");
		Mat img_encrypt = cv::imread("D:\\CODEing\\DataSets\\OpenCV_data\\MyData\\Clannad_3.jpg");
		int encrypt_width = img_encrypt.cols;
		int encrypt_hight = img_encrypt.rows;
		imshow("Img to show", img_show);
		imshow("Img To encrypt", img_encrypt);
		imageEncrypter coder;
		Mat out;
		coder.encrypt(img_show, img_encrypt, out, true);
		imshow("Img after encrypt", out);
		Mat decodeImg;
		coder.decode(out, decodeImg, true);
		resize(decodeImg, decodeImg, Size(encrypt_width, encrypt_hight));
		imshow("decodeImg for the encryptedImg", decodeImg);
		waitKey(0);
	}
	return 1;
}