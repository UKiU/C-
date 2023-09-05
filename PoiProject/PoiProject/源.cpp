#include <iostream>
#include <opencv2//opencv.hpp>

using namespace std;
using namespace cv;

int main(int argc, char** argv)
{
	//VideoCapture cap(0);
	VideoCapture cap("D:/Videos/QQ/QQ�ռ���Ƶ_20190824163933");
	if (!cap.isOpened())
	{
		printf("Can not open a camera\n");
		return -1;
	}

	while (true)
	{
		Mat frame;
		cap >> frame;
		if (frame.empty())
			break;

		imshow("frame", frame);

		// �Ǿ�ֵ�˲�
		Mat robot = (Mat_ <int>(2, 2) << 1, 0, 0, -1);
		Mat result;
		filter2D(frame, result, CV_32F, robot, Point(-1, -1), 127, BORDER_DEFAULT);
		convertScaleAbs(result, result);
		imshow("robot filter", result);

		//�ȴ� 30 �룬����������Ƴ�ѭ��
		if (waitKey(30) >= 0)
			break;
	}

	waitKey(0);
	return 0;
}
