#include "CUDAGrayScaleProcessor.cuh"

namespace CUDAJI
{
	namespace ImageProcess
	{

GrayScaleProcessor::GrayScaleProcessor()
{
	nImageWidth = 512;
	nImageHeight = 512;
	nImageChannel = 1;
}

GrayScaleProcessor::~GrayScaleProcessor()
{

}

bool GrayScaleProcessor::GrayScale(cv::Mat matSrcImage, cv::Mat matDstImag)
{
	return true;
}

bool GrayScaleProcessor::Process()
{
	cv::Mat matSrcImage = ReadImage(nImageWidth, nImageHeight, "../../Resource/Lena_Gray_512_512.raw", nImageChannel);
	cv::Mat matDstImage(nImageWidth, nImageHeight, CV_16UC1);

	GrayScale(matSrcImage, matDstImage);

	WriteImage(nImageWidth, nImageHeight, "../../Resource/Lena_Gray_512_512_Res.raw", nImageChannel, matDstImage);
}



	}
}