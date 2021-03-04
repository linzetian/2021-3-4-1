//图形绘制(以及文字)
#include<opencv2/opencv.hpp>
//#include<opencv2/imgproc/types_c.h>
//#include <opencv2\core\core.hpp>
#include<iostream>
using namespace std;
using namespace cv;


void MyLine();//画线
void MyRectangle();//画矩形
void MyEllipse();//画椭圆
void MyfillPoly();//绘制多边形填充
void Mycircle();//绘制圆
void RandomLineDemo();//绘制随机线
Mat src;
int main()
{
	//Mat src;
	src = imread("F:/image/1.6.png");
	if (!src.data)
	{
		printf("can not load the picture");
		return -1;
	}
	
	MyLine();//函数调用
	MyRectangle();
    MyEllipse();
	MyfillPoly();
	Mycircle();
	RandomLineDemo();
	namedWindow("output",WINDOW_AUTOSIZE);
	imshow("output",src);
	
	waitKey(0);
	return 0;
}

void MyLine()
{
	//Point p;
	Point p = Point(src.cols / 2 - 100, src.rows / 2 - 150);
	Point p1;
	p1.x = src.cols / 2 + 100;
	p1.y = src.rows / 2 +150;
	Scalar color = Scalar(0, 0, 255);
	putText(src,"OPENCV", Point(src.cols / 2, src.rows / 2),FONT_HERSHEY_COMPLEX,2.0, Scalar(0, 0, 255),2,LINE_8);
	line(src, p, p1, color, 2, LINE_8);//src是全局变量
	printf("cols=%d\nrows=%d\n",src.cols,src.rows);
}

void MyRectangle()
{
	//Point p2 = Point(src.cols/2,src.rows/2);
	Rect rect = Rect(src.cols/2-100, src.rows/2-150, 200, 300);
	Scalar color = Scalar(255, 0, 0);
	rectangle(src,rect,color,2,LINE_8);
}

void MyEllipse()
{
	Point p3= Point(src.cols / 2, src.rows / 2);
	Scalar color = Scalar(0, 255, 0);
	ellipse(src,p3, Size(src.cols/4, src.rows/8),90,0,360,color,2,LINE_8);
}

void MyfillPoly()
{
	Point Pts[1][5] = {Point(100,100),Point(100,200), Point(200,200), Point(200,100), Point(100,100)};
	const Point* ptts[] = { Pts[0] };//数组指针
	int count[] = { 5 };
	Scalar color = Scalar(0, 255, 0);
	fillPoly(src, ptts, count, 1, color, LINE_8);//
}

void Mycircle()
{
	Point center = Point(src.cols / 2, src.rows / 2);
	Scalar color = Scalar(34, 25, 134);
	circle(src,center,100,color,2,LINE_AA);
}

void RandomLineDemo()
{
	RNG rng(12345);
	Point p1, p2;
	Mat dst = Mat::zeros(src.size(),src.type());
	for (int i = 0; i < 5000; i++)
	{
		//waitKey(50);
		p1.x = rng.uniform(0, src.cols);
		p2.x = rng.uniform(0, src.cols);
		p1.y = rng.uniform(0, src.rows);
		p1.y = rng.uniform(0, src.rows);
		line(dst, p1, p2, Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255)), 1, LINE_8);
		imshow("randomlinedemo", dst);
		if (waitKey(50) > 0)
		{
			break;
		}
	}
	
}