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
#include <ctime>
#include <pcl/surface/mls.h>
#include <pcl/features/normal_3d_omp.h>
#include <pcl/surface/poisson.h>



//int pt[6][2] ={{7,2},{9,6},{5,4},{2,3},{4,7},{8,1}};
//
//float variance(float* floatArr,int len){
//	float sum=0;
//	for (int i=0;i<len;i++)
//	{
//		sum+=floatArr[i];
//	}
//	return sum/len;
//}
//
//void findMinDist(){
//	
//}
//
//int testKDtree(float* floatArr,int len,float* container){
//	if (len>0)
//	{
//		float v=variance(floatArr,len);
//		for(int i=0;i<len;i++){
//			
//
//		}
//
//	}
//}
//
//void buildKDtree(){
//	
//
//}

#include <pcl/surface/vtk_utils.h>
#include <pcl/surface/vtk_mesh_smoothing_windowed_sinc.h>
#include <vtkWindowedSincPolyDataFilter.h>


void resampler(const std::string& inputfile,const std::string& outputfile){
	// Load input file into a PointCloud<T> with an appropriate type
	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZ> ());
	// Load bun0.pcd -- should be available with the PCL archive in test 
	pcl::io::loadPCDFile (inputfile, *cloud);
	// Create a KD-Tree
	pcl::search::KdTree<pcl::PointXYZ>::Ptr tree (new pcl::search::KdTree<pcl::PointXYZ>);
	// Output has the PointNormal type in order to store the normals calculated by MLS
	pcl::PointCloud<pcl::PointNormal> mls_points;
	// Init object (second point type is for the normals, even if unused)
	pcl::MovingLeastSquares<pcl::PointXYZ, pcl::PointNormal> mls;
	mls.setComputeNormals (true);
	// Set parameters
	mls.setInputCloud (cloud);
	mls.setPolynomialFit (true);
	mls.setSearchMethod (tree);
	mls.setSearchRadius (3);
	// Reconstruct
	mls.process (mls_points);
	// Save output
	pcl::io::savePCDFile (outputfile, mls_points);//"c:\\M17_PT\\m17_pt_2_resampler.pcd"
}

void filter(const std::string& inputfile,const std::string& outputfile){
	sensor_msgs::PointCloud2::Ptr cloud (new sensor_msgs::PointCloud2 ());
	sensor_msgs::PointCloud2::Ptr cloud_filtered (new sensor_msgs::PointCloud2 ());

	// Fill in the cloud data
	pcl::PCDReader reader;
	// Replace the path below with the path where you saved your file
	reader.read (inputfile, *cloud);// "c:\\M17_PT\\m17_pt_2.pcd"// Remember to download the file first!

	std::cerr << "PointCloud before filtering: " << cloud->width * cloud->height 
		<< " data points (" << pcl::getFieldsList (*cloud) << ").";

	// Create the filtering object
	pcl::VoxelGrid<sensor_msgs::PointCloud2> sor;
	sor.setInputCloud (cloud);
	sor.setLeafSize (10.0f, 10.0f, 10.0f);
	sor.filter (*cloud_filtered);

	std::cerr << "PointCloud after filtering: " << cloud_filtered->width * cloud_filtered->height 
		<< " data points (" << pcl::getFieldsList (*cloud_filtered) << ").";

	pcl::PCDWriter writer;
	writer.write (outputfile, *cloud_filtered, 
		Eigen::Vector4f::Zero (), Eigen::Quaternionf::Identity (), false);//"c:\\M17_PT\\m17_pt_2_filter.pcd"
}
#include <pcl/surface/vtk.h>
#include <pcl/surface/vtk_mesh_smoothing_laplacian.h>
#include <pcl/surface/vtk_smoothing/vtk.h>


