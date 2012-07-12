#include <iostream>
#include <pcl/point_types.h>
void resampler(const std::string& inputfile,const std::string& outputfile);
void filter(const std::string& inputfile,const std::string& outputfile);
void  surface(const std::string& inputfile,const std::string& outputfile);
void Removeoutliers(const std::string& inputfile,const std::string& outputfile);
int testCrtHull (const std::string& inputfile,const std::string& outputfile);
int poissonSurface_file(const std::string& inputfile,const std::string& outputfile);
int poissonSurface(pcl::PointCloud<pcl::PointXYZ>::Ptr cloud,const std::string outputfile);