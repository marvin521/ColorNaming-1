#pragma once
#include<opencv2\opencv.hpp>
#include<iostream>  
#include<opencv2\core\core.hpp>  
#include<opencv2\highgui\highgui.hpp>  
using namespace cv;
using namespace std;
typedef Vec<double, 11> Vec11d;

//===========��ɫ�����ĵ�һ�ַ���;�ο�Learning Color Names for Real-World Applications===========//
//Black, Blue, Brown, Grey, Green, Orange, Pink, Purple, Red, White, Yellow
class ColorNamePLSA
{
private:
	vector<vector<double>> RGBtable;									//���ұ���СΪ32768*11;

	Mat floorMat(const Mat & doubleMat);								//ע�����ֻΪ CV_64FC1  
public:
	ColorNamePLSA();													//���캯�������ұ��ʼ��
	vector<double> SampleColorNamePLSA(double R, double G, double B);   //���RGB�ռ��һ��������11����ɫ�ĸ���ֵ
	Mat getColorMapPLSA(const Mat &src);								//�õ�����ͼ���ÿ�����ص����ɫ���ӻ�
	vector<double> getColorNameFeature(const Mat &src);					//����LOMO�������Ƶķ������õ�����ɫ����Ϊ165ά
};



//===============��ɫ�����ĵڶ��ַ���;�ο�Parametric fuzzy sets for automatic color naming=====//
//Red, Orange, Brown, Yellow, Green, Blue, Purple, Pink, Black, Grey, White
class ColorNameTSE
{
private:
	int numColors;														//��ɫ�����
	int numChromatics;													//��ɫ�����
	int numAchromatics;													//�ǲ�ɫ�����
	double parameters[6][8][10];										//parameters of the model(chromatic colors)
	int thrL[7];														//parameters of the model(lightness levels)
	double paramsAchro[4][2];											//parameters of the model(achromatic colors)

	static double Sigmoid(double s, double t, double b);
public:
	ColorNameTSE();														//���캯����������ʼ��
	vector<double> SampleColorNameTSE(double L, double a, double b);    //���Lab�ռ��һ��������11����ɫ�ĸ���ֵ
	Mat getColorMapTSE(const Mat &src);									//�õ�����ͼ���ÿ�����ص����ɫ���ӻ�
	vector<double> getColorNameFeature(const Mat &src);					//����LOMO�������Ƶķ������õ�����ɫ����Ϊ165ά
};
