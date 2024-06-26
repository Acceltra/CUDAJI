#pragma once

#include <opencv2/opencv.hpp>
#include "cuda_runtime.h"

namespace CUDAJI
{
	namespace ImageProcess
	{

template<class TypeName>
class DevImage
{
public:
	DevImage();
	~DevImage();

	long GetImageSize();

	cudaPitchedPtr pPitchedImage;
};

class BaseImageProcessor
{
public:
	BaseImageProcessor();
	~BaseImageProcessor();

	void CUDAFunctionTimer();
	void CPUFunctionTimer();

	cv::Mat ReadImage(int nImageWidth, int nImageHeight, std::string stdImagePath, int nImageChannel);
	void WriteImage(int nImageWidth, int nImageHeight, std::string stdImagePath, int nImageChannel, cv::Mat matDstImage);

	virtual bool Process();
};

	}
}

