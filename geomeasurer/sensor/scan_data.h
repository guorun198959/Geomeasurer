/*
 * Copyright (c) 2017, <copyright holder> <email>
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *     * Neither the name of the <organization> nor the
 *     names of its contributors may be used to endorse or promote products
 *     derived from this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY <copyright holder> <email> ''AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL <copyright holder> <email> BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * 
 */

#ifndef SCAN_DATA_H
#define SCAN_DATA_H
#include <boost/concept_check.hpp>
#include<vector>
#include<pcl/common/common.h>
#include"../transform/pose2d.h"

#include<pcl/kdtree/kdtree_flann.h>


typedef pcl::PointCloud<pcl::PointXYZ> PointCloud;
typedef pcl::PointXYZ point3d;



namespace geomeasurer
{
  namespace sensor
  {

class rangeData{
public:
  rangeData(){}
  rangeData(const double & angle_increment_,const double &maxRange_,const double& angle_min_,const double& angle_max_):
  angle_increment(angle_increment_),maxRange(maxRange_),angle_min(angle_min_),angle_max(angle_max_){}
  double angle_increment;
  double maxRange;
  double angle_min;
  double angle_max;
 std:: vector<double> ranges;
 int getIndexbyPoint(const point3d & point);
 PointCloud getpcdfromscan();
};

struct laserAbstract{
  std::string name;
  
};

typedef std::vector<std::pair<pose2dStamped, sensor::rangeData>> RangesCorrespondingtoposes;
typedef std::pair<pose2dStamped, sensor::rangeData> rangeWithpose;

PointCloud fromRangeData(const rangeData &ranges_data);  
rangeData fromPointCloud(const PointCloud &pcd);



}
}

#endif // SCAN_DATA_H