void  surface(const std::string& inputfile,const std::string& outputfile){
// Load input file into a PointCloud<T> with an appropriate type
  pcl::PointCloud<pcl::PointXYZ>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZ>);
  sensor_msgs::PointCloud2 cloud_blob;
  pcl::io::loadPCDFile(inputfile,cloud_blob);//"c:\\M17_PT\\m17_pt_2_resampler.pcd"
  pcl::fromROSMsg (cloud_blob, *cloud);
  //* the data should be available in cloud
  // Normal estimation*
  pcl::NormalEstimation<pcl::PointXYZ, pcl::Normal> n;
  pcl::PointCloud<pcl::Normal>::Ptr normals (new pcl::PointCloud<pcl::Normal>);
  pcl::search::KdTree<pcl::PointXYZ>::Ptr tree (new pcl::search::KdTree<pcl::PointXYZ>);
  tree->setInputCloud (cloud);
  n.setInputCloud (cloud);
  n.setSearchMethod (tree);
  n.setKSearch(20);
  //  n.setRadiusSearch(0.2);
  n.compute (*normals);
  //* normals should not contain the point normals + surface curvatures
  // Concatenate the XYZ and normal fields*
  pcl::PointCloud<pcl::PointNormal>::Ptr cloud_with_normals (new pcl::PointCloud<pcl::PointNormal>);
  pcl::concatenateFields (*cloud, *normals, *cloud_with_normals);
//  pcl::io::savePCDFile (outputfile, *cloud_with_normals);//"c:\\M17_PT\\m17_pt_2_resampler.pcd"
  //* cloud_with_normals = cloud + normals
  // Create search tree*
  pcl::search::KdTree<pcl::PointNormal>::Ptr tree2 (new pcl::search::KdTree<pcl::PointNormal>);
  tree2->setInputCloud (cloud_with_normals);
  // Initialize objects
  pcl::GreedyProjectionTriangulation<pcl::PointNormal> gp3;
  pcl::PolygonMesh::Ptr  ptr_triangles(new pcl::PolygonMesh);
  // Set the maximum distance between connected points (maximum edge length)
  gp3.setSearchRadius (0.025);
  // Set typical values for the parameters
  gp3.setMu (2.5);
  gp3.setMaximumNearestNeighbors (100);
  gp3.setMaximumSurfaceAngle(M_PI/4); // 45 degrees
  gp3.setMinimumAngle(M_PI/18); // 10 degrees
  gp3.setMaximumAngle(2*M_PI/3); // 120 degrees
  gp3.setNormalConsistency(false);
  // Get result
  gp3.setInputCloud (cloud_with_normals);
  gp3.setSearchMethod (tree2);
  gp3.reconstruct (*ptr_triangles);
  pcl::PolygonMesh triangles_out;
  pcl::MeshSmoothingWindowedSincVTK mesh_smoother;
  mesh_smoother.setInputMesh(ptr_triangles);
  mesh_smoother.setNumIter(20000); 
  mesh_smoother.setBoundarySmoothing(true);
  mesh_smoother.setFeatureEdgeSmoothing(true);
  mesh_smoother.setFeatureAngle(M_PI/5); 
  mesh_smoother.process(triangles_out);
  // Finish.
 // pcl::io::saveVTKFile(outputfile, triangles_out);
  pcl::io::saveVTKFile(outputfile, *ptr_triangles);
}

#include <pcl/filters/statistical_outlier_removal.h>
void Removeoutliers(const std::string& inputfile,const std::string& outputfile)
{
	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZ>);
	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_filtered (new pcl::PointCloud<pcl::PointXYZ>);
	// Fill in the cloud data
	pcl::PCDReader reader;
	// Replace the path below with the path where you saved your file
	reader.read<pcl::PointXYZ> (inputfile, *cloud);
	std::cerr << "Cloud before filtering: " << std::endl;
	std::cerr << *cloud << std::endl;
	// Create the filtering object
	pcl::StatisticalOutlierRemoval<pcl::PointXYZ> sor;
	sor.setInputCloud (cloud);
	sor.setMeanK (50);
	sor.setStddevMulThresh (1.0);
	sor.filter (*cloud_filtered);

	std::cerr << "Cloud after filtering: " << std::endl;
	std::cerr << *cloud_filtered << std::endl;

	pcl::PCDWriter writer;
	writer.write<pcl::PointXYZ> (outputfile+"in.pcd", *cloud_filtered, false);
	sor.setNegative (true);
	sor.filter (*cloud_filtered);

	writer.write<pcl::PointXYZ> (outputfile+"out.pcd", *cloud_filtered, false);
}


