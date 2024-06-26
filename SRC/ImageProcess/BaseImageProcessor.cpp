#include <fstream>
#include "BaseImageProcessor.h"

namespace CUDAJI
{
	namespace ImageProcess
	{

template<class TypeName>
DevImage<TypeName>::DevImage()
{
	pPitchedImage.ptr = nullptr;
	pPitchedImage.pitch = 0;
}

BaseImageProcessor::BaseImageProcessor()
{

}

BaseImageProcessor::~BaseImageProcessor()
{

}

cv::Mat BaseImageProcessor::ReadImage(int nImageWidth, int nImageHeight, std::string stdImagePath, int nImageChannel)
{
	std::fstream fIn(stdImagePath, std::fstream::in | std::fstream::binary);
	char* pBuffer = new char[nImageWidth * nImageHeight * sizeof(ushort) * nImageChannel];
	fIn.read((char*)pBuffer, nImageWidth * nImageHeight * sizeof(ushort) * nImageChannel);
	fIn.close();

	cv::Size SrcSize(nImageWidth, nImageHeight);
	cv::Mat matImage(SrcSize, CV_16UC1, pBuffer);
	cv::Mat matSrcImage = matImage;

	delete pBuffer;

	return matSrcImage;
}

void BaseImageProcessor::WriteImage(int nImageWidth, int nImageHeight, std::string stdImagePath, int nImageChannel, cv::Mat matDstImage)
{
	std::fstream fOut(stdImagePath, std::fstream::out | std::fstream::binary);
	fOut.write((char*)matDstImage.data, nImageWidth * nImageHeight * sizeof(ushort) * nImageChannel);
	fOut.close();
}

bool BaseImageProcessor::Process()
{
	return true;
}



	}
}