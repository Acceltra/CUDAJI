#include "BaseImageProcessor.h"

namespace CUDAJI
{
	namespace ImageProcess
	{

class GrayScaleProcessor :public BaseImageProcessor
{
public:
	GrayScaleProcessor();
	~GrayScaleProcessor();
	
	bool GrayScale(cv::Mat matSrcImage, cv::Mat matDstImage);
	bool Process();

public:
	int nImageWidth;
	int nImageHeight;
	int nImageChannel;
};

	}
}