#include <pcl/ModelCoefficients.h>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/sample_consensus/method_types.h>
#include <pcl/sample_consensus/model_types.h>
#include <pcl/filters/passthrough.h>
#include <pcl/filters/project_inliers.h>
#include <pcl/segmentation/sac_segmentation.h>
#include <pcl/surface/concave_hull.h>

int
  testCrtHull (const std::string& inputfile,const std::string& outputfile)
{
	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZ>), 
		cloud_filtered (new pcl::PointCloud<pcl::PointXYZ>), 
		cloud_projected (new pcl::PointCloud<pcl::PointXYZ>);
	pcl::PCDReader reader;

	reader.read (inputfile, *cloud);
	// Build a filter to remove spurious NaNs
	pcl::PassThrough<pcl::PointXYZ> pass;
	pass.setInputCloud (cloud);
	pass.setFilterFieldName ("z");
	pass.setFilterLimits (0, 1.1);
	pass.filter (*cloud_filtered);
	std::cerr << "PointCloud after filtering has: "
		<< cloud_filtered->points.size () << " data points." << std::endl;

	pcl::ModelCoefficients::Ptr coefficients (new pcl::ModelCoefficients);
	pcl::PointIndices::Ptr inliers (new pcl::PointIndices);
	// Create the segmentation object
	pcl::SACSegmentation<pcl::PointXYZ> seg;
	// Optional
	seg.setOptimizeCoefficients (true);
	// Mandatory
	seg.setModelType (pcl::SACMODEL_PLANE);
	seg.setMethodType (pcl::SAC_RANSAC);
	seg.setDistanceThreshold (0.01);

	seg.setInputCloud (cloud_filtered);
	seg.segment (*inliers, *coefficients);
	std::cerr << "PointCloud after segmentation has: "
		<< inliers->indices.size () << " inliers." << std::endl;

	// Project the model inliers
	pcl::ProjectInliers<pcl::PointXYZ> proj;
	proj.setModelType (pcl::SACMODEL_PLANE);
	proj.setInputCloud (cloud_filtered);
	proj.setModelCoefficients (coefficients);
	proj.filter (*cloud_projected);
	std::cerr << "PointCloud after projection has: "
		<< cloud_projected->points.size () << " data points." << std::endl;

	// Create a Concave Hull representation of the projected inliers
	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_hull (new pcl::PointCloud<pcl::PointXYZ>);
	pcl::ConcaveHull<pcl::PointXYZ> chull;
	chull.setInputCloud (cloud_projected);
	chull.setAlpha (0.1);
	chull.reconstruct (*cloud_hull);
	pcl::PCDWriter writer;
	writer.write (outputfile, *cloud_hull, false);
	return (0);
}
#include <ctime>
#include <pcl/surface/mls.h>
#include <pcl/features/normal_3d_omp.h>
#include <pcl/surface/poisson.h>
#include <pcl/filters/filter.h>
int poissonSurface_file(const std::string& inputfile,const std::string& outputfile){
/////////***********
	time_t t;
	t=time(&t);
	char* time_start=ctime(&t);
	std::cerr << "strat time is: "<< time_start << " *****" << std::endl;
/////////***********
	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZ> ());
	pcl::io::loadPCDFile (inputfile, *cloud);
/////////***********
	t=time(&t);
	char* time_load=ctime(&t);
	std::cerr << "end load time is: "<< time_load << " *****" << std::endl;
