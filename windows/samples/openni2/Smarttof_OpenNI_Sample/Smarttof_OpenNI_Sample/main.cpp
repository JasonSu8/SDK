/*****************************************************************************
*                                                                            *
*  OpenNI 2.x Alpha                                                          *
*  Copyright (C) 2012 PrimeSense Ltd.                                        *
*                                                                            *
*  This file is part of OpenNI.                                              *
*                                                                            *
*  Licensed under the Apache License, Version 2.0 (the "License");           *
*  you may not use this file except in compliance with the License.          *
*  You may obtain a copy of the License at                                   *
*                                                                            *
*      http://www.apache.org/licenses/LICENSE-2.0                            *
*                                                                            *
*  Unless required by applicable law or agreed to in writing, software       *
*  distributed under the License is distributed on an "AS IS" BASIS,         *
*  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  *
*  See the License for the specific language governing permissions and       *
*  limitations under the License.                                            *
*                                                                            *
*****************************************************************************/
#include <OpenNI.h>
#include "Viewer.h"

int main(int argc, char** argv)
{
	openni::Status rc = openni::STATUS_OK;

	openni::Device device;
	openni::VideoStream depth, color;
	//const char* deviceURI = openni::ANY_DEVICE;
	const char* deviceURI = "SMARTTOFURI";

	if (argc > 1)
	{
		deviceURI = argv[1];
	}

	rc = openni::OpenNI::initialize();

	//ni
	if (rc != openni::STATUS_OK)
	{
		printf("smarttof initialization failed\n");
	}

	printf("After initialization:\n%s\n", openni::OpenNI::getExtendedError());

	rc = device.open(deviceURI);
	if (rc != openni::STATUS_OK)
	{
		printf("SimpleViewer: Device open failed:\n%s\n", openni::OpenNI::getExtendedError());
		openni::OpenNI::shutdown();
		return 1;
	}
	else{
		printf("smarttof viewer open ok\n");
	}

	rc = depth.create(device, openni::SENSOR_DEPTH);
	if (rc == openni::STATUS_OK)
	{
		rc = depth.start();
		if (rc != openni::STATUS_OK)
		{
			printf("SimpleViewer: Couldn't start depth stream:\n%s\n", openni::OpenNI::getExtendedError());
			depth.destroy();
		}
	}
	else
	{
		printf("SimpleViewer: Couldn't find depth stream:\n%s\n", openni::OpenNI::getExtendedError());
	}

	openni::VideoFrameRef frameDepth ;

	
	printf("Start process depth data\n");
	for (int i = 0; i < 200; i++)
	{
		
		if (rc != openni::STATUS_OK)
		{
		
		}
		rc = depth.readFrame(&frameDepth);
		printf("%d ,%d %d,**********\n",frameDepth.getDataSize(), frameDepth.getVideoMode().getResolutionX(), frameDepth.getVideoMode().getResolutionY());
		if (openni::STATUS_OK == rc)
		{
			printf("Read %d frame ok\n",++i);
		} else
		{
			printf("Read frame failed\n");
		}
	}
	depth.destroy();
	device.close();
	openni::OpenNI::shutdown();
	getchar();


	//if (!depth.isValid() || !color.isValid())
	//if (!depth.isValid())
	//{
	//	printf("SimpleViewer: No valid streams. Exiting\n");
	//	openni::OpenNI::shutdown();
	//	return 2;
	//}

	////SampleViewer sampleViewer("Simple Viewer", device, depth, color);
	//SampleViewer sampleViewer("Simple Viewer", device, depth, color);

	//rc = sampleViewer.init(argc, argv);
	//if (rc != openni::STATUS_OK)
	//{
	//	openni::OpenNI::shutdown();
	//	return 3;
	//}
	//sampleViewer.run();
}