#include "stdafx.h"
#include "pcl_function.h"
#include <pcl/io/pcd_io.h>
#include <pcl/features/normal_3d.h>
#include <pcl/surface/gp3.h>
#include <pcl/features/feature.h>
#include <pcl/io/vtk_io.h>
#include <pcl/filters/voxel_grid.h>
#include <pcl/kdtree/kdtree_flann.h>
#include <pcl/surface/mls.h>
#include <pcl/features/normal_3d_omp.h>
#include <pcl/surface/poisson.h>

#include <pcl/surface/vtk_utils.h>
#include <pcl/surface/vtk_mesh_smoothing_windowed_sinc.h>
#include <vtkWindowedSincPolyDataFilter.h>
#include <pcl/surface/vtk.h>
#include <pcl/surface/vtk_mesh_smoothing_laplacian.h>
#include <pcl/surface/vtk_smoothing/vtk.h>
#include <pcl/ModelCoefficients.h>
#include <pcl/point_types.h>
#include <pcl/sample_consensus/method_types.h>
#include <pcl/sample_consensus/model_types.h>
#include <pcl/filters/passthrough.h>
#include <pcl/filters/project_inliers.h>
#include <pcl/segmentation/sac_segmentation.h>
#include <pcl/surface/concave_hull.h>

int poissonSurface(pcl::PointCloud<pcl::PointXYZ> &cloud1,const std::string outputfile){
std::vector<int> indexes;
	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);
	cloud->is_dense = false; 
	pcl::removeNaNFromPointCloud(cloud1,*cloud,indexes);
	/*pcl::PointCloud<pcl::PointXYZ>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZ> ());*/
	pcl::io::loadPCDFile ("c:\\wm_all_1.pcd", *cloud);
/////////***********
	time_t t;
	t=time(&t);
	char* time_start=ctime(&t);
	std::cerr << "strat time is: "<< time_start << " *****" << std::endl;	
	t=time(&t);
	char* time_load=ctime(&t);
	std::cerr << "end load time is: "<< time_load << " *****" << std::endl;
/////////***********
//	pcl::MovingLeastSquaresOMP<pcl::PointXYZ, pcl::PointXYZ> mls;
	pcl::MovingLeastSquares<pcl::PointXYZ, pcl::PointXYZ> mls;
//	mls.setNumberOfThreads(4);
	mls.setInputCloud (cloud);
	mls.setSearchRadius (0.01);
	mls.setPolynomialFit (true);
	mls.setPolynomialOrder (2);
	mls.setUpsamplingMethod(pcl::MovingLeastSquares<pcl::PointXYZ, pcl::PointXYZ>::SAMPLE_LOCAL_PLANE);
	mls.setUpsamplingRadius (0.005);
	mls.setUpsamplingStepSize (0.003);
	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_smoothed (new pcl::PointCloud<pcl::PointXYZ> ());
	mls.process(*cloud_smoothed);
/////////***********
	t=time(&t);
	char* time_MLS_end=ctime(&t);
	std::cerr << "end process MovingLeastSquares time is: "<< time_MLS_end << " *****" << std::endl;
/////////***********0.0
	t=time(&t);
	char* time_Normal=ctime(&t);
	std::cerr << "start Normal time is: "<< time_Normal<< " *****" << std::endl;
/////////***********
	pcl::NormalEstimationOMP<pcl::PointXYZ, pcl::Normal> ne;
	ne.setNumberOfThreads (4);
	ne.setInputCloud (cloud_smoothed);
	Eigen::Vector4f centroid;
	compute3DCentroid (*cloud_smoothed, centroid);
	ne.setViewPoint (centroid[0], centroid[1], centroid[2]);
	pcl::PointCloud<pcl::Normal>::Ptr cloud_normals (new pcl::PointCloud<pcl::Normal> ());
	pcl::search::KdTree<pcl::PointXYZ>::Ptr tree (new pcl::search::KdTree<pcl::PointXYZ>);
	ne.setSearchMethod(tree);
	ne.setKSearch(20);
	ne.compute (*cloud_normals);
	for (size_t i = 0; i < cloud_normals->size (); ++i)
	{
		cloud_normals->points[i].normal_x *= -1;
		cloud_normals->points[i].normal_y *= -1;
		cloud_normals->points[i].normal_z *= -1;
	}
	/////////***********64324023 
	t=time(&t);
	char* time_Normal_end=ctime(&t);
	std::cerr << "end Normal time is: "<< time_Normal_end<< " *****" << std::endl;
/////////***********
	pcl::PointCloud<pcl::PointNormal>::Ptr cloud_smoothed_normals (new pcl::PointCloud<pcl::PointNormal> ());
	concatenateFields (*cloud_smoothed, *cloud_normals, *cloud_smoothed_normals);
	pcl::Poisson<pcl::PointNormal> poisson;
	poisson.setDepth (9);
	poisson.setInputCloud(cloud_smoothed_normals);
	pcl::PolygonMesh::Ptr mesh(new pcl::PolygonMesh);
	poisson.reconstruct (*mesh);
	pcl::io::saveVTKFile(outputfile,*mesh);
	/////////***********
	t=time(&t);
	char* time_poission=ctime(&t);
	std::cerr << "end poinssion time is: "<< time_poission<< " *****" << std::endl;
/////////***********
	return 0; 
}