/////////***********
//	pcl::MovingLeastSquaresOMP<pcl::PointXYZ, pcl::PointXYZ> mls;
	pcl::MovingLeastSquares<pcl::PointXYZ, pcl::PointXYZ> mls;
	mls.setInputCloud (cloud);
	mls.setSearchRadius (0.01);
	mls.setPolynomialFit (true);
	mls.setPolynomialOrder (2);
//	mls.setUpsamplingMethod(pcl::MovingLeastSquaresOMP<pcl::PointXYZ, pcl::PointXYZ>::SAMPLE_LOCAL_PLANE);
	mls.setUpsamplingMethod(pcl::MovingLeastSquares<pcl::PointXYZ, pcl::PointXYZ>::SAMPLE_LOCAL_PLANE);
	mls.setUpsamplingRadius (0.005);
	mls.setUpsamplingStepSize (0.003);
	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_smoothed (new pcl::PointCloud<pcl::PointXYZ> ());
//	if(false==mls.initCompute){return 0;}
/////////***********
	t=time(&t);
	char* time_MLS=ctime(&t);
	std::cerr << "start process MovingLeastSquares time is: "<< time_MLS << " *****" << std::endl;
/////////***********
	mls.process (*cloud_smoothed);
/////////***********
	t=time(&t);
	char* time_MLS_end=ctime(&t);
	std::cerr << "end process MovingLeastSquares time is: "<< time_MLS_end << " *****" << std::endl;
/////////***********
	t=time(&t);
	char* time_Normal=ctime(&t);
	std::cerr << "start Normal time is: "<< time_Normal<< " *****" << std::endl;
/////////***********
	pcl::NormalEstimationOMP<pcl::PointXYZ, pcl::Normal> ne;
	ne.setNumberOfThreads (4);
	ne.setInputCloud (cloud_smoothed);
//	ne.setRadiusSearch (0.01);
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
	/////////***********
	t=time(&t);
	char* time_Normal_end=ctime(&t);
	std::cerr << "end Normal time is: "<< time_Normal_end<< " *****" << std::endl;
/////////***********
	pcl::PointCloud<pcl::PointNormal>::Ptr cloud_smoothed_normals (new pcl::PointCloud<pcl::PointNormal> ());
	concatenateFields (*cloud_smoothed, *cloud_normals, *cloud_smoothed_normals);
	pcl::Poisson<pcl::PointNormal> poisson;
	poisson.setDepth (9);
	poisson.setInputCloud(cloud_smoothed_normals);
	pcl::PolygonMesh mesh;
	poisson.reconstruct (mesh);
	pcl::io::saveVTKFile (outputfile, mesh);
	/////////***********
	t=time(&t);
	char* time_poission=ctime(&t);
	std::cerr << "end poinssion time is: "<< time_poission<< " *****" << std::endl;
/////////***********
	return 0; 
}

int poissonSurface(pcl::PointCloud<pcl::PointXYZ> &cloud1,const std::string outputfile){
	std::vector<int> indexes;
	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);
	cloud->is_dense = false; 
	pcl::removeNaNFromPointCloud(cloud1,*cloud,indexes);
/////////***********
	time_t t;
	t=time(&t);
	char* time_start=ctime(&t);
	std::cerr << "strat time is: "<< time_start << " *****" << std::endl;	
/////////***********
	/*pcl::PointCloud<pcl::PointXYZ>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZ> ());
	pcl::io::loadPCDFile ("c:\\wm_all.pcd", *cloud);*/
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
	/*if(!mls.initCompute()){
		return 0;
	}*/
/////////***********
//	t=time(&t);
//	char* time_MLS=ctime(&t);
//	std::cerr << "start process MovingLeastSquares time is: "<< time_MLS << " *****" << std::endl;
/////////***********
	
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
//	pcl::NormalEstimationOMP<pcl::PointXYZ, pcl::Normal> ne;
	pcl::NormalEstimation<pcl::PointXYZ, pcl::Normal> ne;
//	ne.setNumberOfThreads (4);
	ne.setInputCloud (cloud_smoothed);
//	ne.setRadiusSearch (0.01);
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
	/////////***********
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

